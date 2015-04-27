#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<map>

#define lson L,M,now<<1
#define rson M+1,R,now<<1|1

using namespace std;
int N,P;


vector<int> v[300005];
int cnt[300005];

int sum[300005<<2];

void update(int p,int L,int R,int now)
{
    if( p == L && p == R ){
        sum[now]++;
        return;
    }

    int M = (L+R)/2;
    if( p <= M )update(p,lson);
    else update(p,rson);
    sum[now] = sum[now<<1] + sum[now<<1|1];
}

int query(int l,int r,int L,int R,int now)
{
    if( l <= L && R <= r ){
        return sum[now];
    }

    int M=(L+R)/2;
    int res = 0;
    if( l <= M )res += query(l,r,lson);
    if( r >  M )res += query(l,r,rson);
    return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("pa.out","w",stdout);
    int a,b,aa,bb;
    scanf(" %d %d",&N,&P);

    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));

    for( int i = 1; i <= N; i++ ){
        scanf(" %d %d",&a,&b);
        aa = min(a,b);
        bb = max(a,b);

        v[aa].push_back(bb);
        cnt[aa]++; cnt[bb]++;
    }

    for( int i = 1; i <= N; i++ )
        sort(v[i].begin(),v[i].end());

    long long res=0;
    for( int i = N; i >= 1; i-- ){
        res += query(max(0,P-cnt[i]),N,0,N,1);
        for(int j = 0, k = 0; j < int(v[i].size()); j=k ){
            k = j + 1;
            while (k < int(v[i].size()) && v[i][k] == v[i][j])k++;
            int c = k-j;
            if( cnt[v[i][j]]+cnt[i] >= P && cnt[v[i][j]]+cnt[i]-c < P )res--;
        }
        update(cnt[i],0,N,1);
    }
    printf("%I64d\n",res);

    return 0;
}
