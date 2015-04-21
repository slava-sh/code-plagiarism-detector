#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <list>
#include <bitset>
#include <cstring>
#include <string>
// C++11 Headers
#include <tuple>
#include <initializer_list>
// *C++11 Headers

#ifdef DEBUG
	#define debug printf
	#define reader scanf
#else
	#define debug ;
	#define reader ;
#endif

#define ll long long

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

string s;
int n;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	cin >> s;
	
	bool f = true;
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] != s[i - 1])
			f = false;
	} 
	
	if (f) {
		cout << "1\n" << s[0] << '\n';
		return 0;
	}
	
	if (n >= (int)s.size()) {
		cout << "1\n" << s << '\n';
	} else {
		cout << "2\na\nb\n";
	}
		
	return 0;
}
