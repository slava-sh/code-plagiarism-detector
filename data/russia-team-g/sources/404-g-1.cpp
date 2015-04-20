#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

#define push_back pb
#define make_pair mp
#define first fr
#define second sc


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	if (n == 2 && m > 1){
		cout << 0;
		return 0;
	}
	if (n > 2 && m > 2){
		cout << 1;
		return 0;
	}
	if (n == 1){
		cout << (m + 1) / 4;
		return 0;
	}
}