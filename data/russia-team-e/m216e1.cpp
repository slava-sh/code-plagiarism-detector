#
include < iostream > #include < vector > #include < algorithm > #include < queue > #include < map > #include < set > #include < stack > #include < string >
    typedef long long ll;

using namespace std;

map < int, set < int > > mp;

int main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int c, k;
        cin >> c >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            mp[c].insert(v);
        }
    }
    int m;
    cin >> m;
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        int kdstr = 0;
        bool fl = 0;
        for (int j = 0; j < 3; j++) {
            if (fl) {
                break;
            }
            kdstr *= 10;
            kdstr += s[j] - '0';
            if (mp.find(kdstr) != mp.end()) {
                int kdreg = 0;
                for (int q = j + 1; q < j + 3; q++) {
                    kdreg *= 10;
                    kdreg += s[q] - '0';
                }
                for (int q = j + 3; q < j + 6; q++) {
                    if (fl) {
                        break;
                    }
                    kdreg *= 10;
                    kdreg += s[q] - '0';
                    if (mp[kdstr].find(kdreg) != mp[kdstr].end()) {
                        if (s[q + 1] == '0') {
                            continue;
                        }
                        fl = 1;
                        cout << "+" << kdstr << "(" << kdreg << ")";

                        if (11 - q - 1 == 3) {
                            cout << s[8] << s[9] << s[10];
                        }
                        if (11 - q - 1 == 4) {
                            cout << s[7] << s[8] << "-" << s[9] << s[10];
                        }
                        if (11 - q - 1 == 5) {
                            cout << s[6] << s[7] << s[8] << "-" << s[9] << s[10];
                        }
                        if (11 - q - 1 == 6) {
                            cout << s[5] << s[6] << "-" << s[7] << s[8] << "-" << s[9] << s[10];
                        }
                        if (11 - q - 1 == 7) {
                            cout << s[4] << s[5] << s[6] << "-" << s[7] << s[8] << "-" << s[9] << s[10];
                        }
                        cout << endl;
                    }
                }
            }
        }
        if (!fl) {
            cout << "Incorrect" << endl;
        }
    }
    return 0;
}
