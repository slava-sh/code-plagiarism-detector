/*
 * byc.cpp
 *
 *  Created on: 2012-11-2
 *      Author: dfs
 */




#include <cstdio>
#include <cstring>
#include <algorithm>
const double eps = 1e-8;
int b[2][110], e[2][110], sc[2][110], m[2];
bool v[2][110];
bool contain(int a, int c, double x){
	return (x + eps >= b[a][c] && x - eps <= e[a][c]);
}
int getSc(int a, double x){
	for (int i = 1; i <= m[a]; i ++)
		if (contain(a, i, x)){
			if (v[a][i])
				return -0x3f3f3f3f;
			v[a][i] = true;
			return sc[a][i];
		}
	return -0x3f3f3f3f;
}
void swap(int &a, int &b){
	int t = a; a = b; b = t;
}
int hl, hr, n;
int main(){
	scanf("%d%d%d", &hl, &hr, &n);
	m[0] = m[1] = 0;
	for (int i = 1; i <= n; i ++){
		int v, x, y;
		char s[3];
		scanf("%d%s%d%d", &v, s, &x, &y);
		int a = (s[0] != 'T');
		m[a] ++;
		b[a][m[a]] = x;
		e[a][m[a]] = y;
		sc[a][m[a]] = v;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++){
		int dy = 0;
		if (i & 1)
			dy = hl + hr + 100 * (i - 1);
		else
			dy = 100 * i + hl - hr;
		double xl = 1e5/dy;
		double x = hl * xl;
		memset(v, false, sizeof(v));
		int res = getSc(1, x);
		if (res < 0)
			continue;
		for (int j = 2; j <= i; j ++){
			x += 100 * xl;
			res += getSc(j & 1, x);
			if (res < 0)
				break;
		}
		if (res > ans)
			ans = res;
	}
	int len = std::max(m[0], m[1]);
	hl = 100 - hl; hr = 100 - hr;
	for (int j = 1; j <= len; j ++){
		swap(b[0][j], b[1][j]);
		swap(e[0][j], e[1][j]);
		swap(sc[0][j], sc[1][j]);
	}
	swap(m[0], m[1]);
	for (int i = 1; i <= n; i ++){
		int dy = 0;
		if (i & 1)
			dy = hl + hr + 100 * (i - 1);
		else
			dy = 100 * i + hl - hr;
		double xl = 1e5/dy;
		double x = hl * xl;
		memset(v, false, sizeof(v));
		int res = getSc(1, x);
		if (res < 0)
			continue;
		for (int j = 2; j <= i; j ++){
			x += 100 * xl;
			res += getSc(j & 1, x);
			if (res < 0)
				break;
		}
		if (res > ans)
			ans = res;
	}
	printf("%d\n", ans);
	return 0;

}
