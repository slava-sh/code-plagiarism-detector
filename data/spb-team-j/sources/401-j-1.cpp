#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;

class SegTree
{
    private:
        vector<int> nodes;
        int len;

    public:
        void init(vector<int> v)
        {
            int n = (int)v.size();
            len = 1;
            while (len < n)
                len *= 2;

            nodes.assign(2 * len, -1);
            for (int i = len; i < len + n; i++)
                nodes[i] = v[i - len];
            for (int i = len - 1; i > 0; i--)
                nodes[i] = max(nodes[2 * i],
                               nodes[2 * i + 1]);
        }

        int getmax(int l, int r)
        {
            l += len;
            r += len;

            int ans = (int)1e9;;
            while (r > l)
            {
                if (l % 2 == 1)
                {
                    ans = min(ans, nodes[l]);
                    l++;
                }
                if (l == r)
                    break;

                if (r % 2 == 0)
                {
                    ans = min(ans, nodes[r]);
                    r--;
                }

                l >>= 1;
                r >>= 1;
                assert(l > 0);
                assert(r > 0);
            }

            ans = min(ans, nodes[l]);
            return ans;
        }

        void print()
        {
            for (int i = 1; i < 2 * len; i++)
                cerr << nodes[i] << ' ';
            cerr << endl;
        }
};

void solve(int n)
{
    int h;
    cin >> h;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);

    vector<int> l(n);
    vector<ll> prefsum(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefsum[i + 1] = prefsum[i] + v[i];

    for (int i = 0; i < n; i++)
    {
        l[i] = i - v[i] + 1;
        if (l[i] > i)
            l[i] = i;
    }

  //  for (int i = 0; i < n; i++)
  //      cerr << l[i] << ' ';
  //  cerr << endl;

    SegTree Data;
    Data.init(l);
  //  Data.print();

    ll ans = (ll)1e18;
    bool found = false;

    for (int i = 0; i <= n - h; i++)
    {
        int res = Data.getmax(i, i + h - 1);

        if (res >= i)
        {
            ll cur = prefsum[i + h] - prefsum[i];
            cur -= (ll)h * (ll)(h + 1) / 2LL;
            if (-cur < ans)
                ans = -cur, found = true;
        }
    }

    if (found)
        cout << ans << endl;
    else
        cout << -1 << endl;
}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("seq.in", "rt", stdin);
    freopen("seq.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
