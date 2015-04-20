#include <fstream>

#include<vector>
#include<algorithm>
#define int long long int

using namespace std;

main()
{
    ifstream cin ("sochi.in");
    ofstream cout("sochi.out");
//    int n, m;
//    cin >> n >> m;
//    cout << min((n + 1) / 4, (m + 1) / 4) << endl;
    int n, d;
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
        }
    }
    sort(A.rbegin(), A.rend());
    if(answer == 0)
    {
        if(A.size() == 0)
        {
            cout << 0 << endl;
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
