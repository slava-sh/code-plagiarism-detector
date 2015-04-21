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

vector<int> divs;
vector<int> t;
int res = INF;

void calc()
{
    int ans = 1;
    rep(i, t.size()) ans *= dup(t[i], 2);
    res = min(res, ans);
}

void go(int n, int k)
{
    if (k == K && n == divs.size())
    {
        calc();
    }
    if (k == K) return;
    t.push_back(1);
    go(n, k+1);
    t.pop_back();
    int q = 1;
    forn(i, n, divs.size())
    {
        q *= divs[i];
        t.push_back(q);
        go(i+1, k+1);
        t.pop_back();
    }
}

int main()
{
    cin >> N >> K;
    int bN = N;
    for (int i = 2; i*i <= bN; i++)
    {
        while (N % i == 0)
        {
            N /= i;
            divs.push_back(i);
        }
    }
    if (N != 1)
    {
        divs.push_back(N);
    }
    N = bN;
    go(0, 0);
    cout << res;
    return 0;
}
