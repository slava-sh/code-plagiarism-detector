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
    int dis[NN];
    bool fix[NN];
    vector <int > v[NN],s[NN];
    set <pair <int,pair <int,int> > > D;
    pair <int,pair <int,int> > M;
    int main()
    {
        freopen("secure.in","r",stdin);
        freopen("secure.out","w",stdout);
     cin>>n>>m;
     for (i=1;i<=n;i++) scanf("%d",&a[i]);
     for (i=1;i<=m;i++)
     {
         scanf("%d%d%d",&l,&r,&k);
         v[l].pb(r);
         v[r].pb(l);
         s[l].pb(k);
         s[r].pb(k);
     }
     for (i=1;i<=n;i++) dis[i]=(a[i]==1?0:INF);
     for (i=1;i<=n;i++)
     if (a[i]==1)  D.insert(mp(0,mp(i,i)));
     while (D.size())
     {
         M=*D.begin();
         D.erase(D.begin());
         if (fix[M.Y.X]==0)
         {
             if (a[M.Y.X]==2)
             {
                 cout<<M.Y.Y<<" "<<M.Y.X<<" "<<M.X<<endl;
                 return 0;
             }
             fix[M.Y.X]=1;
             for (i=0;i<v[M.Y.X].size();i++)
             if (dis[v[M.Y.X][i]]>M.X+s[M.Y.X][i])
             {
                 dis[v[M.Y.X][i]]=M.X+s[M.Y.X][i];
                 D.insert(mp(dis[v[M.Y.X][i]],mp(v[M.Y.X][i],M.Y.Y)));
             }
         }

     }
     cout<<-1<<endl;
        return 0;
    }
