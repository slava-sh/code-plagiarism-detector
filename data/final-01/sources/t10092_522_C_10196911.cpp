#define _CRT_SECURE_NO_DEPRECATE

#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <ctime>
using namespace std;

#define sz(x) int((x).size())
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define eps 1e-9
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef pair<int, int> pii;

const int maxN = 100010;

int tests;
int m, n;
int a[maxN], b[maxN];
bool hadBadGuy;
bool ateAfterBadGay[maxN];
int t, r, ka, kb, minAtBad;

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    scanf("%d", &tests);
    for (int test = 0; test < tests; test++)
    {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = 0;
            ateAfterBadGay[i] = false;
        }
        hadBadGuy = false;
        ka = kb = 0;

        for (int req = 0; req < m - 1; req++)
        {
            scanf("%d %d", &t, &r);
            if (r == 1 && hadBadGuy == false)
            {
                hadBadGuy = true;
                for (int i = 0; i < n; i++)
                    b[i] = a[i];
                kb = ka;
            }

            if (t == 0)
            {
                ka++;
            } else
            {
                a[t - 1]--;
                if (hadBadGuy)
                    ateAfterBadGay[t - 1] = true;
            }
        }

        if (hadBadGuy == false)
        {
            for (int i = 0; i < n; i++)
                if (a[i] <= ka)
                    printf("Y");
                else
                    printf("N");
            printf("\n");
        }
        else
        {
            minAtBad = 999999999;
            for (int i = 0; i < n; i++)
                if (ateAfterBadGay[i] == false)
                    minAtBad = min(minAtBad, b[i]);

            for (int i = 0; i < n; i++)
                if ((ateAfterBadGay[i] == false && b[i] <= kb) ||
                    a[i] <= ka - minAtBad)
                    printf("Y");
                else
                    printf("N");
            printf("\n");
        }
    }

	return 0;
}

















