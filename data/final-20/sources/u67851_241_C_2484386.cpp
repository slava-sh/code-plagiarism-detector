#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

#define H 100

struct pv
{
    double x,y;
    pv(){}
    pv(const double &a,const double &b):x(a),y(b){}
    inline pv operator-(const pv &i)const
    {
        return pv(x-i.x,y-i.y);
    }
}r,o,v,now;

short sc[111];
char mi[2][100111];
bool done[111];
char buf[11];

short hl,hr,n,h;
int i,j,k,l;
int ans;

inline int go1()
{
    v=o-r;
    h=H;
    k=1;
    memset(done,0,sizeof(done));
    int re(0);
    while(h<r.y)
    {
        now.y=h;
        now.x=(h-o.y)/v.y*v.x+o.x;
        if(mi[k][(int)now.x]==-1 || done[mi[k][(int)now.x]])
            return -1;
        else
        {
            re+=sc[mi[k][(int)now.x]];
            done[mi[k][(int)now.x]]=true;
        }
        h+=H;
        k=!k;
    }
    return re;
}

inline int go2()
{
    v=o-r;
    h=0;
    k=0;
    memset(done,0,sizeof(done));
    int re(0);
//    printf("go:%lf %lf\n",r.x,r.y);
    while(h>r.y)
    {
        now.y=h;
        now.x=(h-o.y)/v.y*v.x+o.x;
//        printf("%lf %lf\n",now.x,now.y);
//        printf("%hd\n",mi[k][(int)now.x]);
        if(mi[k][(int)now.x]==-1 || done[mi[k][(int)now.x]])
            return -1;
        else
        {
            re+=sc[mi[k][(int)now.x]];
            done[mi[k][(int)now.x]]=true;
        }
        h-=H;
        k=!k;
    }
    return re;
}

int main()
{
    memset(mi,-1,sizeof(mi));
    scanf("%hd %hd %hd",&hl,&hr,&n);
    r.x=1e5;
    r.y=hr;
    o.x=0;
    o.y=hl;
    for(i=0;i<n;++i)
    {
        scanf("%hd %s %d %d",sc+i,buf,&j,&k);
        if(buf[0]=='T')
            l=1;
        else
            l=0;
        for(;j<k;++j)
            mi[l][j]=i;
    }
    for(i=0;i<=25;++i)
    {
        r.y=2*i*H-hr;
        ans=std::max(ans,go1());
        r.y=2*i*H+hr;
        ans=std::max(ans,go1());
        r.y=-2*i*H-hr;
        ans=std::max(ans,go2());
        r.y=-2*i*H+hr;
        ans=std::max(ans,go2());
    }
    printf("%d\n",ans);
    return 0;
}
