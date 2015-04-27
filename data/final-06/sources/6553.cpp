#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
#define push_back pb
#define make_pair mp
typedef long long ll;
const int N=110000;
char s[100][100];
int col[100][100];
int begi[20],begj[20];
int curcol=0;
int c[20][20];
int col2[20];
char cans[100][100];
ll ans=0;
int n,m;
void check () {
	for (int i=1; i<=14; i++) {
		int si=begi[i], sj=begj[i];
		col[si][sj]=col[si+1][sj]=col[si][sj+1]=col[si+1][sj+1]=col2[i];
	}
	int cntdom[10][10];
	for (int i=1; i<=7; i++)
		for (int j=1; j<=7; j++) cntdom[i][j]=0;
	for (int i=1; i<=7; i++)
		for (int j=i; j<=7; j++) cntdom[i][j]++;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) 
			if (s[i][j]!='.') {
				if (s[i][j]==s[i+1][j]) {
					if (cntdom[min(col[i][j],col[i+1][j])][max(col[i][j],col[i+1][j])]>0) cntdom[min(col[i][j],col[i+1][j])][max(col[i][j],col[i+1][j])]=0;
					else return;
				} else if (s[i][j]==s[i][j+1]) {
					if (cntdom[min(col[i][j],col[i][j+1])][max(col[i][j],col[i][j+1])]>0) cntdom[min(col[i][j],col[i][j+1])][max(col[i][j],col[i][j+1])]=0;
					else return;
				}
		}
	ans++;
	if (ans==1) {
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (s[i][j]=='.') cans[i][j]='.';
				else cans[i][j]=col[i][j]-1+'0';
	}
}
void gen (int i, int curc=0) {
	if (i>14) {
		check();
		return;
	}
	if (col2[i]!=0) { gen(i+1, curc); return ; }
	curc++;
	col2[i]=curc;
	for (int j=i+1; j<=14; j++) 
		if (!col2[j]) {
			col2[j]=curc;
			gen(i+1, curc);
			col2[j]=0;
		}
	col2[i]=0;
}

ll f (ll i) {
	if (i==1) return 1;
	else return f(i-1)*i;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
#endif
	cin>>n>>m;
	for (int i=0; i<n; i++) scanf("%s",s[i]);
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (s[i][j]!='.' && !col[i][j]) {
				curcol++;
				col[i][j]=col[i+1][j]=col[i][j+1]=col[i+1][j+1]=curcol;
				begi[curcol]=i;
				begj[curcol]=j;
			}
	gen(1);
	cout<<ans*f(7)<<endl;
	for (int i=0; i<n; i++) cout<<cans[i]<<endl;
}