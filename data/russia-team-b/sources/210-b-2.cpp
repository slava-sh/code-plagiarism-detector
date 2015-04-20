#include <cstdio>

using namespace std;
int main()
{   
	int n,r,k,l,d1[400001],res=0;
	freopen("che.in", "r", stdin);
	scanf("%d%d", &n, &r);

	for(k=0;k<n;k++)
	{
		scanf("%d", &d1[k]);
	}
	fclose(stdin);
	for (k=0;k<n;k++)
	{
		for (l=0;l<n;l++)
		{
            if (d1[l]-d1[k]>r)
			{
				res++;
			}
		}
	}
	freopen("che.out", "w", stdout);
	printf("%d", res);
	return 0;
	fclose(stdout);
}
