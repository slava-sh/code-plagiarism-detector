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

void go()
{
    array<char, 4> arr = {'U', 'L', 'D', 'R'};
    int i = 0;
    for (int num = 1; ; num++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < num; k++)
                make_turn(arr[i]);
            i = (i + 1) % 4;
        }
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
