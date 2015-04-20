#include <fstream>
#include <algorithm>

using namespace std;

long long pref[100000], suf[100001], bottles[100000];

bool compare(long long a, long long b) {
	return a > b;
}

int main() {
	ifstream fin("merlin.in");
	ofstream fout("merlin.out");
	long long n;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> bottles[i];
    }
	sort(bottles, bottles + n, compare);
	long long total = 0;
	for (int i = 0; i < n; i++) {
		total += bottles[i];
		pref[i] = total;
	}
	suf[n] = 0;
	int ans = -1;
	for (long long i = 0; (i <= n) && (ans == -1); i++) {
		if (bottles[i] * (n - i) <= total) {
			ans = i;
		}

	}
	fout << ans;

	return 0;
}