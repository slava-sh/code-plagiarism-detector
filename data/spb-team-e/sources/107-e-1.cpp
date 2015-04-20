#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define problem "game"
#define ll long long
using namespace std;

int n, m, l[2], r[2], k = 0, cnt[3], t, num[2];

int main()
{
	ifstream cin (problem".in");
	ofstream cout (problem".out");
	cin >> n >> m >> l[0] >> r[0] >> l[1] >> r[1];
	for (int i = 0; i < n; i++){
		cin >> t;
		if (t <= r[0] && t >= l[0]){
			if (t >= l[1] && t <= r[1]) cnt[2]++;
			else cnt[0]++;
		}
		else if (t >= l[1] && t <= r[1]){
			cnt[1]++;
		}
	}


	for (int i = 0; i < m; i++){
		if (cnt[2]) {
			cnt[2]--;
			num[i & 1]++;
		}
		else {
			if (cnt[i & 1]){
				cnt[i & 1]--;
				num[i & 1]++;
			}
		}
	}
	if (num[0] > num[1]) cout << "Petya";
	else if (num[0] == num[1]) cout << "Draw";
	else cout << "Vasya";
	return 0;
}
