#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define F first
#define S second

#define foreach(i, q) for (typeof(q.begin()) i = q.begin(); i != q.end(); ++i)

#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif // LOCAL

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int INF = int(1e9);
const int MOD = INF + 7;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    int L;
    cin >> L;
    string s;
    cin >> s;
    if (s.size() <= L) {
        cout << 1 << endl << s;
        return 0;
    }
    vi p(s.size());
    int x = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (x && s[i] != s[x])
            x = p[x - 1];
        x += (s[i] == s[x]);
        p[i] = x;
    }
    int l = (s.size() - p.back());
    bool f = 1;
    for (int i = 0; i < s.size() - l; ++i)
        if (s[i] != s[i + l])
            f = 0;
    if (f && s.size() % l == 0 && l <= L) {
        cout << "1\n";
        cout << s.substr(0, l);
        return 0;
    }
    vi tmp(3);
    for (int i = 0; i < s.size(); ++i)
        tmp[s[i] - 'a'] = 1;
    if (tmp[0] + tmp[1] + tmp[2] == 2) {
        vector<char> ans;
        if (tmp[0])
            ans.pb('a');
        if (tmp[1])
            ans.pb('b');
        if (tmp[2])
            ans.pb('c');
        cout << 2 << endl << ans[0] << endl << ans[1] << endl;
        return 0;
    }
    string s2 = "#";
    for (int l = 1; l <= min(L, (int)s.size()); ++l) {
        s2.erase((--s2.end()));
        s2 += s[l - 1];
        s2 += '#';
        p.assign(s.size(), 0);
        int x = 0;
        for (int i = 1; i < s.size(); ++i) {
            while (x && s[i] != s2[x])
                x = p[x - 1];
            x += (s[i] == s2[x]);
            p[i] = x;
        }
        int r = l;
        while (r + l - 1 < s.size() && p[r + l - 1] == l)
            r += l;
        if (r == s.size()) {
            s2.erase((--s2.end()));
            cout << 1 << endl << s2 << endl;
            return 0;
        }
    }
    s2 = "#";
    for (int l = 1; l <= min(L, (int)s.size()); ++l) {
        s2.erase((--s2.end()));
        s2 += s[l - 1];
        s2 += '#';
        p.assign(s.size(), 0);
        int x = 0;
        for (int i = 1; i < s.size(); ++i) {
            while (x && s[i] != s2[x])
                x = p[x - 1];
            x += (s[i] == s2[x]);
            p[i] = x;
        }
        int r = l;
        while (r + l - 1 < s.size() && p[r + l - 1] == l)
            r += l;
        string s3 = "#";
        for (int l2 = 1; l2 <= min(L, (int)s.size() - r); ++l2) {
            s3.erase((--s3.end()));
            s3 += s[r + l2 - 1];
            s3 += '#';
            vi p2(s.size());
            int x = 0;
            for (int i = 1; i < s.size(); ++i) {
                while (x && s[i] != s3[x])
                    x = p2[x - 1];
                x += (s[i] == s3[x]);
                p2[i] = x;
            }
            vi used(s.size() + 1);
            used[r] = 1;
            for (int z = r; z < s.size(); ++z) {
                if (!used[z])
                    continue;
                if (z + l <= s.size() && p[z + l - 1] == l)
                    used[z + l] = 1;
                if (z + l2 <= s.size() && p2[z + l2 - 1] == l2)
                    used[z + l2] = 1;
            }
            if (used[s.size()]) {
                s3.erase((--s3.end()));
                s2.erase((--s2.end()));
                cout << 2 << endl << s2 << endl << s3;
                return 0;
            }
        }
    }
    cout << "3\na\nb\nc";
    return 0;
}
