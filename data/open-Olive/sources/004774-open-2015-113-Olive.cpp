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
    int mx = 0;
    int ma = -1, mb = -1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i])
                continue;
            int tans = 0;
            for(int k=j+1;k<i;k++)
            {
                tans += (arr[k] < arr[j] ? 1 : -1) + (arr[k] > arr[i] ? 1 : -1);
            }
            if(tans > mx)
            {
                mx = tans;
                ma = i+1;
                mb = j+1;
            }
        }
    }
    cout << mb << ' ' << ma;
    return 0;
}
