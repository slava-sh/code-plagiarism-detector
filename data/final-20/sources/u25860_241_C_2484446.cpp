#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int,int> pii;
typedef map<int,int> mii;
#define SQR(x) ((x)*(x))
#define PI acos(-1.)
#define INF (INT_MAX/100)
#define mid(x,y) (x+y)/2
#define ll long long
#define sz(v) ((int)(v).size())
#define fill(a, b) memset(a, b, sizeof(a))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define pb push_back
#define pf push_front
#define itr iterator

#define N 100000
#define M 100

int i,j,k,m,n,l;
char T[N+10], F[N+10];
int c[M+10];
int hl, hr;

int gao(int hl, int hr, char* t, char* f);

int main(){
    cin>>hl>>hr>>n;
	fill(T, -1), fill(F, -1);
	rep(i, n){
		char s[2];
		int a,b;
		scanf("%d%s%d%d", &c[i], s, &a, &b);
		char *p=(*s=='T'? T:F);
		repf(j, a, b-1) p[j]=i;
	}
	cout<< max(gao(hl, hr, T, F), gao(100-hl, 100-hr, F, T));
    return 0;
}

int gao(int hl, int hr, char* t, char* f) {
    int y2;
    int ans = 0;
    for(int k = 1; k <= 100; ++k) {
 
        y2 = (k%2?100-hr:hr)+k*100;
        bool B[100] = {};
        int sum = 0;
        for(int i = 1; i <= k; ++i) {
            int y = i * 100;
            int x = 100000*(y-hl)/(y2-hl);
            char* p = (i%2?t:f);
 
            if(p[x] == -1 || B[p[x]]) {
                sum = -1;
                break;
            }
            else {
                B[p[x]] = true;
                sum += c[p[x]];
            }
        }
 
        ans = max(sum, ans);
 
    }
    return ans;
}

