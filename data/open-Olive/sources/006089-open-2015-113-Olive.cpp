#include <bits/stdc++.h>

using namespace std;

int arr[1000006];
int tarr[1000006];
int lmore[5001][5001];
int rless[5001][5001];
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

inline int gless(int a, int b)
{
    int t = arr[a];
    return rless[a][t] - rless[b][t];
}

inline int gmore(int a, int b)
{
    int t = arr[b];
    return lmore[b][t] - lmore[a][t];
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
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            lmore[i][j] = lmore[i-1][j];
        }
        for(int j=0;j<arr[i-1];j++)
        {
            lmore[i][j]++;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=n;j++)
        {
            rless[i][j] = rless[i+1][j];
        }
        for(int j=arr[i+1]+1;j<=n;j++)
        {
            rless[i][j]++;
        }
    }
    int mx = 0;
    int ma = -1, mb = -1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i])
                continue;
            int tans = gless(j, i) + gmore(j, i) - i + j ;
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
