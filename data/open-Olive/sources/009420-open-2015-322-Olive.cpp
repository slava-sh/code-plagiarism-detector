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
    int n, n1;
    cin >> n;
    n1 = n - 1;
    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    int sum1, sum2;
    int best = 0;
    /*for (int i = 0; i < n; i++){
        for (int i = 0; i < n1; i++)
            if (b[i] > b[i + 1]){
                best++;
                swap(b[i], b[i + 1]);
            }
    }
    cout << best << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1)*/
    int col[n];
    memset(col, 0, sizeof(col));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((j < i && a[j] > a[i]) || (j > i && a[j] < a[i]))
                col[i]++;
    short k;
    int num = 0;
    pair<int, int> ans = make_pair(-2, -2);
    for (short i = 0; i < n; i++)
        for (short j = i + 1; j < n; j++)
            if (a[i] > a[j]){
                if (num > 50000)
                    break;
                num++;
                int sum(0);
                sum -= col[j] + col[i];
                for (k = 0; k < i; k++)
                    if (a[k] > a[j])
                        sum++;
                //for (int k = 0; k < i; k++)
                //    if (a[k] > a[i])
                //        sum--;
                for (k = i + 1; k < n; k++)
                    if (a[k] < a[j])
                        sum++;
                //for (int k = i + 1; k < n; k++)
                //    if (a[k] < a[i])
                //        sum--;

                //for (int k = 0; k < j; k++)
                //    if (a[k] > a[j])
                //        sum--;
                for (k = 0; k < j; k++)
                    if (a[k] > a[i])
                        sum++;
                //for (int k = j + 1; k < n; k++)
                //    if (a[k] < a[j])
                //        sum--;
                for (k = j + 1; k < n; k++)
                    if (a[k] < a[i])
                        sum++;
                //cout << i << " " << j << " " << sum << endl;
                if (sum < best){
                    best = sum;
                    ans = make_pair(i, j);
                }
            }
    cout << ans.first + 1 << " " << ans.second + 1 << endl;
    return 0;
}
