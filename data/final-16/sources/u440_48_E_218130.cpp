#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <queue>
#include <cstring>
#include <map>
#include <sstream>
#include <cmath>
#include <fstream>
#include <stack>
using namespace std;
#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
int n,m,H,T,R;
int f[444][444],h[222][222],t[222][222];
queue< pii > q;
bool cycle(pii cur)
{
	if (cur.x+cur.y>R)
		return false;
	f[cur.x][cur.y]=1;
	for(int deh=1;deh<=n&&deh<=cur.x;++deh)
	{
			pii np=mp(cur.x-deh+h[deh][0],cur.y+h[deh][1]);
			if (f[np.x][np.y]==-1&&cycle(np))
				return true;
			else
				if (f[np.x][np.y]==1)
					return true;
	}
	for(int det=1;det<=m&&det<=cur.y;++det)
	{
			pii np=mp(cur.x+t[det][0],cur.y-det+t[det][1]);
			if (f[np.x][np.y]==-1&&cycle(np))
				return true;
			else
				if (f[np.x][np.y]==1)
					return true;
	}
	f[cur.x][cur.y]=0;
	return false;
}
int dfs(pii cur)
{
	if (f[cur.x][cur.y]!=-1)
		return f[cur.x][cur.y];
	if (cur.x+cur.y>R)
		return f[cur.x][cur.y]=0;
	f[cur.x][cur.y]=0;
	for(int deh=1;deh<=n&&deh<=cur.x;++deh)
	{
			pii np=mp(cur.x-deh+h[deh][0],cur.y+h[deh][1]);
			f[cur.x][cur.y]=max(f[cur.x][cur.y],dfs(np));
	}
	for(int det=1;det<=m&&det<=cur.y;++det)
	{
			pii np=mp(cur.x+t[det][0],cur.y-det+t[det][1]);
			f[cur.x][cur.y]=max(f[cur.x][cur.y],dfs(np));
	}
	return ++f[cur.x][cur.y];
}
int main()
{
	scanf("%d%d%d",&H,&T,&R);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&h[i][0],&h[i][1]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&t[i][0],&t[i][1]);
	memset(f,-1,sizeof(f));
	q.push(mp(H,T));
	f[H][T]=0;
	while(!q.empty())
	{
		pii cur=q.front();
		q.pop();
		if (cur.x+cur.y>R)
			continue;
		for(int deh=1;deh<=n&&deh<=cur.x;++deh)
		{
			pii np=mp(cur.x-deh+h[deh][0],cur.y+h[deh][1]);
			if (f[np.x][np.y]==-1)
			{
				f[np.x][np.y]=f[cur.x][cur.y]+1;
				q.push(np);
			}
		}
		for(int det=1;det<=m&&det<=cur.y;++det)
		{
			pii np=mp(cur.x+t[det][0],cur.y-det+t[det][1]);
			if (f[np.x][np.y]==-1)
			{
				f[np.x][np.y]=f[cur.x][cur.y]+1;
				q.push(np);
			}
		}
	}
	if (f[0][0]!=-1)
	{
		cout<<"Ivan\n";
		cout<<f[0][0]<<endl;
		return 0;
	}
	memset(f,-1,sizeof(f));
	if (cycle(mp(H,T)))
	{
		cout<<"Draw\n";
		return 0;
	}
	memset(f,-1,sizeof(f));
	cout<<"Zmey\n";
	cout<<dfs(mp(H,T))<<endl;
}