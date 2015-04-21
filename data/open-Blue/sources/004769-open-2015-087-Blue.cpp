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
int go[10010][3];
int ss[10010];
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
    int l, l2;
    cin >> l;
    l2 = l;
    string s;
    cin >> s;
    int n = s.size();
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
        pr[i] = j;
        //cout << pr[i];
    }
    //cout << endl;
    return 0;
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
    if (kk['a'] == 0) {
        cout << "2\nb\nc";
        return 0;
    }
    if (kk['b'] == 0) {
        cout << "2\na\nc";
        return 0;
    }
    if (kk['c'] == 0) {
        cout << "2\na\nb";
        return 0;
    }
    for (int i = 1; i < l; i++) {
        go1[i - 1][s[i-1]-'a'] = i;
        if (i == 1) ss1[i] = 0; else ss1[i] = go1[ss1[i-1]][s[i-1]-'a'];
        //cout << "go ";
        //for (int o = 0; o < 3; o++) cout << go1[i-1][o] << " ";
        //cout << endl;
        //cout << "ss[" << i << "] = " << ss1[i] << endl;
        for (int o = 0; o < 3; o++) go1[i][o] = go1[ss1[i]][o];
        for (int j = i; j < n;) {
            for (int o = 0; o < 3; o++) go[0][o] = 0;
            for (int l = j + 1; l < n && l - j <= l2; l++) {
                go[l - j - 1][s[l-1]-'a'] = l - j;
                if (l - j == 1) ss[l - j] = 0; else ss[l - j] = go[ss[l - j - 1]][s[l]-'a'];
                for (int o = 0; o < 3; o++) go[l - j][o] = go[ss[l - j]][o];
                //cout << go[0][0] << " " << go[0][1] << " " << go[0][2] << " " << go[1][0] << " " << go[1][1] << " " << go[1][2] << endl;
                int st = 0;
                int st1 = i;
                // cout << i << " " << j << " " << l << endl;
                is[l-1] = true;
                for (int p = l; p < n; p++) {
                    st1 = go1[st1][s[p]-'a'];
                    st = go[st][s[p]-'a'];
                    is[p] = false;
                    if (p - (l - 1) >= i && st1 == i && is[p - i]) is[p] = true;
                    else if (st == l - j && is[p - (l - j)]) is[p] = true;
                    //cout << p << " " << st << " " << st1 << " " << is[p] << endl;
                }
                if (is[n-1]) {
                    cout << "2\n";
                    for (int p = 0; p < i; p++) cout << s[p];
                    cout << endl;
                    for (int p = j; p < l; p++) cout << s[p];
                    cout << endl;
                    return 0;
                }
            }
            j += i;
            if (j >= n || pr[j-1] < i) break;
        }
    }
    cout << 3 << endl;
    cout << "a\nb\nc\n";
    return 0;
}
