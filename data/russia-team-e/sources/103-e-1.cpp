#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

pair <string, int> a[20000];
int len;
string cod, str;
int kol, l, r, m, n;
bool fail;

void doit (int p) {
    if (p == 4)
        cout << str[4] << str[5] << str[6] << "-" << str[7] << str[8] << "-" << str[9] << str[10] << "\n";
    if (p == 5)
        cout << str[5] << str[6] << "-" << str[7] << str[8] << "-" << str[9] << str[10] << "\n";
    if (p == 6)
        cout << str[6] << str[7] << str[8] << "-" << str[9] << str[10] << "\n";
    if (p == 7)
        cout << str[7] << str[8] << "-" << str[9] << str[10] << "\n";
    if (p == 8)
        cout << str[8] << str[9] << str[10] << "\n";
}

int main() {
    freopen("numbers.in", "r", stdin);
    freopen("numbers.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cod;
        cin >> kol;
        for (int j = 0; j < kol; j++) {
            cin >> str;
            a[len++] = make_pair(cod + str, cod.length());
        }
    }

    sort(a, a + len);
    //for (int i = 0; i < len; i++)
        //cerr << a[i].first << " " << a[i].second << "\n";

    cin >> kol;
    for (int i = 0; i < kol; i++) {
        cin >> str;
        l = 0;
        r = len;
        while (r - l > 1) {
            m = (r + l) / 2;
            if (a[m].first > str)
                r = m;
            else
                l = m;
        }
        fail = false;
        r = l;

        for (int i = 0; i < a[r].first.length(); i++)
            if (a[r].first[i] != str[i]) {
                cout << "Incorrect\n";
                fail = true;
                break;
            }
        if (fail) continue;

        if (str[a[r].first.length()] == '0') {
            cout << "Incorrect\n";
            continue;
        }

        cout << "+";
        for (int i = 0; i < a[r].second; i++)
            cout << str[i];
        cout << "(";
        for (int i = a[r].second; i < a[r].first.length(); i++)
            cout << str[i];
        cout << ")";

        doit(a[r].first.length());

    }

    return 0;
}
