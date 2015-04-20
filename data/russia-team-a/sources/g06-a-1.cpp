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
    const int NN=2000;
    int n,r,m,i,j,k;
    int a[NN];
    int d[NN];
    int fix[NN];
    long long A;
    int c[NN][NN];
    int col[NN];
    int f(int  x)
    {
        if (d[x]==x) return x;
        return d[x]=f(d[x]);
    }
    void go(int x,int color)
    {
        if (col[x]!=-1) return;
       col[x]=color;
        for (int i=1;i<=n;i++)
            if (c[x][i]>-1)
                go(i,(color^c[x][i]));
    }

    int main()
    {
        freopen("binary.in","r",stdin);
        freopen("binary.out","w",stdout);
      cin>>n;
      for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        c[i][j]=-1;

      for (i=1;i<=n;i++)
        cin>>a[i];
      if (a[1]>0) {cout<<0<<endl;return 0;}
      for (i=2;i<=n;i++)
        if (a[i]>=0)
        if (i+a[i]>n+1) {cout<<0<<endl;return 0;}
    for (i=1;i<=n;i++) d[i]=i;

    for (i=2;i<=n;i++)
        for (j=0;j<a[i];j++){
        d[f(j+1)]=f(i+j);
        c[j+1][i+j]=0;
        c[i+j][j+1]=0;
        }
    for (i=2;i<=n;i++)
        if (i+a[i]<n+1)
    if (f(i+a[i])==f(a[i]+1)) {cout<<0<<endl;return 0;}
    for (i=2;i<=n;i++)
        if (a[i]!=-1)
        if (i+a[i]<n+1){
    d[f(i+a[i])]=f(a[i]+1);
        c[i+a[i]][a[i]+1]=1;
        c[a[i]+1][i+a[i]]=1;

        }
        for (i=1;i<=n;i++) col[i]=-1;

        for (i=1;i<=n;i++)
        go(i,0);




    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        if (c[i][j]>=0)
        if ((col[i]^col[j])!=c[i][j])
    {cout<<0<<endl;return 0;}

    A=1;
    for (i=1;i<=n;i++)
    {
        if (!fix[f(i)])
        {
            A=(A*2)%1000000007ll;
        }
        fix[f(i)]=1;
    }
    cout<<A<<endl;

    return 0;
    }
