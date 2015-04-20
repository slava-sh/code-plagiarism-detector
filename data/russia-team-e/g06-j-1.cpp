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
     int n,m,i,j,k,t,I,J,x,y;
     char c[550][505];
     int f[550][505];
     const string s[5]={"","SN","NS","EW","WE"};
     pair <int,int> A;
    int main()
    {
        freopen("travel.in","r",stdin);
        freopen("travel.out","w",stdout);
     cin>>m>>n>>t;
     for (i=1;i<=n;i++)
     scanf("%s",c[i]+1);
     for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        if (c[i][j]=='V') I=i,J=j;
     A=mp(INF,INF);
     for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
     if (c[i][j]=='T')
     {
         if (c[i+1][j]=='T') f[i][j]=1;
         if (c[i-1][j]=='T') f[i][j]=2;
         if (c[i][j+1]=='T') f[i][j]=3;
         if (c[i][j-1]=='T') f[i][j]=4;
         if (f[i][j]>0)
         {
             if (A>mp(AB(I-i)+AB(J-j)+t-1,f[i][j]))
             {
                 A=mp(AB(I-i)+AB(J-j)+t-1,f[i][j]);
                 x=i;
                 y=j;
             }

                      } else
         {
             if (A>mp(AB(I-i)+AB(J-j)+(t-1)*2,0))
             {
                 A=mp(AB(I-i)+AB(J-j)+(t-1)*2,0);
                 x=i;
                 y=j;
             }
         }
     }
     for (i=I;i<x;i++) putchar('S');
     for (i=I;i>x;i--) putchar('N');
     for (i=J;i<y;i++) putchar('E');
     for (i=J;i>y;i--) putchar('W');
     t--;
     if (A.Y>0)
     {
         for (i=0;i<t;i++)
         putchar(s[A.Y][i%2]);
         putchar('\n');
         return 0;
     }

     if (x<n) k=1;
     if (y<m) k=3;
     if (x>1) k=2;
     if (y>1) k=4;


         for (i=0;i<t;i++)
         putchar(s[k][0]),
         putchar(s[k][1]);
         putchar('\n');
         return 0;




     return 0;
    }
