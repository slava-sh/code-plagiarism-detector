#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> Pi;
#define Px first
#define Py second
const int maxn = 3e5 + 50;
int n, m, First[maxn], Second[maxn], num[maxn];
LL res; int checked[maxn], ti;
vector<int> p[maxn];
struct data
{
    int key, id;
    data(){}
    data(int _key, int _id)
    {
        key = _key; id = _id;
    }
    friend bool operator <(const data &A, const data &B)
    {
        return A.key < B.key;
    }
}besused[maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        besused[i].id = i;
        int x, y; scanf("%d %d", &x, &y); 
        ++besused[x].key; ++besused[y].key;
        First[i] = x; Second[i] = y;
        p[x].push_back(i); p[y].push_back(i);
    }
    sort(besused + 1, besused + 1 + n);
    for (int i = 1; i <= n; ++i) num[besused[i].id] = i;
    for (int i = 1; i <= n; ++i) {
        int ite = lower_bound(besused + 1, besused + 1 + n, data(m - besused[i].key, -1)) - besused;
        ite = max(i + 1, ite);
        res += (LL)(n - ite + 1);
        
        ++ti; queue<int> q;
        for (int j = 0; j < (int)p[besused[i].id].size(); ++j) {
            int now = p[besused[i].id][j];
            
            if (checked[now] == ti) continue;
            checked[now] = ti;
            {
                int ind = num[First[now]];
                if (ind >= ite) {
                    if (besused[ind].key < m - besused[i].key) ++res;
                    --besused[ind].key;
                    if(besused[ind].key < m - besused[i].key) --res;
                    q.push(ind);
                }
            }
            
            {
                int ind = num[Second[now]];
                if (ind >= ite) {
                    if (besused[ind].key < m - besused[i].key) ++res;
                    --besused[ind].key;
                    if(besused[ind].key < m - besused[i].key) --res;
                    q.push(ind);
                }
            }
        }
        while (!q.empty()) {
                int tmp = q.front(); q.pop(); ++besused[tmp].key;
        }
    }
    cout << res << endl;
    return 0;
}
