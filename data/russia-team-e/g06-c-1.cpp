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
    int I,J,n,m,i,j,k,l,r,L[NN],R[NN],x,y,A;
    int a[NN];
    int d[NN];
    bool fi;
    set <pair <int,int> > S;
    vector <int > v[NN],z;
    void fin(int x,int fr)
    {
        if (x==J) fi=1;
        for (int i=0;i<v[x].size();i++)
        if (v[x][i]!=fr && fi==0)
            fin(v[x][i],x);
        if (fi) z.pb(x);
    }
    int sol(int x,int fr)
    {
        int R=0;
        for (int i=0;i<v[x].size();i++)
            if (v[x][i]!=0 && v[x][i]!=fr)
            R=max(R,sol(v[x][i],x)+1);
        return R;
    }
    int main()
    {
      freopen("dwarfs.in","r",stdin);
        freopen("dwarfs.out","w",stdout);
     cin>>n;
     for (i=1;i<n;i++)
     {
         scanf("%d%d",&l,&r);
         v[l].pb(r);
         v[r].pb(l);
      }
      cin>>I>>J;
      fin(I,I);
      for (i=1;i<z.size();i++) S.insert(mp(z[i],z[i-1])),S.insert(mp(z[i-1],z[i]));
      for (i=1;i<=n;i++)
       for (j=0;j<v[i].size();j++)
        if (S.find(mp(i,v[i][j]))!=S.end())
         v[i][j]=0;
      for (i=0;i<z.size();i++)
        d[i]=sol(z[i],z[i]);

     //   for (i=0;i<z.size();i++) cout<<z[i]<<" ";cout<<endl;
     //   for (i=0;i<z.size();i++) cout<<d[i]<<" ";cout<<endl;

     L[0]=d[0];
     for (i=1;i<z.size();i++)
        L[i]=MA(L[i-1],d[i]+i);
     R[z.size()-1]=d[z.size()-1];
     for (i=z.size()-2;i>=0;i--)
        R[i]=MA(R[i+1],d[i]+z.size()-i-1);
    for (i=1;i<z.size();i++)
    A=MA(A,MI(L[i-1],R[i]));
    cout<<A+1<<endl;


        return 0;
    }
