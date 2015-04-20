#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int T = 110;
char pCode[T][10];
char rCode[T][T][10];
int cntT[T];
char num[100];
int n;

void printStr(char *str, int pos, int cnt)
{
	for (int i = pos; i < pos + cnt; i++)
		printf("%c", str[i]);
}

void printAns(char *str, int a, int b)
{
	printf("+%s(%s)", pCode[a], rCode[a][b]);
	int len = strlen(str) - strlen(pCode[a]) - strlen(rCode[a][b]);
	int pos = strlen(pCode[a]) + strlen(rCode[a][b]);

	if (len == 3)
	{
		printStr(str, pos, 3);
	}
	else if (len == 4)
	{
		printStr(str, pos, 2);putchar('-');
		printStr(str, pos + 2, 2);
	}
	else if (len == 5)
	{
		printStr(str, pos, 3);putchar('-');
		printStr(str, pos + 3, 2);
	}
	else if (len == 6)
	{
		printStr(str, pos, 2);putchar('-');
		printStr(str, pos + 2, 2);putchar('-');
		printStr(str, pos + 4, 2);
	}
	else
	{
		printStr(str, pos, 3);putchar('-');
		printStr(str, pos + 3, 2);putchar('-');
		printStr(str, pos + 5, 2);
	}
	puts("");
}

void solve(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < n; i++)
	{
		bool h = true;
		int pLen = strlen(pCode[i]);
		for (int s = 0; s < pLen; s++)
		{
			if (pCode[i][s] != str[s])
			{
				h = false;
				break;
			}
		}
		if (h)
		{
			for (int s = 0; s < cntT[i]; s++)
			{
				bool f = true;
				int rLen = strlen(rCode[i][s]);
				for (int q = 0; q < rLen; q++)
				{
					if (str[q + pLen] != rCode[i][s][q])
					{
						f = false;
						break;
					}
				}
				if (f && str[pLen + rLen] != '0')
				{
					printAns(str, i, s);
					return;
				}
			}
		}
	}
	puts("Incorrect");
	return;
}

int main()
{
	freopen ("numbers.in", "r", stdin);
	freopen ("numbers.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf(" %s %d", &pCode[i], &cntT[i]);
		for (int s = 0; s < cntT[i]; s++)
		{
			scanf(" %s", &rCode[i][s]);
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf(" %s", num);
		solve(num);
	}

	return 0;
}