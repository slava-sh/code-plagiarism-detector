#include <string>
#include <iostream>
#include <stdio.h>
#include <cctype>

using namespace std;

typedef long long ll;

struct Meal {
	bool state;
	int lg;
	int q;
};

Meal meal[100001];
int mg   [100001];
int r    [100001];


void nonempty(int& virt, int const& k, int const& curmeal, int const& i);

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r+", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; ++tt) {
		int m, k;
		scanf("%d%d", &m, &k);
		for (int i = 1; i <= k; ++i) {
			meal[i].state = 0;
			meal[i].q = 0;
			meal[i].lg = 1;
		}
		for (int i = 1; i <= k; ++i) {
			int q;
			scanf("%d", &q);
			meal[i].q = q;
		}
		for (int i = 1; i < m; ++i) {
			scanf("%d%d", &mg[i], &r[i]);
			if (mg[i] > 0) {
				meal[mg[i]].lg = i;
			}
		}

		int virt = 0;
		bool empty = 0;

		for (int i = 1; i < m; ++i) {
			if ((mg[i] > 0) && (r[i] == 0)) {
				int curmeal = mg[i];
				--meal[curmeal].q;
				if (meal[curmeal].q == 0) {
					meal[curmeal].state = 1;
					empty = 1;
				}
			}
			if ((mg[i] > 0) && (r[i] == 1)) {
				int curmeal = mg[i];
				if (!empty) {
					int num = 0;
					int min = 100000;
					for (int j = 1; j <= k; ++j) {
						if (j == curmeal)
							continue;
						if (meal[j].lg >= i)
							continue;
						if (meal[j].q < min) {
							num = j;
							min = meal[j].q;
						}
						if (meal[j].q <= virt) {
							meal[j].state = 1;
						}
					}
					virt -= min;
					meal[num].q = 0;
					meal[num].state = 1;
					empty = 1;
				}
				--meal[curmeal].q;
				if (meal[curmeal].q == 0) {
					meal[curmeal].state = 1;
				}
			}
			if ((mg[i] == 0) && (r[i] == 0)) {
				++virt;
			}
			if ((mg[i] == 0) && (r[i] == 1)) {
				if (!empty) {
					int num = 0;
					int min = 100000;
					for (int j = 1; j <= k; ++j) {
						if (meal[j].lg >= i)
							continue;
						if (meal[j].q < min) {
							num = j;
							min = meal[j].q;
						}
						if (meal[j].q <= virt) {
							meal[j].state = 1;
						}
					}
					virt -= min;
					meal[num].q = 0;
					meal[num].state = 1;
					empty = 1;

				}
				++virt;
			}
		}
		for (int i = 1; i <= k; ++i) {
			if ((!meal[i].state) && (virt >= meal[i].q)) {
				meal[i].state = 1;
			}
		}
		for (int i = 1; i <= k; ++i) {
			if (meal[i].state) 
				printf("Y");
			else
				printf("N");
		}
		printf("\n");
	}
	return 0;
}

void nonempty(int& virt, int const& k, int const& curmeal, int const& i) {
	int num = 0;
	int min = 100000;
	for (int j = 1; j <= k; ++j) {
		if (j == curmeal)
			continue;
		if (meal[j].lg >= i)
			continue;
		if (meal[j].q < min) {
			num = j;
			min = meal[j].q;
		}
	}
	virt -= min;
	meal[num].q = 0;
	meal[num].state = 1;
}