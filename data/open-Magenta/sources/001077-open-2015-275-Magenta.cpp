#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define forn(i,a,b) for(int i = a; i < (int)b; i++)
#define srep(i, a) for(__typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

void go(char c)
{
    cout << c << endl;
    cout.flush();
    cin >> c;
    if (c == 'Y' || c == 'E')
        exit(0);
}

int main()
{
    go('U');
    go('R');
    go('D');
    go('R');
    int k = 1;
    while (1)
    {
        rep(i, k*2) go('U');
        rep(i, k*2) go('L');
        go('U');
        rep(i, k*2+1) go('R');
        rep(i, k*2+1) go('D');
        go('R');
        k++;
    }
    return 0;
}
