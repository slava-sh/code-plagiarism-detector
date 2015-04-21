#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <functional>
#include <cassert>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l,n,pi[100105];
char s[100105],s2[100105];

int main()
{
    ///freopen("input.txt", "r", stdin);
    ///freopen("output.txt", "w", stdout);

    scanf("%d%s",&l,s);
    n = strlen(s);
    if (l >= n) { printf("1\n"); printf("%s",s); return 0; }
    bool isa = false, isb = false, isc = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') isa = true;
        if (s[i] == 'b') isb = true;
        if (s[i] == 'c') isc = true;
    }
    if (isa && !isb && !isc) { printf("1\n"); printf("a"); return 0; }
    if (!isa && isb && !isc) { printf("1\n"); printf("b"); return 0; }
    if (!isa && !isb && isc) { printf("1\n"); printf("c"); return 0; }

    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    int curlen = n - pi[n-1];
    if (n % curlen == 0 && curlen <= l) {
        strcpy(s2, s);
        s2[curlen] = 0;
        printf("1\n");
        printf("%s",s2);
        return 0;
    }

    if (!isa || !isb || !isc) {
        printf("2\n");
        if (isa) printf("a\n");
        if (isb) printf("b\n");
        if (isc) printf("c\n");
        return 0;
    }

    printf("3\na\nb\nc");

    return 0;
}
