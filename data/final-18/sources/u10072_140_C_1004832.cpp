// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
//#define PB push_back
#define CLEAR(c,d) memset((c),(d),sizeof(c))
#define TO_STRING(VariableName) # VariableName
//#define DB(c) cout<<TO_STRING(c)<<"="<<(c)<<endl

#define EXIST(e,s) ((s).find(e)!=(s).end())
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;

int read(int &n){return scanf("%d",&n);}
int read(unsigned int &n){return scanf("%u",&n);}
int read(long long &n){return scanf("%lld",&n);}
int read(unsigned long long &n){return scanf("%llu",&n);}
int read(double &n){return scanf("%lf",&n);}
int read(long double &n){return scanf("%Lf",&n);}
int read(char *c){return scanf("%s",c);}
// }}}

int n,m;
map<int,int> mp;
map<int,vector<int> > mp2;
int rad[100010];

bool calc(int m){
	int s=0;
	FOR(it,mp){
		s+=min(m,(int)it->second);
	}
	if(s>=m*3)return true;
	else return false;
}

int main(){
	read(n);
	REP(i,n)read(rad[i]),mp[rad[i]]++,mp2[rad[i]].push_back(i);
	int l=0,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
		if(calc(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%d\n",l);
	if(l==0){
		return 0;
	}
	vector<int> v;
	vector<vector<int> > vi(l);
	FOR(it,mp2){
		const vector<int> &p=it->second;
		int t=min((int)p.size(),l);
		REP(c,t)v.push_back(p[c]);
	}
	assert(l*3<=v.size() and v.size()<(l+1)*3);
	REP(i,l*3){
		vi[i%l].push_back(v[i]);
	}
	REP(i,l){
		REP(j,3){
			printf("%d",rad[vi[i][2-j]]);
			if(j<2)printf(" ");
		}
		int s=vi[i][0],t=vi[i][1],u=vi[i][2];
		assert(rad[s]<rad[t] and rad[t]<rad[u]);
		printf("\n");
	}
	return 0;
}

