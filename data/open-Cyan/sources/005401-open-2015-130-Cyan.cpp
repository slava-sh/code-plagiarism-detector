#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mp make_pair
#define ll long long
#define mod 1000000007

static vector <vector <int> > vc, vc1;

ll triar(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
}

ll chk(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4){
    ll a = triar(x1, y1, x2, y2, x3, y3), b = triar(x1, y1, x2, y2, x4, y4);
    ll c = triar(x3, y3, x4, y4, x1, y1), d = triar(x3, y3, x4, y4, x2, y2);
    if (a < 0)
        a = -1;
    else if (a > 0)
        a = 1;
    if (c < 0)
        c = -1;
    else if (c > 0)
        c = 1;
    if (a * b < 0 && c * d < 0)
        return 1;
    return 0;
}

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	ll A, B, n, a, b, c;
	cin >> A >> B >> n;
	vc.resize(n);
	vc1.resize(n);
	for (int i = 0; i < n; ++i){
        cin >> a;
		++a;
        vc[i].resize(a);
        vc1[i].resize(a);
        for (int j = 0; j < a; ++j)
            cin >> vc[i][j] >> vc1[i][j];
	}
	for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            a = 1;
            b = 1;
            for (int k = 1; k < vc[i].size(); ++k){
                if (chk(vc[i][k - 1], vc1[i][k - 1], vc[i][k], vc1[i][k], vc[j][a - 1], vc1[j][a - 1],
                        vc[j][a], vc1[j][a])){
                            b = 0;
                            break;
                        }
                while (vc[j][a] < vc[i][k]){
                    ++a;
                if (chk(vc[i][k - 1], vc1[i][k - 1], vc[i][k], vc1[i][k], vc[j][a - 1], vc1[j][a - 1],
                        vc[j][a], vc1[j][a])){
                            b = 0;
                            break;
                        }
                }
            }
            if (b == 0){
                cout << "No\n" << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
        }
    cout << "Yes\n";
	//system("pause");
	return 0;
}
