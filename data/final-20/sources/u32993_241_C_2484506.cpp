#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

char s[100];

struct point
{
    double begin,end;
    int p,data;
    void read()
    {
        scanf("%d%s%lf%lf",&data,s,&begin,&end);
        if(s[0]=='F')p=1;
        else p=0;
    }
}f[105];

double hl,hr,l,r,x;
int n,i,j,k,p[105],ans,sum,ss;

int main()
{
    scanf("%lf%lf",&hl,&hr);
    scanf("%d",&n);
    for(i=0;i<n;i++)
        f[i].read();
    ans=0;
    l=hl;
    r=hr;
    for(i=1;i<=n;i++)
    {
        r=-200.0*(i-1)-r;
        for(j=0;j<n;j++)
            p[j]=0;
        for(j=1;j<=i;j++)
        {
            x=1e5*(-100.0*(j-1)-l)/(r-l);
            for(k=0;k<n;k++)
                if(j%2==f[k].p && f[k].begin<=x && x<=f[k].end)p[k]++;
        }
        ss=0;
        sum=0;
        for(j=0;j<n;j++)
            if(p[j])ss++,sum+=f[j].data;
        if(ss==i && sum>ans)ans=sum;
    }
    l=hl;
    r=hr;
    for(i=1;i<=n;i++)
    {
        r=200.0*i-r;
        memset(p,0,sizeof(p));
        for(j=0;j<n;j++)
            p[j]=0;
        for(j=1;j<=i;j++)
        {
            x=1e5*(100.0*(j)-l)/(r-l);
            for(k=0;k<n;k++)
                if(j%2!=f[k].p && f[k].begin<=x && x<=f[k].end)p[k]++;
        }
        ss=0;
        sum=0;
        for(j=0;j<n;j++)
            if(p[j])ss++,sum+=f[j].data;
        if(ss==i && sum>ans)ans=sum;
    }
    printf("%d\n",ans);
    return 0;
}
