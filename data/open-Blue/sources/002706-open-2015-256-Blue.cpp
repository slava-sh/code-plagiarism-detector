#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

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


int main() {
	//freopen("input.txt", "r", stdin);
	int L;
	scanf("%d\n", &L);
	string str;
	getline(cin, str);
	int n = str.size();
	if (L >= n) {
		cout << 1 << endl;
		cout << str << endl;
	} else {
		cout << 2 << endl;
		cout << 'a' << endl;
		cout << 'b' << endl;
	}
}