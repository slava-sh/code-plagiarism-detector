#include <stdio.h>
#include <cmath>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> a;


int main(){
	long long n, m, x, l1, r1, l2, r2, left1, left2, right1, right2, common, only1, only2, p1 = 0, p2 = 0;
	bool first = true;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%I64d%I64d", &n, &m);
	scanf("%I64d%I64d", &l1, &r1);
	scanf("%I64d%I64d", &l2, &r2);
	for (int i = 0; i < n; i++)
	{
		scanf("%I64d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	left1 = 0;
	while (left1 < n && (a[left1] < l1 || a[left1] > r1))
		left1++;
	right1 = n - 1;
	while (right1 >= 0 && (a[right1] < l1 || a[right1] > r1))
		right1--;
	
	left2 = 0;
	while (left2 < n && (a[left2] < l2 || a[left2] > r2))
		left2++;
	right2 = n - 1;
	while (right2 >= 0 && (a[right2] < l2 || a[right2] > r2))
		right2--;

	if (left1 == n && left2 == n)
	{
		printf("Draw");
		//_getch();
		return 0;
	}
	
	if (left1 == n)
	{
		printf("Vasya");
		//_getch();
		return 0;
	}
	
	if (left2 == n)
	{
		printf("Petya");
		//_getch();
		return 0;
	}

	common = min(right1, right2) - max(left1, left2) + 1;
	if (common < 0)
		common = 0;
	only1 = right1 - left1 - common + 1;
	only2 = right2 - left2 - common + 1;

	if (m <= common)
	{
		if (m % 2 == 0)
		{
			printf("Draw");
			//_getch();
			return 0;
		}
		else
		{
			printf("Petya");
			//_getch();
			return 0;
		}
	}
	else
	{
		if (common % 2 != 0)
		{
			p1 = 1;
			first = false;
		}
		m -= common;
	}

	while (m > 0)
	{
		if (only1 == 0 && only2 == 0)
			break;
		if (first)
		{
			if (only1 > 0)
			{
				only1--;
				p1++;
			}
		}
		else
		{
			if (only2 > 0)
			{
				only2--;
				p2++;
			}
		}
		m--;
		first = !first;
	}

	if (p1 == p2)
		printf("Draw");
	if (p1 > p2)
		printf("Petya");
	if (p2 > p1)
		printf("Vasya");

	//_getch();
	return 0;
}