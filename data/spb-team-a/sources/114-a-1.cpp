#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int t;
string str;

int main(){
	freopen("abcd.in", "r", stdin);
	freopen("abcd.out", "w", stdout);
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> str;
		long long a = (str[0] - '0') * 10, b = (str[1] - '0');
		a += b;
		long long c = (str[2] - '0') * 10, d = (str[3]- '0');
		c += d;
		long long ans = a * a + c * c;
		if(ans % 7 == 1)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	return 0;
}