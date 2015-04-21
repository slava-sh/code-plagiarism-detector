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

void go(int mx)
{
    for (int i = 1; i <= mx; i+= 2)
    {
        put_chars('R', (mx + i - 1) / i - 1);
        make_turn('D');
        put_chars('L', (mx + i - 1) / i - 1);
        make_turn('D');
    }
}

int main()
{
    try
    {
        go(300);
    }
    catch(end_of_iteration e)
    {
        return 0;
    }
    return 0;
}
