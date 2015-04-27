#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef stringstream ss;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;i++)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;i++)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;i++)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;i++)

const double pi=acos(-1.0),eps=1e-9;
char gc(){char c;while((c=getchar())<=' ' && c!=-1);return c;}
int gs(char*s){if(!fgets(s,999999,stdin))return -1;int l=strlen(s);while(l && (s[l-1])<=' ')s[--l]=0;return l;}

typedef pair<int,ii> iii;
int main() { ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);
	
	int n;
	cin>>n;
	map<int,int> m;
	multiset<ii> s;
	rep(i,n) {
		int t;
		cin>>t;
		m[t]++;
	}
	repi(i,m) {
		s.insert(ii(i->second,i->first));
	}
	vector<iii> v;
	while(true) {
		if(s.size()<3) break;
		multiset<ii>::iterator t=s.end(),t2,t3;
		t--;
		t2=t;
		t2--;
		t3=t2;
		t3--;
		v.push_back(iii(t->se,ii(t2->se,t3->se)));
		ii a=*t,b=*t2,c=*t3;
		s.erase(t);
		s.erase(t2);
		s.erase(t3);
		if(a.fi>=2) {
			s.insert(ii(a.fi-1,a.se));
		}
		if(b.fi>=2) {
			s.insert(ii(b.fi-1,b.se));
		}
		if(c.fi>=2) {
			s.insert(ii(c.fi-1,c.se));
		}
	}
	cout<<v.size()<<'\n';
	rep(i,sz(v)) {
		if(v[i].fi<v[i].se.fi) {
			swap(v[i].fi,v[i].se.fi);
		}
		if(v[i].se.fi<v[i].se.se) {
			swap(v[i].se.fi,v[i].se.se);
		}
		if(v[i].fi<v[i].se.fi) {
			swap(v[i].fi,v[i].se.fi);
		}
		cout<<v[i].fi<<' '<<v[i].se.fi<<' '<<v[i].se.se<<'\n';
	}
}
