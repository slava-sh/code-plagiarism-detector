#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int kk[300];
int go[20020][3];
int ss[20020];
int go1[20020][3];
int ss1[20020];
bool is[20020];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int l;
    cin >> l;
    string s;
    cin >> s;
    int n = s.length();
    if (l > n) l = n;
    if (l == n) {
        cout << "1\n" << s << endl;
        return 0;
    }
    vector<int> pr;
    pr.pb(0);
    kk[s[0]]++;
    for (int i = 1; i < n; i++) {
        kk[s[i]]++;
        int j = pr[i-1];
        while (j > 0 && s[j] != s[i]) j = pr[j-1];
        if (s[j] == s[i]) j++;
        pr.pb(j);
        //cout << pr[i];
    }
    //cout << endl;
    for (int i = 1; i <= l; i++) {
        if (n % i != 0) {
            continue;
        }
        bool b = true;
        for (int j = i + i - 1; j < n; j += i) {
            if (pr[j] != j + 1 - i) b = false;
        }
        if (b) {
            cout << 1 << endl;
            for (int j = 0; j < i; j++) cout << s[j];
            return 0;
        }
    }
    if (kk['c'] == 0) {
        cout << "2\na\nb";
        return 0;
    }
    if (kk['b'] == 0) {
        cout << "2\na\nc";
        return 0;
    }
    if (kk['a'] == 0) {
        cout << "2\nb\nc";
        return 0;
    }
    for (int i = 1; i < l; i++) {
        go1[i - 1][s[i-1]-'a'] = i;
        if (i == 1) ss1[i] = 0; else ss1[i] = go1[ss1[i-1]][s[i-1]-'a'];
        for (int o = 0; o < 3; o++) go1[i][o] = go1[ss1[i]][o];
        for (int j = i; j < n;) {
            for (int o = 0; o < 3; o++) go[0][o] = 0;
            for (int t = j + 1; t < n && t - j <= l; t++) {
                go[t - j - 1][s[t-1]-'a'] = t - j;
                if (t - j == 1) ss[t - j] = 0; else ss[t - j] = go[ss[t - j - 1]][s[t-1]-'a'];
                for (int o = 0; o < 3; o++) go[t - j][o] = go[ss[t - j]][o];
                int st = 0;
                int st1 = i;
                is[t-1] = true;
                for (int p = t; p < n; p++) {
                    st1 = go1[st1][s[p]-'a'];
                    st = go[st][s[p]-'a'];
                    is[p] = false;
                    if (p - (t - 1) >= i && st1 == i && is[p - i]) is[p] = true;
                    else if (st == t - j && is[p - (t - j)]) is[p] = true;
                }
                if (is[n-1]) {
                    cout << "2\n";
                    for (int p = 0; p < i; p++) cout << s[p];
                    cout << endl;
                    for (int p = j; p < t; p++) cout << s[p];
                    cout << endl;
                    return 0;
                }
            }
            j += i;
            if (j >= n || pr[j-1] < j-i) break;
        }
    }
    cout << 3 << endl;
    cout << "a\nb\nc\n";
    return 0;
}
