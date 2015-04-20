#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n, k, x, a[200000];
long long s;

int finds(int mid){
    s = 0;
        for(int i = 1; i <= n; i++)

            if(a[i] > s + mid)
                s = a[i];
            else
                s = s + mid;


    return s;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
        cin>>a[i];

    if(n == 1){
        cout<<min(k, a[1]);
        exit(0);
    }

    sort(a + 1, a + n + 1);

    int s, mid, l = 0, r = min(k / n, a[1]);
    while(r - l > 1){
        mid = (l + r) / 2;
        if(finds(s) > k)
            r = mid - 1;
        else
            l = mid;
    }
    if(finds(r) > k) r = l;
    cout<<r;
	return 0;
}
