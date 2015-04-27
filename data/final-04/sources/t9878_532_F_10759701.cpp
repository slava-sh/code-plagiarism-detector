#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
const int K = 30;
void calc(bool here[N], string s, string t, char c) {
    vector <int> a;
    int m = t.size();
    int n = s.size();
    int prev = -1, fir = -1;
    vector <int> r, lab(n + 1);
    r.assign(n, -1);

    for (int i = 0; i < m; ++i)
        if (t[i] == c) {
            if (fir == -1)
                fir = i;
            if (prev != -1)
                a.push_back(i - prev);
            prev = i;
        }
    vector <int> chars[K];
    for (int i = 0; i < n; ++i)
        chars[s[i]].push_back(i);
    int sta = a.size();
    if (a.size() == 0) {
        for (int i = 0; i < n; ++i)
            r[i] = i;
    } else {
        int cnSp = N;
        vector <int> ind;
        for (int i = 0; i < sta; ++i) ind.push_back(-N);
        for (int i = 0; i < K; ++i) {
            a.push_back(cnSp++);
            ind.push_back(-N);
            for (int j = 1; j < chars[i].size(); ++j) {
                a.push_back(chars[i][j] - chars[i][j - 1]);
                ind.push_back(chars[i][j - 1]);
            }
        }
        //for (int i = 0; i < a.size(); ++i) cout << a[i] << endl;

        vector<int> pi(a.size());
        for (int i = 1; i< a.size(); ++i) {
            int j = pi[i - 1];
            while (j > 0 && a[i] != a[j])
                j = pi[j - 1];
            if (a[i] == a[j])  ++j;
            pi[i] = j;
        }

        for (int i = 0; i < a.size(); ++i)
            if (pi[i] == sta) {
                int lef = i - sta + 1;
                lef = ind[lef];
                r[lef] = ind[i] + a[i];
            }
    }

    for (int i = 0; i < K; ++i)
        for (int j = 0; j < chars[i].size(); ++j)
            if (r[chars[i][j]] != -1) {;
                int prev = (j == 0 ? -1 : chars[i][j - 1]) + 1;
                int nx = (j + sta + 1 == chars[i].size() ? n : chars[i][j + sta + 1]);

                int l1 = prev, r1 = chars[i][j];
                int l2 = r[chars[i][j]] - m + 1, r2 = nx - m;
                //cerr << " l1 r1 " << l1 << " " << r1 << endl;
                //cerr << " l1 r1 " << l2 << " " << r2 << endl;

                /*l1 = max(l1, l2);
                r1 = min(r1, r2);
                if (l1 <= r1) {
                    lab[l1]++;
                    lab[r1 + 1]--;
                }*/
                int p = chars[i][j];
                int st = p - fir;
                if (st >= prev && st + m <= nx)
                    here[st] = true;
            }
    /*int cr = 0;
    for (int i = 0; i < n; ++i) {
        cr += lab[i];
        if (cr > 0) here[i] = true;
    }*/
}

char ss[N], tt[N];
int n, m;
bool pos[K][N];

int main() {
    scanf("%d%d%s%s", &n, &m, ss, tt);
    string s(ss);
    string t(tt);
    int useAl[K] = {0};
    for (int i = 0; i < K; ++i)
        useAl[i] = -1;

    for (int i = 0; i < n; ++i)
        s[i] -= 'a';
    for (int i = 0; i < m; ++i)
        t[i] -= 'a';

    for (int i = 0; i < m; ++i)
        useAl[t[i]] = i;
    for (int i = 0; i < K; ++i)
        if (useAl[i] != -1) {
            calc(pos[i], s, t, i);
            //cout << "i = " << i << " : "; for (int j = 0; j < n; ++j) cout << pos[i][j] << " ";cout << endl;
        }

    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        bool yes = true;
        for (int j = 0; j < K; ++j)
            if (useAl[j] != -1)
                yes &= pos[j][i];
        if (yes) {
            int was[K] = {0};
            bool er = false;
            for (int j = 0; j < K; ++j)
                was[j] = -1;

            for (int j = 0; j < K; ++j)
                if (useAl[j] != -1) {
                    int c = s[i + useAl[j]];
                    if (j == c) {
                        er |= was[j] != -1;
                        was[j] = j;
                        continue;
                    }
                    er |= (was[j] != -1 && was[j] != c);
                    was[j] = c;

                    er |= (was[c] != -1 && was[c] != j);
                    was[c] = j;
                }
            if (!er)
                ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i] + 1);
    /*
    4 4
    aaaa
    aaaa
    */
    return 0;
}
