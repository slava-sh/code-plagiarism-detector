#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <time.h>
#include <iterator>
#include <sstream>
#include <assert.h>
#include <limits.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define pb(a) push_back(a)
#define sz size()
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()
#define X first
#define Y second
#define mp(a,b) make_pair(a,b)

typedef long long ll;
typedef long double ld;

template<typename T> inline void SWAP(T &a, T &b){T tmp=a;a=b;b=tmp;}
template<typename T> inline T ABS(const T &VAL) {return VAL<0?-VAL:VAL;}
template<typename T> inline T MAX(const T &a, const T &b){return a<b?b:a;}
template<typename T> inline T MIN(const T &a, const T &b){return a<b?a:b;}
template<typename T> inline T SQR(const T &a){return a*a;}

#define MSET(d) memset(d,0,sizeof(d))
#define forn(i,n) for(int i=0;i!=n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i!=b;i++)
#define for1ab(i,a,b) for(int i=a+1;i<=b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define ford1ab(i,a,b) for(int i=b;i!=a;i--)
#define ford(i,n) for(int i=n-1;i!=-1;i--)
#define ford1(i,n) for(int i=n;i!=0;i--)

//const int INTinf = 2147483647;
const int INTinf = 1000000005;
const int nINTinf = 0-2147483648;
const ll LLinf = 9223372036854775807LL;

using namespace std;
typedef pair<int, int> pii;
typedef unsigned int uint;
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
template <typename Cont> string p(Cont& container) {
    ostringstream sout;
    sout<<"("<<container.size()<<")[";
    copy(container.begin(), container.end(), ostream_iterator<typename Cont::value_type>(sout, ","));
    sout<<"]";
    return sout.str();
}
#endif

priority_queue<pii> vl;
map<int, int> M;
int a[50000][3];
int cnt=0;
int n,tmp;
void ADD(pii val){
	if (val.first!=1){
		val.first--;
		vl.push(val);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	cin>>n;
	forn(i,n){
		cin>>tmp;
		M[tmp]++;
	}
	for(map<int, int>::iterator it = M.begin(); it!=M.end(); it++){
		vl.push(pii(it->Y, it->X));
	}
	while(vl.size()>2){
		pii p1 = vl.top();
		a[cnt][0] = p1.second;
		vl.pop();
		pii p2 = vl.top();
		a[cnt][1] = p2.second;
		vl.pop();
		pii p3 = vl.top();
		a[cnt++][2] = p3.second;
		vl.pop();
		ADD(p1);ADD(p2);ADD(p3);
	}
	cout<<cnt<<endl;
	forn(i,cnt){
		sort(&a[i][0], &a[i][3]);
		cout<<a[i][2]<<' '<<a[i][1]<<' '<<a[i][0]<<endl;
	}



#ifndef ONLINE_JUDGE
	fclose(stdin);
#endif
	return 0;
}
