#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;

#define sz size()
#define all(n) n.begin(),n.end()
#define clr(a,n) memset(a,n,sizeof(a))
#define pb push_back
#define fo(i,j) for(int i=0;i<j;i++)
#define foreach(it, c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)

int brushMaxWidth;
int brushMaxHeight;
int N, M, startR, startC, accR[1005][1005], accC[1005][1005];
char grid[1002][1002];

int flood(int R, int C, int &NBrush, int &MBrush)
{
	if(R+NBrush<N && accR[R+NBrush][C+MBrush] - accR[R+NBrush][C] == MBrush){/*printf("done1\n");*/ return MBrush + flood(R+1, C, NBrush, MBrush);}
	else if(C+MBrush<M && accC[C+MBrush][R+NBrush] - accC[C+MBrush][R] == NBrush){ /*printf("done2\n");*/return NBrush + flood(R, C+1, NBrush, MBrush);}
	return 0;
}

int main()
{
	brushMaxHeight = 1<<30;
	brushMaxWidth = 1<<30;
	
	int allXs = 0;
	bool flag = 0;
	
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++)
    {
		scanf("%s",grid[i]);
		for(int j=0; j<M; j++)
		{
			if(grid[i][j] == 'X') allXs++;
			if(!flag && grid[i][j] == 'X')
			{
				startR = i;
				startC = j;
				flag = 1;
			}
		}
	}
	
	for(int i=0; i<N; i++)
	{
		int w=0;
		for(int j=0; j<M; j++)
		{
			accR[i][j+1] = accR[i][j] + bool(grid[i][j] == 'X');
			if(grid[i][j] == 'X')
				w++;
			else
			{
				if(w)brushMaxWidth = min(brushMaxWidth, w);
				w=0;
			}
		}
		if(w)brushMaxWidth = min(brushMaxWidth, w);
	}
	for(int j=0; j<M; j++)
	{
		int h=0;
		for(int i=0; i<N; i++)
		{
			accC[j][i+1] = accC[j][i] + bool(grid[i][j] == 'X');
			if(grid[i][j] == 'X')
				h++;
			else
			{
				if(h)brushMaxHeight = min(brushMaxHeight, h);
				h=0;
			}
		}
		if(h)brushMaxHeight = min(brushMaxHeight, h);
	}
	/*for(int i=0; i<M; i++){
		for(int j=0; j<=N; j++)
			printf("%d, ",accC[i][j]);printf("\n");}*/
	int ret = 1<<30;
	
	for(int L = 1; L<=brushMaxHeight; L++)
	{
		int totalVisited = flood(startR, startC, L, brushMaxWidth) + L*brushMaxWidth;
		//printf("%d %d :: %d *\n",L, brushMaxWidth,totalVisited);
		if(totalVisited == allXs)
			ret = min(ret, L*brushMaxWidth);
	}
	for(int L = 1; L<=brushMaxWidth; L++)
		if(flood(startR, startC, brushMaxHeight, L) + brushMaxHeight*L == allXs)
			ret = min(ret, brushMaxHeight*L);
	
	if(ret == 1<<30) ret = -1;
	printf("%d\n", ret);
}


































