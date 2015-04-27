#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define mp(a,b) make_pair(a,b)

const int N = 4e5;
const int mod = 1000000007;
const int inf = 1e9;
const double pi =  acos(-1.0);
const double eps = 1e-8;

struct unionset
{
    int fat[1003],len;
    void init(int x)
    {
        len = x;
        for(int i=0;i<x;i++)
            fat[i] = i;
        return ;
    }
    int getf(int x)
    {
        if(fat[x] == x)
            return x;
        return fat[x] = getf(fat[x]);
    }
    void un(int x,int y)
    {
        fat[getf(y)] = getf(x);
        return ;
    }
};

struct tree_array
{
    int c[1003];
    int v[1003],len;
    int get_low(int x) {return x&(-x);}
    void init(int x)
    {
        len = x;
        for(int i=0;i<x;i++)
            c[i] = v[i] = 0;
        return ;
    }
    void add(int x,int value)///v[x] += v
    {
        v[x] += value;
        while(x<=len)
        {
            c[x] += value;
            x += get_low(x);
        }
        return ;
    }
    int sum(int x)/// sigma(1,x)
    {
        int ans = 0;
        while(x>0)
        {
            ans += c[x];
            x -= get_low(x);
        }
        return ans;
    }
};

int pow_mod(int a,int b,int c)
{
    long long ans = 1,tmp = a;
    while(b){
        if(b&1)ans = ans*tmp%c;
        tmp = tmp*tmp%c;
        b>>=1;
    }
    return ans;
}

long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}

/// -----------------------------------------------------------------

class ColorfulCoins
{
    public:
        int minQueries(vector<long long> values)
        {
            int xx[100];
            int n = values.size()-1;
            for(int i=0;i<values.size();i++)
                xx[i] = values[i+1]/values[i];
            if(n == 0)return 0;
            int cnt = n,tag[100] = {0};
            while(cnt>0){
                int id = 0,bb = 0;
                for(int i=0;i<n;i++)
                if(tag[i]==0&&xx[i]>bb){
                    id = i;
                    bb = xx[i];
                }
                tag[id] = 1;
                cnt --;
            }
        }
};

vector<int> qnext[N];
struct bb{
int l,r;
    bool operator<(const bb &a)const{
        if(l == a.l)
            return r < a.r;
        return l<a.l;
    }
}qlist[N],tmp[N];
int cnt[N];
int vvv[N];
bool xt[N];

int main()
{
    int i,n,p;
    scanf("%d%d",&n,&p);
    for(i=0;i<n;i++){
        tmp[i].r = i+1;
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r)swap(l,r);
        qlist[i].l = l;
        qlist[i].r = r;
        cnt[l]++;
        tmp[l-1].l++;
        tmp[r-1].l++;
        cnt[r]++;
    }
    sort(tmp,tmp+n);
    for(i=0;i<n;i++)
        vvv[i] = tmp[i].l;
    sort(qlist,qlist+n);

    for(i=0;i<n;i++)
        if(i==n-1||!(qlist[i+1].l==qlist[i].l&&qlist[i+1].r==qlist[i].r))
    {
        qnext[qlist[i].l].push_back(qlist[i].r);
        qnext[qlist[i].r].push_back(qlist[i].l);
    }
    long long ans = 0;
    int num = 1,l = qlist[0].l,r = qlist[0].r;
    for(i=1;i<n;i++)
        if(qlist[i].l == l && qlist[i].r == r)num++;
        else{
            if(cnt[l] + cnt[r] - num >= p )ans++;
            num = 1;
            l = qlist[i].l;
            r = qlist[i].r;
        }
    if(cnt[l] + cnt[r] - num >= p )ans++;

    for(i=n-1;i>0;i--){
        if(tmp[i].l<p-tmp[i].l)break;
        int num = vvv+i - lower_bound(vvv,vvv+n,p-tmp[i].l);
        int u = tmp[i].r;
        xt[u] = true;
        for(int j = 0;j<qnext[u].size();j++)
            if(cnt[qnext[u][j]]>=p-tmp[i].l&&!xt[qnext[u][j]])
                num--;
        ans += num;
    }
    cout << ans;
    //printf("%d\n",ans);
    return 0;
}
/*
char s[N];
int main()
{
    int tag[26] ={1,0,0,0,0,0,0,
                1,1,0,0,0,1,0,
                1,0,0,0,0,1,
                1,1,1,1,1,0};
    scanf("%s",s);
    int len =  strlen(s),i;
    for(i=0;i<len;i++)
        if(!tag[s[i] -'A']||(s[i]!=s[len-1-i]))break;
    if(i>=len)printf("YES");
    else printf("NO");


    return 0;
}
*/
