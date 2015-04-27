#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define maxn 1005
using namespace std;

string s[maxn],ret[maxn];
int m,n;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int ans[maxn][maxn];
bool flag = true;

bool outside(int fx,int fy)
{
	return (fx < 0 || fx >= m || fy < 0 || fy >= n);
}

bool isolate(int fx,int fy)
{
	if (outside(fx,fy) || ans[fx][fy] >= 0 || s[fx][fy] == '#') return false;
	for (int i = 0; i < 4; i++)
	{
		int tx = fx + dx[i],ty = fy + dy[i];
		if (!outside(tx,ty) && ans[tx][ty] < 0 && s[tx][ty] != '#') return false;
	}
	return true;
}

void cover(vector< pair<int,int> > p)
{
	bool ok[10];
	for (int i = 0; i < p.size(); i++) ans[p[i].first][p[i].second] = -1;
	memset(ok,true,sizeof(ok));
	for (int i = 0; i < p.size(); i++)
	  for (int j = 0; j < 4; j++)
	  {
		  int sx = p[i].first + dx[j],sy = p[i].second + dy[j];
		  if (outside(sx,sy) || ans[sx][sy] < 0) continue;
		  ok[ans[sx][sy]] = false;
	  }
	for (int i = 0; i < 10; i++) if (ok[i])
	{
		for (int j = 0; j < p.size(); j++) 
		{
			ans[p[j].first][p[j].second] = i;  ret[p[j].first][p[j].second] = i + '0';
		}
		return;
	}
}

void attempt(int sx,int sy)
{
	if (isolate(sx,sy))
	{
		flag = false;  return;
	}
	vector< pair<int,int> > p;  p.push_back(make_pair(sx,sy));
	ans[sx][sy] = 0;
	for (int i = 0; i < 4; i++)
	{
		int tx = sx + dx[i],ty = sy + dy[i];
		if (outside(tx,ty) || ans[tx][ty] >= 0 || s[tx][ty] == '#') continue;
		p.push_back(make_pair(tx,ty));  ans[tx][ty] = 0;  break;
	}
	for (int i = 0; i < 2; i++)
	  for (int j = 0; j < 4; j++)
	  {
		  int tx = p[i].first + dx[j],ty = p[i].second + dy[j];
		  if (isolate(tx,ty))
		  {
			  ans[tx][ty] = 0;  p.push_back(make_pair(tx,ty));
		  }
	  }
	cover(p);
}

int main()
{
	//freopen("b.in","r",stdin);
	
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++) cin >> s[i];
	
	memset(ans,-1,sizeof(ans));
	for (int i = 0; i < m; i++) ret[i] = s[i];
	for (int i = 0; i < m; i++)
	  for (int j = 0; j < n; j++) if (ans[i][j] < 0 && s[i][j] == '.')
	  {
		  attempt(i,j); 
		  if (!flag)
		  {
			  printf("-1\n");  return 0;
		  }
	  }
	
	for (int i = 0; i < m; i++) cout << ret[i] << endl;
}
