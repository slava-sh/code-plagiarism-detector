#include <bits/stdc++.h>

using namespace std;

void go(char c, int n)
{
    char d;
    for(int i=0;i<n;i++)
    {
        putc(c, stdout);
        putc('\n', stdout);
        fflush(stdout);
        d = getc(stdin);
        if(d != 'N')
            exit(0);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    for(int i=1;;i++)
    {
        go('U', 2*i-1);
        go('R', 2*i-1);
        go('D', 2*i);
        go('L', 2*i);
    }
    return 0;
}
