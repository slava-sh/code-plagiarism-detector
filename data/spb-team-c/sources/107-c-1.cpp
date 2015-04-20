
#pragma comment(linker, "/STACK:10000000000000")


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <ctime>
#include <map>

#define problem "conquest"
#define sort stable_sort
#define ll long long
#define INFll 1e18 + 7
#define mp make_pair
#define pb push_back
using namespace std;


struct town
{
	int num, cost;
};

town t[1111];
int a[1111];
int n;

bool cmp(town a, town b)
{
	if (a.num == b.num)
		return a.cost > b.cost;
	return a.num < b.num;
}

int main()
{
	ifstream cin(problem".in");
	ofstream cout(problem".out");
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> t[i].num >> t[i].cost;
	sort(t, t + n, cmp);
	a[0] = (t[0].num + 1) / 2;
	int have = a[0];
	for (int i = 1; i < n; i++){
		if (t[i].num < have) a[i] = -1;
		else {
			a[i] = (t[i].num - have + 1) / 2;
		}
		have += a[i];
	}
	ll ans = 0;
	for (int i = n - 1; i > 0; i--){
		if (a[i] != -1){
			ans += (a[i]) * t[i].cost;
			for (int j = 0; j < i; j++){
				if (a[j] > 0){
					a[j] -= a[i];
					if (a[j] < 0) a[i] = -a[j];
					else a[i] = 0;
				}
				if (a[i] <= 0) break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}