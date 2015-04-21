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
    //ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int sum1, sum2;
    int best = 0;
    pair<int, int> ans = make_pair(-2, -2);
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++){
            sum1 = abs(a[i] - i - 1) + abs(a[j] - j - 1);
            sum2 = abs(a[i] - j - 1) + abs(a[j] - i - 1);
            if (sum1 - sum2 > best){
                best = sum1 - sum2;
                ans = make_pair(i, j);
            }
        }
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
    return 0;
}
