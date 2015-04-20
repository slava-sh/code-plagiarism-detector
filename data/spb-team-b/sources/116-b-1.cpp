#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

int main()
{
    fin.open("chess.in");
    fout.open("chess.out");
    int n;
    fin >> n;
    int f[n];
    for (int i = 0; i < n; i++){
        fin >> f[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (f[i] >= i + 1)
            cnt++;
        else break;
    }
    fout << cnt << endl;
    for (int i = 0; i < cnt; i++){
        fout << i + 1 << ' ' << i + 1 << endl;
    }
}
