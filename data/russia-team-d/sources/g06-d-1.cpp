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
    #define INF 1001001001ll
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
    const int NN=400000;
    int n,m,i,j,k,l,r;
    int a[NN];
    int d[NN];
    long long s;
    bool f(long long x)
    {
        long long z=INF*INF;
        for (int i=1;i<=n;i++)
        z=MI(z,x*i-a[i]);
     //   cout<<x<<" "<<x*n-k<<" "<<z<<endl;
        return x*n-k<z;
    }
    int main()
    {
        freopen("fence.in","r",stdin);
        freopen("fence.out","w",stdout);
     cin>>n>>k;
     for (i=1;i<=n;i++) scanf("%d",&a[i]);
     sort(a+1,a+n+1);
     l=0;
     r=k;
     for (i=1;i<=n;i++) r=MI(r,a[i]);
     while (l<r)
     {
         int mid=(l+r);
         if (f(mid)) l=mid; else r=mid-1;
         if (l+1==r)
         {
             if (f(r)) l=r; r=l;
         }
     }
     cout<<l<<endl;
        return 0;
    }
