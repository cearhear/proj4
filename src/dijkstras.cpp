#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{
    int row = 0;
    int col = 0;
    int cost = 0;
    int distance = -1;
    Node *backedge = NULL;
    bool visited = false;
};

struct Graph{
    vector<vector<Node>> graph;
    int MAP_ROWS;
    int MAP_COLS;
};

//pass in ref to graph, start/end positions, and the tile values
void dijkstras(Graph &G, int startR, int startC, int endR, int endC);

void print(Node *path);

// Main Execution
int main(int argc, char *argv[]) {
    int numTiles, rows, columns, startR, startC, endR, endC;
    char tile;
    map<char, int> tVals; //map to hold tile values with names

    while(cin>>numTiles){
        int tCost;
        char tName;
        Graph G;
        //reads in the tile names and costs
        for(int i=0; i<numTiles; i++){
            cin >> tName >> tCost;
            tVals.insert(pair<char, int>(tName, tCost));
        }
        
		cin >> rows >> columns; 
		
		//assigns rows and colums to Graph structure & resizes graph
		G.MAP_ROWS = rows;
		G.MAP_COLS = columns;
		G.graph.resize(rows);
		
		Node n;
        
		//reads in input matrix & assigns values to nodes which are pushed to Graph struct
		for(int r=0; r<rows; r++){
            G.graph[r].resize(columns);
            for(int c=0; c<columns; c++){
                cin >> tile;				
				//defines node values
				n.row=r;
				n.col=c;
				n.cost=tVals[tile];
				//push nodes to graph 
                G.graph[r][c] = n;
           }
        }
        cin >> startR >> startC >> endR >> endC; //maybe store these as pairs?? for passing into Dijkstras function easier????
	
    
    dijkstras(G, startR, startC, endR, endC);
    

    //clears the map for next set of data
    tVals.clear();
    }


    return 0;
}

//Runs Dijkstras algorithm
void dijkstras(Graph &G, int startR, int startC, int endR, int endC){

	//Sets values for 1st node and put on multimap
    Node *curr = &G.graph[startR][startC];
    Node *end = &G.graph[endR][endC];
    curr->distance=0; 
	multimap<int, Node*> frontier;
    frontier.insert(pair<int, Node*>(curr->distance, curr));
    curr->visited = true;

    //loop for all nodes
    while(!frontier.empty()){
        //takes first item in map and deletes it from map
        curr = frontier.begin()->second;

        int r = curr->row;
        int c = curr->col;
        frontier.erase(frontier.begin());
        curr->visited = true;
        //to check if path from current is shorter
        int d = curr->distance + curr->cost;

        //process adj nodes
        //checking below node
        if((r != 0) && (G.graph[r-1][c].visited == false)){
            if((G.graph[r-1][c].distance = -1) || (d < G.graph[r-1][c].distance)){
                G.graph[r-1][c].distance = d;
                G.graph[r-1][c].backedge = curr;
                frontier.insert(pair<int,Node*>(G.graph[r-1][c].distance, &G.graph[r-1][c]));
            }
        //checking above node
        }
        if((r != G.MAP_ROWS-1) && (G.graph[r+1][c].visited == false)){
            if((G.graph[r+1][c].distance = -1) || (d < G.graph[r+1][c].distance)){
                G.graph[r+1][c].distance = d;
                G.graph[r+1][c].backedge = curr;
                frontier.insert(pair<int,Node*>(G.graph[r+1][c].distance, &G.graph[r+1][c]));
            }
        //checking left node
        }
        if((c != 0) && (G.graph[r][c-1].visited == false)){
            if((G.graph[r][c-1].distance = -1) || (d < G.graph[r][c-1].distance)){
                G.graph[r][c-1].distance = d;
                G.graph[r][c-1].backedge = curr;
                frontier.insert(pair<int,Node*>(G.graph[r][c-1].distance, &G.graph[r][c-1]));
            }
        //checking right node
        }
        if((c != G.MAP_COLS-1) && (G.graph[r][c+1].visited == false)){
            if((G.graph[r][c+1].distance = -1) || (d < G.graph[r][c+1].distance)){
                G.graph[r][c+1].distance = d;
                G.graph[r][c+1].backedge = curr;
                frontier.insert(pair<int,Node*>(G.graph[r][c+1].distance, &G.graph[r][c+1]));
            }
        }

    }

	//testing graph output 
    //for(auto outer:G.graph){
    //    for(auto inner:outer){
    //        cout << inner.distance << " ";
    //  }
    //  cout << endl;
    //}


    //call the print function
    print(end);
    
}

//Prints the distance and the path
//still printing backwards will need to change
void print(Node *path){
    
    Node* curr = path;
    cout << curr->distance << endl;
    cout << curr->row << " " << curr->col << endl;
    while(curr->backedge != NULL){
        cout << curr->backedge->row << " " << curr->backedge->col << endl;
        curr = curr->backedge;
    }

}

