#include <stdio.h>

struct sTree {
    int L, R;
    int pl, pr;

    int BL, BR;
    int dl, dr;
} tree[200009];
int treeSize = 0;

int arr[100009];

int BuildTree(int L, int R)
{
    int cur = ++treeSize;
    tree[cur].L = L;
    tree[cur].R = R;
    tree[cur].dl = -1;
    tree[cur].dr = -1;
    if (L < R) {
        tree[cur].pl = BuildTree(L, (L+R)/2);
        tree[cur].pr = BuildTree((L+R)/2+1, R);
    }

    return cur;
}

void Cut(int, int, int);

void ProcessDebt(int cur)
{
    if (tree[cur].dl != -1) {
        Cut(tree[cur].pl, tree[cur].dl, tree[cur].dr);
        Cut(tree[cur].pr, tree[cur].dl, tree[cur].dr);
        tree[cur].dl = -1;
    }
}

void Cut(int cur, int L, int R)
{
    if (L <= tree[cur].L && R >= tree[cur].R) {
        tree[cur].BL = L;
        tree[cur].BR = R;
        tree[cur].dl = L;
        tree[cur].dr = R;
        return;
    }

    ProcessDebt(cur);

    if (L <= tree[ tree[cur].pl ].R && tree[ tree[cur].pl ].L <= R)
        Cut(tree[cur].pl, L, R);
    if (L <= tree[ tree[cur].pr ].R && tree[ tree[cur].pr ].L <= R)
        Cut(tree[cur].pr, L, R);
}

int GetLeft(int cur, int i)
{
    if (tree[cur].L == tree[cur].R)
        return tree[cur].BL;

    ProcessDebt(cur);

    if (i <= tree[ tree[cur].pl ].R)
        return GetLeft(tree[cur].pl, i);
    else
        return GetLeft(tree[cur].pr, i);
}

int GetRight(int cur, int i)
{
    if (tree[cur].L == tree[cur].R)
        return tree[cur].BR;

    ProcessDebt(cur);

    if (i <= tree[ tree[cur].pl ].R)
        return GetRight(tree[cur].pl, i);
    else
        return GetRight(tree[cur].pr, i);
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);

    int root = BuildTree(1, N);

    int cnt = 0;
    int i = 1, j = 1;
    while (i <= N) {
        while (i < N && arr[i+1] == arr[j])
            i++;

        Cut(root, j, i);
        i++; j = i;
        cnt++;
    }

    int Q;
    scanf("%d", &Q);

    while (Q--) {
        int p, c;
        scanf("%d %d", &p, &c);


        if (arr[p] != c) {
            int L = GetLeft(root, p);
            int R = GetRight(root, p);
            arr[p] = c;

            if (L < p && p < R) { ///atrodas pa vidu
                cnt += 2;
                Cut(root, L, p-1);
                Cut(root, p, p);
                Cut(root, p+1, R);
            }
            else if (L == p && p < R) { ///atrodas uz kreisas
                if (p > 1 && arr[p-1] == arr[p]) {
                    int TL = GetLeft(root, p-1);
                    Cut(root, TL, p);
                }
                else {
                    cnt++;
                    Cut(root, p, p);
                }
                Cut(root, p+1, R);
            }
            else if (L < p && p == R) { ///atrodas uz labas
                if (p < N && arr[p+1] == arr[p]) {
                    int TR = GetRight(root, p+1);
                    Cut(root, p, TR);
                }
                else {
                    cnt++;
                    Cut(root, p, p);
                }
                Cut(root, L, p-1);
            }
            else { ///L == p == R
                if (p > 1 && p < N && arr[p-1] == arr[p] && arr[p] == arr[p+1]) {
                    cnt -= 2;
                    int TL = GetLeft(root, p-1);
                    int TR = GetRight(root, p+1);
                    Cut(root, TL, TR);
                }
                else if (p > 1 && arr[p-1] == arr[p]) {
                    cnt--;
                    int TL = GetLeft(root, p-1);
                    Cut(root, TL, p);
                }
                else if (p < N && arr[p] == arr[p+1]) {
                    cnt--;
                    int TR = GetRight(root, p+1);
                    Cut(root, p, TR);
                }
            }
        }

        printf("%d\n", cnt);
    }
}
