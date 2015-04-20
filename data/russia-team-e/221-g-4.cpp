#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

#define INF 1<<30

using namespace std;

const int N = 111111;

int n, m;

int main()
{
    #define TASKNAME "prizes"

    #ifdef DEBUG
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d%d", &n, &m);

    if (n == 2 || m == 2)
    {
        printf("0");
        return 0;
    }

    if (n == 1 || m == 1)
    {
        printf("%d", (n+m)/4);
        return 0;
    }

    printf("1");

    return 0;
}
