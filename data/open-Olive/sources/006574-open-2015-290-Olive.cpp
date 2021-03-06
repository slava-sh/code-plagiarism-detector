#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

struct end_of_iteration
{
    end_of_iteration(){}
};

void make_turn(char c)
{
    cout << c << endl;
    cout.flush();
    char a;
    cin >> a;
    if (a != 'N')
        throw end_of_iteration();
}

void put_chars(char c, int n)
{
    for (int i = 0; i < n; i++)
        make_turn(c);
}

int bsearch(int i, int mx)
{
    int l = 0, r = mx + 1;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (i * mid > mx)
            r = mid;
        else
            l = mid;
    }
    return r;
}

void go(int mx)
{
    int cnt = 0;
    put_chars('R', mx);
    put_chars('L', mx);
    for (int i = 1; i <= mx; i++)
    {
        put_chars('L', bsearch(i, mx));
        make_turn('D');
        put_chars('R', bsearch(i, mx));
        cnt += 2 * (mx + i - 1) / i;
    }
    put_chars('U', mx + 1);
    for (int i = 1; i <= mx; i++)
    {
        put_chars('L', bsearch(i, mx));
        make_turn('U');
        put_chars('R', bsearch(i, mx));
        cnt += 2 * (mx + i - 1) / i;
    }
    //cout << cnt << endl;
}

int main()
{
    try
    {
        go(1000);
    }
    catch(end_of_iteration e)
    {
        return 0;
    }
    return 0;
}
