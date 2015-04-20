#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, ml, num, nump;
vector <int> mas;

int main() {
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        mas.push_back(num);
    }
    sort(mas.begin(), mas.end());

    int maxns = -1, maxsns = -1;
    for (int i = 0; i < n; ++i) {
        if (mas[i] >= 2 * d && mas[i] < 3 * d) {
            maxsns = maxns;
            maxns = mas[i];
        } else if (mas[i] >= 3 * d) {
            ml += mas[i];
            ++nump;
        }
    }
    if (maxsns != -1) {
        ++nump;
        ml += maxsns;
    }
    if (maxns != -1) {
        ++nump;
        ml += maxns;
    }
    cout << ml - (nump - 1) * 2 * d;
    return 0;
}