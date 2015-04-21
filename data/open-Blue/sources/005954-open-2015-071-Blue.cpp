#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cassert>


using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;

const int M= 1009;
const ll Q = 1e9 + 7;
char s[M];      
bool    dp[M], fu[M];
pair<ull, ll> hash1[M];
pair<ull, ll> po[M];

int n;

inline pair<ull, ll> get(int l, int r){
	return mp(hash1[r].first - po[r - l].first * hash1[l].first, (((hash1[r].second - (po[r - l].second * hash1[l].second) % Q) % Q + Q) % Q));
}
void check(int i1, int j1, int i2, int j2){
	int d1, d2, i;
	pair<ull, ll> h1, h2;
	h1 = get(i1, j1);d1 = j1 - i1;
	h2 = get(i2, j2);d2 = j2 - i2;
	for (i = 0; i < n; i++)
		dp[i] = false;
	dp[0] = true;         
	for (i = 0; i < n; i++){             
		if (i - d1 + 1 >= 0 && dp[i - d1 + 1] && get(i - d1 + 1, i + 1) == h1)
			dp[i + 1] = true;
		if (i - d2 + 1 >= 0 && dp[i - d2 + 1] && get(i - d2 + 1, i + 1) == h2)
			dp[i + 1] = true;
		
	}
	if (dp[n]){
		cout << 2 << endl;
		for (i = i1; i < j1; i++)
			cout << s[i];
		cout << endl;
		for (i = i2; i < j2; i++)
			cout << s[i];
		exit(0);	
	}
}
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i,l,d, j;
	bool ok;
	ll p = 131;

	scanf("%d\n", &l);
	scanf("%s", s);

	n = strlen(s);
	hash1[0] = mp(0, 0);
	po[0] = mp((ull)1, 1LL);
	for (i = 1; i <= 1000; i++){
		po[i].first = (po[i - 1].first * p);
		po[i].second = (po[i - 1].second * p) % Q;
	}
	for (i = 1; i <= n; i++){
		hash1[i].first = hash1[i - 1].first * p + s[i - 1];
		hash1[i].second = (hash1[i - 1].second * p + s[i - 1]) % Q;
	}

	for (int d = 1; d<= l; d++){
   		if (n % d)
   			continue;
   		bool ok = true;
   		for (i = 0; i < n - d; i++)
   			if (s[i] != s[i + d])
   				ok = false;
   		if (ok){
   			cout << 1 << endl;
   			for (i =0; i < d; i++)
   				cout << s[i];
   			return 0;
   		}
   	}
   	for (i = 1; i <= l; i++){
   		if (fu[i])
   			continue;
   		for (d = 1;;d++){
   			fu[d * i] = true;
   			for (j = 1; j <= l; j++){
   				if (d * i + j > n)
   					break;
   				check(0, i, d * i, d * i + j);
   			}
   			if (d * i + i > n)
   				break;
   			ok = true;
   			for (j = d * i; j < d * i + i; j++)
   				if (s[j] != s[j - i])
   					ok = false;
   			if (!ok)
   				break;
   		}

   	}
   	cout << 3;
   	printf("\na\nb\nc");
	return 0;
}