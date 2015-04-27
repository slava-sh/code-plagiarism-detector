#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 333333;

int cnt[N];

int a[N], b[N];

map<pair<int, int>, int> exist;

int n, p;

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i ++){
		scanf("%d%d", &a[i], &b[i]);
		if(a[i] > b[i]) swap(a[i], b[i]);
		exist[make_pair(a[i], b[i])] ++;
		cnt[a[i] - 1] ++;
		cnt[b[i] - 1] ++;
	}
	long long counter1 = 0;
	for(map<pair<int, int>, int>::iterator it = exist.begin(); it != exist.end(); it ++){
		int u = it->first.first, v = it->first.second;
		if(cnt[u - 1] + cnt[v - 1] >= p && cnt[u - 1] + cnt[v - 1] - it->second < p)
			counter1 ++;
	}
	
	sort(cnt, cnt + n);
	
//	for(int i = 0; i < n; i ++)
//		cout<<cnt[i]<<' ';cout<<endl;
	
	long long counter = 0;
	for(int i = 1; i < n; i ++){
		int l = 0, r = i - 1, t = -1, mid;
		while(l <= r){
			mid = (l + r)/2;
			if(cnt[i] + cnt[mid] >= p){
				t = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		if(t != -1)
			counter += (long long) i - t;
	}
	
	printf("%I64d\n", counter - counter1);
}
