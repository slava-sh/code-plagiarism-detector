#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <functional>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define SS stringstream
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> > 
#define FIN freopen("1.in", "r", stdin)
#define FOUT freopen("1.out", "w", stdout)
#define FILE FIN; FOUT
#define SRD srand((int)time(NULL))
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) (1ll*(x)*(x))
#define pw(x) (1ll<<(x))
#define SC(x) scanf("%d", &x)
#define CC(x) cout << x << endl
#define forr(i, l, r) for(int i = l; i <= r; i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;

using namespace std;

int n,m,i,j,d;
int a[100500], b[100500];

int main()
{
	//ios_base::sync_with_stdin(false);
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	cin>>n>>d;
	for (i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	m=0;
	for(i = 1;i<= n; i++){
	 	if (a[i]>d){
	 	 	b[++m]=a[i];
	 	}
	}
	if (m==0){
	 	cout<<a[n]<<endl;
	 	return 0;

	}
	if (m==1){
	 	cout<<b[1]<<endl;
	 	return 0;
	}
	int r=m+1;
	for (i=m; i>0; i--){
	 	if (b[i]>=3*d)
	 		r=i;
	}
	r=max(r,3);
	int s=b[r-1]+b[r-2];
	int num=2;
	for(i = r; i<= m; i++){
	 	s+=b[i];
	 	num++;
	}
	cout<<max(a[n],s-(num-1)*d*2)<<endl;

	return 0;
}