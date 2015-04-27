#include <stdio.h>
#include <limits.h>
#include <list>
#include <queue>
using namespace std;

#define TASK "graph"
#define VNUM 500001
#define QNUM 13
//#define ENUM 00001

int N, M;
typedef pair<int, int> pr;

list<pr> E[VNUM];
queue<int> Q[QNUM];
int s[VNUM];

int main(int argc, char* argv[])
{
	freopen (TASK ".in", "r", stdin);
	freopen (TASK ".out", "w", stdout);
	scanf("%d %d", &N, &M);
	int t1, t2, w;
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &t1, &t2, &w);
		E[t1].push_back(pr(t2, 12 / w));
		E[t2].push_back(pr(t1, 12 / w));
	}
	s[1] = 0;
	for (int i = 2; i <= N; i++)
		s[i] = INT_MAX / 3;
	int cur = 0;
	int num = 1;
	Q[0].push(1);
	while(num)
	{
		while(!Q[cur].empty())
		{
			int v = Q[cur].front();
			Q[cur].pop();
			num--;
			for (list<pr>::iterator it = E[v].begin(); it != E[v].end(); it++)
			{
				if (s[it->first] > s[v] + it->second)
				{
					Q[(cur + it->second) % QNUM].push(it->first);
					s[it->first] = s[v] + it->second;
					num++;
				}
			}
		}
		cur = (cur + 1) % QNUM;
	}
	for (int i = 2; i <= N; i++)
	{
		printf("%.9lf\n", ((double)s[i]) / (double)12.0);
	}
	return 0;
}
