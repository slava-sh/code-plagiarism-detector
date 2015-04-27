#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>


#define FNAME ""

#define pb push_back
#define mp make_pair

#define forn(i, n) for (int i = 0; i < n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

using namespace std;

template <class T> T sqr(const T &a) {return a * a;}



struct Node
{
    Node () {left = right = NULL;}
	Node (int _x, int _pos, int _y)
	{	
		left = right = NULL;
		x = _x, y = _y, pos = _pos, add = 0, size = 1;
	}
	Node *left, *right;
	int size, y, x, add, pos;
};

typedef Node* pnode;

inline int size(pnode r)
{
	if (!r)
		return 0;
	return r->size;
}
inline void update(pnode &r)
{
	if (!r)
		return;
	r->size = size(r->left) + size(r->right) + 1;
}
void split(pnode r, pnode &a, pnode &b, int k)
{
	if (!r)  
	{
		a = NULL;
		b = NULL;
		return;
	}
	if (size(r->left) >= k)
	{
		;
		split(r->left, a, r->left, k);
		b = r;
		update(a);
		update(b);
		return;
	}
	else
	{	
		;
		split(r->right, r->right, b, k - size(r->left) - 1);
		a = r;
		update(a);
		update(b);
		return;
	}
}

pnode merge(pnode a, pnode b)
{
	if (!a)
		return b;
	if (!b)
		return a;
	if (a->y > b->y)
	{
		a->right = merge(a->right, b);
		update(a);
		return a;	
	}
	else
	{
		b->left = merge(a, b->left);
		update(b);
		return b;
	}
}

int used[1000010], ans[1000010], x[1000000], y[1000000], pos, n, m;
pnode r, a, b;

void print(pnode r)
{
	if (r == NULL)	
		return;

	print(r->left);               
	//printf("size = %d key = %d\n", size(r), r->x);
	if (r->x == -1)
	{
		while (used[pos])
			pos++;
		printf("%d ", pos);
		pos++;
	}
	else
		printf("%d ", r->x);    
	print(r->right);
}

int main()
{
	pos = 0;
	scanf("%d%d", &n, &m);
	forn(i, n)
		ans[i] = -1;
	r = new Node(-1, 0, rand());
	forn(i, n - 1)
		r = merge(r, new Node(-1, i + 1, (rand() << 16) + rand()));
	forn(i, m)
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i]--;
		split(r, a, r, y[i] - 1);
		split(r, r, b, 1);
		if ((r->x != -1 && r->x != x[i]) || (r->x != x[i] && used[x[i]]))
		{
			puts("-1");
			return 0;
		}                          
	    ans[r->pos] = x[i];
	    r->x = x[i];
	    used[x[i]] = 1;
		r = merge(r, a);
		r = merge(r, b);
	}                          
	forn(i, n)
	{
		if (ans[i] == -1)
		{
			while (used[pos])
				pos++;
			printf("%d ", pos + 1);
			pos++;
		}
		else
			printf("%d ", ans[i] + 1);
	}
}