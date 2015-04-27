#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define sqr(x) (x * x)

using namespace std;

const int maxn = 100001;
const long long base = 29;

string s[maxn];
long long  p[maxn];
vector<long long> hash_1[maxn], hash_2[maxn];
int n;

long long h1(int x, int l, int r)
{
    if (l == 0)
        return hash_1[x][r];
    return hash_1[x][r] - hash_1[x][l - 1] * p[r - l + 1];
}

long long h2(int x, int l, int r)
{
     if (r == s[x].length() - 1)
        return hash_2[x][l];
     return hash_2[x][l] - hash_2[x][r + 1] * p[r - l + 1];
}

void check(int x)
{
    int an;
    long long ha1 = hash_1[x][s[x].length() - 1];
    long long ha2 = hash_2[x][0];
    for(an = 0; an <= s[x].length() - 1; an++)
    {
        if (ha1 == ha2)
        {
            printf("%d\n", an);
            return;
        }
        ha1 = h1(x, 0, an) + h1(x, an + 1, s[x].length() - 1) * p[an + 1];
        ha2 = h2(x, an + 1, s[x].length() - 1) + h2(x, 0, an) * p[s[x].length() - an - 1];
    }
    printf("-1\n");
    return;
}

int main()
{
    freopen("inventory.in", "rt", stdin);
    freopen("inventory.out", "wt", stdout);
    scanf("%d", &n);
    p[0] = 1;
    for(int i = 1; i <= maxn; i++)
        p[i] = p[i - 1] * base;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 1; i <= n; i++)
    {
        hash_1[i].push_back(s[i][0] - 'a' + 1);
        hash_1[i].resize(s[i].length());
        for(int j = 1; j < s[i].length(); j++)
            hash_1[i][j] = hash_1[i][j - 1] * base + (s[i][j] - 'a' + 1);
        hash_2[i].resize(s[i].length());
        hash_2[i][s[i].length() - 1] = (s[i][s[i].length() - 1] - 'a' + 1);
        for(int j = s[i].length() - 2; j >= 0; j--)
            hash_2[i][j] = hash_2[i][j + 1] * base + (s[i][j] - 'a' + 1);
    }
    for(int i = 1; i <= n; i++)
        check(i);
    return 0;
}
