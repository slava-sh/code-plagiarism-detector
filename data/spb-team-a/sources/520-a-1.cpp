// new.cpp : Defines the entry point for the console application.
//
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int a, b, c; 
		ifstream file;
		ofstream ofile;
		file.open("abcd.in", ifstream::in);
		file >> a;
		ofile.open("abcd.out", ofstream::out);
		for (int i = 0; i < a; i++){
			file >> b;
			c = ((b / 100)*(b / 100)) + (b - ((b / 100) * 100)) * (b - ((b / 100) * 100));
			if ((c - (c / 7) * 7) == 1) {
			
				ofile << "Yes" << endl;
			
			}
			else {
				
				ofile << "No" << endl;
			
			}
			c = 0;
			b = 0;

		}
		file.close();
		ofile.close();
}

