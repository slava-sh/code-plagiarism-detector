#include <fstream>
#include <vector>

using namespace std;

ifstream fin("che.in");
ofstream fout("che.out");

vector<int> a;
int n;

int bin (int x, int l, int r) {
    if (a[r] < x)
        return r + 1;
    int mid = (l + r) / 2;
    if (mid + 1 < n && a[mid + 1] > x && a[mid] < x)
        return mid + 1;
    if (a[mid] == x){
        return min(mid + 1, n);
    }
    if (a[mid] <= x)
        return bin(x, mid, r);
    else
        return bin(x, l, mid);
}

int main() {
    int r;
    fin >> n >> r;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        fin >> a[i];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += n  - bin(a[i] + r, 0, n - 1);
    }
    fout << sum << endl;
    return 0;
}
