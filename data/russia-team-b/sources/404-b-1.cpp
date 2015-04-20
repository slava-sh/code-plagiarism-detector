#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

#define push_back pb
#define make_pair mp
#define first fr
#define second sc


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n,r;
	scanf("%d%d",&n,&r);
	vector<int>a(n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int ri=0;
	int ans=0;
	for (int i=0;i<n-1;i++)
	{
		while (ri<n&&a[ri]-a[i]<=r)ri++;
		if (ri<n)ans+=n-ri;
	}
	printf("%d",ans);
}