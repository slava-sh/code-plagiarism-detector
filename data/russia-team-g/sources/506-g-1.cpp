#include <fstream>
#include <vector>

using namespace std;

ifstream fin("prizes.in");
ofstream fout("prizes.out");

int main() {
    int n, m;
    fin >> n >> m;
    if (n == 1 || m == 1) {
        fout << ((n == 1 ? m : n) + 1 ) / 4;
        return 0;
    }
    if (n == 2 || m == 2) {
        fout << 0;
        return 0;
    }
    fout << 1;
    return 0;
}
