#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
pair<int, int> p[300030];
vector<int> a[300030];
int f[300030], s[300030];

void update(int i, int v) {
    for (++i; i <= n+1; i+=i&-i) f[i] += v;
}
int get(int i) {
    int ret = 0;
    for (++i; i > 0; i-=i&-i) ret += f[i];
    return ret;
}


int main() {

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = make_pair(x, y);
        a[x].push_back(i); s[x]++;
        a[y].push_back(i); s[y]++;
    }
    for (int i = 1; i <= n; i++)
        update(s[i], 1);
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            update(s[p[a[i][j]].first], -1);
            s[p[a[i][j]].first]--;
            update(s[p[a[i][j]].first], +1);
            
            update(s[p[a[i][j]].second], -1);
            s[p[a[i][j]].second]--;
            update(s[p[a[i][j]].second], +1);
        }
        int need = k - (int)a[i].size();
        if (need <= 0) ret += n;
        else ret += n-get(need-1);
        if ((int)a[i].size() >= k) ret--;
            
        for (int j = 0; j < a[i].size(); j++) {
            update(s[p[a[i][j]].first], -1);
            s[p[a[i][j]].first]++;
            update(s[p[a[i][j]].first], +1);
            
            update(s[p[a[i][j]].second], -1);
            s[p[a[i][j]].second]++;
            update(s[p[a[i][j]].second], +1);
        }
            
    }
    
    printf("%I64d", ret/2);

    return 0;
}
