#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    int n, m;
    cin >> n;
    int a[n + 2];
    int ans = 0;
    a[0] = -1;
    a[n + 1] = -2;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != a[i - 1])
            ans++;
    }
    cin >> m;
    int p, c;
    for (int i = 0; i < m; i++){
        cin >> p >> c;
        if (c == a[p]){
            cout << ans << endl;
            continue;
        }
        if (c == a[p - 1] && c == a[p + 1])
            ans -= 2;
        else
        if ((c == a[p - 1] || c == a[p + 1]) && !(a[p] == a[p - 1] || a[p] == a[p + 1]))
            ans -= 1;
        else
        if (a[p] == a[p - 1] && a[p] == a[p + 1])
            ans += 2;
        else
        if ((a[p] == a[p - 1] || a[p] == a[p + 1]) && !(c == a[p - 1] || c == a[p + 1]))
            ans += 1;
        cout << ans << endl;
        a[p] = c;
    }
    return 0;
}
