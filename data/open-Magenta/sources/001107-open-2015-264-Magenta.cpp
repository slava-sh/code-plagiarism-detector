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
	for(int i = 1; i < 1000000; i++){
		k = 1;
		int g = 0;
		while(g < i * 100){
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
			k++;
			cout << "R" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
			for (int i = 0; i < k; i++){
				cout << "D" << endl;
				getline(cin, s);
				if (s == "Y" || s == "E"){
					return 0;
				}
			}
			k++;
			g++;
		}
		cout << "L" << endl;
		getline(cin, s);
		if (s == "Y" || s == "E"){
			return 0;
		}
		cout << "D" << endl;
		getline(cin, s);
		if (s == "Y" || s == "E"){
			return 0;
		}
		k = 2;
		while(g < i * 200){
			cout << "L" << endl;
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
			k++;
			cout << "L" << endl;
			getline(cin, s);
			if (s == "Y" || s == "E"){
				return 0;
			}
			for (int i = 0; i < k; i++){
				cout << "D" << endl;
				getline(cin, s);
				if (s == "Y" || s == "E"){
					return 0;
				}
			}
			k++;
			g++;
		}
	}

}