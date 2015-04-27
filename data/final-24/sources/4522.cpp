#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <vector>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

char s[102];

bool pref(long long l)
{
    long long len = strlen(s);
    bool ok = true;
    for (long long i = 0; i < len; i++)
        if (s[i] != s[i % l])
            return false;
    if ((len % l != 0) || (ok == false))
        return false;
    return true;
}

int main()
{
    long long l;
    scanf("%lld", &l);
    scanf("%s", s);
    for (long long i = 1; i <= l; i++)
        if (pref(i))
        {
            printf("1\n");
            for (long long j = 0; j < i; j++)
                fputc(s[j], stdout);
            fputc('\n', stdout);
            return 0;
        }
    printf("2\na\nb\n");
    return 0;
}
