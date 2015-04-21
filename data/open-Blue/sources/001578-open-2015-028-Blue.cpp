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
    vi p(s.size());
    int x = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (x && s[i] != s[x])
            x = p[x - 1];
        x += (s[x] == s[x]);
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
        cout << "2\na\nb";
        return 0;
    }
    return 0;
}
