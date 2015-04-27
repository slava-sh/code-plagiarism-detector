#include <iostream>
#include <sstream>
#include <memory.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
using namespace std;

const int SIZE = 501;
long long D[SIZE][SIZE];
long long C[SIZE];
long long F[SIZE];
long long MOD;
long long calc(long long k, long long l) {
    if (k < 0 || l < 0)
        return 0;
    if (D[k][l] == -1) {
        D[k][l] = calc(k - 2, l) * C[k] +
                  calc(k, l - 1) * k * l +
                  calc(k + 2, l - 2) * C[l];

        D[k][l] %= MOD;

    }
    return D[k][l];
}

int main()
{
    memset(D, -1, sizeof(D));
    memset(C, 0, sizeof(C));

    int n, m;
    string s;
    cin >> n >> m >> MOD;
    int left[SIZE];

    for(int i = 0; i < n; i++)
        left[i] = 2;

    C[0] = 0;
    D[0][1] = 0;
    D[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        C[i] = ((i - 1) * i / 2) % MOD;
    }
    for (int i = 0; i < m; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            if (s[j] == '1')
                left[j]--;
    }
    int k = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        if (left[i] == 1)
            k++;
        else if (left[i] == 2)
            l++;
    }
    cout << calc(k, l);

    return 0;
}
