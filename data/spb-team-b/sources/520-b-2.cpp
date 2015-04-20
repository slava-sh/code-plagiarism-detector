
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int a, b, c;
	ifstream file;
	c = 0;
	file.open("chess.in", ifstream::in);
	file >> a;
	
	for (int i = 0; i < a; i++){
		file >> b;
		if ((c < b ) && (c < a)) {
			c = c + 1;
		}
		else {
			break;
		}
	}
	file.close();

	ofstream ofile;
	ofile.open("chess.out", ofstream::out);
	ofile << c << endl;
	for (int j = 0; j < c; j++) {
		ofile << j + 1 << " " << j + 1 << endl;
	}
	ofile.close();
}