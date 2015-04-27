#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int hl, hr, n, h[110], ans;
int f[100010], t[100010];
int idf[100010], idt[100010];
char s[10];

void calc()
{
	h[0] = hl - hr;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (flag)
			h[i] = h[i - 1] + 2 * hr;
		else h[i] = h[i - 1] + 2 * (100 - hr);
		flag = !flag;
	}
	for (int i = 1; i <= n; i++)
	{
		bool p = true;
		int tmp = 0, hh = hl;
		int ff = 0, tt = 0;
		for (int j = 1; j <= i && p; j++)
		{
			int x = 100000 * hh;
			if (x % h[i] == 0)
				x = x / h[i] - 1;
			else x = x / h[i];
			if (j % 2 == 1)
				if (f[x] && ff != idf[x])
				{
					tmp += f[x];
					ff = idf[x];
				}
				else p = false;
			else
				if (t[x] && tt != idt[x])
				{
					tmp += t[x];
					tt = idt[x];
				}
				else p = false;
			hh += 100;
		}
	//	if (p) cout << i << " " << tmp << endl;
		if (p)
			if (ans < tmp)
				ans = tmp;
	}
}

int main()
{
	memset(f, 0, sizeof(f));
	memset(t, 0, sizeof(t));
	memset(idf, 0, sizeof(idf));
	memset(idt, 0, sizeof(idt));
	scanf("%d%d%d", &hl, &hr, &n);
	for (int i = 1; i <= n; i++)
	{
		int v, a, b;
		scanf("%d%s%d%d", &v, s, &a, &b);
		for (int j = a; j < b; j++)
		{
			if (s[0] == 'F')
				f[j] = v;
			else t[j] = v;
			if (s[0] == 'F')
				idf[j] = i;
			else idt[j] = i;
		}
			
	}
	calc();
	for (int i = 0; i <= 100000; i++)
	{
		int temp = f[i];
		f[i] = t[i];
		t[i] = temp;
		temp = idf[i];
		idf[i] = idt[i];
		idt[i] = temp;
	}
	hl = 100 - hl;
	hr = 100 - hr;
	calc();
	printf("%d\n", ans);
	return 0;
}
