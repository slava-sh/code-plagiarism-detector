#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e6+1;
typedef long long LL;
typedef pair<int ,int> St;
struct Person {
    int time, num;
    bool operator<(const Person &a) const {
        return num<a.num;
    }
}pe[maxn];

int N, P, flag[maxn], p[maxn];
LL s[maxn];
map<St, int> m;
int main()
{
    scanf ("%d%d", &N, &P);
    for (int i=1; i<=N; ++i) {
        int x, y;
        scanf ("%d%d", &x, &y);
        if (x>y) {
            swap(x, y);
        }
        ++flag[x];
        ++flag[y];
        ++m[make_pair(x,y)];
    }

    for (int i=1; i<=N; ++i) {
        p[i] = flag[i];
    }
    sort(p+1, p+N+1);
    int M = 0;
    for (int i=1; i<=N; ++i) {
        int j = i;
        while (i<N && p[i]==p[i+1]) ++i;
        pe[++M].num = p[i];
        pe[M].time = i-j+1;
    }
    LL ans = 0;
    for (int i=1; i<=M; ++i) {
        s[i] = s[i-1] + pe[i].time;
    }
    for (int i=1; i<=M; ++i) {
        if (2*pe[i].num>=P && pe[i].time>1) {
                ans += (long long)pe[i].time*(pe[i].time-1)/2;
            }
    }
    for (int l=1,r=M; l<r; ) {
        if (pe[l].num+pe[r].num>=P) {
            ans += (long long)(s[r-1]-s[l-1])*pe[r].time;
            --r;
        } else {
            ++l;
        }
    }
    for (map<St,int>::iterator i=m.begin(); i!=m.end(); ++i) {
        int x = i->first.first;
        int y = i->first.second;
        if (flag[x]+flag[y]>=P && flag[x]+flag[y]-i->second<P) {
            --ans;
        }
    }
    printf ("%I64d\n", ans);
    return 0;
}
