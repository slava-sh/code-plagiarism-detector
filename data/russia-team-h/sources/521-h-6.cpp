// *** ADDED BY HEADER FIXUP ***
#include <algorithm>
#include <iostream>
#include<queue>
#include <vector>
#include<set>
// *** END ***
using namespace std;
typedef long long ll;
ll inf = (ll)1e12;
struct edge
{
    int a,b;
    ll len;
	edge(int a1,int b1, ll le):a(a1),b(b1),len(le){}
};
bool operator<(edge a,edge b){
    if(a.len<b.len) return true;
    if(a.len>b.len) return !true;
    if(a.a<b.a) return true;
    if(a.a>b.a) return !true;
    return a.b<b.b;
}
vector<edge> ee[5100];
int n;
vector<ll> dij(int s){
    vector<ll> dis(n,inf);
    set<int> q;
	dis[s]=0;
	q.insert(s);
	while(q.size()){
		int  s  = *q.begin();
		q.erase(s);
		for(int  i = 0;i<ee[s].size();++i)
		{
			if(dis[ee[s][i].b] > dis[s] + ee[s][i].len){
					dis[ee[s][i].b] = dis[s] + ee[s][i].len;
					if(q.count(ee[s][i].b)==0) 
						q.insert(ee[s][i].b);
			}
		}
	}
	return dis;
}

int main()
{
   freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    int m;
    cin>>n>>m;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    vector<int> first;
    vector<int> second;
    for(int i = 0; i<n; ++i)
    {
        int kk;
        cin>>kk;
        if(kk==1)
            first.push_back(i);
        else if(kk==2)
            second.push_back(i);
    }
    for(int i = 0; i<m; ++i)
    {
        int a,b,l;
        cin>>a>>b>>l;
        a--,b--;
        ee[a].push_back(edge(a,b,l));
        ee[b].push_back(edge(b,a,l));
    }
    bool sw  =false;
    if(first.size()>second.size()){
            swap(first,second);
            sw = true;
    }
    edge mini(0,0,inf);
    for(int i = 0;i<first.size();++i)
    {
        vector<ll> dists = dij(first[i]);
        for(int j = 0;j<second.size();++j)
            if(dists[second[j]]<mini.len)
                mini = edge(first[i],second[j],dists[second[j]]);
    }
    if(sw) swap(mini.a,mini.b);
    if(mini.len==inf) cout<<-1;
    else
        cout<<mini.a+1<<' '<<mini.b+1<<' '<<mini.len;
}
