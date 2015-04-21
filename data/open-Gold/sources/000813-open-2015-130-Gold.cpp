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

static vector <char> vc;
static ll m1[300000], m2[300000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	ll n, k, C, D, res = (ll)mod * mod, ol = 0;
	cin >> n >> k >> C >> D;
	for (int i = 0; i < n; ++i){
        cin >> m1[i] >> m2[i];
        ol += (m2[i] - m1[i]);
	}
	priority_queue <ll, vector <ll>, greater <ll> > pq;
	for (int i = 1; i < n; ++i)
        pq.push(m1[i] - m2[i - 1]);
    res = min(res, ((n + k - 1) / k) * C + ol * D);
    for (int i = 1; i < n; ++i){
        ol += pq.top();
		pq.pop();
        res = min(res, ((pq.size() + k) / k) * C + ol * D);
    }
    cout << res - C << endl;
	//system("pause");
	return 0;
}
