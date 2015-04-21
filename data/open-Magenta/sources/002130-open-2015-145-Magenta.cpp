#include <bits/stdc++.h>

using namespace std;

//ifstream fin("input.txt");
//ofstream fout("output.txt");

const int S = 300;


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


void try_po_spirali()
{
    for (int i = 1; ; i += 2)
    {
        for (int j = 0; j < i; j++)
            send('D');
        for (int j = 0; j < i; j++)
            send('R');
        for (int j = 0; j < i + 1; j++)
            send('U');
        for (int j = 0; j < i + 1; j++)
            send('L');
    }
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
    try_po_spirali();
    //try_kvadrat();
    //try_w();
    //try_h();
    assert(false);
    return 0;
}
