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

void go()
{
    for (int num = 1; ; num += 2)
    {
        make_turn('R');
        put_chars('D', num);
        put_chars('L', num);
        make_turn('D');
        put_chars('R', num + 1);
        put_chars('U', num + 1);
    }
}

int main()
{
    try
    {
        go();
    }
    catch(end_of_iteration e)
    {
        return 0;
    }
    return 0;
}
