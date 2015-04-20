#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("sochi.in", "r", stdin);
    //freopen("sochi.out", "w", stdout);
    long long N;
    cin >> N;
    long long d;
    cin >> d;
    int k = d;
    vector <long long> A(N);
    for (long long i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    stable_sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    long long Ans = 0;
    for (long long i = 0; i < N; ++i)
    {
        if (i == 0 || (A[i] - 2 * d > 0 && (i == 1 || (A[i - 1] - 2 * d >= d))))
        {
            Ans += A[i];
            if (i != 0)
            {
                Ans -= 2 * d;
            }
        }
    }
    cout << Ans << endl;
    return 0;
}
