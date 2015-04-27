#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define FILE freopen("../data.in","r",stdin)
#define REP(i,n) for(int i=0; i<(n); i++)
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin(); it!=(a).end(); it++)

const int N = 100010;

int pre[N];
bool ans[N];

char op[N];
int id[N];

struct Node {
    int l, r;
    int id;
    
    Node() {}
    Node(int l, int r, int id)
    :l(l), r(r), id(id) {}
    
    bool operator < (const Node &a) const {
        return l < a.l || (l == a.l && r > a.r);
    }
};

vector<Node> p;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    memset(pre, 0, sizeof(pre));
    memset(ans, true, sizeof(ans));
    for (int i = 1; i <= m; i++) {
        char str[2];
        scanf("%s%d", str, &id[i]);
        op[i] = *str;
        ans[id[i]] = false;
        if (op[i] == '+') {
            pre[id[i]] = i;
        } else {
            p.push_back(Node(pre[id[i]], i, id[i]));
            pre[id[i]] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
        if (pre[i] != 0)
            p.push_back(Node(pre[i], m + 1, i));
    sort(p.begin(), p.end());
    int x = p[0].id;
    int r = p[0].r;
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i].r > r) {
            if (p[i].id != x) {
                x = -1;
                break;
            } else
                r = p[i].r;
        }
    }
    if (x != -1)
        ans[x] = true;
    
    cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += ans[i];
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        if (ans[i])
            printf("%d ", i);
    return 0;
}
