#include <fstream>
#define int long long int

using namespace std;

main()
{
    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    int n, m;
    cin >> n >> m;
    cout << min((n + 1) / 4, (m + 1) / 4) << endl;
}
