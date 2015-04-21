#include <iostream>
#include <fstream>

using namespace std;

const int st = 1 << 18;
int a, b, c, d;

class Point{
public:
	int l, r, n;
	Point(){}
	Point(int a): l(a), r(a), n(0){}
};

Point m[st * 2];

void recalc(int a){
	m[a].l = m[a * 2].l;
	m[a].r = m[a * 2 + 1].r;
	m[a].n = m[a * 2].n + m[a * 2 + 1].n + (m[a * 2].r == m[a * 2 + 1].l ? 0 : 1);
}

void build(){
	for(int i = st - 1; i > 0; --i)
		recalc(i);
}

void update(int x, int a){
	x += st - 1;
	m[x] = Point(a);
	x /= 2;
	while(x){
		recalc(x);
		x /= 2;
	}
}

int main(){
	cin >> a;
	for(int i = 0; i < a; ++i){
		scanf("%d", &b);
		m[i + st] = Point(b);
	}
	for(int i = a; i < st; ++i)
		m[i + st] = Point(2E9);
	build();
	cin >> b;
	for(int i = 0; i < b; ++i){
		scanf("%d%d", &c, &d);
		update(c, d);
		printf("%d\n", m[1].n);
	}
}