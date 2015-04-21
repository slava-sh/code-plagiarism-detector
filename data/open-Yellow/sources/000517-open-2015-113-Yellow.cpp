#include <bits/stdc++.h>

using namespace std;

int arr[1000000];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int ans = 1;
    for(int i=1;i<n;i++)
    {
        ans += arr[i] != arr[i-1];
    }
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        if(n == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        if(arr[a] == b)
        {
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(a == 0)
        {
            if(arr[a] == arr[a + 1])
            {
                ans++;
                cout << ans << '\n';
                arr[a] = b;
                continue;
            }
            if(b == arr[a + 1])
            {
                ans--;
                cout << ans << '\n';
                arr[a] = b;
                continue;
            }
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(a == n-1)
        {
            if(arr[a] == arr[a - 1])
            {
                ans++;
                cout << ans << '\n';
                arr[a] = b;
                continue;
            }
            if(b == arr[a - 1])
            {
                ans--;
                cout << ans << '\n';
                arr[a] = b;
                continue;
            }
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(arr[a] == arr[a - 1] && arr[a] == arr[a + 1])
        {
            ans += 2;
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(b == arr[a - 1] && b == arr[a + 1])
        {
            ans -= 2;
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(arr[a] == arr[a - 1] && b == arr[a + 1] || b == arr[a - 1] && arr[a] == arr[a + 1])
        {
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(arr[a] == arr[a - 1] || arr[a] == arr[a + 1])
        {
            ans++;
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        if(b == arr[a - 1] || b == arr[a + 1])
        {
            ans--;
            cout << ans << '\n';
            arr[a] = b;
            continue;
        }
        cout << ans << '\n';
        arr[a] = b;
        continue;
    }
    return 0;
}
