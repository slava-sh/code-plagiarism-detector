//Programmer: Amit Saharana, IIT Delhi 
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
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
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <fstream> 
#include <cassert> 
using namespace std; 
 
#define ll long long 
#define gc getchar
#define pc putchar 

ll a[300005];
vector<vector<ll> > b;
ll e[300005];
ll f[300005]; //number of people being suspected upon by i people

int main(){
#ifdef amit
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
	freopen("err.txt","w",stderr); 
#endif
	ll n,m;
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int c,d;
	b.resize(n+1);
	for(int i=1; i<=n; i++) {
		cin>>c>>d;
		e[c]++; e[d]++;
		b[c].push_back(d);
		b[d].push_back(c);
	}
	for(int i=1; i<=n; i++) {
		sort(b[i].begin(),b[i].end());
	}
	for(int i=1; i<=n; i++) {
		f[e[i]]++;
	}
	for(int i=n-1; i>=0; i--) {
		f[i]+=f[i+1];
	}
	ll tot = 0;
	for(int i=1; i<=n; i++) {
		if(e[i]>=m) tot+=n-1;
		else {
			tot+=f[m-e[i]];
			if(e[i]>=m-e[i]) tot--;
			for(int j=0; j<b[i].size(); j++){ 
				int t1=1;
				j++;
				while(j<b[i].size() && b[i][j]==b[i][j-1]) {
					j++;
					t1++;
				}
				j--;
				if(e[b[i][j]]<m-e[i]+t1 && e[b[i][j]]>=m-e[i]) tot--;
			}
		}
	}
	cout<<tot/2<<endl;
	return 0;
}