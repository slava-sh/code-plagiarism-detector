#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

struct field{
    int a, b, c;
};
int main()
{
    fin.open("dunes.in");
    fout.open("dunes.out");
    int n, m;
    fin >> n >> m;
    field f[n];
    for (int i = 0; i < n; i++){
        fin >> f[i].a >> f[i].b >> f[i].c;
    }
    for (int i = 0; i < m; i++){
        int g;
        fin >> g;
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (f[j].a <= g && f[j].b >= g)
                if ((g - f[j].a) % 2 == 0)
                    cnt += f[j].c;
                else cnt -= f[j].c;

        }
        fout << cnt << endl;
    }


}
