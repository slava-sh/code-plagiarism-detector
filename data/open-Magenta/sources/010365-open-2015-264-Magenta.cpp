#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <map>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>

#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
#define S second
#define F first


const int INF = int(1e9) + 7;


using namespace std;


ll INFll;


string s;
vector <int> num, pr;

int main(){
	INFll = 1e18;
	INFll *= 2;
	srand(time(NULL));
	num.resize(1000000, 0);
	for (int i = 2; i < 1000000; i++){
		if (!num[i]) {
			pr.pb(i);
			for (int j = 2 * i; j < 1000000; j += i) num[j] = 1;
		}
	}
//	ifstream cin ("test.in");
	int g = 0;
	while(1){
		for (int i = 0; i < pr[g]; i++){
			cout << "U" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		g+=2;
		if (g == pr.size()) g = 0;
		for (int i = 0; i < pr[g]; i++){
			cout << "L" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		g+=2;
		if (g == pr.size()) g = 0;
		for (int i = 0; i < pr[g]; i++){
			cout << "D" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		g+=2;
		if (g == pr.size()) g = 0;
		for (int i = 0; i < pr[g]; i++){
			cout << "R" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		g+=2;
		if (g == pr.size()) g = 0;
	}


}