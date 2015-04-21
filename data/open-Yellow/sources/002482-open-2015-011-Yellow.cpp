#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>

using namespace std;

int N, Q;
////////////////////////////DECART////////////////////////////
int SIZE = 2e5;

struct Node
{
    int X_L, X_R, T, Y, L, R, A;
};

vector<Node> Tree;
vector<int> Nums;
set<int> Free;

void refresh(int V)
{
    if (V == -1)
    {
        return;
    }
    Tree[V].A = 1;
    if (Tree[V].L != -1)
    {
        Tree[V].A += Tree[Tree[V].L].A;
    }
    if (Tree[V].R != -1)
    {
        Tree[V].A += Tree[Tree[V].R].A;
    }
    return;
}

int Add()
{
    int V = *Free.begin();
    Free.erase(Free.begin());
    Tree[V].X_L = 0;
    Tree[V].X_R = 0;
    Tree[V].T = 0;
    Tree[V].Y = rand();
    Tree[V].A = 1;
    Tree[V].L = -1;
    Tree[V].R = -1;
    return V;
}

void Delete(int V)
{
    if (V != -1)
    {
        Free.insert(V);
    }
}

int Merge(int L, int R)
{
    if (L == -1)
    {
        return R;
    }
    else if (R == -1)
    {
        return L;
    }
    else
    {
        if (Tree[L].Y > Tree[R].Y)
        {
            Tree[L].R = Merge(Tree[L].R, R);
            refresh(L);
            return L;
        }
        else
        {
            Tree[R].L = Merge(L, Tree[R].L);
            refresh(R);
            return R;
        }
    }
}

pair<int, int> Split(int V, int K)
{
    if (V == -1)
    {
        return make_pair(-1, -1);
    }
    if (Tree[V].R == -1 and K == Tree[V].X_R)
    {
        return make_pair(V, -1);
    }
    else if (Tree[V].X_L == K)
    {
        int rez = Tree[V].L;
        Tree[V].L = -1;
        refresh(V);
        return make_pair(rez, V);
    }
    if (Tree[V].X_L > K)
    {
        pair<int, int> rez = Split(Tree[V].L, K);
        Tree[V].L = rez.second;
        refresh(V);
        return make_pair(rez.first, V);
    }
    else if (Tree[V].X_R <= K)
    {
        pair<int, int> rez = Split(Tree[V].R, K);
        Tree[V].R = rez.first;
        refresh(V);
        return make_pair(V, rez.second);
    }
    else
    {
        int New = Add();
        Tree[New].R = Tree[V].R;
        Tree[V].R = -1;
        Tree[New].T = Tree[V].T;
        Tree[New].X_R = Tree[V].X_R;
        Tree[New].X_L = K; Tree[V].X_R = K;
        refresh(V); refresh(New);
        return make_pair(V, New);
    }
}

int Find(int V, int K)
{
    if (V == -1)
    {
        return -1;
    }
    if (Tree[V].X_L > K)
    {
        return Find(Tree[V].L, K);
    }
    else if (Tree[V].X_R <= K)
    {
        return Find(Tree[V].R, K);
    }
    else
    {
        return V;
    }
}

