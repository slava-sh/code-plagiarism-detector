#include <iostream>
#include <string>
using namespace std;
int sum[100100];
const long long P = 1000000007LL;

long long fastpow(int a, int p) {
	long long result = 1;
	long long temp = a;
	while(p) {
		if(p&1) {
			result = result * temp % P;
		}
		temp = temp * temp % P;
		p>>=1;
	}
	return result;
}

inline long long inverse(int n) {
	return fastpow(n, P-2);
}

long long C(int n, int b) {
	if(n-b < b) {
		b = n-b;
	}
	long long res = 1;
	for(int i=1;i<=b;i++) {
		res *= (n-i+1);
		res %= P;
		res *= inverse(i);
		res %= P;
	}
	return res;
}
int main() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	sum[0] = 0;
	for(int i=1;i<=n;i++) {
		sum[i] = sum[i-1] + s[i-1] - '0';
	}
	long long res = 0;
	long long tempC = C(n-2, k-1);
	long long tempC2 = C(n-1,k);
	for(int i=1;i<=n-k;i++) {
		if(k > 0) res = (res + tempC * sum[n-i] % P * fastpow(10, i-1)) % P;
		tempC = tempC * inverse(n-i-1) % P * (n-i-k) % P;
		res = (res + tempC2 * (s[n-i] - '0') % P * fastpow(10, i-1)) % P;
		tempC2 = tempC2 * inverse(n-i) % P * (n-i-k) % P;
	}
	cout << res << endl;
	//system("pause");
}