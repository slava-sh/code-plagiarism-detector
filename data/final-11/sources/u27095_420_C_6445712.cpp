#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define forr(i,a,b) for(int i = (a); i <= (b); ++i)

typedef long long ll;

const int N = 3 * 100111;
vector< vector<int> > adj;
int bl[N]; // bug level
int hbl[N]; // histo
int shbl[N];
int dbl[N];

int main()
{
#ifdef my_env_def
    freopen ("out.txt","w",stdout);
    freopen("in.txt","r",stdin);
#endif

    int n,p;
    cin >> n >> p;
    adj.resize(n);
    int a,b;
    rep(i,n)
    {
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        bl[a]++;
        bl[b]++;
    }

    rep(i,n)
        hbl[bl[i]]++;

    shbl[n-1] = hbl[n-1];
    for (int i = n-2; i >= 0; --i)
        shbl[i] = hbl[i] + shbl[i+1];

    ll ans = 0;
    int cans;
    rep(i,n)
    {
        int pm = p - bl[i];
        if (pm <= 0)
            ans += n-1;
        else
        {
            cans = shbl[pm];
            if (bl[i] >= pm)
                cans--;

            rep(j,adj[i].size())
                dbl[adj[i][j]]--;

            rep(j,adj[i].size())
            {
                int v = adj[i][j];
                if (bl[v] >= pm && bl[v] + dbl[v] < pm)
                    --cans;

                dbl[v] = 0; // zero
            }

            ans += cans;
        }
    }

    cout << ans / 2 << "\n";

#ifdef my_env_def
    fclose(stdout);
#endif
    return 0;
}