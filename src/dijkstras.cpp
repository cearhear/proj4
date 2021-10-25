#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node{
    int row = 0;
    int col = 0;
    //char type = ' ';
    int cost = 0;
    int distance = -1;
    Node *backedge = NULL;
    bool visited = false;
};

struct Graph{
    vector<vector<Node>> graph;
    map <char, int> edge_weights;
    int MAP_ROWS;
    int MAP_COLS;
};

//pass in ref to graph, start/end positions, and the tile values
Node* dijkstras(Graph &G, int startR, int startC, int endR, int endC);

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
        G.graph.resize(rows);
		Node n;
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
	
    //function calls on each set of data
    dijkstras(G, startR, startC, endR, endC);
    
    //testing graph output 
    //for(auto outer:G.graph){
  //      for(auto inner:outer){
    //        cout << inner.cost << " ";
  //      }
 //      cout << endl;
  //  }

    //clears the data structs for next set of data
    tVals.clear();
    }


    return 0;
}

//Runs Dijkstras algorithm
Node* dijkstras(Graph &G, int startR, int startC, int endR, int endC){
    //Disjkstras algorithm: keeps track of distance traveled and paths taken


    //call the print function
    
}

//Prints the distance and the path
void print(Node *path){

}

