#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

void step(char dir) {
	cout << dir << endl;
	char ans;
	cin >> ws >> ans;
	if (ans == 'Y' || ans == 'E') {
		exit(0);
	}
}

int main() {
	ll it = 0;
	srand(1337);
	//string s = "R ULURRDDR UUULLLURRRRDDDDR UUUUULLLLLURRRRRRDDDDDDR ";
	//step('R');
	while (true) {
		string steps;
		char a = 'R', b = 'U';
		if (rand()%3==0) {
			swap(a, b);
		}
		for (ll i = 0; i < 1+it; ++i) {
			steps += a;
		}
		for (ll i = 0; i < 1; ++i) {
			steps += b;
		}
		/*for (ll i = 0; i < 1+2*it; ++i) {
			steps += 'R';
		}
		for (ll i = 0; i < 1+2*it; ++i) {
			steps += 'D';
		}
		for (ll i = 0; i < 2+2*it; ++i) {
			steps += 'L';
		}
		for (ll i = 0; i < 2+2*it; ++i) {
			steps += 'U';
		}*/
		/*for (ll i = 0; i < 1+2*it; ++i) {
			steps += 'U';
		}
		for (ll i = 0; i < 1+2*it; ++i) {
			steps += 'L';
		}
		steps += 'U';
		for (ll i = 0; i < 2+2*it; ++i) {
			steps += 'R';
		}
		for (ll i = 0; i < 2+2*it; ++i) {
			steps += 'D';
		}
		steps += 'R';*/
		
		for (ll i = 0; i < steps.length(); ++i) {
			step(steps[i]);
		}
		++it;
	}

	return 0;
}