#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 300300;

int n, p, val[maxn], vvv[maxn], x, y;
map<int, int> mp[maxn];

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        val[x]++; val[y]++;
        vvv[x]++; vvv[y]++;
        mp[x][y]++; mp[y][x]++;
    }
    sort(vvv + 1, vvv + n + 1);
    long long answer = 0;
    for (int i = 1; i <= n; i++) {
        long long tmp = n + 1;
        long long tem = lower_bound(vvv + 1, vvv + n + 1, p - val[i]) - vvv;
        answer += tmp - tem;
        if (val[i] * 2 >= p)
            answer--;
        map<int, int>::iterator it;
        for (it = mp[i].begin(); it != mp[i].end(); it++) {
            if (val[i] + val[it->first] >= p) {
                if (val[i] + val[it->first] - it->second < p)
                    answer--;
            }
        }
    }
    printf("%I64d\n", answer / 2);
}
