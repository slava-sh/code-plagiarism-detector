// Author: Nguyen Duy Khanh
#include<bits/stdc++.h>
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define DEBUG(x) { printf << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define Nmax 35000
using namespace std;

long long f[505][505], k1, k2, k3;
int MOD, n, m, cnt, a[505];
string s;

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> MOD;

    FOR(i,1,m){
        cin >> s;
        FOR(j,0,n-1) a[j+1] += s[j] - '0';
    }

    FOR(i,1,n)
        if (a[i] == 1) cnt++;

    f[m][cnt] = 1;

    FOR(i,m+1,n)
    FOR(j,0,n){
        if (j % 2 == 1) continue;
        k1 = f[i-1][j+2] * (j+1) * (j+2) / 2;

        k2 = (2*i - 2 - j) / 2; // so cot bang 2
        k2 = j * (n - j - k2);
        k2 = f[i-1][j] * k2;

        if (j) {
            k3 = (2*i - 2 - (j-2)) / 2; // so cot bang 2
            k3 = n - k3 - (j-2); // so cot bang 0
            k3 = f[i-1][j-2] * k3 * (k3 - 1) / 2;
            f[i][j] = (k1 + k2 + k3) % MOD;
        }
        else f[i][j] = (k1 + k2) % MOD;
    }

    /*
    FOR(i,1,n){
        FOR(j,0,n) cout << f[i][j] << " ";
        cout << endl;
    }
    */

    cout << f[n][0];

    return 0;
}
