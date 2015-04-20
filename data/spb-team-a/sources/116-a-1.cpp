#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

int main()
{
    fin.open("abcd.in");
    fout.open("abcd.out");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        if (((a / 100) % 7) * ((a / 100) % 7) + ((a % 100) % 7) * ((a % 100) % 7) == 1)
            fout << "YES" << endl;
        else fout << "NO" << endl;
    }
}
