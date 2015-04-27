#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const li lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif // DEBUG

vector< int > dish;
vector< char > run_out;

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int t;
    cin >> t;
    while (t)
    {
        --t;
        int m, k;
        scanf ("%d%d", &m, &k);
        //dout (m << ' ' << k << endl);
        dish.assign (k + 1, 0);
        run_out.assign (k, 0);
        for (int i = 0 ; i < k ; ++i)
        {
            scanf ("%d", &dish[i + 1]);
        }
        int check = 0, before = 0;
        bool was = false;
        bool never_mind = false;
        for (int i = 0 ; i < m - 1 ; ++i)
        {
            int cur_dish, pleased;
            scanf ("%d%d", &cur_dish, &pleased);
            if (!was && cur_dish == 0 && pleased == 0)
            {
                ++before;
            }
            else if (!was && pleased == 1)
            {
                was = true;
                for (int j = 1 ; j <= k ; ++j)
                {
                    if (dish[j] <= 0)
                    {
                        never_mind = true;
                        check = before;
                        break;
                    }
                    else if (dish[j] <= before)
                    {
                        run_out[j - 1] = true;
                    }
                }
            }
            if (was && cur_dish == 0)
            {
                ++check;
            }
            else if (was && run_out[cur_dish - 1])
            {
                run_out[cur_dish - 1] = false;
            }
            --dish[cur_dish];
        }
        if (never_mind)
        {
            //dout ("never mind\n");
            for (int i = 0 ; i < k ; ++i)
            {
                if (dish[i + 1] <= check)
                {
                    printf ("Y");
                }
                else
                {
                    printf ("N");
                }
            }
            printf ("\n");
            continue;
        }
        int used = INF;
        for (int i = 0 ; i < k ; ++i)
        {
            if (run_out[i] && used > dish[i + 1])
            {
                used = dish[i + 1];
            }
        }
        //dout (used << endl);
        if (used == INF)
        {
            for (int i = 0 ; i < k ; ++i)
            {
                if (dish[i + 1] <= before)
                {
                    printf ("Y");
                }
                else
                {
                    printf ("N");
                }
            }
            printf ("\n");
        }
        else
        {
            check += before - used;
            for (int i = 0 ; i < k ; ++i)
            {
                if (run_out[i] || dish[i + 1] <= check)
                {
                    printf ("Y");
                }
                else
                {
                    printf ("N");
                }
            }
            printf ("\n");
        }
        dish.clear ();
        run_out.clear ();
    }
    return 0;
}
