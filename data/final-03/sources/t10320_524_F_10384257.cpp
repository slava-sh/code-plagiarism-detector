#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

namespace SUFFARR
{

const int MAXN = 3000000;
int a[MAXN], na[MAXN], c[MAXN], nc[MAXN], kol[MAXN];

int sum(int x, int y, int mod)
{
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

void getSuffArr(string str) {
//    str = str + ((char)(39));
    size_t len = str.length();

    int kolc = 256;
    memset(kol, 0, sizeof(int)*kolc);
    for (int i = 0; i < len; ++i)
       kol[str[i]]++;
    for (size_t i = 1; i < kolc; ++i)
        kol[i] += kol[i-1];

    memset(a, 0, sizeof(int)*len);
    memset(na, 0, sizeof(int)*len);
    memset(c, 0, sizeof(int)*len);
    memset(nc, 0, sizeof(int)*len);

    for (int i = len - 1; i >= 0; --i) {
        a[--kol[str[i]]] = i;
        c[i] = str[i];
    }

    memset(kol, 0, sizeof(int)*kolc);
    for (int i = 0; i < len; ++i)
       kol[str[i]]++;

    for (int l = 1; l < len; l += l) {
        for (size_t i = 1; i < kolc; ++i)
            kol[i] += kol[i-1];
        for (int i = len - 1; i >= 0; --i) {
            int pos = a[i] - l;
            if (pos < 0)
                pos += len;
            na[--kol[c[pos]]] = pos;
        }
        memcpy(a, na, sizeof(int)*len);
        
        kolc = 0;
        kol[0] = 1;
        nc[a[0]] = 0;
        for (int i = 1; i < len; ++i)
        {
            if (c[a[i]] == c[a[i - 1]] &&
               (c[sum(a[i], l, len)] == c[sum(a[i-1], l, len)]))
            {
                nc[a[i]] = kolc;
                kol[kolc]++;
            }
            else
            {
                nc[a[i]] = ++kolc;
                kol[kolc] = 1;
            }
        }
        ++kolc;
        memcpy(c, nc, sizeof(int)*len);
    }

//    for (int i = 1; i < len; ++i)
//        a[i-1] = a[i];
}

int rev[MAXN];
void getLcp(const string &str, int *suffArr, int *lcp) {
    int len = str.length();
    memset(rev, 0, sizeof(int)*len);
    for (int i = 0; i < len; ++i)
    {
        rev[suffArr[i]] = i;
    }
    for (size_t i = 0; i + 1 < len; ++i)
        lcp[i] = -1;
    int st = 0;
    for (int i = 0; i < len; ++i)
    {
        int pos = rev[i];
        if (pos + 1 == len)
        {
            st = 0;
            continue;
        }

        int v1 = suffArr[pos];
        int v2 = suffArr[pos + 1];
        lcp[pos] = st;
        v1 += st;
        v2 += st;
        while (v1 < len && v2 < len && str[v1] == str[v2]) {
            lcp[pos]++;
            v1++;
            v2++;
        }

        st = std::max(0, lcp[pos] - 1);
    }
}

} // end of SUFFARR namespace

struct St {
    int pos, l, r;
    St(){}
    St(int pos, int l, int r)
        :pos(pos), l(l), r(r)
    {}
};

int main() {
    ios_base::sync_with_stdio(0);
    string s;
    //cerr << ((int)('(')) << ' ' << ((int)(')')) << "\n";

    cin >> s;
    int n = s.length();
    vector<int> ls(n+1, 0);
    for (int i = 0; i < n; ++i)
        ls[i+1] = ls[i] + ((s[i] == '(') ? 1 : -1);
    vector<int> minpref(n+1, 0), minsuff(n+1, n);
    for (int i = 0; i < n; ++i) {
        minpref[i+1] = minpref[i];
        if (ls[minpref[i+1]] > ls[i+1])
            minpref[i+1] = i+1;
    }
    for (int i = n-1; i >= 0; --i) {
        minsuff[i] = minsuff[i+1];
        if (ls[minsuff[i]] > ls[i])
            minsuff[i] = i;
    }

    vector<St> anss;
    int ans = 1000000000;
    for (int i = 0; i < n; ++i) {
        int minl = min(ls[minsuff[i]], ls[minpref[i]] + ls[n]);
        int curl = ls[n];
        minl -= ls[i];
//        if (minl > 0)
//            minl = 0;
        int v = -minl + curl - minl;
        //cout << i << ' ' << v << ' ' << curl << ' ' << minl << "\n";
        if (v < ans) {
            ans = v;
            anss.clear();
        }
        if (v == ans)
            anss.push_back(St(i, -minl, curl - minl));
    }

    SUFFARR::getSuffArr(s);
//    for (int i = 0; i < n; ++i)
//        cout << SUFFARR::a[i] << " ";
//    cout << "\n";
    vector<int> rev(n, 0);
    for (int i = 0; i < n; ++i) {
        rev[SUFFARR::a[i]] = i;
    }

    int pos = 0;
    for (int i = 1; i < (int)anss.size(); ++i) {
        St st1 = anss[pos];
        St st2 = anss[i];
        if (rev[st1.pos] > rev[st2.pos])
            pos = i;
    }

    
//    cerr << anss[pos].pos << "\n";
    int l = anss[pos].l;
    for (int i = 0; i < l; ++i)
        cout << '(';
    pos = anss[pos].pos;
    for (int i = 0; i < n; ++i) {
        char c = s[(i + pos)%n];
        if (c == '(') {
            cout << "(";
            ++l;
        }
        else {
            --l;
            //if (l < 0) {
            //    l = 0;
            //    cout << '(';
            //}
            cout << ')';
        }
    }
    while (l--)
        cout << ')';
    cout << "\n";

    return 0;
}