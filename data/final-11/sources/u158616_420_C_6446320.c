#include<stdio.h>
#include<stdlib.h>
#define lim 600006u
typedef long long unsigned llu;
typedef unsigned u;
u X[lim],Y[lim],Z[lim],Xt[lim],Yt[lim],Ag[lim],N[lim],q;
int F(const void*x,const void*y)
{
	if(Xt[*(u*)x]>Xt[*(u*)y])return 1;
	if(Xt[*(u*)x]<Xt[*(u*)y])return-1;
	if(Yt[*(u*)x]>Yt[*(u*)y])return 1;
	if(Yt[*(u*)x]<Yt[*(u*)y])return-1;
	return 0;
}
int G(const void*x,const void*y)
{
	if(Ag[*(u*)x]<Ag[*(u*)y])return 1;
	if(Ag[*(u*)x]>Ag[*(u*)y])return-1;
	return 0;
}
int main()
{
	u n,p,i,j,k,l,L,U,M;llu r;
	scanf("%u%u",&n,&p);
	for(l=0;l<n;l++)
	{
		scanf("%u%u",&i,&j);
		Ag[--i]++;Ag[--j]++;N[l]=l;
		Xt[q]=i;Yt[q]=j;q++;
		Xt[q]=j;Yt[q]=i;q++;
	}
	for(;l<q;l++)N[l]=l;
	qsort(N,q,sizeof(u),F);
	X[0]=Xt[N[0]];Y[0]=Yt[N[0]];
	for(l=i=0,j=1;++l<q;)
	{
		if(X[i]==Xt[N[l]]&&Y[i]==Yt[N[l]])j++;
		else
		{
			Z[i]=j;j=1;i++;
			Y[i]=Yt[N[l]];
			X[i]=Xt[N[l]];
		}
	}
	Z[i]=j;q=i+1;
	for(i=0;i<n;i++)N[i]=i;
	qsort(N,n,sizeof(u),G);
	for(r=i=0;i<n;i++)
	{
		k=Ag[i];
		if(k>=p){r+=n-1;continue;}
		if(p<=(k<<1))r--;
		L=0;U=n-1;k=p-k;
		if(k>Ag[N[0]])continue;
		if(k<=Ag[N[n-1]]){r+=n;continue;}
		while((M=(L+U)>>1)>L)
		{
			if(Ag[N[M]]>=k)L=M;
			else U=M;
		}
		r+=U;
	}
	for(i=0;i<q;i++)if(Ag[X[i]]+Ag[Y[i]]>=p&&Ag[X[i]]+Ag[Y[i]]<p+Z[i])r--;
	printf("%I64u\n",r>>1);
	return 0;
}
