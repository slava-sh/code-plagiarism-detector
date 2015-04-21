/**
 * “¿Ÿ»Ã
**/

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <memory.h>
#include <stack>
#include <queue>
#include <deque>
#include <assert.h>


using namespace std;

int l;
string s;
long long MOD = 1e+9 + 7;
long long MAG = 7;
long long h[20001];
long long mpow[20001];
int slen;

long long strhash(int i, int j)
{
    if(i == 0)
        return h[j];
    return (h[j] - h[i - 1] * mpow[j - i + 1] + MOD) % MOD;
}

bool try_1()
{
    for(int i = 1; i <= l; ++i)
    {
        if(s.length() % i != 0)
            continue;
        int j = 0;
        for(; j + i < (int)s.length(); ++j)
        {
            if(s[j] != s[j + i])
                break;
        }
        if(j + i == (int)s.length())
        {
            cout << 1 << endl;
            cout << s.substr(0, i) << endl;
            return true;
        }
    }
    return false;
}

bool go_2(int as, int alen, int bs, int blen, bool st, int pos)
{
    bool exit_now = true;
    for(int x = 0; x * alen <= slen - pos; ++x)
    {
        if((slen - pos - x * alen) % blen == 0)
        {
            exit_now = false;
            break;
        }
    }
    if(exit_now)
        return false;

    if(pos == slen)
    {
        if(st)
        {
            cout << 2 << endl;
            cout << s.substr(as, alen) << endl;
            cout << s.substr(bs, blen) << endl;
        }
        return true;
    }

    if(rand() % 2)
    {
        if(pos + alen <= slen)
        {
            if(strhash(pos, pos + alen - 1) == strhash(as, as + alen - 1))
            {
                if(go_2(as, alen, bs, blen, st, pos + alen))
                    return true;
            }
        }
        if(pos + blen <= slen)
        {
            if(strhash(pos, pos + blen - 1) == strhash(bs, bs + blen - 1))
            {
                if(go_2(as, alen, bs, blen, st, pos + blen))
                    return true;
            }
        }
    }
    else
    {
        if(pos + blen <= slen)
        {
            if(strhash(pos, pos + blen - 1) == strhash(bs, bs + blen - 1))
            {
                if(go_2(as, alen, bs, blen, st, pos + blen))
                    return true;
            }
        }
        if(pos + alen <= slen)
        {
            if(strhash(pos, pos + alen - 1) == strhash(as, as + alen - 1))
            {
                if(go_2(as, alen, bs, blen, st, pos + alen))
                    return true;
            }
        }
    }

    return false;
}

bool go_1(int as, int alen, int b, bool st, int pos)
{
    bool exit_now = true;
    for(int x = 0; x * alen <= slen - pos; ++x)
    {
        if((slen - pos - x * alen) % b == 0)
        {
            exit_now = false;
            break;
        }
    }
    if(exit_now)
        return false;

    if(pos == slen)
    {
        assert(false);
    }

    if(pos + alen <= slen)
    {
        if(strhash(pos, pos + alen - 1) == strhash(as, as + alen - 1))
        {
            if(go_1(as, alen, b, st, pos + alen))
                return true;
        }
    }

    if(pos + b <= slen)
    {
        return go_2(as, alen, pos, b, st, pos + b);
    }
    return false;
}

bool go_0(int a, int b, bool st)
{
    if(rand() % 2)
        swap(a, b);
    if(0 + a <= slen)
    {
        if(go_1(0, a, b, st, a))
            return true;
    }
    if(0 + b <= slen)
    {
        if(go_1(0, b, a, st, b))
            return true;
    }
    return false;
}

bool try_2()
{
    for(int i = 1; i <= l; ++i)
    {
        for(int j = i; j <= l; ++j)
        {
            if(go_0(i, j, false))
            {
                go_0(i, j, true);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    srand(1303);
    freopen("input.txt", "r", stdin);

    cin >> l;
    cin >> s;

    slen = s.length();

    h[0] = s[0] - 'a' + 1;
    mpow[0] = 1;
    for(int i = 1; i < slen; ++i)
    {
        h[i] = (h[i - 1] * MAG + (s[i] - 'a' + 1)) % MOD;
        mpow[i] = (mpow[i - 1] * MAG) % MOD;
    }

    bool was[3];
    was[0] = was[1] = was[2] = false;
    for(auto c : s)
        was[c - 'a'] = true;

    int c = 0;
    c += was[0];
    c += was[1];
    c += was[2];

    if(c == 1)
    {
        cout << 1 << endl;
        for(char i = 0; i < 3; ++i)
            if(was[(int)i])
                cout << (char)(i + 'a') << endl;
        return 0;
    }

    if(try_1())
        return 0;

    if(c == 2)
    {
        cout << 2 << endl;
        for(char i = 0; i < 3; ++i)
            if(was[(int)i])
                cout << (char)(i + 'a') << endl;
        return 0;
    }

    if(try_2())
        return 0;

    if(c == 3)
    {
        cout << 3 << endl;
        for(char i = 0; i < 3; ++i)
            if(was[(int)i])
                cout << (char)(i + 'a') << endl;
        return 0;
    }

    return 0;
}
