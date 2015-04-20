#include <fstream>
#include <algorithm>

using namespace std;

int bottles[100000];
long long pref[100000], suf[100001];

int main() {
	ifstream fin("merlin.in");
	ofstream fout("merlin.out");
	int n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> bottles[i];
    }
	sort(bottles, bottles + n);
	long long total = 0;
	for (int i = 0; i < n; i++) {
		total += bottles[i];
		pref[i] = total;
	}
	total = 0;
	for (int i = n - 1; i >= 0; i--) {
		total += bottles[i];
		suf[i] = total;
	}
	suf[n] = 0;
	int ans;
	for (int i = 0; i < n; i++) {
		long long needed = bottles[i] * (i + 1) - pref[i];
		long long available = suf[i + 1];
		if (available >= needed) {
			ans = n - i - 1;
		}
	}
	fout << ans;

	return 0;
}