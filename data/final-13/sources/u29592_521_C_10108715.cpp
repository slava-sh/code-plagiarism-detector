#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

long long powm(long long a, long long b) {
	if(b == 0) return 1 % MOD;
	if(b % 2 == 0) return powm((a*a)%MOD, b/2);
	return a * powm(a, b-1) % MOD;
}

long long inv(long long x) {
	return powm(x, MOD-2);
}

vector<long long> calc_binom(long long n, long long k) {
	vector<long long> res(k, 0);
	res.push_back(1);

	for(long long m = k + 1; m <= n; m++) {
		long long prev = res.back();

		prev = prev * m % MOD;
		prev = prev * inv(m - k) % MOD; 

		res.push_back(prev);
	}
	
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	string s;

	cin >> n >> k >> s;

	auto binom = calc_binom(n, k == 0 ? n : k-1);
	auto binom2 = calc_binom(n, k);

	vector<long long> sum;
	long long dz = 1;
	long long tsum = 0;

	for(int j = 0; j <= n - 2; j ++) {
		sum.push_back(dz * binom[n-2-j] % MOD);
		dz = dz * 10 % MOD;
		tsum = (tsum + sum.back()) % MOD;
	}

	long long res = 0;
	for(int i = 1; i <= n-1; i++) {
		long long digit = s[i-1] - '0';
		
		res = (res + digit * tsum) % MOD;
		tsum -= sum[n-i-1];
	}

	dz = 1;
	for(int i = n; i >= 1; i--) {
		long long digit = s[i-1] - '0';
		
		res = (res + (binom2[i-1] * dz) % MOD * digit) % MOD;
		dz = (dz * 10)  %MOD;
	}

	cout << res << endl;
}
