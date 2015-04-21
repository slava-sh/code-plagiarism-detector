#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i, j, l, r, ans, buf;
    cin >> n;
    vector<int> h(n);
    for (i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<vector<int> > invs(n, vector<int> (n, 0)), invf(n, vector<int> (n, 0));
    for (i = 0; i < n; i++)
    {
        for (j = i - 1; j >= 0; j--)
            invs[i][j] = invs[i][j + 1] + (h[j] > h[i]);
        for (j = i + 1; j < n; j++)
            invf[i][j] = invf[i][j - 1] + (h[i] > h[j]);
    }
//    for (auto w: invs)
//    {
//        for (auto z: w)
//            cout << z << ' ';
//        cout << endl;
//    }
//    cout << endl;
//    for (auto w: invf)
//    {
//        for (auto z: w)
//            cout << z << ' ';
//        cout << endl;
//    }
    ans = 0;
    l = -1;
    r = -1;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
        {
            buf = invs[j][i] + invf[i][j] - (j - i - invf[i][j]) - (j - i - invs[j][i]);
            if (ans < buf) {ans = buf; l = i + 1; r = j + 1;}
        }
    cout << l << ' ' << r << endl;
    return 0;
}
