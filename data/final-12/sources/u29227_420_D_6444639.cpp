#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Treap
{
    int size, key, auxkey, val;
    Treap *lf, *rg;

    Treap(int _size, int _key, int _auxkey, int _val, Treap *_lf, Treap *_rg)
    {
        size = _size;
        key = _key;
        auxkey = _auxkey;
        val = _val;
        lf = _lf;
        rg = _rg;
    }
};
Treap *nil = new Treap(0, 0, 0, 0, 0, 0);
Treap *root = nil;

void get_size(Treap* &nod)
{
    if (nod == nil) return;
    nod->size = nod->lf->size + nod->rg->size + 1;
}
void rotate_lf(Treap* &nod)
{
    Treap* aux = nod->lf;
    nod->lf = nod->lf->rg;
    aux->rg = nod;
    nod = aux;

    get_size(nod->lf);
    get_size(nod->rg);
    get_size(nod);
}
void rotate_rg(Treap* &nod)
{
    Treap* aux = nod->rg;
    nod->rg = nod->rg->lf;
    aux->lf = nod;
    nod = aux;

    get_size(nod->lf);
    get_size(nod->rg);
    get_size(nod);
}
void balance(Treap* &nod)
{
    if (nod->lf->val > nod->val) rotate_lf(nod);
    if (nod->rg->val > nod->val) rotate_rg(nod);
    get_size(nod);
}
void insert(Treap* &nod, int key, int auxkey, int val)
{
    if (nod == nil)
    {
        nod = new Treap(1, key, auxkey, val, nil, nil);
        return;
    }

    if (nod->key > key) insert(nod->lf, key, auxkey, val);
    else                insert(nod->rg, key, auxkey, val);

    balance(nod);
}
void erase(Treap* &nod, int key)
{
    if (nod->key > key)
    {
        erase(nod->lf, key);
        balance(nod);
    }
    else if (nod->key < key)
    {
        erase(nod->rg, key);
        balance(nod);
    }
    else
    {
        if (nod->lf == nil && nod->rg == nil)
        {
            delete nod;
            nod = nil;
            return;
        }
        if (nod->lf->val > nod->rg->val)
        {
            rotate_lf(nod);
            erase(nod->rg, key);
            balance(nod);
        }
        else
        {
            rotate_rg(nod);
            erase(nod->lf, key);
            balance(nod);
        }
    }
}
int findt(Treap* &nod, int szn)
{
    if (nod->lf->size == szn) return nod->auxkey;

    if (nod->lf->size > szn) return findt(nod->lf, szn);
    else                     return findt(nod->rg, szn - nod->lf->size - 1);
}

int get_rand()
{
    int now = rand() * rand();
    if (now < 0) now = -now;
    if (now == 0) return 1;
    return now;
}

int N, M;
int A[1000002], F[1000002], W[1000002];
set<int> S;
bool impossible;

int main()
{
    srand(time(0));
    cin.sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        insert(root, i, i, get_rand() + 1);
        W[i] = i;
    }
    for (int i = 1, what, where; i <= M; ++i)
    {
        cin >> what >> where;

        int pos = findt(root, where - 1);

        erase(root, W[pos]);
        W[pos] = --W[0];
        insert(root, W[pos], pos, get_rand() + 1);

        if (A[pos] == 0)
            A[pos] = what;
        else if (A[pos] != what)
            impossible = true;
    }

    for (int i = 1; i <= N; ++i)
        if (A[i] != 0)
        {
            if (F[A[i]] == 1) impossible = true;
            ++F[A[i]];
        }
    for (int i = 1; i <= N; ++i)
        if (F[i] == 0)
            S.insert(i);

    if (impossible)
        printf("-1\n");
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            if (A[i] == 0)
            {
                A[i] = (*S.begin());
                S.erase(S.begin());
            }
            printf("%d ", A[i]);
        }
        printf("\n");
    }
}
