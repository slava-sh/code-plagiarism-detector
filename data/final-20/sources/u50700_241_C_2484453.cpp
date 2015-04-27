#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 103;
const double eps = 1e-8;

struct Seg {
	int v, a, b;
	char c;
}s[maxn];

int ans;
bool mk[maxn];

void gao(int hl, int hr, int n, int idx) {
	char ca[2] = {'T', 'F'};
	int i, j, k;
	for (i=1; i <= n; i++) {
		double t;
		if (i&1)
			t = 100000.0/(hl+hr+100*(i-1));
		else
			t = 100000.0/(hl-hr+100*i);
		double sta = t * hl;
		memset(mk, 0, sizeof(mk));
		int tag = idx;
		int sum = 0;
	//	printf("i=%d: ",i);
		for (j=1; j <= i; j++,tag=!tag) {
		//	printf("	sta=%.2lf %c\n",sta,ca[tag]);
			for (k=0; k < n; k++) if (!mk[k] && s[k].c == ca[tag]) {
				if (s[k].a - eps < sta && sta < s[k].b + eps) {
					mk[k] = true;
					sum += s[k].v;
					//printf(" %d",s[k].v);
					break;
				}
			}
			if (k >= n)
				break;
			sta += t*100;
		}
	//	printf("\n");
		if (j > i) {
			ans = ans > sum ? ans : sum;
		}
	}
}
int main() {
//	printf("%lf\n",atan(sqrt(3.0))/acos(-1.0)*180);
	int n, i;
	char ch[5];
	int hl, hr;
	scanf("%d%d%d",&hl,&hr,&n);
	for (i=0; i < n; i++) {
		scanf("%d%s%d%d",&s[i].v,ch,&s[i].a,&s[i].b);
		s[i].c = ch[0];
	}
	ans = 0;
	gao(hl, hr, n, 1);
	gao(100-hl, 100-hr, n, 0);
	printf("%d\n",ans);
	return 0;
}
/*
80 72 9
15 T 8210 15679
10 F 11940 22399
50 T 30600 44789
50 F 32090 36579
5 F 45520 48519
120 F 49250 55229
8 F 59700 80609
35 T 61940 64939
2 T 92540 97769

20 28 9
15 F 8210 15679
10 T 11940 22399
50 F 30600 44789
50 T 32090 36579
5 T 45520 48519
120 T 49250 55229
8 T 59700 80609
35 F 61940 64939
2 F 92540 97769
*/
