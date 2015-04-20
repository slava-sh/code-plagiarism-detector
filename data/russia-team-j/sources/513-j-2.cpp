#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

#define FNAME "travel"
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int X1, X2, Y1, Y2, X, Y, n, p[1000][1000], d[1000][1000], t, m, k, d1 = 1e9, d2 = 1e9, pos2, turn[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}}, dx, dy, x, y, res[260000], head, tail;
char a[1000][1000], go[4] = {'E', 'S', 'N', 'W'};
pair <int, int>  q[5000000];
int main()
{
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d%d%d\n", &n, &m, &k);
	forn(i, m)
	{
		forn(j, n)
		{
		    scanf("%c", &a[j][i]);
			//printf("%c\n", a[i][j]);		    
			if (a[j][i] == 'V')
				X = j, Y = i;
		}
	//	puts(a[i]);
		scanf("\n");
	}
	forn(i, n)
	{
		forn(j, m)
		{
	//	    printf("%d %d %d %d %c\n", X, Y, i, j, a[i][j]);
			if (a[i][j] == 'T' && abs(i - X) + abs(j - Y) < d1)
			{
				d1 = abs(i - X) + abs(j - Y);
				X1 = i, Y1 = j; 
			}
		}
	}
	head = tail = 2500000;
	forn(i, n)
		forn(j, m)
			d[i][j] = 1e9;
	d[X][Y] = 0;		
	q[head++] = mp(X, Y);
	while (head != tail)
	{
		x = q[tail].first, y = q[tail].second;
		tail++;
		forn(i, 4)
		{
			dx = x + turn[i][0], dy = y + turn[i][1];
			if (dx >= 0 && dx < n && dy >= 0 && dy < m)
			{
				if (a[dx][dy] == 'T' && d[x][y] < d[dx][dy])
				{
					q[--tail] = mp(dx, dy);
			        d[dx][dy] = d[x][y];
					p[dx][dy] = i;
				
				}	
				if (a[dx][dy] != 'T' && d[x][y] + 1 < d[dx][dy])
				{
					q[head++] = mp(dx, dy);
					d[dx][dy] = d[x][y] + 1;
					p[dx][dy] = i;
				}
			}
		}
	}
//	forn(i, m)
//	{
//		forn(j, n)
//			printf("%d ", d[j][i]);
//		puts(""); 
//	}
	forn(i, n)
		forn(j, m)
		{
			if (a[i][j] == 'T')
			{	
//			    printf("%d %d %d\n", i, j, d[i][j]);
				forn(l, 4)
				{
					dx = i + turn[l][0], dy = j + turn[l][1];
					if (dx >= 0 && dx < n && dy >= 0 && dy < m && a[dx][dy] == 'T' && k + d[i][j] < d2 && k - (abs(X - i) + abs(Y - j) - d[i][j]) >= 0)
					{
						d2 = k + d[i][j], X2 = i, Y2 = j, pos2 = l;
					}
				}
			}
		}
//	printf("%d %d %d %d %d %d %d\n", X1, Y1, d1 + (k - 1) * 2, X2, Y2, d2, pos2);
	if (d1 + (k - 1) * 2 < d2)
	{
//		puts("AAA");
		if (X < X1)
			forn(i, X1 - X)
				printf("E");
		else
			forn(i, X - X1)
				printf("W");
		if (Y < Y1)
			forn(i, Y1 - Y)
				printf("S");
		else
			forn(i, Y - Y1)
				printf("N");
		if (X1 > 0)
			forn(i, k - 1)
				printf("WE");
		else if (X1 < n - 1)	
			forn(i, k - 1)
				printf("EW");
		else if (Y1 < m - 1)	
			forn(i, k - 1)
				printf("SN");
		else
			forn(i, k - 1)
				printf("NS");		
	}
	else
	{
	    k = k - (abs(X - X2) + abs(Y - Y2) - d[X2][Y2]);
	  //  printf("%d\n", k);
	    x = X2, y = Y2;
//	    printf("%d %d\n", X, Y);
	    while (x != X || y != Y)
	    {
	    	res[t] = p[x][y];
	    //	printf("%d %d %d\n", x, y, p[x][y]);
			x = x + turn[3 - res[t]][0], y = y + turn[3 - res[t]][1];
			t++;	    	
	    }
	    reverse(res, res + t);
//	    printf("%d\n", t);
	    forn(i, t)
	    	printf("%c", go[res[i]]);
		if (pos2 == 0)
		{    
			forn(i, (k) / 2)
				printf("EW");
			if ((k) % 2 == 1)
				printf("E");
		}	
		if (pos2 == 1)
		{    
			forn(i, (k) / 2)
				printf("SN");
			if ((k) % 2 == 1)
				printf("S");
		}	
		if (pos2 == 2)
		{    
			forn(i, (k) / 2)
				printf("NS");
			if ((k) % 2 == 1)
				printf("N");
		}	
		if (pos2 == 3)
		{    
			forn(i, (k) / 2)
				printf("WE");
			if ((k) % 2 == 1)
				printf("W");
		}	
	}

	return 0;
}