#include <iostream>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <fstream>
using namespace std;
int main ()
{
    //freopen ("prizes.in", "r", stdin);
    ifstream cin("prizes.in");
    ofstream cout("prizes.out");
    //freopen ("input.txt", "r", stdin);
    long long int n, m;
    cin >> n >> m;
    if (n>m) swap(n, m);
    if (n==1)
    {
        cout << (m+1)/4 << endl;
        return 0;
    }
    if (n==2)
    {
        cout << "0" << endl;
        return 0;
    }
    if (n>2)
    {
        cout << "1" << endl;
        return 0;
    }
    return 0;
}
