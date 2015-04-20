#include <iostream>
#include <cmath>

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n, k, minim = 2000000000;
	
	scanf("%d %d", &n, &k);
	n++;

	for(int i = 0; i<n; i++) {
		int t;
		scanf("%d", &t);
		if(t < minim) minim = t;
	}

	if(k/n < minim) minim = k/n;

	printf("%d", minim);

	return 0;
}