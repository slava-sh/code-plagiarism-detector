
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("seq.in");
	ofstream fout("seq.out");
	int n, h, max=-1, max1;
	bool d;
	fin >> n >> h;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		fin >> a[i];
	for (int i = 0; i < n + 1 - h; i++){
		max1 = 0;
		d = true;
		for (int j = 1; j <= h; j++)
			if ((a[i + j - 1] <= j) && (d))
				max1 += j - a[i + j - 1];
			else
				d = false;
		if (d)
			if ((max == -1) || (max > max1))
				max = max1;
	}
	fout << max;
    fout.close(); 
}