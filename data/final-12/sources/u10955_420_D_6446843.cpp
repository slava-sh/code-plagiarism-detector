#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = (int)2e8;

int mem_size;
char mem[SIZE];

inline void * operator new (size_t size)
{
    mem_size += size;
    if (mem_size > SIZE)
        throw;
    return mem + mem_size - size;
}

inline void operator delete (void * ptr) {}

struct Node
{
    int pr, info, cnt;
    Node * l;
    Node * r;

    Node() {}

    Node(int info): pr(rand()), info(info), cnt(1), l(NULL), r(NULL) {}
};

typedef Node * Node_ptr;

int get_cnt(Node_ptr v)
{
    if (v == NULL)
        return 0;
    return v->cnt;
}

void update(Node_ptr v)
{
    if (v == NULL)
        return;
    v->cnt = get_cnt(v->l) + get_cnt(v->r) + 1;
}

void split(Node_ptr v, int key, Node_ptr & t1, Node_ptr & t2)
{
    if (v == NULL)
    {
        t1 = t2 = NULL;
        return;
    }

    if (get_cnt(v->l) <= key)
    {
        split(v->r, key - get_cnt(v->l) - 1, v->r, t2);
        t1 = v;
        update(t1);
    }
    else
    {
        split(v->l, key, t1, v->l);
        t2 = v;
        update(t2);
    }
}

Node_ptr merge(Node_ptr t1, Node_ptr t2)
{
    if (t1 == NULL)
        return t2;
    if (t2 == NULL)
        return t1;

    if (t1->pr > t2->pr)
    {
        t1->r = merge(t1->r, t2);
        update(t1);
        return t1;
    }
    else
    {
        t2->l = merge(t1, t2->l);
        update(t2);
        return t2;
    }   
}

int move_to_front(Node_ptr & v, int ind)
{
    Node_ptr t1, t2, t3;
    split(v, ind - 1, t1, t2);
    split(t2, 0, t2, t3);
    int ind1 = t2->info;
    t1 = merge(t2, t1);
    v = merge(t1, t3);
    return ind1;
}

const int N = 1000500;

int n, m;
int perm[N];
bool in_perm[N];
bool used_num[N];
Node_ptr root;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    fill(perm, perm + N, -1);
    for (int i = 0; i < n; i++)
        root = merge(root, new Node(i));

    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;

        int ind = move_to_front(root, y);
        if (perm[ind] != -1 && perm[ind] != x)
        {
            puts("-1");
            return 0;
        }
        perm[ind] = x;
    }

    for (int i = 0; i < n; i++)
        if (perm[i] != -1)
        {
            if (used_num[perm[i]])
            {
                puts("-1");
                return 0;
            }
            used_num[perm[i]] = true;
        }

    for (int i = 0; i < n; i++)
        if (perm[i] != -1)
            in_perm[perm[i]] = true;

    vector<int> values;
    for (int i = 0; i < n; i++)
        if (!in_perm[i])
            values.push_back(i);
    sort(values.begin(), values.end());

    int ptr = 0;
    for (int i = 0; i < n; i++)
        if (perm[i] == -1)
            perm[i] = values[ptr++];

    for (int i = 0; i < n; i++)
        printf("%d ", perm[i] + 1);

    return 0;   
}