#include<iostream>
#include<cstring>
using namespace std;
int a[100100],r[100100],br[100100];
int main()
{
	int n,k,i,b[100100],v=0,brr=0;
	char c[100100];
	cin>>n>>k;
	for(i=0;i<k;i++)
	{
		cin>>c[i]>>b[i];
		if(c[i]=='+')
		{
			br[i]=v;
			v++;
			r[b[i]]=1;
		}
		else
		{
			br[i]=v;
			if(r[b[i]]==1)v--;
			r[b[i]]=0;
		}
	}
	br[k]=v;
	c[k]='-';
	v=0;
	memset(r,0,sizeof(r));
	for(i=k-1;i>=0;i--)
	{
		if(c[i]=='-')
		{
			br[i]+=v;
			v++;
			r[b[i]]=1;
			if(k!=i+1)if(!(c[i+1]=='+' && b[i+1]==b[i]))a[b[i]]=1;
		}
		else
		{
			if(r[b[i]]==1)v--;
			br[i]+=v;
			r[b[i]]=0;
			if(i!=0)if(!(c[i-1]=='-' && b[i-1]==b[i]))a[b[i]]=1;
		}
	}
	for(i=0;i<k;i++)
		if((c[i]=='-' && br[i+1]!=0) || (c[i]=='+' && br[i]!=0))a[b[i]]=1;
	brr=0;
	for(i=1;i<=n;i++)
		brr+=1-a[i];
	cout<<brr<<endl;
	for(i=1;i<=n;i++)
		if(a[i]==0)cout<<i<<" ";
}
