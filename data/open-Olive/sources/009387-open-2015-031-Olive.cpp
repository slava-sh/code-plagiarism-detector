#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

const int maxn = 1000010;

struct Tnode
{
    int L, R, key;
};

Tnode tree[4 * maxn];

void build_tree(int v, int L, int R)
{
    tree[v].L = L;
    tree[v].R = R;
    if (R - L == 1)
    {
        tree[v].key = 0;
        return;
    }
    int M = (L + R) / 2;
    build_tree(2 * v, L, M);
    build_tree(2 * v + 1, M, R);
    tree[v].key = 0;
}

int get_sum(int v, int left, int right)
{
    int L = tree[v].L;
    int R = tree[v].R;
    if (right <= L || R <= left)
    {
        return 0;
    }
    if (L >= left && R <= right)
    {
        return tree[v].key;
    }
    return get_sum(2 * v, left, right) + get_sum(2 * v + 1, left, right);
}

void update(int v, int x)
{
    int L = tree[v].L;
    int R = tree[v].R;
    if (x < L || x >= R) return;
    if (R - L == 1)
    {
        tree[v].key = 1;
        return;
    }
    update(2 * v, x);
    update(2 * v + 1, x);
    tree[v].key = tree[2 * v].key + tree[2 * v + 1].key;
}

int a[maxn];

int main()
{
    int n;
    cin >> n;
    int more[n + 3][n + 3];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] -= 1;
    }

    build_tree(1, -1, n + 3);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            more[i][j] = get_sum(1, j, n + 3);
            //cout << i  << ' ' << j << more[i][j] << '\n';
        }
        update(1, a[i]);
    }

    int answi = -2;
    int answj = -2;
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] < a[j]) continue;
            int num1 = -1;

            if (i + 1 < j)
            {
                num1 += more[j][a[i]] - more[i + 1][a[i]];
                num1 -= (more[j][a[j]] - more[i + 1][a[j]]);
            }

           /* for (int k = i + 1; k < j; ++k)
            {
                if (a[k] > a[i]) num1 += 1;
                if (a[k] > a[j]) num1 -= 1;
            }*/
            if (num1 < num)
            {
                num = num1;
                answi = i;
                answj = j;
            }
        }
    }

    cout << answi + 1 << ' ' << answj + 1;

    return 0;
}


