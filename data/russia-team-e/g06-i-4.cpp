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
    const int NN=400000;
    int n,r,m,i,j,k;
    int a[NN];
    int d[NN],m1,m2;
    bool f[NN];
    long long s,ss;

    int main()
    {
        freopen("sochi.in","r",stdin);
        freopen("sochi.out","w",stdout);
     cin>>n>>m;

     for (i=1;i<=n;i++) scanf("%d",&a[i]);
     sort(a+1,a+n+1);

     if (n==1)
     {
         cout<<a[1]<<endl;
         return 0;
     }
     ss=MA(a[n],a[n]+a[n-1]-2*m);

     s=0;
     bool TT=0;
     for (i=n;i>=1;i--)
     if(a[i]>=3*m)TT=1,s+=a[i]-2*m;else{
        m1=a[i];
        m2=a[i-1];
        goto mere;
     }

     mere:
      if (TT){ s+=2*m;

     if(m1>m)s+=m1-2*m;
     if(m2>m)s+=m2-2*m;
      }
     cout<<MA(s,ss)<<endl;
  return 0;

    }
