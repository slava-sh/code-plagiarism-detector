#include <iostream>
#include <fstream>
using namespace std;

int main(){

	fstream f;
	f.open("dunes.in", fstream::in);
	int n, m;
	f >> n >> m;
	int *x = new int[n];
	long long *l = new long long[n];
	long long *r = new long long[n];
	for (int i = 0; i < n; i++){
		f >> l[i] >> r[i] >> x[i];
	}
	long long maxq = 0;
	long long *q = new long long[m];
	for (int i = 0; i < m; i++){
		f >> q[i];
		if (maxq < q[i]) { maxq = q[i]; }
	}
	long long *a = new long long[maxq];
	for (int i = 0; i <= maxq; i++){
		a[i] = 0;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < maxq; j++){

			if ((j >= l[i]) & (j <= r[i])) {
				a[j] += pow(-1, j - l[i])*x[i];
			}
		}
	}
	

	f.close();
	f.open("dunes.out", fstream::out);
	for (int i = 0; i < m; i++)
	{
		f << a[q[i]] << endl;
	}

	f.close();
	return 0;
    
}