#include <iostream>
#include <map>
#include <vector>

using namespace std;

//pass in the start/end positions, the matrix, and the tile values
void dijkstras(int startR, int startC, int endR, int endC, vector<vector<int>>matrix, map<char, int> tVals);

//pass in the distance and.....
void print(int dist, );

// Main Execution
int main(int argc, char *argv[]) {
    int numTiles, rows, columns, startR, startC, endR, endC, temp;
    map<char, int> tVals; //map to hold tile values with names
    vector<vector<int>> matrix;

    while(cin>>numTiles){
        int tCost;
        char tName;
        //reads in the tile names and costs
        for(int i=0; i<numTiles; i++){
            cin >> tName >> tCost;
            tVales.insert(pair<char, int>(tName, tCost));
        }
        cin >> rows >> columns;
        for(int r=0; r<rows; r++){
            for(int c=0; c<columns; c++){
                cin >> temp;
                matrix[r].push_back(temp);//reads in matrix??
            }
        }
        cin >> startR >> startC >> endR >> endC; //maybe store these as pairs?? for passing into Dijkstras function easier????

    //function calls on each set of data
    dijkstras(startR, startC, endR, endC, matrix, tVals);

    //clears the data structs for next set of data
    tVals.clear();
    matrix.clear();
    }

    return 0;
}

//Runs Dijkstras algorithm
void dijkstras(int startR, int startC, int endR, int endC, vector<vector<int>>matrix, map<char, int> tVals){
    //Disjkstras algorithm: keeps track of distance traveled and paths taken


    //call the print function
    print(distance,... );
}

//Prints the distance and the path
void print(int dist, ){

}

