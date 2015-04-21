#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#define forauto(a, b) for (auto a = b.begin(); a != b.end(); ++a)
#define N 50001

using namespace std;

queue<pair<int, int>> q;
int A[N], B[N], t[N];
int da[N], db[N], a, b, d;
vector<int> o[N];

int g(int a)
{
    return a >= -d && a <= d;
}

bool bfs()
{
    int a = q.front().first, _v = q.front().second, d, v;
    q.pop();
    if (A[a] == _v)
        v = B[a], d = da[a];
    else
        v = A[a], d = db[a];
    if (v == b)
    {
        cout << d << '\n';
        return 1;
    }
    forauto(i, o[v])
    {
        if (!g(t[a] - t[*i]))
            continue;
        if (A[*i] == v)
        {
            if (!da[*i])
                da[*i] = d + 1, q.push(make_pair(*i, A[*i]));
        }
        else
            if (!db[*i])
                db[*i] = d + 1, q.push(make_pair(*i, B[*i]));
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> t[i];
        A[i] = a, B[i] = b;
        o[a].push_back(i);
        o[b].push_back(i);
    }
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < m; ++j)
//            if (i != j && g(t[i] - t[j]))
//                if (A[i] == B[j] || A[i] == A[j])
//                    neia[i].push_back(j);
//                else if (B[i] == B[j] || B[i] == A[j])
//                    neib[i].push_back(j);
    int Q;
    cin >> Q;
    while (Q--)
    {
        cin >> a >> b;
        memset(da, 0, sizeof(da));
        memset(db, 0, sizeof(db));
        forauto(i, o[a])
            if (A[*i] == a)
                q.push(make_pair(*i, a)), da[*i] = 1;
            else
                q.push(make_pair(*i, a)), db[*i] = 1;
        while (q.size())
            if (bfs())
                goto found;
        if (1)
            cout << -1 << '\n';
        else
            found:;
        while (q.size())
            q.pop();
    }
    return 0;
}
