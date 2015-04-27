#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<ctime>

using namespace std;
#define eps 1e-8
#define N 100030
#define M 20000200
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
#define MP(a,b) make_pair(a,b)

int n,m;
char ch[N][5];
int arr[N];
int flag[N];
int ans[N];
bool vis[N],in[N];

int main()
{


	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			flag[i] = 0,vis[i] = true,in[i] = false;
		int k = -1;
		for(int i=0;i<m;i++)
		{
			scanf("%s%d",ch[i],arr+i);
			vis[arr[i]] = false;
			if(flag[arr[i]]==0&&ch[i][0]=='-')
			{
				k = i;
			}
			flag[arr[i]] = (ch[i][0]=='+'?1:2);

		}
		arr[m] = 0;
		int cnt = 0;
		
		bool ok = true;
		for(int i=0;i<=k;i++)
		{
			if(ch[i][0]=='+')
			{
				ans[cnt++] = arr[i];
				in[arr[i]] = true;

			}
			else
			{
				in[arr[i]] = false;
				while(cnt&&in[ans[cnt-1]]==false)
					cnt--;
			}

		}
		if(cnt) ok = false;
		if(k>=0&&k+1<m&&arr[k]!=arr[k+1]) ok = false;
		int x;
		if(k>=0) x = arr[k];
		if(k+1<m) x = arr[k+1];

		for(int i=k+1;ok&&i<m;i++)
		{
			//vis[arr[i]] = false;
			if(ch[i][0]=='+')
			{
				ans[cnt++] = arr[i];
				in[arr[i]] = true;
				
			}
			else
			{
				
				in[arr[i]] = false;
				while(cnt>0&&in[ans[cnt-1]]==false)
					cnt--;
				if(arr[i]==x&&cnt)
					ok = false;
				if(cnt==0&&i+1<m&&arr[i]!=arr[i+1])
					ok = false;
				
			}
			
		}
		if(ok&&x>0)
			vis[x] = true;
		cnt = 0;
		for(int i=1;i<=n;i++)
			if(vis[i]) ans[cnt++] = i;
		cout<<cnt<<endl;
		for(int i=0;i<cnt;i++)
		{
			if(i) printf(" ");
			printf("%d",ans[i]);
		}
		if(cnt) puts("");

	}
	return 0;
}

