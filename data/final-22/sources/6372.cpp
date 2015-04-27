#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std ;
const int INF = 1000000000 ;
const int MaxE = 800005 ;
const int MaxV = 500005 ;
const int MaxQ = 13 ;
int n , m ;
int next[2 * MaxE] , first[MaxV] , end[2 * MaxE] , we[2 * MaxE] ;
int d[MaxV] ;
bool was[MaxV]  ;
void bfs (int x)
{
	int l = 0 ;
	vector <queue <int> > q(MaxQ) ;
	q[0].push (x) ;
	d[x] = 0 ;
	while (true)
	{
		bool flag = false ;
		for (int i = 0; i < MaxQ; i++)
			if (!(q[i].empty()))
			{
				flag = true ;
				break ;
			}
		if (!flag) break ;
		while (q[l].empty()) 
			l = (l + 1) % MaxQ ;		
		int k = q[l].front() ;
		q[l].pop() ;
		if (!was[k])
		{
			was[k] = 1 ;	
			for (int i = first[k]; i != 0; i = next[i])
			{
				if (!was[end[i]])
				{
					d[end[i]] = min (d[end[i]] , d[k] + we[i]) ;
					q[(l + we[i]) % MaxQ].push (end[i]) ;	
				}
			}
		}
	}
}

void Load ()
{
	int q = 0 , u , v , w ;
	scanf ("%d%d", &n, &m) ;
	for (int i = 1; i <= m; i++)
	{
		scanf ("%d%d%d", &u, &v, &w) ;
		q++ ;
		next[q] = first[u] ;
		first[u] = q ;
		end[q] = v ;
		we[q] = 12 / w ;
		q++ ;
		next[q] = first[v] ;
		first[v] = q ;
		end[q] = u ;
		we[q] = 12 / w ;
 	}	
}
void Solve ()
{
	for (int i = 1; i <= n; i++)
		d[i] = INF ;
	bfs (1) ;
	for (int i = 2; i <= n; i++)
		printf ("%.9f\n", (double)d[i] / 12.0) ;
}
#define FILENAME "graph" 
int main ()
{
	freopen (FILENAME".in","r",stdin) ;
	freopen (FILENAME".out","w",stdout) ;
	Load () ;
	Solve () ;
	return 0 ;	
}