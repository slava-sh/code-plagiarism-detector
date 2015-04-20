    #include<math.h>
    #include<algorithm>
    #include<cstdlib>
    #include<iostream>
    #include<stdio.h>
    #include<map>
    #include<ext/hash_map>
    #include<ext/hash_set>
    #include<set>
    #include<string>
    #include<assert.h>
    #include<vector>
    #include<time.h>
    #include<queue>
    #include<deque>
    #include<sstream>
    #include<stack>
    #include<sstream>
    #define INF 1001001001
    #define MA(a,b) ((a)>(b)?(a):(b))
    #define MI(a,b) ((a)<(b)?(a):(b))
    #define AB(a) (-(a)<(a)?(a):-(a))
    #define P 1000000007
    #define X first
    #define Y second
    #define mp make_pair
    #define pb push_back
    #define pob pop_back
    #define E 0.0000000000000001
    using namespace std;
    using namespace __gnu_cxx;
    const int NN=4000;
    int n,r,m,i,j,k;
    int a[NN];
    int d[NN];
    bool f[NN];
    long long s;
    int DSU(int x)
    {
        if (d[x]==x) return x;
        return  d[x]=DSU(d[x]);
    }
    int main()
    {
        freopen("prizes.in","r",stdin);
        freopen("prizes.out","w",stdout);
     cin>>n>>m;
     n=MI(n,m);
     cout<<(n+1)/4<<endl;
  return 0;
   // for (i=1;i<=n;i++) scanf("%d",&a[i]);
   // for (i=1;i<=n;i++) d[i]=i;
 // if (a[1]>0) {cout<<0<<endl; return  0;}

    for (i=2;i<=n;i++)
    if (i+a[i]-1>n)
    {
        cout<<0<<endl; return  0;
    }
    for (i=2;i<=n;i++)
    for (j=0;j<a[i];j++)
        d[DSU(j+1)]=DSU(i+j);
    s=1;
    for (i=1;i<=n;i++)
    {
        if (f[DSU(i)]==0) s=(s*2)%1000000007ll;
        f[DSU(i)]=1;
    }
    cout<<s<<endl;

        return 0;
    }
