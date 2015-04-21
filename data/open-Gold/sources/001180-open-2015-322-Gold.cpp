#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    int n, k, c;
    long long d;
    cin >> n >> k >> c >> d;
    long long ans = 1e18, sum = 0, sum_s = 0;
    int a[n], b[n];
    multiset<int> s;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        sum += (b[i] - a[i]) * d;
        if (i != 0){
            s.insert(a[i] - b[i - 1]);
            sum_s += a[i] - b[i - 1];
        }
    }
    ans = sum_s * d;
    long long best(0);
    //for (int i = 1; i <= n; i++){
    int col = 0;
    //    best = i * c;
    //    vector<int> v;
    for (multiset<int>::reverse_iterator i = s.rbegin(); i != s.rend(); i++){
        col++;
        if (col % k == 0)
            best++;
        //if (col == s.size())
        //    best--;
        sum_s -= (*i);
        //v.push_back(*i);
        //cout << sum_s << " " << best << " " << best * c+ sum_s * d << endl;
        ans = min(ans, best * c + sum_s * d);
    }
        //cout << best << "  " << sum_s << endl;
        //cout << best + sum_s * d << endl;
    //}
    cout << ans + sum;
    return 0;
}
