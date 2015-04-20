#include <iostream>
#include <vector>
using namespace std;

#define TASK "che"

const int maxn = 300010;

typedef long long ll;
ll A[maxn];

int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	int n;
	cin >> n;
	ll r;
	cin >> r;
	for (int i = 0; i < n; ++i) {
	    cin >> A[i];
	}
	ll End = 0;
	ll Res = 0;
	for (ll i = 0; i < n; ++i) {
	    while (End < n && A[End] - A[i] <= r) {
		    ++End;
		}
		Res += n - End;
	}
	cout << Res;
}