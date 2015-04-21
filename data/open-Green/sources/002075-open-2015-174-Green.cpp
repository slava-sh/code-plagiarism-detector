#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> divisors;
map< pair<int, int>, int> table;

void factorize(int n) {
    divisors.clear();
    int i = 2;
    while (i * i < n) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
        i++;
    }
    if (n == 1);
    else {
        if (i * i == n) divisors.push_back(i);
        divisors.push_back(n);
    }
    //sort(divisors.begin(), divisors.end());
}

/*int f(int n, int k) {
    if (n == 1 || k == 1) return (n + 1) >> 1;
    int i;
    for (i = 2; i * i <= n && n % i; i++);
    if (n % i) return (n + 1) >> 1;
    return (i + 1) / 2 * f(n / i, k - 1);
}*/

int f2(int n, int k) {
    auto t = table.find(make_pair(n, k));
    if (t != table.end()) return t->second;
    if (k == 1) return (n + 1) >> 1;
    int result = f2(n, k - 1);
    for (auto d: divisors) {
        if (n % d == 0) {
            result = min(result, (d + 1) / 2 * f2(n / d, k - 1));
        }
    }
    table[make_pair(n, k)] = result;
    return result;
}

main() {
    divisors.reserve(200);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i < 1e5 / 2; i++) {
        factorize(i);
        if (divisors.size() <= 1) {
            for (int t = 1; t <= 10; t++) {
                table[make_pair(i, t)] = (i + 1) >> 1;
            }
        }
        else {
            f2(i, 10);
        }
    }

    factorize(n);
    cout << f2(n, k) << endl;

    return 0;
}
