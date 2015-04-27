#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = 200500;
const int A = 26;
const char DOLLAR = 'a' + A;

char s[N], t[N], pat[2 * N];
int slen, tlen, patlen;
char trans_left[A + 1], trans_right[A + 1];
int z[2 * N];

bool possible[N][A];
int res[N];
int res_size;

char trans(int ind)
{
    if (ind <= tlen)
        return trans_left[pat[ind] - 'a'];
    return trans_right[pat[ind] - 'a'];
}

void calc_z()
{
    memset(z, 0, sizeof(z));

    int l = 0, r = -1;
    for (int i = 1; i < patlen; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < patlen && trans(z[i]) == trans(i + z[i]))
            z[i]++;
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

void mark(char x, char y)
{
    for (int i = 0; i < A; i++)
        trans_left[i] = trans_right[i] = '?';
    trans_left[DOLLAR - 'a'] = trans_right[DOLLAR - 'a'] = DOLLAR;

    trans_left[x - 'a'] = x;
    trans_left[y - 'a'] = y;

    trans_right[x - 'a'] = y;
    trans_right[y - 'a'] = x;

    calc_z();

    for (int i = tlen + 1; i < patlen; i++)
        if (z[i] == tlen)
            possible[i - tlen - 1][x - 'a'] = possible[i - tlen - 1][y - 'a'] = true;
}

int slow()
{
    string X = s;
    string Y = t;
    int cnt = 0;

    for (int i = 0; i + (int) Y.length() <= (int) X.length(); i++)
    {
        bool bad = false;
        vector<int> who(A, -1);
        for (int j = 0; j < (int) Y.length(); j++)
        {
            int from = Y[j] - 'a';
            int to = X[i + j] - 'a';
            if (who[from] == -1)
                who[from] = to;
            if (who[from] != to)
                bad = true;
        }
        if (!bad)
            cnt++;
    }

    return cnt;
}

void solve()
{
    scanf("%d%d", &slen, &tlen);
    scanf("%s%s", s, t);

    strcpy(pat, t);
    patlen = tlen;
    pat[patlen++] = DOLLAR;
    strcpy(pat + patlen, s);
    patlen += slen;

    for (char x = 'a'; x <= 'z'; x++)
        for (char y = x; y <= 'z'; y++)
            mark(x, y);

    for (int i = 0; i < slen; i++)
    {
        int cnt = 0;
        for (int j = 0; j < A; j++)
            if (possible[i][j])
                cnt++;
        if (cnt == A)
            res[res_size++] = i;
    }

    //cout << slow() << endl;
    /*
    if (slow() != res_size)
    {
        puts("FAIL");
        return;
    }
    */

    printf("%d\n", res_size);
    for (int i = 0; i < res_size; i++)
        printf("%d ", res[i] + 1);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}
