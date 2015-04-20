#include <fstream>
#include <iostream>

#include<vector>
#include<algorithm>

#define int long long int

using namespace std;

main()
{
    ifstream cin ("sochi.in");
    ofstream cout("sochi.out");
    int n, d;
    int maxi = -1000ll * 1000 * 1000 * 1000 * 1000;
    cin >> n >> d;
    vector<int> A;
    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (x >= 3 * d)
        {
            if(answer != 0)
                answer = (answer + x) - 2 * d;
            else
                answer = x;
        }
        else
        {
            if(x > 2 * d)
                A.push_back(x);
            else
                maxi = max(maxi, x);
        }
    }
    sort(A.rbegin(), A.rend());
    if(answer == 0)
    {
        if(A.size() == 0)
        {
            cout << max(0ll, maxi) << endl;
        }
        else
        {
            cout << A[0] << endl;
        }
        return 0;
    }
    for(int i = 0; i < 2; ++i)
    {
        if(i < A.size())
            answer = (answer + A[i]) - 2 * d;
    }
    cout << answer << endl;
}
