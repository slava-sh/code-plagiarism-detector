#include <stdio.h>
#include <cmath>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> d;
vector <long long> pref;
vector <long long> post;


int main(){
	long long a, n, flag = 1;
	freopen("merlin.in", "r", stdin);
	freopen("merlin.out", "w", stdout);
	scanf("%I64d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &a);
		d.push_back(a);
	}
	sort(d.begin(), d.end());
	for (int i = 1; i < n; i++)
		if (d[i - 1] != d[i])
			flag = 0;
	if (flag)
	{
		printf("0");
		return 0;
	}
	pref.push_back(d[0]);
	for (int i = 1; i < n; i++)
		pref.push_back(pref[i - 1] + d[i]);
	post.push_back(pref[n - 1]);
	for (int i = 1; i < n; i++)
		post.push_back(post[i - 1] - d[i - 1]);
	int i = n - 1;
	while (post[i] < i*d[i - 1] - pref[i - 1])
		i--;
	printf("%I64d", n - i);
//	_getch();
	return 0;
}