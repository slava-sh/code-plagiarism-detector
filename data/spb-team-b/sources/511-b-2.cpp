#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	int n,a;
	fstream f;
	f.open("chess.in", fstream::in);
	f >> n;
	int *x = new int[n];
	int k = 1;
	for (int i = 0; i < n; i++){
		f >> a;
		x[i] = a;
		if (x[i] >= i+1) 
        { k = i+1; }
	}



	f.close();
	f.open("chess.out", fstream::out);
	f << k << endl;
	for (int i = 0; i < k; i++){
		f << i+1 << " " << i+1 << endl;
	}
	f.close();
	delete[]x;
	return 0;
}