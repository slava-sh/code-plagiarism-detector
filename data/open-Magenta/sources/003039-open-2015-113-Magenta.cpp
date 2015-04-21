#include <bits/stdc++.h>

using namespace std;

void go(char c, int n)
{
    char d;
    for(int i=0;i<n;i++)
    {
        cout << c << endl;
        cin >> d;
        if(d != 'N')
            exit(0);
    }
}

int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    for(int i=1;i<50;i++)
    {
        go('U', 2*i-1);
        go('R', 2*i-1);
        go('D', 2*i);
        go('L', 2*i);
    }
    for(int i=0;i<1000;i++)
    {
        go('D', 20);
        go('R', 1);
        go('U', 20);
        go('R', 1);
    }
    for(int i=0;i<1000;i++)
    {
        go('R', 20);
        go('U', 1);
        go('L', 20);
        go('U', 1);
    }
    return 0;
}
