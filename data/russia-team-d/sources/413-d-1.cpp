#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("fence.in");
ofstream out("fence.out");

int main()
{
    int n, k;
    long long curr_min, delta, ost, colored = 0, part;

    in >> n >> k;
    vector <long long> a(n);
    for (int i = 0; i < n; i++)
        in >> a[i];
    sort(a.begin(), a.end());

    curr_min = a[0];
    ost = n - 1;
    colored = a[0];

    for (int i = 1; i < n; i++)
    {
        part = (k - colored) / ost;
        delta = a[i] - colored;
        delta = max(delta, min(curr_min, part));

        curr_min = min(curr_min, delta);
        colored += delta;
        ost--;
    }

    out << curr_min;

    in.close();
    out.close();

    return 0;
}