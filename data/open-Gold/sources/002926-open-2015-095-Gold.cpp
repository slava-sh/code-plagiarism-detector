#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int a[200009];
int b[200009];

int diff[200009];


int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    ll C, D;
    cin >> N >> K >> C >> D;

    ll sum = 0;

    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> b[i];
        sum += (ll)(b[i] - a[i]);
    }

    //cout << sum << endl;

    for (int i = 1; i <= N-1; i++) {
        diff[i] = a[i+1] - b[i];
    }

    sort(diff+1, &diff[N]);

    //for (int i = 1; i <= N-1; i++) cout << diff[i] << endl;

    ll ans = (ll)((N-1)/K) * C;
    //cout << ans << endl;
    ll tmp = 0;
    for (int m = N-2; m >= 0; m--) {
        tmp += (ll)diff[N-m-1];
        ans = min(ans, (ll)(m/K) * C + tmp*D);
    }

    cout << ans + sum*D;
}
