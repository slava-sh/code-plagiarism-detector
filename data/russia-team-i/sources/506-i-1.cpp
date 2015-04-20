#include <fstream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ifstream fin("sochi.in");
ofstream fout("sochi.out");

vector<ll> a;

int main() {
    int n, d;
    fin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        fin >> a[i];
    sort(a.begin(), a.end());
    int cur = 0, sum = 0, k = 0;
    for (int i = a.size() - 1; i >= 0 && cur < 2; --i) {
        if (a[i] < 3 * d)
            ++cur;
        sum += a[i];
        k++;
    }
    fout << sum - 2 * d * (k - 1);
    return 0;
}
