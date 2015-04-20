#include <iostream>
#include <algorithm>
using namespace std;

int a[1000001];

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
		int val, mid, l = a[i], r = a[i+1];
		
		int t = k-sum;

		while(l<r) {
			mid = (l+r+1) / 2;
			val = (i+1)*(mid - a[i]);
			if(val > t) r = mid - 1;
			else l = mid;
		}

		sum += (i+1)*(r - a[i]);
		if(sum > k) break;

		x = r;
		i++;
	}

	if(i == (n-1)) {
		x += (k - sum) / n;
	}

	if(x > min) x = min;

	if(n == 1) {
		if(k < min) x = k;
		else x = min;
	}

	cout << x;

	return 0;
}