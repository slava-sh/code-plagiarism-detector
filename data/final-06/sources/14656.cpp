//#include "stdafx.h"
#include <iostream>

using namespace std;

int n,m;
char A[32][32];
char F[32][32];
int D[28][4];
int S[14][2];
int V[7];
int R[7][7];
int res=0;

void genall(int k) {
	if (k==0) {
		for (int i=0;i<7;i++)
			for (int j=i;j<7;j++)
				R[i][j]=1;
		for (int i=0;i<28;i++) {
			int a=F[D[i][0]][D[i][1]];
			int b=F[D[i][2]][D[i][3]];
			if (a>b) {
				int t=a;a=b;b=t;
			}
			if (R[a][b])
				R[a][b]=0;
			else return;
		}
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++)
				if (F[i][j]!='.')
					A[i][j]=F[i][j]+'0';
				else
					A[i][j]='.';
			A[i][m]=0;
		}
		res++;
	} else {
		int s=14,i;
		for (i=0;i<7 && k<s;i++) {
			if (V[i]) {
				V[i]--;
				int a=S[k-1][0],b=S[k-1][1];
				F[a][b]=F[a+1][b]=F[a][b+1]=F[a+1][b+1]=i;
				genall(k-1);
				V[i]++;
			}
			s-=2-V[i];
		}
		if (i<7) {
			V[i]--;
			int a=S[k-1][0],b=S[k-1][1];
			F[a][b]=F[a+1][b]=F[a][b+1]=F[a+1][b+1]=i;
			genall(k-1);
			V[i]++;
		}
	}
}

int main(void) {
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>F[i];
	for (int i=0,k=0;i<n;i++)
		for (int j=0;j<m;j++) {
			if (F[i][j]!='.'&&F[i][j]!='*') {
				D[k][0]=i;
				D[k][1]=j;
				if (F[i][j]==F[i][j+1])
					D[k][2]=i,D[k][3]=j+1,F[i][j+1]='*';
				else
					D[k][2]=i+1,D[k][3]=j,F[i+1][j]='*';
				F[i][j]='*';
				k++;
			}
		}
	for (int i=0,k=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (F[i][j]=='*') {
				S[k][0]=i;
				S[k][1]=j;
				F[i][j]=F[i][j+1]=F[i+1][j]=F[i+1][j+1]='.';
				k++;
			}
	for (int i=0;i<7;i++)
		V[i]=2;
	genall(14);
	cout<<res*5040<<endl;
	for (int i=0;i<n;i++)
		cout<<A[i]<<endl;
	return 0;
}
