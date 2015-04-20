#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;


const int brr=300010;
int n;
int R;
int d[brr];
ll ans=0;

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	
	scanf("%i %i", &n, &R);
	for (int i=0; i<n; i++)
		scanf("%i", &d[i]);

	for (int i=0; i<n-1; i++)
	{
		int l=i+1;
		int r=n-1;
		while (l<r)
		{
			int k=(l+r)/2;
			if (d[k]-d[i]<=R)
				l=k+1;
			else
				r=k;
		}

		if (d[l]-d[i]<=R)
			l++;
		ans+= (ll) (n-l); 
	}

	printf("%lld", ans);
}