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
    string s2 = "#";
    for (int l = 1; l <= min(L, (int)s.size()); ++l) {
        s2.erase((--s2.end()));
        s2 += s[l - 1];
        s2 += '#';
        vi p(s.size());
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
            cout << "1\n";
            cout << s.substr(0, l);
            return 0;
        }
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
    cout << "3\na\nb\nc";
    return 0;
}
