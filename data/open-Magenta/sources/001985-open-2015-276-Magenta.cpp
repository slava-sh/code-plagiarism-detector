#include <bits/stdc++.h>
#define dout if (true) cout

using namespace std;

typedef long long ll;

char s = 'N';

int main() {
    ios::sync_with_stdio(false);
    vector<char> v;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++)
            v.push_back('L');
        v.push_back('D');
    }
    int i = 0;
    while(s != 'Y' && s != 'E' && i < v.size()) {
        cout << v[i] << endl;
        cout.flush();
        cin >> s;
        i++;
    }
}

