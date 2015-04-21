#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

const ll INF = 1LL << 62LL;

struct Point {
	ld x, y;
	Point(ld=0, ld=0);
	Point operator-(const Point &) const;
	ld len() const;
};

Point::Point(ld x, ld y): x(x), y(y)
{}

Point Point::operator-(const Point &p) const {
	return Point(x - p.x, y - p.y);
}

ld Point::len() const {
	return sqrt(x*x + y*y);
}

int n;
vector <int> arr;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	vector <int> biggerLeft(n, 0), bigger(n, 0), biggerCur(n, 0);
	int profit = 0;
	int ans1 = -2, ans2 = -2;
	for (int i = 1; i < n; ++i) {
		//vector <int> biggerLeft(n, 0), bigger(n, 0), biggerCur(n, 0);

		biggerCur[0] = 0;
		for (int j = 1; j < i; ++j) {
			biggerCur[j] = biggerCur[j - 1] + (arr[j - 1] > arr[i]);
		}
		for (int j = 0; j < i; ++j)
			biggerLeft[i] += arr[j] > arr[i];
		/*
		for (int j = 0; j < n; ++j)
			printf("%d ", biggerLeft[j]);
		printf("\n");
		for (int j = 0; j < n; ++j)
			printf("%d ", bigger[j]);
		printf("\n");
		for (int j = 0; j < n; ++j)
			printf("%d ", biggerCur[j]);
		printf("\n");
		printf("\n");*/
		for (int j = 0; j < i; ++j) {
			int k = biggerCur[j] + bigger[j] - biggerLeft[i];
			if (k < profit) {
				profit = k;
				ans1 = i;
				ans2 = j;
			}
		}
		for (int j = 0; j < i; ++j) {
			//bigger[j] = 0;
			//for (int g = 0; g < i; ++g)
				//bigger[j] += arr[g] > arr[j];
			bigger[j] += arr[i] > arr[j];
		}
	}
	//cout << profit << endl;
	cout << ans2 + 1 << " " << ans1 + 1 << endl;
}