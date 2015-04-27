#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

#define lint long long

#define ss stringstream
#define sz size()
#define pb push_back
#define mp make_pair

#define FOR(i,n) SFOR(i,0,n)
#define SFOR(i,m,n) for(i=m;i<n;i++)
#define FORD(i,n) for(i=n-1;i>=0;i--)

int A[40][40];
int C1[40];

__int64 ans;

int X[40], Y[40], C[40];

int D[40][2];
int V[7][7];

int K, K1;

void Rec(int q) {
	if (q == 14) {
		if (ans == 0) { FOR(q,14) { C1[q] = C[q]; } K1 = K; }
		ans++;
		return ;
	}
	int i,j;
	int Q[5],W[5],sq;
	FOR(j,28) if ((D[j][0] == q) && (D[j][1] == q)) break;
	int q1, q2;
	if (j == 28) { q1 = 0; q2 = 7; } else { q1 = K; q2 = K+1; K++;  }
	SFOR(i,q1,q2) {
		sq = 0;
		FOR(j,28) if ((D[j][0] == q) && (D[j][1] == q)) { Q[sq] = i; W[sq] = i; sq++; }
		FOR(j,28) if ((D[j][1] == q) && (D[j][0] != q)) { Q[sq] = C[D[j][0]]; W[sq] = i; sq++; }
		FOR(j,sq) if (W[j] < Q[j]) swap(Q[j],W[j]); 
		FOR(j,sq) V[Q[j]][W[j]]++;
		FOR(j,sq) if (V[Q[j]][W[j]] > 1) break;
		if (j == sq) { C[q] = i; Rec(q+1); }
		FOR(j,sq) V[Q[j]][W[j]]--;
	}
	FOR(j,28) if ((D[j][0] == q) && (D[j][1] == q)) break;
	if (j != 28) K--;
}

int main() {
    int i,j,m,n,k,fx,fy,p;
	char ch;
	scanf("%d%d",&m,&n);
	memset(A,0,sizeof(A));
	FOR(i,m) FOR(j,n) {
		do { scanf("%c",&ch); } while ((ch != '.') && (ch != 'A') && (ch != 'B') && ((ch < 'a') || (ch > 'z'))); 
		if ((ch == 'A') || (ch == 'B')) A[i+1][j+1] = ch - 'A' + 27;
		if ((ch >= 'a') && (ch <= 'z')) A[i+1][j+1] = ch - 'a' + 1;
	}
	m++; n++;
	p = 0;
	FOR(i,m) FOR(j,n) if (A[i][j] != 0) {
		FOR(k,p) if (((i-X[k] == 0) || (i-X[k] == 1)) && ((j-Y[k] == 0) || (j-Y[k] == 1))) break;
		if (k == p) { X[p] = i; Y[p] = j; p++; }
	}
	memset(D,0xFF,sizeof(D));
	FOR(i,m) FOR(j,n) if (A[i][j] != 0) {
		FOR(k,p) if (((i-X[k] == 0) || (i-X[k] == 1)) && ((j-Y[k] == 0) || (j-Y[k] == 1))) break;
		if (D[A[i][j]][0] == -1) D[A[i][j]][0] = k; else D[A[i][j]][1] = k;
	}
	FOR(i,28) if (D[i][0] > D[i][1]) swap(D[i][0],D[i][1]);
	FOR(k,14) C[k] = -1;
	ans = 0;
	memset(V,0,sizeof(V));
	K = 0;
	Rec(0);
	FOR(i,K1) ans *= 7-i;
	printf("%I64d\n",ans);
	SFOR(i,1,m) {
		SFOR(j,1,n) if (A[i][j] == 0) printf("."); else {
			FOR(k,14) if (((i-X[k] == 0) || (i-X[k] == 1)) && ((j-Y[k] == 0) || (j-Y[k] == 1))) break;
			printf("%d",C1[k]);
		}
		printf("\n");
	}
	return 0;
}