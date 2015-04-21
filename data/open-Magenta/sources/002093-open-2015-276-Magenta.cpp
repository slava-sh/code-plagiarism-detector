#include <bits/stdc++.h>
#define dout if (true) cout

using namespace std;

typedef long long ll;

char s = 'N';

char need[4];

int main() {
    need[0] = 'U';
    need[1] = 'L';
    need[2] = 'D';
    need[3] = 'R';

    int pos = 0;
    ios::sync_with_stdio(false);
    vector<char> v;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k <= i; k++)
                v.push_back(need[pos]);
            pos = (pos+1)%4;
        }
    }
    int i = 0;
    while(s != 'Y' && s != 'E' && i < v.size()) {
        cout << v[i] << endl;
        cout.flush();
        cin >> s;
        i++;
    }
}

