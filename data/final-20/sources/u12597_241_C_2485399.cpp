#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int hl,hr,n;
int v[100],a[100],b[100];
char c[100];

const double eps = 1e-8;
bool check[100];

int calc()
{
	int ans = 0;
	for (int times = 1;times <= n;times++)
	{
		int toth = hl+(times-1)*100+100-hr;
		if (times%2 == 1)
			toth = hl+(times-1)*100+hr;
		int totw = 100000;

		//printf("========================\n");
		//printf("times = %d, toth = %d, totw = %d\n",times,toth,totw);

		int tans = 0;
		bool flag = true;
		memset(check,false,sizeof(check));

		for (int i = 0;i < times;i++)
		{
			int ypos = hl+i*100;
			double xpos = (double)totw*ypos/toth;

			char cnow = 'F';
			if (i%2 == 1)
				cnow = 'T';

			//printf("cnow = %c, ypos = %d, xpos = %.6f\n",cnow,ypos,xpos);
			
			bool tflag = false;
			for (int j = 0;j < n;j++)
				if (c[j] == cnow)
				{
					if (a[j]-eps <= xpos && xpos <= b[j]+eps)
					{
						if (check[j] == false)
						{
							check[j] = true;
							tflag = true;
							tans += v[j];
						}
						break;
					}
				}
			if (tflag == false)
			{
				flag = false;
				break;
			}
		}

		if (flag == true)
		{
			//printf("tans = %d, times = %d\n",tans,times);
			ans = max(ans,tans);
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d%d",&hl,&hr,&n);
	for (int i = 0;i < n;i++)
		scanf("%d %c%d%d",&v[i],&c[i],&a[i],&b[i]);

	int ans = 0;

	ans = calc();
	for (int i = 0;i < n;i++)
		if (c[i] == 'T')
			c[i] = 'F';
		else
			c[i] = 'T';
	hl = 100-hl;
	hr = 100-hr;
	//printf("===============\n");
	ans = max(ans,calc());

	printf("%d\n",ans);
	return 0;
}
