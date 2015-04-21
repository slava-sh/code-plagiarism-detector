#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;


#define INF 1000000000


queue<int> q;
int n, m, d1;
vector<pair<pair<int, int>, int> > v;
vector<int> s[50001];
int d[100000];


int main() {
    cin >> n >> m >> d1;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        v.push_back(make_pair(make_pair(a, b), t));
        v.push_back(make_pair(make_pair(b, a), t));
        s[b].push_back(2 * i + 1);
        s[a].push_back(2 * i);
    }
    int q1;
    cin >> q1;
    for (int k = 0; k < q1; k++) {
        int a, b;
        scanf("%d %d", &a, &b);
        for (int i = 0; i < 2 * m; i++) {
            if (v[i].first.first == a) {
                d[i] = 1;
                q.push(i);
            } else {
                d[i] = INF;
            }
        }
        int t = 0;
        while (!q.empty() && t < 1010) {
                t++;
            int x = q.front();
            q.pop();
            int g = v[x].first.second;
            for (int i = 0; i < (int)s[g].size(); i++) {
                int k = s[g][i];
                if (d[k] == INF) {
                    if (abs(v[x].second - v[k].second) <= d1) {
                        d[k] = d[x] + 1;
                        q.push(k);
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 2 * m; i++) {
            if (v[i].first.second == b) {
                ans = min(ans, d[i]);
            }
        }
        if (ans == INF) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}
