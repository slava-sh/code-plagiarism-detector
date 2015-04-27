#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <map>
  
  
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-7
  
  
#define FOR0(i,x) for(i=0;i<x;i++)
#define FOR1(i,x) for(i=1;i<=x;i++)
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define FORL0(i,a) for(i=a;i>=0;i--)
#define FORL1(i,a) for(i=a;i>=1;i--)
#define FORL(i,a,b)for(i=a;i>=b;i--)
  
  
#define rush() int CC;for(scanf("%d",&CC);CC--;)
#define Rush(n)  while(scanf("%d",&n)!=-1)
using namespace std;
  
  
void RD(int &x){scanf("%d",&x);}
void RD(u32 &x){scanf("%u",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(u32 &x,u32 &y){scanf("%u%u",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(u32 &x,u32 &y,u32 &z){scanf("%u%u%u",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char &x){x=getchar();}
void RD(char *s){scanf("%s",s);}
void RD(string &s){cin>>s;}
  
  
void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(u32 x) {printf("%u\n",x);}
void PR(u64 x) {cout<<x<<endl;}
void PR(double x) {printf("%.4lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}
  
void upMin(int &x,int y) {if(x>y) x=y;}
void upMin(i64 &x,i64 y) {if(x>y) x=y;}
void upMin(double &x,double y) {if(x>y) x=y;}
void upMax(int &x,int y) {if(x<y) x=y;}
void upMax(i64 &x,i64 y) {if(x<y) x=y;}
void upMax(double &x,double y) {if(x<y) x=y;}
  
  
  
  
  
int sgn(double x)
{
    if(x>1e-10) return 1;
    if(x<-1e-10) return -1;
    return 0;
}
  
i64 Gcd(i64 x,i64 y)
{
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(y==0) return x;
    return Gcd(y,x%y);
}
  
i64 Lcm(i64 x,i64 y)
{
    return x/Gcd(x,y)*y;
}
  
i64 eular(i64 n)
{
    i64 ans=n,i;
    for(i=2;i*i<=n;i++) if(n%i==0)
    {
        ans-=ans/i;
        while(n%i==0) n/=i;
    }
    if(n>1) ans-=ans/n;
    return ans;
}
  
  
i64 exGcd(i64 a,i64 b,i64 &x,i64 &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    i64 temp=exGcd(b,a%b,x,y);
    i64 t=x;
    x=y;
    y=t-a/b*y;
    return temp;
}
  
i64 gcdReverse(i64 a,i64 b)
{
    i64 x,y;
    exGcd(a,b,x,y);
    x%=b;
    if(x<0) x+=b;
    return x;
}
  
i64 myPow(i64 a,i64 b)
{
    i64 ans=1;
    while(b)
    {
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
  
i64 myPow(i64 a,i64 b,i64 mod)
{
    a%=mod;
    i64 ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
  
  
i64 getInt()
{
    i64 x=0,flag=1;
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        flag=-1,c=getchar();
        while(!isdigit(c)) c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*flag;
}
  
i64 getSqrt(i64 t)
{
    i64 p=sqrt(1.0*t);
    while(p*p>t) p--;
    while((p+1)<=t/(p+1)) p++;
    return p;
}
  
  
  
  
struct point
{
    double x,y;
  
    point(){}
    point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
  
    void get()
    {
        scanf("%lf%lf",&x,&y);
    }
  
    point operator+(point a)
    {
        return point(x+a.x,y+a.y);
    }
  
    point operator-(point a)
    {
        return point(x-a.x,y-a.y);
    }
  
    point operator*(double t)
    {
        return point(x*t,y*t);
    }
  
    double operator*(point a)
    {
        return x*a.y-y*a.x;
    }
  
  
    double operator^(point a)
    {
        return x*a.x+y*a.y;
    }
  
    double Len()
    {
        return sqrt(x*x+y*y);
    }
  
    point adjustTo(double L)
    {
        L/=Len();
        return point(x*L,y*L);
    }
  
    point operator/(double t)
    {
        return point(x/t,y/t);
    }
  
  
    double rotateAngle(point a)
    {
        point p=*this;
        return atan2(p*a,p^a);
    }
  
    int operator==(point a)
    {
        return sgn(x-a.x)==0&&sgn(y-a.y)==0;
    }
  
    void print()
    {
        printf("%.4lf %.4lf\n",x,y);
    }
};
  
double calPloyArea(point a[],int n)
{
    double ans=0;
    int i;
    for(i=0;i<n;i++) ans+=a[i]*a[(i+1)%n];
    return ans;
}
  
int changeToClockwise(point a[],int n)
{
    double s=calPloyArea(a,n);
    if(sgn(s)>=0) return 0;
    int L=0,R=n-1;
    while(L<R) swap(a[L++],a[R--]);
    return 1;
}
  
int pointOnSeg(point p,point a,point b)
{
    if(sgn((p-a)*(p-b))) return 0;
    int x=sgn((p.x-a.x)*(p.x-b.x));
    int y=sgn((p.y-a.y)*(p.y-b.y));
    return x<=0&&y<=0;
}
  
int pointOnRightOfLine(point p,point a,point b)
{
    return sgn((p-a)*(b-a))>0;
}
  
int pointOnLine(point p,point a,point b)
{
    return sgn((p-a)*(b-a))==0;
}
  
int pointOnLeftOfLine(point p,point a,point b)
{
    return sgn((b-a)*(p-a))>0;
}
  
  
  
/**
 *out: 1
 * on: 0
 * in: -1
 * */
int getRelationOfPointAndPloy(point a[],int n,point p)
{
    a[n]=a[0];
    int i;
    double sum=0;
    for(i=0;i<n;i++)
    {
        if(pointOnSeg(p,a[i],a[i+1])) return 0;
        point aa=a[i]-p;
        point bb=a[i+1]-p;
        sum+=aa.rotateAngle(bb);
    }
  
  
    if(fabs(sum-2*PI)<1e-2) return -1;
    return 1;
}
  
  
int isParal(point a,point b,point p,point q)
{
    double aa=(b.x-a.x)*(p.y-q.y);
    double bb=(b.y-a.y)*(p.x-q.x);
    return sgn(aa-bb)==0;
}
  
/**
 * 1: only one cross
 * 0: no cross
 * 2: many cross
 *
 * */
int lineCrossLine(point a,point b,point p,point q,point &ans)
{
    if(isParal(a,b,p,q))
    {
        if(!pointOnLine(p,a,b)) return 0;
        return 2;
    }
  
    double s1=(p-a)*(q-a);
    double s2=(q-b)*(p-b);
    ans=(a*s2+b*s1)/(s1+s2);
    return 1;
  
}
  
/**
 * 1: only one cross point and store in ans
 * 0: no cross point
 * 2: many cross point
 * */
  
int segCrossSeg(point a,point b,point p,point q,point &ans)
{
    if(isParal(a,b,p,q))
    {
        if(!pointOnLine(p,a,b)) return 0;
        if(sgn(a.x-b.x)==0)
        {
            if(p.y>q.y) swap(p,q);
            if(a.y>b.y) swap(a,b);
            if(sgn(q.y-a.y)==-1||sgn(b.y-p.y)==-1) return 0;
            if(q==a||p==b)
            {
                if(q==a) ans=q;
                if(p==b) ans=p;
                return 1;
            }
            return 2;
        }
        if(p.x>q.x) swap(p,q);
        if(a.x>b.x) swap(a,b);
        if(sgn(q.x-a.x)==-1||sgn(b.x-p.x)==-1) return 0;
        if(q==a||p==b)
        {
            if(q==a) ans=q;
            if(p==b) ans=p;
            return 1;
        }
        return 2;
    }
    lineCrossLine(a,b,p,q,ans);
    if(pointOnSeg(ans,a,b)&&pointOnSeg(ans,p,q)) return 1;
    return 0;
}
 
 
const i64 MM=1000000000000LL;
 
struct BigInteger
{
    i64 a[20];
    int cnt;
 
    BigInteger()
    {
        cnt=1;
        a[1]=0;
    }
 
    BigInteger(i64 x)
    {
        if(x==0)
        {
            cnt=1;
            a[1]=0;
            return;
        }
        cnt=1;
        a[1]=x;
    }


    void reset()
    {
        cnt=1;
        a[1]=0;
    }
 
    BigInteger operator*(int x)
    {
        if(x==0) return BigInteger(0);
        if(zero()) return BigInteger(0);

        BigInteger p=*this;
        int i;
        FOR1(i,p.cnt) p.a[i]*=x;
        int t=0;
        FOR1(i,p.cnt)
        {
            p.a[i]+=t;
            t=p.a[i]/MM;
            p.a[i]%=MM;
        }
        if(t==0) return p;
        while(t) p.a[++p.cnt]=t%MM,t/=MM;
        return p;
    }


    int zero()
    {
        return cnt==1&&a[1]==0;
    }
 
    BigInteger operator+(BigInteger a)
    {
        if(a.zero()) return *this;
        if(zero()) return a;

        BigInteger p,q;
        if(a.cnt>cnt) p=a,q=*this;
        else p=*this,q=a;
 
        int i;
        for(i=1;i<=q.cnt;i++) p.a[i]+=q.a[i];
        int re=0;
        for(i=1;i<=p.cnt;i++)
        {
            p.a[i]+=re;
            re=p.a[i]/MM;
            p.a[i]%=MM;
        }
        if(re)
        {
            p.a[++p.cnt]=re;
        }
        return p;
    }

 
};
 
const i64 inf=(((i64)1)<<61)+5;
const double dinf=1000000000;
const int INF=1000000005;
const int N=222225;
  
  
  
struct SegTree
{
    struct node
    {
        int L,R,size;
        double v;
    };
 
    node a[N<<2];
    int n;
 
    SegTree(){}
    SegTree(int x)
    {
        n=x;
        build(1,1,n);
    }
 
 
    void build(int t,int L,int R)
    {
        a[t].L=L;
        a[t].R=R;
        if(L==R)
        {
            a[t].size=0;
            a[t].v=0;
            return;
        }
        int M=(L+R)>>1;
        build(t<<1,L,M);
        build(t<<1|1,M+1,R);
        a[t].size=a[t<<1].size+a[t<<1|1].size;
    }
 
    int query(int t,double v)
    {
        if(a[t].L==a[t].R) return a[t].v>v;
        if(sgn(a[t<<1].v-v)<=0) return query(t<<1|1,v);
        return a[t<<1|1].size+query(t<<1,v);
    }
 
    void change(int t,int pos,double v)
    {
        if(a[t].L==a[t].R)
        {
            a[t].size=1;
            a[t].v=v;
            return;
        }
        int M=(a[t].L+a[t].R)>>1;
        if(pos<=M) change(t<<1,pos,v);
        else  change(t<<1|1,pos,v);
        a[t].v=max(a[t<<1].v,a[t<<1|1].v);
        a[t<<1|1].size=query(t<<1|1,a[t<<1].v);
        a[t].size=a[t<<1].size+a[t<<1|1].size;
    }
};
 

struct heapTree
{
    struct heapNode
    {
        int L,R,pri,size;
        i64 x,y;

        heapNode(){}
        heapNode(i64 _x,i64 _y)
        {
            x=_x;
            y=_y;
            if(x<0) x=-x,y=-y;
            i64 tmp=Gcd(x,y);
            x/=tmp;
            y/=tmp;
        }

        int operator>=(const heapNode &a) const
        {
            return *this==a||*this>a;
        }

        int operator<=(const heapNode &a) const
        {
            return *this<a||*this==a;
        }

        int operator==(const heapNode &a) const
        {
            return y*a.x==x*a.y;
        }

        int operator<(const heapNode &a)const
        {
            return y*a.x<x*a.y;
        }

        int operator>(const heapNode &a) const
        {
            return y*a.x>x*a.y;
        }
    };




    heapNode a[200005];
    int e,root;

    void init()
    {
        e=0;
        root=-1;
    }

    void pushUp(int x)
    {
        if(x==-1) return;
        a[x].size=1;
        if(a[x].L!=-1) a[x].size+=a[a[x].L].size;
        if(a[x].R!=-1) a[x].size+=a[a[x].R].size;
    }

    void rotL(int &x)
    {
        int y=a[x].R;
        a[x].R=a[y].L; pushUp(x);
        a[y].L=x; pushUp(y);
        x=y;
    }

    void rotR(int &x)
    {
        int y=a[x].L;
        a[x].L=a[y].R; pushUp(x);
        a[y].R=x; pushUp(y);
        x=y;
    }

    void insert(int &k,heapNode p)
    {
        if(k==-1)
        {
            k=++e;
            a[k].L=a[k].R=-1;
            a[k].x=p.x;
            a[k].y=p.y;
            a[k].pri=rand();
        }
        else if(p<a[k])
        {
            insert(a[k].L,p);
            if(a[a[k].L].pri>a[k].pri) rotR(k);
        }
        else
        {
            insert(a[k].R,p);
            if(a[a[k].R].pri>a[k].pri) rotL(k);
        }
        pushUp(k);
    }


    void insert(i64 x,i64 y)
    {
        insert(root,heapNode(x,y));
    }

    void del(int &k,heapNode p)
    {
        if(k==-1) return;
        else if(p<a[k]) del(a[k].L,p);
        else if(p>a[k]) del(a[k].R,p);
        else
        {
            if(a[k].L==-1&&a[k].R==-1) k=-1;
            else if(a[k].L==-1) k=a[k].R;
            else if(a[k].R==-1) k=a[k].L;
            else
            {
                if(a[a[k].L].pri<a[a[k].R].pri)
                {
                    rotL(k);
                    del(a[k].L,p);
                }
                else
                {
                    rotR(k);
                    del(a[k].R,p);
                }
            }
        }
        pushUp(k);
    }

    void del(i64 x,i64 y)
    {
        del(root,heapNode(x,y));
    }


    int findSmallThan(int k,heapNode p)
    {
        if(k==-1) return 0;
        if(p<=a[k]) return findSmallThan(a[k].L,p);
        int ans=1;
        if(a[k].L!=-1) ans+=a[a[k].L].size;
        return ans+findSmallThan(a[k].R,p);
    }

    int findSmallThan(i64 x)
    {
        return findSmallThan(root,heapNode(1,x));
    }

    int findBigThan(int k,heapNode p)
    {
        if(k==-1) return 0;
        if(p>=a[k]) return findBigThan(a[k].R,p);
        int ans=1;
        if(a[k].R!=-1) ans+=a[a[k].R].size;
        return ans+findBigThan(a[k].L,p);
    }

    int findBigThan(i64 x)
    {
        return findBigThan(root,heapNode(1,x));
    }
};
 

const int spfaEdgeNum=5005;
const int spfaNodeNum=2005;

struct spfaStruct
{
    struct node
    {
        int v,w;
    };

    vector<node> g[N];
    i64 dis[N];
    int inq[N],n;

    void init(int N)
    {
        n=N;
        int i;
        for(i=0;i<=n;i++)  g[i].clear(),d[i]=0;
    }

    void add(int u,int v,int w=1)
    {
        node p;
        p.v=v;
        p.w=w;
        g[u].pb(p);
        d[v]++;
    }


    void spfa(int s)
    {
        int i;
        FOR1(i,n) dis[i]=inf,inq[i]=0;
        dis[s]=0;
        inq[s]=1;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();

            inq[u]=0;
            FOR0(i,SZ(g[u]))
            {
                int v=g[u][i].v;
                int w=g[u][i].w;
                if(dis[v]>dis[u]+w)
                {
                    dis[v]=dis[u]+w;
                    if(!inq[v]) Q.push(v),inq[v]=1;
                }
            }
        }
    }

    i64 f[N];
    int d[N];

    void DP()
    {
        int i;
        queue<int> Q;
        FOR1(i,n) if(!d[i]) Q.push(i);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();

            FOR0(i,SZ(g[u]))
            {
                int v=g[u][i].v;
                f[v]+=f[u];
                if(--d[v]==0) Q.push(v);
            }
        }
    }
};

struct fraction
{
    i64 a,b;

    fraction() {}
    fraction(i64 x)
    {
        a=x; b=1;
    }

    fraction(i64 x,i64 y)
    {
        a=x; b=y;
        deal();
    }

    void deal()
    {
        if(b<0) b=-b,a=-a;
        i64 k=Gcd(a,b);
        if(k<0) k=-k;
        a/=k; b/=k;
    }

    fraction operator+(fraction p)
    {
        fraction ans;
        ans.b=Lcm(b,p.b);
        ans.a=ans.b/b*a+ans.b/p.b*p.a;
        ans.deal();
        return ans;
    }

    fraction operator-(fraction p)
    {
        fraction ans;
        ans.b=Lcm(b,p.b);
        ans.a=ans.b/b*a-ans.b/p.b*p.a;
        ans.deal();
        return ans;
    }

    fraction operator*(fraction p)
    {
        fraction ans;
        ans.a=a*p.a;
        ans.b=b*p.b;
        ans.deal();
        return ans;
    }

    fraction operator/(fraction p)
    {
        fraction ans;
        ans.a=a*p.b;
        ans.b=b*p.a;
        ans.deal();
        return ans;
    }

    int operator<(const fraction &p) const
    {
        return a*p.b<b*p.a;
    }

    int operator>(const fraction &p) const
    {
        return a*p.b>b*p.a;
    }

    int operator==(const fraction &p) const
    {
        return a*p.b==b*p.a;
    }

    int operator!=(const fraction &p) const
    {
        return a*p.b!=b*p.a;
    }

};


/****************************/
  
  
  
  
/*****************************/
 

#define pii pair<int,int> 
const int mod=1000000007;
const i64 MAX=1000000000000000000LL;
const int M=3005;



int a[M][M];

char s[M][22][22];
int n,m,K,w;

int cal(int x,int y)
{
    int ans=0;
    int i,j;
    FOR1(i,n) FOR1(j,m) if(s[x][i][j]!=s[y][i][j]) ans++;
    return ans;
}

int p[M];
int dis[M];
int h[M];

int main()
{
    RD(n,m); RD(K,w);
    int i,j,k;
    FOR1(i,K) FOR1(j,n) RD(s[i][j]+1);
    FOR1(i,K) for(j=i+1;j<=K;j++)
    {
        int t=cal(i,j);
        a[i][j]=a[j][i]=t*w;
    }
    K++;
    for(i=1;i<=K-1;i++) a[i][K]=a[K][i]=n*m;
    p[1]=K;
    dis[1]=0; h[1]=1;
    int ans=n*m;
    for(i=2;i<=K;i++) 
    {
        dis[i]=a[1][i],p[i]=1;
    }
    vector<pair<int,int> > pp;
    pp.pb(MP(1,0));
    for(i=1;i<K;i++)
    {
        int Min=INF,t;
        FOR1(j,K) if(!h[j]&&dis[j]<Min)
        {
            Min=dis[j];
            t=j;
        }
        h[t]=1;
        if(t!=K)
        {
            if(p[t]==K) pp.pb(MP(t,0));
            else pp.pb(MP(t,p[t]));
            ans+=Min;
        }
        FOR1(j,K) if(!h[j]&&dis[j]>a[t][j])
        {
            p[j]=t;
            dis[j]=a[t][j];
        }
    }
    PR(ans);
    FOR1(i,K-1) printf("%d %d\n",pp[i-1].first,pp[i-1].second);
}