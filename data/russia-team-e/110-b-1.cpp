#include <fstream>
#define int long long int

using namespace std;

main()
{
    ifstream cin("che.in");
    ofstream cout("che.out");
    int n, dist;
    cin >> n >> dist;
    int A[n];
    for(int i = 0; i < n; ++i)
        cin >> A[i];
    int j = 0, ans = 0;
    for(int i = 0; i < n - 1; ++i)
    {

        while(j < n && A[j] - A[i] <= dist)
            ++j;
        ans += (n - j);
    }
    cout << ans << endl;
}
