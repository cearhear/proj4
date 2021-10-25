#include <iostream>
#include <fstream>
using namespace std;

int main(){
	char letters[]="fgGhmr";
	char x;
	ofstream file;
	file.open("size1k.txt");
	file << "6\n" << "f 3\n" << "g 1\n" <<"G 2\n"<< "h 4\n"<< "m 7\n"<< "r 5\n" << "1000 1000" << endl;
	for(int r=0; r<1000; r++){
		x = letters[rand()%6];
		for(int c=0; c<1000;c++){
			file << x << " ";
			x = letters[rand()%6];
		}
		file << endl;
	}
	file << "0 0" << endl;
	file << "999 999" << endl;

	return 0;
}