void print_tree(int V, int D)
{
    if (V == -1)
    {
        return;
    }
    print_tree(Tree[V].R, D + 1);

    for (int i = 0; i < D; ++i)
    {
        printf("     ");
    }
    printf("[%d, %d): %d; %d\n", Tree[V].X_L, Tree[V].X_R, Tree[V].T, Tree[V].A);

    print_tree(Tree[V].L, D + 1);
}
///////////////////////////////////////////////////////////////////////
int main()
{
    srand(179179179);

    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    Tree.resize(SIZE);
    for (int i = 0; i < SIZE; ++i)
    {
        Free.insert(i);
    }

    int Root = -1;
    scanf("%d", &N);
    int L = 0, R = 0, Curr = -1, Num, V;
    scanf("%d", &Num);
    R = 1; Curr = Num;
    Nums.resize(N);
    for (int i = 1; i < N; ++i)
    {
        scanf("%d", &Num);
        Nums[i] = Num;
        if (Num == Curr)
        {
            ++R;
        }
        else
        {
            V = Add();
            Tree[V].X_L = L;
            Tree[V].X_R = R;
            Tree[V].T = Curr;
            Root = Merge(Root, V);
            //print_tree(Root, 0);
            //printf("\n");
            Curr = Num;
            L = R;
            ++R;
        }
    }
    V = Add();
    Tree[V].X_L = L;
    Tree[V].X_R = R;
    Tree[V].T = Curr;
    Root = Merge(Root, V);
    //print_tree(Root, 0);
    //printf("\n###############\n");

    scanf("%d", &Q);
    if (N == 1)
    {
        for (int i = 0; i < Q; ++i)
        {
            printf("1\n");
        }
        return 0;
    }

    int P, T;
    pair<int, int> rez_1, rez_2;
    for (int i = 0; i < Q; ++i)
    {
        scanf("%d%d", &P, &T); --P;
        if (Nums[P] != T)
        {
            if (P == 0)
            {
                rez_1 = Split(Root, 1);
                V = Find(rez_1.first, P);
                Tree[V].T = T;
                if (Nums[1] == T)
                {
                    V = Find(rez_1.second, 1);
                    Tree[V].X_L = 0;
                    Delete(rez_1.first);
                    Root = rez_1.second;
                }
                else
                {
                    Root = Merge(rez_1.first, rez_1.second);
                }
            }
            else if (P == N - 1)
            {
                rez_1 = Split(Root, N - 1);
                V = Find(rez_1.second, P);
                Tree[V].T = T;
                if (Nums[N - 2] == T)
                {
                    V = Find(rez_1.first, N - 2);
                    Tree[V].X_R = N;
                    Delete(rez_1.second);
                    Root = rez_1.first;
                }
                else
                {
                    Root = Merge(rez_1.first, rez_1.second);
                }
            }
            else
            {
                if (Nums[P - 1] == Nums[P])
                {
                    if (Nums[P + 1] == Nums[P])
                    {
                        rez_1 = Split(Root, P);
                        rez_2 = Split(rez_1.second, P + 1);
                        V = Find(rez_2.first, P);
                        Tree[V].T = T;
                        Root = Merge(rez_1.first, Merge(rez_2.first, rez_2.second));
                    }
                    else
                    {
                        rez_1 = Split(Root, P);
                        V = Find(rez_1.second, P);
                        Tree[V].T = T;
                        if (Nums[P + 1] == T)
                        {
                            rez_2 = Split(rez_1.second, P + 1);
                            V = Find(rez_2.second, P + 1);
                            --Tree[V].X_L;
                            Delete(rez_2.first);
                            Root = Merge(rez_1.first, rez_2.second);
                        }
                        else
                        {
                            Root = Merge(rez_1.first, rez_1.second);
                        }
                    }
                }
                else
                {
                    if (Nums[P + 1] == Nums[P])
                    {
                        rez_1 = Split(Root, P + 1);
                        V = Find(rez_1.first, P);
                        Tree[V].T = T;
                        if (Nums[P - 1] == T)
                        {
                            rez_2 = Split(rez_1.first, P);
                            V = Find(rez_2.first, P - 1);
                            ++Tree[V].X_R;
                            Delete(rez_2.second);
                            Root = Merge(rez_2.first, rez_1.second);
                        }
                        else
                        {
                            Root = Merge(rez_1.first, rez_2.second);
                        }
                    }
                    else
                    {
                        V = Find(Root, P);
                        Tree[V].T = T;
                        if (Nums[P - 1] == T)
                        {
                            if (Nums[P + 1] == T)
                            {
                                V = Find(Root, P + 1);
                                rez_1 = Split(Root, Tree[V].X_R);
                                rez_2 = Split(rez_1.first, P);
                                int V_2 = Find(rez_2.first, P - 1);
                                Tree[V_2].X_R = Tree[V].X_R;
                                Delete(Tree[rez_2.second].L);
                                Delete(Tree[rez_2.second].R);
                                Delete(rez_2.second);
                                Root = Merge(rez_2.first, rez_1.second);
                            }
                            else
                            {
                                rez_1 = Split(Root, P);
                                rez_2 = Split(rez_1.second, P + 1);
                                V = Find(rez_1.first, P - 1);
                                ++Tree[V].X_R;
                                Delete(rez_2.first);
                                Root = Merge(rez_1.first, rez_2.second);
                            }
                        }
                        else
                        {
                            if (Nums[P + 1] == T)
                            {
                                rez_1 = Split(Root, P);
                                rez_2 = Split(rez_1.second, P + 1);
                                V = Find(rez_2.second, P + 1);
                                --Tree[V].X_L;
                                Delete(rez_2.first);
                                Root = Merge(rez_1.first, rez_2.second);
                            }
                        }
                    }
                }
            }
        }

        Nums[P] = T;
        //print_tree(Root, 0);
        printf("%d\n", Tree[Root].A);
    }

    return 0;
}

