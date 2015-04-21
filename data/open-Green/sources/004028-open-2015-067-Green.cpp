#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
const int MAXS = 100;

LL n;
int k;
int where[MAXS];
LL there[MAXS];

int main() {
    srand(239147);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    cin >> k; 
    LL now = n;
    vector <LL> dvs;
    for (LL i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            dvs.puba(i);
        }
    }
    
    //assert(MAXS > szof(dvs));
    /*if (szof(dvs) >= MAXS) {
        cout << "!@#" << endl;
        return 0;
    }*/

    if (n != 1) {
        dvs.puba(n);
    }

    
    for (int i = 0; i < szof(dvs); ++i) {
        where[i] = 0;        
    }

    for (int i = 1; i < k; ++i) {
        there[i] = 1;
    }

    there[0] = now;
    now = (now + 1) / 2;
    
    //cout << now << endl;
    //int rc = 0;
    double t = 1;
    double deltat = 1.0000002;
    LL ans = now;
    for (int lk = 0; lk < 1e7; ++lk) {
        /*
        if (rc - 200 == 0) {
            rc = 0;
            if (clock() > 2.6 * CLOCKS_PER_SEC) {
                break;
            }
        }
        ++rc;*/
        int pos = rand() % szof(dvs);
        int to = rand() % (k - 1);
        if (to >= where[pos]) {
            ++to;
        }
        /*
        if (to >= k) {
            cout << "!@#" << endl;
            return 0;
        }*/
        //cout << ((there[to] + 1) / 2) << endl;
        LL newp = now / ((there[where[pos]] + 1) / 2) * ((there[where[pos]] / dvs[pos] + 1) / 2) / ((there[to] + 1) / 2) * ((there[to] * dvs[pos] + 1) / 2);
        
        /*
        if (newp == 0) {
            cout << now << endl;
            cout << pos << " " << to << " " << newp << endl;        
            for (int i = 0; i < szof(dvs); ++i) {
                cout << dvs[i] << " " << where[i] << endl;
            }
            return 0;
        }*/
        if (newp <= now || rand() / (double) RAND_MAX < exp(-1 * t * (now - newp))) {
            now = newp;
            there[where[pos]] /= dvs[pos];
            there[to] *= dvs[pos];
            /*
            if (there[where[pos]] == 0 || there[to] == 0 || dvs[pos] == 0) {
                cout << "!@#" << endl;
                return 0;
            }*/
            where[pos] = to;
            ans = min(ans, now);
        }
        t *= deltat;
    }

    cout << ans << endl;

    /*
    for (int i = 0; i < szof(dvs); ++i) {
        cout << dvs[i] << " " << where[i] << endl;
    }*/
    
    /*
    cout << clock() / (double) CLOCKS_PER_SEC << endl;
    */
    //cout << t << endl;

    return 0;
}