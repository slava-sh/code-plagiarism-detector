#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];

int main() {
	freopen("fence.in", "r", stdin);
	//freopen("in.txt", "r", stdin);
	freopen("fence.out", "w", stdout);
	int i, n, k, min = 2000000000;
	
	scanf("%d %d", &n, &k);

	a[0] = 0;
	for(i = 1; i<=n; i++) {
		scanf("%d", a+i);
		if(a[i] < min) min = a[i];
	}


	sort(a, a+n+1);

	for(i = 0; i<n; i++) a[i] = -(a[i]-a[i+1]);

	a[n-1] = 0;


	sort(a, a+n);

	int sum = 0, x = 0, add = 0;
	for(i = 0; i<n; i++) sum += a[i];

	if(sum > k) x = 0;
	else {
		int minim = 2000000000;
		for(i = 0; i<n; i++) if(a[i] < minim) minim = a[i];
		x = minim;
	}

	i = 0;
	while((i<(n-1)) && (sum < k)) {
		sum += (i+1)*(a[i+1] - a[i]);
		if(sum > k) break;

		x = a[i+1];
		i++;
	}

	if(i == (n-1)) {
		x += (k - sum) / n;
	}

	if(x > min) x = min;

	if(n == 1) {
		if(k < min) x = k;
	}

	cout << x;

	return 0;
}