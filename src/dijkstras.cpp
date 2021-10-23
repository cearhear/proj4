// dijsktras.cpp
#include <iostream>
#include <map>

using namespace std;

void print();

// Main Execution
int main(int argc, char *argv[]) {
	int numTiles, rows, columns, startR, startC, endR, endC;
	map<char, int> tVals; //map to hold tile values with names
	//need to decide on data structure to hold matrix...
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
			
			}
		}
		cin >> startR >> startC >> endR >> endC;
	//function calls on each set of data
	
	print();
	//clears the data structs for next set of data
	tVals.clear();

	}
	
	return 0;
}

void print(){
	
}
