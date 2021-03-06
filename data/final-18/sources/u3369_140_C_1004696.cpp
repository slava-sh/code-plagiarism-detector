#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <climits>
#include <limits>
using namespace std;
//Macros
#define SIZE(A) ((int)(A.size()))
#define SET(A,x) memset(A,x,sizeof(A));                 //NOTE: Works only for x = 0 and -1. Only for integers.
#define FILL(A,x) fill(A.begin(),A.end(),x)
#define REP(i,N) for(int i=0;i<(int)(N);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define REV(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ALL(x)  x.begin(),x.end()
#define INF (INT_MAX/2)
#define LLINF (LONG_LONG_MAX/2LL)
#define EPS 1e-11
#define GI ({int t;scanf("%d",&t);t;})                  //NOTE: Don't comma separate two inputs.
#define GL ({long long t;scanf("%lld",&t);t;})          //NOTE: Don't comma separate two inputs.
#define GF ({double t;scanf("%lf",&t);t;})              //NOTE: Don't comma separate two inputs.
#define MP make_pair
#define PB push_back
#define gcd(a,b) __gcd(a,b)                             //NOTE: Both the arguments should be of the same type.
#define nbits(n) __builtin_popcount(n)                  //NOTE: Works only for int. Write your own function for long long :-/
#define MOD 1000000007
#define MAXN 1000005
#define FIX(a) (((a)%MOD+MOD)%MOD)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define SUBMIT false                                    //NOTE: Set this to true before submitting
#define   debug(x)              if(!SUBMIT){ cout<<"-> "<<#x<<" = "<<x<<"\n";}
#define   debugv(x)             if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x))cout<<x[i]<<" ";cout<<"\n";}
#define   debugvv(x)            if(!SUBMIT){ cout<<"-> "<<#x<<" =\n";REP(i,SIZE(x)){REP(j,SIZE(x[i])){cout<<x[i][j]<<" ";}cout<<"\n";}}
#define   debug1(A,N)           if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,N)cout<<A[i]<<" ";cout<<"\n";}
#define   debug2(A,R,C)         if(!SUBMIT){ cout<<"-> "<<#A<<" =\n";REP(i,R){REP(j,C){cout<<A[i][j]<<" ";}cout<<"\n";}}

vector<int>  a, b, c;
set<pair<int, int> >S; 
//Main code starts here
int main()
{
	map<int, int> M; 
	int n = GI;
	REP(i, n){
		int x = GI;
		M[x]++;
	}
	TR(M, it)
		S.insert(make_pair(it->second, it->first));
	set<pair<int, int> >::iterator it1, it2, it3;
	while(S.size() >= 3)
	{
		set<pair<int, int> >::iterator it = S.end();
		it--;
		it1 = it;
		it--;
		it2 = it;
		it--;
		it3 = it;

		int v1 = (*it3).first; 
		int v2 = (*it2).first; 
		int v3 = (*it1).first;
		int vv1 = (*it3).second; 
		int vv2 = (*it2).second; 
		int vv3 = (*it1).second;


		assert(v1 <= v2 && v2 <= v3); 
		if(v1 == 0) break;
		int arr[] = {vv3, vv2, vv1};
		sort(arr, arr+3); 
		a.push_back(arr[2]); b.push_back(arr[1]); c.push_back(arr[0]);
		S.erase(it1); S.erase(it2); S.erase(it3); 
		S.insert(make_pair(v1-1, vv1)); 
		S.insert(make_pair(v2-1, vv2)); 
		S.insert(make_pair(v3-1, vv3)); 
	}
	int m = a.size();
	cout<<m<<endl;
	REP(i, m){
		printf("%d %d %d\n", a[i], b[i], c[i]); 
	}
	return 0;
}
