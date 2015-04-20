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
    long long s;

    int main()
    {
        freopen("che.in","r",stdin);
        freopen("che.out","w",stdout);
     cin>>n>>r;
    for (i=1;i<=n;i++) scanf("%d",&a[i]);
    k=0;
    for (i=1;i<=n;i++)
    {
    while  (a[i]>a[k+1]+r) k++;
    if (a[i]>a[k]+r) {s+=k;}
    }
    cout<<s<<endl;

        return 0;
    }
