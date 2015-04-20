#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>

#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>

using namespace std;

#define EPS 1e-9
#define MAXN 100001
#define MOD 1000000007
#define mp(a, b) make_pair(a, b)

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front

typedef long long int64;
typedef long double real;
typedef pair<int, int> pii;

#define TASK "numbers"

int n;
set<int> T;

int P[10];
bool city[1000];
bool oper[100000];

int sznum(int num) {
    if (num == 0) {
        return 1;
    }

    int res = 0;
    while (num) {
        num /= 10;
        ++res;
    }

    return res;
}

bool check(int c, int o, int cpo) {
    return city[c] && oper[o] && T.find(cpo) != T.end();
}

void parse(int pref, int num) {
    int t = pref;

    int op = 0;
    int sz = 0;
    while (pref > 999 || !check(pref, op, t)) {
        op = (pref % 10) * P[sz++] + op;
        pref /= 10;
    }

    printf("+%d(%d)", pref, op);
    switch(sznum(num)) {
        case 3:
            printf("%03d", num);
        break;

        case 4:
            printf("%02d-%02d", num / 100, num % 100);
        break;

        case 5:
            printf("%03d-%02d", num / 100, num % 100);
        break;

        case 6:
            printf("%02d-%02d-%02d", num / 10000, (num / 100) % 100, num % 100);
        break;

        case 7:
            printf("%03d-%02d-%02d", num / 10000, (num / 100) % 100, num % 100);
        break;
    }

    printf("\n");
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("log.txt", "w", stderr);
#else
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    
    P[0] = 1;
    for (int i = 1; i < 10; ++i) {
        P[i] = P[i - 1] * 10;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int c, k;
        scanf("%d %d", &c, &k);
        city[c] = true;
        for (int j = 0; j < k; ++j) {
            int num;
            scanf("%d", &num);
            oper[num] = true;
            T.insert(c * P[sznum(num)] + num);
        }
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;

        if (s[0] == '0') {
            printf("Incorrect\n");
            continue;
        }

        int pref = 0;
        int p = 0;

        bool res = false;
        while (p < 8) {
            pref = pref * 10 + (s[p] - '0');
            ++p;
            if (T.find(pref) != T.end() && s[p] != '0') {
                res = true;
                break;
            }
        }

        if (res == false) {
            printf("Incorrect\n");
            continue;
        }

        parse(pref, atoi(s.substr(p).c_str()));
    }
}