#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    srand(time(0));
    while (true) {
        cout << "RLUD"[rand() & 3] << endl;
        string c;
        cin >> c;
        if (c == "Y" || c == "E") break;
    }
}
