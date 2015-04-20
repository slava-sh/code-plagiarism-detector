#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("game.in");
	ofstream fout("game.out");
	int n, m, l1, r1, l2, r2, t = 0, w1=0, w2=0;
	bool d;
	fin >> n >> m >> l1 >> r1 >> l2 >> r2;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		fin >> a[i];
	for (int i = 0; i < m; i++){
		d = true;
		for (int j = 0; j < n; j++){
			if ((l1 <= a[j]) && (r1 >= a[j]) && (l2 <= a[j]) && (r2 >= a[j]) && (d) && (t < m)){
				n--;
				t++;
				w1++;
				d = false;
				for (int x = j; x < n; x++)
					a[x] = a[x + 1];
			}
		}
		if (d)
			for (int j = 0; j < n; j++){
			if ((l1 <= a[j]) && (r1 >= a[j]) && (d) && (t < m)){
				n--;
				t++;
				w1++;
				d = false;
				for (int x = j; x < n; x++)
					a[x] = a[x + 1];
			}
			}

		d = true;
		for (int j = 0; j < n; j++){
			if ((l1 <= a[j]) && (r1 >= a[j]) && (l2 <= a[j]) && (r2 >= a[j]) && (d) && (t < m)){
				n--;
				t++;
				w2++;
				d = false;
				for (int x = j; x < n; x++)
					a[x] = a[x + 1];
			}
		}
		if (d)
			for (int j = 0; j < n; j++){
			if ((l2 <= a[j]) && (r2 >= a[j]) && (d) && (t < m)){
				n--;
				t++;
				w2++;
				d = false;
				for (int x = j; x < n; x++)
					a[x] = a[x + 1];
			}
			}
	}
	if (w1 == w2)
		fout << "Draw";
	else
		if (w1 > w2)
			fout << "Petya";
		else
			fout << "Vasya";
	fout.close();
	return 0;
}