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
    str = cod;
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
   // for (int i = 0; i < len; i++)
       // cerr << a[i].first << " " << a[i].second << "\n";

    cin >> kol;
    for (int qi = 0; qi < kol; qi++) {
        cin >> cod;
        str = "";
        for (int je = 0; je < 3; je++)
            str += cod[je];
        for (int je = 3; je < 8; je++) {
            str += cod[je];
            //cerr << str << "\n";

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


            if (a[r].first != str && je == 7) {
                cout << "Incorrect\n";
                fail = true;
                break;
            }
            if (a[r].first != str)
                continue;

            if (cod[a[r].first.length()] == '0' && je == 7) {
                cout << "Incorrect\n";
                continue;
            }

            if (cod[a[r].first.length()] == '0') {
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
            break;
        }

    }

    return 0;
}
