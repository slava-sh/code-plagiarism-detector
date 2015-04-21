#include <bits/stdc++.h>

using namespace std;

int arr[15001];
unsigned short sums[15001][15001];
int n;


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        sums[i+1][arr[i]] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sums[i][j] += sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
        }
    }
    int mx = 0;
    int ma = -1, mb = -1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] < arr[j])
                continue;
            int tm = sums[j+1][arr[i]] - sums[j+1][arr[j]-1] - sums[i][arr[i]] + sums[i][arr[j]-1];
            if(tm > mx)
            {
                mx = tm;
                ma = j + 1;
                mb = i + 1;
            }
        }
    }
    cout << mb << ' ' << ma;
    return 0;
}
