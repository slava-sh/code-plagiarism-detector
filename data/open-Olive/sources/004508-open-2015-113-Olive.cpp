#include <bits/stdc++.h>

using namespace std;

int arr[1000006];
int tarr[1000006];
int n;

int countinv()
{
    for(int i=0;i<n;i++)
    {
        tarr[i] = arr[i];
    }
    int ans = 0;
    for(int i=n-1;i;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(tarr[j] > tarr[j+1])
            {
                swap(tarr[j], tarr[j+1]);
                ans++;
            }
        }
    }
    return ans;
}

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
    int mx = countinv();
    int ma = -1, mb = -1;
    for(int i=n-1;i;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
                int tm = countinv();
                if(tm < mx)
                {
                    mx = tm;
                    ma = i+1;
                    mb = j+1;
                }
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << mb << ' ' << ma;
    return 0;
}
