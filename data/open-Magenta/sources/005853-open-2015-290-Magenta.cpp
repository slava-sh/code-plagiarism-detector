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
    for (int num = 1; num <= 19; num += 2)
    {
        make_turn('R');
        put_chars('D', num);
        put_chars('L', num);
        make_turn('D');
        put_chars('R', num + 1);
        put_chars('U', num + 1);
    }
    make_turn('R');
    for (int i = 1; i < 9; i++)
    {
        put_chars('R', 281);
        make_turn('D');
        put_chars('L', 281);
        make_turn('D');
    }
    make_turn('D');
    make_turn('L');
    for (int i = 1; i < 9; i++)
    {
        put_chars('D', 281);
        make_turn('L');
        put_chars('U', 281);
        make_turn('L');
    }
}

void go3()
{
    for (int num = 1; num <= 45; num += 2)
    {
        make_turn('R');
        put_chars('D', num);
        put_chars('L', num);
        make_turn('D');
        put_chars('R', num + 1);
        put_chars('U', num + 1);
    }
    make_turn('R');
    for (int i = 1; i < 23; i++)
    {
        put_chars('R', 1654);
        make_turn('D');
        put_chars('L', 1654);
        make_turn('D');
    }
    put_chars('R', 1654);
    put_chars('L', 1654);
    make_turn('D');
    make_turn('L');
    for (int i = 1; i < 23; i++)
    {
        put_chars('D', 1654);
        make_turn('L');
        put_chars('U', 1654);
        make_turn('L');
    }
    put_chars('D', 1654);
}

int main()
{
    try
    {
        go();
        go3();
    }
    catch(end_of_iteration e)
    {
        return 0;
    }
    return 0;
}
