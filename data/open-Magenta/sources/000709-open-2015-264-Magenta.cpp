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

int main(){
	INFll = 1e18;
	INFll *= 2;
	srand(time(NULL));
//	ifstream cin ("test.in");
	int k = 1;
	while(1){
		cout << "R" << endl;
		getline(cin, s);
		if (s == "Y" || s == "E"){
			return 0;
		}
		for (int i = 0; i < k; i++){
			cout << "U" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		for (int i = 0; i < k; i++){
			cout << "L" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		k++;
		cout << "U" << endl;
		getline(cin, s);
		if (s == "Y" || s == "E"){
			return 0;
		}
		for (int i = 0; i < k; i++){
			cout << "R" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		for (int i = 0; i < k; i++){
			cout << "D" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
		}
		k++;
	}


}