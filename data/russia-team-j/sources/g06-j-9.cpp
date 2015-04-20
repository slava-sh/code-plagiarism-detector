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
    struct ELE{int x,y,k;} T,TT;
     int n,m,i,j,k,t,I,J,x,y;
     char c[555][555];
     int f[555][555];
     int d[555][555];
     const string s[5]={"","SN","NS","EW","WE"};
     pair <int,int> A;
     vector <char> ans;
     void go(int x,int y)
     {
         if (x==I && y==J) return;
         int xx=0,yy=0;
         if (x==I) {
            if (y>J) {ans.pb('E'); go(x,y-1); return;}
                     {ans.pb('W'); go(x,y+1); return;}
         }
         if (y==J) {
            if (x>I) {ans.pb('S'); go(x-1,y); return;}
                     {ans.pb('N'); go(x+1,y); return;}
         }

         if (x>I) xx=d[x-1][y]; else xx=d[x+1][y];
         if (y>J) yy=d[x][y-1]; else yy=d[x][y+1];
         if (xx>yy)
         {
             if (x>I) {ans.pb('S'); go(x-1,y); return;}
                       {ans.pb('N'); go(x+1,y); return;}
         }
         else {
               if (y>J) {ans.pb('E'); go(x,y-1); return;}
                     {ans.pb('W'); go(x,y+1); return;}
         }
        }
    void sol()
    {
        int v[n+5][m+5][t*2+m+n+5];
            for (i=0;i<n+5;i++)
            for (j=0;j<m+5;j++)
            for (k=0;k<t*2+m+n+5;k++) v[i][j][k]=-1;
            v[I][J][0]=0;

            queue<ELE> Q;

            while (Q.size()) Q.pop();
            T.x=I;
            T.y=J;
            T.k=0;
            Q.push(T);
            while (Q.size())
            {
                T=Q.front();
                Q.pop();
               // cout<<T.x<<" "<<T.y<<" "<<T.k<<" "<<v[T.x][T.y][T.k]<<" ";system("pause");
                if (v[T.x][T.y][T.k]>=t)
                {
                    x=T.x;
                    y=T.y;
                    k=T.k;
                    ans.clear();
                    while (k)
                    {
                      if (x>1 && v[x][y][k]==v[x-1][y][k-1]+(int)(c[x][y]=='T'))
                      {
                          ans.pb('S');
                          x--;
                          k--;
                      } else
                      if (x<n && v[x][y][k]==v[x+1][y][k-1]+(int)(c[x][y]=='T'))
                      {
                          ans.pb('N');
                          x++;
                          k--;
                      } else
                      if (y>1 && v[x][y][k]==v[x][y-1][k-1]+(int)(c[x][y]=='T'))
                      {
                          ans.pb('E');
                          y--;
                          k--;
                      } else
                      if (y<m && v[x][y][k]==v[x][y+1][k-1]+(int)(c[x][y]=='T'))
                      {
                          ans.pb('W');
                          y++;
                          k--;
                      }
                    }

                          for (i=ans.size()-1;i>=0;i--)
                        putchar(ans[i]);
                  cout<<endl;

                    exit (0);
                }

                if (T.x<n) {TT=T; TT.k++; TT.x++;
                if (v[TT.x][TT.y][TT.k]<v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')){
                v[TT.x][TT.y][TT.k]=MA(v[TT.x][TT.y][TT.k],v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')); Q.push(TT);}}

                if (T.x>1) {TT=T; TT.k++;TT.x--;
                if (v[TT.x][TT.y][TT.k]<v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')){
                v[TT.x][TT.y][TT.k]=MA(v[TT.x][TT.y][TT.k],v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')); Q.push(TT);}}

                if (T.y<m) {TT=T; TT.y++;TT.k++;
                if (v[TT.x][TT.y][TT.k]<v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')){
                v[TT.x][TT.y][TT.k]=MA(v[TT.x][TT.y][TT.k],v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')); Q.push(TT);}}
                if (T.y>1) {TT=T; TT.y--;TT.k++;
                if (v[TT.x][TT.y][TT.k]<v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')){
                v[TT.x][TT.y][TT.k]=MA(v[TT.x][TT.y][TT.k],v[T.x][T.y][T.k]+(int)(c[TT.x][TT.y]=='T')); Q.push(TT);}}

            }


        }
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

      if (n*m*(t*2+m+n)<12000000)
      {

       sol();
      return 0;
      }


     A=mp(INF,INF);


     for (i=I;i<=n;i++)
        for (j=J;j<=m;j++)
        if (I+J!=i+j)
        {
            if (i!=I) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i-1][j]);
            if (j!=J) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i][j-1]);
        }
     for (i=I;i<=n;i++)
        for (j=J;j>0;j--)
        if (I+J!=i+j)
        {
            if (i!=I) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i-1][j]);
            if (j!=J) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i][j+1]);
        }
    for (i=I;i>0;i--)
        for (j=J;j<=m;j++)
        if (I+J!=i+j)
        {
            if (i!=I) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i+1][j]);
            if (j!=J) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i][j-1]);
        }
     for (i=I;i>0;i--)
        for (j=J;j>0;j--)
        if (I+J!=i+j)
        {
            if (i!=I) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i+1][j]);
            if (j!=J) d[i][j]=MA(d[i][j],(int)(c[i][j]=='T')+d[i][j+1]);
        }

    /* for (i=1;i<=n;i++)
     {
         for (j=1;j<=m;j++)
            cout<<d[i][j]<<" ";cout<<endl;
     }*/

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
             if (A>mp(AB(I-i)+AB(J-j)+MA(t-d[i][j],0),f[i][j]))
             {
                 A=mp(AB(I-i)+AB(J-j)+MA(t-d[i][j],0),f[i][j]);
             //    cout<<"@ "<<A.X<<" "<<i<<" "<<j<<" | "<<I<<" "<<J<<endl;
                 x=i;
                 y=j;
             }
                      } else
         {
             if (A>mp(AB(I-i)+AB(J-j)+(MA(t-d[i][j],0))*2,0))
             {
                 A=mp(AB(I-i)+AB(J-j)+(MA(t-d[i][j],0))*2,0);
               //    cout<<"# "<<A.X<<" "<<i<<" "<<j<<" | "<<I<<" "<<J<<endl;
               x=i;
                 y=j;
             }
         }
     }
   //   cout<<A.X<<endl;
   //   cout<<t<<endl;
  //    cout<<x<<" "<<y<<endl;
     t-=d[x][y];
  //   cout<<t<<endl;
     go(x,y);
     for (i=ans.size()-1;i>=0;i--)
        putchar(ans[i]);


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
