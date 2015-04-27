#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>

#define mp make_pair
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

// globals starts here
const int MAX_K = 100050;

int a[MAX_K];
bool e[MAX_K];
bool rest[MAX_K];
int tt[MAX_K];

int main()
{
#ifdef DEBUGAGA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
#endif

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int tc = 0; tc < tests; ++tc)
    {
        int m, k;
        cin >> m >> k;
        ZERO(e);
        ZERO(rest);

        for (int i = 0; i < k; ++i)
        {
            cin >> a[i];
        }

        int disapp_index = -1;
        for (int i = 0; i < m - 1; ++i)
        {
            int r;
            cin >> tt[i] >> r;

            if (r == 1 && disapp_index == -1)
            {
                disapp_index = i;
            }

            if (disapp_index != -1 && tt[i] > 0)
            {
                rest[tt[i] - 1] = true;
            }
        }

        int unknown = 0;
        for (int i = 0; i < m - 1; ++i)
        {
            int t = tt[i];

            if (i == disapp_index)
            {
                int mi = INT_MAX;
                for (int j = 0; j < k; ++j)
                {
                    if (!rest[j] && mi > a[j])
                    {
                        mi = a[j];
                    }

                    if (!rest[j] && a[j] - unknown <= 0)
                    {
                        e[j] = true;
                    }
                }
                unknown -= mi;
            }

            if (t == 0)
            {
                ++unknown;
            }
            else
            {
                --a[t - 1];
            }
        }

        for (int j = 0; j < k; ++j)
        {
            if (e[j] || a[j] - unknown <= 0)
            {
                cout << "Y";
            }
            else
            {
                cout << "N";
            }
        }
        cout << endl;
    }

    return 0;
}
