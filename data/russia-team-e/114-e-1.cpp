#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define LLD "%I64d"

#define FILENAME "numbers"

struct tnode
{
	tnode *next[10];
	tnode *prev;
	int isend;

	tnode()
	{
		for (int i = 0; i < 10; i++) next[i] = NULL;
		prev = NULL;
		isend = 0;
	}
};

typedef tnode* pnode;

pnode add(pnode cur, char *s, int curp, int endt, pnode prev)
{
	if (s[curp] == '\0')
	{
		cur->isend |= endt;
		if (prev != NULL) cur->prev = prev;
		return cur;
	}
	if (cur->next[s[curp] - '0'] == NULL) cur->next[s[curp] - '0'] = new tnode();
	return add(cur->next[s[curp] - '0'], s, curp + 1, endt, prev);
}

char s[20];
int n, m;
pnode root;

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d", &n);
	root = new tnode();
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%s%d", s, &k);
		pnode cur = add(root, s, 0, 1, NULL);
		for (int j = 0; j < k; j++)
		{
			scanf("%s", s);
			add(cur, s, 0, 2, cur);
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", s);
		pnode cur = root;
		int curp = 0;
		bool ok = true;

		while (cur->isend != 2 || s[curp] == '0')
		{
			if (cur->next[s[curp] - '0'] == NULL)
			{
				ok = false;
				break;
			}
			cur = cur->next[s[curp] - '0'];
			curp++;
			if (curp > 10)
			{
				ok = false;
				break;
			}
		}
		if (!ok) printf("Incorrect\n");
		else
		{
			pnode wh = cur->prev;
			printf("+");
			pnode cur = root;
			int curp = 0;

			while (cur != wh)
			{
				cur = cur->next[s[curp] - '0'];
				printf("%c", s[curp]);
				curp++;
			}
			printf("(");
			while (cur->isend != 2 || s[curp] == '0')
			{
				cur = cur->next[s[curp] - '0'];
				printf("%c", s[curp]);
				curp++;
			}
			printf(")");
			int len = 11 - curp;
			if (len % 2 == 1)
			{
				printf("%c", s[curp]);
				curp++;
			}
			while (curp < 11)
			{
				printf("%c%c", s[curp], s[curp + 1]);
				curp += 2;
				if (curp < 11) printf("-");
			}
			printf("\n");
		}
	}
	return 0;
}