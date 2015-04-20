#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int Max_n = 100100;
int A[Max_n];
vector<int> can;

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    int i;
    int sum = 0;
    for (i = 0; i < n; ++i)
    {
        cin >> A[i];
        if (A[i] < 3 * d)
        {
            if (A[i] > 2 * d)
            {
                can.push_back(A[i]);
            }
        }
        else
        {
            sum += A[i] - 2 * d;
        }
    }
    if (can.size() == 0)
    {
        sum += 2 * d;
    }
    if (can.size() == 1)
    {
        sum += can[0];
    }
    if (can.size() >= 2)
    {
        sort(can.begin(), can.end());
        int first, second;
        first = can[can.size() - 1];
        second = can[can.size() - 2];
        sum += first - d + second - d;
    }
    cout << sum;
    return 0;
}
