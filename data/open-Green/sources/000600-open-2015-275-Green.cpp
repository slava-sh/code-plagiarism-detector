#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

const int INF = 1e9;

inline int dup(int a, int b)
{
    int res = a/b;
    if (res*b < a) res++;
    return res;
}

int N, K;

int go(int n, int k)
{
    if (k == K)
        return 1;
    if (k == K-1)
        return dup(n, 2);
    int res = INF;
    for (int i = 1; i*i <= n; i++)
    {
        if (n%i != 0) continue;
        res = min(res, dup(i, 2)*go(n/i, k+1));
        res = min(res, dup(n/i, 2)*go(i, k+1));
    }
    return res;
}

int main()
{
    cin >> N >> K;
    cout << go(N, 0);
    return 0;
}
