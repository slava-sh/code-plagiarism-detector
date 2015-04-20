#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(){
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int a[1000], i=0, j=0, n, b[1000][1000];
	cin >> n;
	for (i = 0; i < n; i++){
		cin >> a[i];
	}
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			b[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < a[i]; j++){
			b[i][j] = 1;
		}
	}
	for (i = 0; i < n; i++){
		  if (b[i][i]== 0){
			    cout << i << endl;
				break;
            }
	    
	}
	int c[1000];
	for (int f = 1; f <= i; f++){
		cout << f << " " << f << endl;
	}
	return 0;
	int l;
	cin >> l;
}
