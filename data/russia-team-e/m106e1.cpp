#
include < iostream > #include < cstdio > #include < cstdlib > #include < algorithm > #include < vector > #include < set > #include < cstring > #include < string > #include < queue >

    #define x first# define y second# define mp make_pair# define pb push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
const int N = (int) 1e4 + 7;
const int INF = 2e9 + 5;

pair < string, int > a[N];
int kol;

void strok(string s) {
    if (s.size() == 3) {
        cout << s;
        return;
    }
    if (s.size() == 4) {
        cout << s[0] << s[1] << "-" << s[2] << s[3] << endl;
        return;
    }
    if (s.size() == 5) {
        cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4] << endl;
        return;
    }
    if (s.size() == 6) {
        cout << s[0] << s[1] << "-" << s[2] << s[3] << "-" << s[4] << s[5] << endl;
        return;
    }
    if (s.size() == 7) {
        cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4] << "-" << s[5] << s[6] << endl;
        return;
    }
}

int main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        string x;
        cin >> x >> m;
        for (int j = 0; j < m; ++j) {
            string y;
            cin >> y;
            a[kol++] = mp(x + y, x.size());
        }
    }
    sort(a, a + kol);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        bool f = 0;
        for (int j = 4; j < 9; ++j) {
            string s1 = s.substr(0, j);
            int q = upper_bound(a, a + kol, mp(s1, 0)) - a;
            if (q < kol && a[q].x == s1) {
                if (s[s1.size()] == '0')
                    continue;
                f = 1;
                cout << "+" << s1.substr(0, a[q].y) << "(" << s1.substr(a[q].y, (int) s1.size() - a[q].y) << ")";
                strok(s.substr(s1.size(), (int) s.size() - (int) s1.size()));
                break;
            }
        }
        if (!f)
            cout << "Incorrect\n";
    }
    return 0;
}
