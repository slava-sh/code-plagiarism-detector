#include <bits/stdc++.h>

using namespace std;

//ifstream fin("input.txt");
//ofstream fout("output.txt");

const int S = 330;


void send(char c)
{
    cout << c << endl;
    cout.flush();
    char get;
    cin >> get;
    assert(get != 'E');
    if (get == 'Y')
        exit(0);
}


void try_kvadrat()
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
            send('L');
        send('D');
    }
}


void try_w()
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j * j < S; j++)
            send('L');
        send('D');
    }
}


void try_h()
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j * j < S; j++)
            send('U');
        send('R');
    }
}


int main()
{
    try_kvadrat();
    try_w();
    try_h();
    return 0;
}
