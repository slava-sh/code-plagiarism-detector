#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 100005
#define MYINF 1000000000

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int a[MAXN];
	static int d[MAXN];
	static int s[MAXN];
	static char res[MAXN];
	static int A[MAXN];
	static char b[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int M, N;
		scanf("%d %d",&M,&N);
		M--;
		memset(res, 'N', sizeof(res));
		res[N] = 0;
		int i;
		for (i = 0; i < N; i++) scanf("%d",&(a[i]));
		for (i = 0; i < M; i++) scanf("%d %d",&(d[i]),&(s[i]));
		int Q = 0;
		while ((Q < M) && (s[Q] == 0)) Q++;
		int taken = 0;
		int fr;
		if (Q < M)
		{
			memset(A,0,sizeof(A));
			fr = 0;
			for (i = 0; i < Q; i++)
			{
				if (d[i]) A[d[i]-1]++;
				else fr++;
			}
			memset(b,1,sizeof(b));
			for (i = Q; i < M; i++)
			{
				if (d[i]) b[d[i]-1] = 0;
			}
			taken = MYINF;
			for (i = 0; i < N; i++)
			{
				if (b[i])
				{
					int temp = a[i] - A[i];
					if (temp <= fr)
					{
						res[i] = 'Y';
						if (temp < taken) taken = temp;
					}
				}
			}
		}
		fr = 0;
		memset(A,0,sizeof(A));
		for (i = 0; i < M; i++)
		{
			if (d[i]) A[d[i]-1]++;
			else fr++;
		}
		fr -= taken;
		for (i = 0; i < N; i++)
		{
			if (res[i] == 'N')
			{
				int temp = a[i] - A[i];
				if (temp <= fr) res[i] = 'Y';
			}
		}
		printf("%s\n",res);
	}
	return 0;	
}
