#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>
#include<cmath>
#define inf 2E+9
using namespace std;
int main(){
	int n,m,D;
	scanf("%d%d%d",&n,&m,&D);
	vector<vector<pair<int,int> > >g(n);
	for(int i=0;i<m;i++){
		int a,b,t;
		scanf("%d%d%d",&a,&b,&t);
		a--;
		b--;
		g[a].push_back(make_pair(b,t));
		g[b].push_back(make_pair(a,t));
	}
	int Q;
	scanf("%d",&Q);
	for(;Q;Q--){
		vector<unordered_map<int,int> >d(n);
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		queue<pair<int,pair<int,int> > >q;
		for(int i=0;i<g[a].size();i++){
			d[a][g[a][i].second]=0;
			d[g[a][i].first][g[a][i].second]=1;
			q.push(make_pair(g[a][i].first,make_pair(g[a][i].second,1)));
		}
		while(!q.empty()){
			pair<int,pair<int,int> >v=q.front();
			q.pop();
			for(int i=0;i<g[v.first].size();i++)
				if((int)abs((double)v.second.first-(double)g[v.first][i].second)<=D && !d[g[v.first][i].first][g[v.first][i].second]){
					d[g[v.first][i].first][g[v.first][i].second]=v.second.second+1;
					q.push(make_pair(g[v.first][i].first,make_pair(g[v.first][i].second,v.second.second+1)));
				}
		}
		int ans=inf;
		for(auto i=d[b].begin();i!=d[b].end();i++)
			if(i->second)
				ans=min(ans,i->second);
		if(ans==inf)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
}