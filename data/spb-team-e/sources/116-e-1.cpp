#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin;
ofstream fout;

int per(int a, int b, int c, int d){
    if ((a > c) || (b > d)) return 0;
    if (a <= c){
        if (b < c){
            return 0;
        } else if (b < d) {
            return (b - c + 1);
        } else {
            return 0;
        }
    } else {
        if (d < b){
            return 0;
        } else if (d < a) {
            return (a - d + 1);
        } else {
            return 0;
        }
    }
}

int main(){
    fin.open("game.in");
    fout.open("game.out");
    int n, m;
    fin >> m >> n;
    int l1, r1, l2, r2;
    fin >> l1 >> r1 >> l2 >> r2;
    int c1, c2, c3, c4;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    c4 = 0;
    int st[m];
    for (int i = 0; i < m; i++){
        fin >> st[i];
        if (st[i] < l1) c1++;
        if (st[i] > r1) c2++;
        if (st[i] < l2) c3++;
        if (st[i] > r2) c4++;
    }
    l1 = c1 + 1;
    l2 = c3 + 1;
    r1 = m - c2;
    r2 = m - c4;
    /*if (r1 < l1){
        l1 = -1;
        r1 = -1;
    }
    if (r2 < l2){
        l2 = -1;
        r2 = -1;
    }*/
    //cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
    int c = 0;
    int p[2];
    p[0] = 0;
    p[1] = 0;
    int v[2];
    v[0] = 0;
    v[1] = 0;
    if (1 == 1){
        int cnt = per(l1, r1, l2, r2);
        //cout << cnt;
        while (n > 0 && cnt > 0){
            n--;
            cnt--;
            p[c]++;
            c = 1 - c;
            v[0]++;
            v[1]++;
        }
        if (n == 0){
            if (p[1] > p[0]) fout << "Vasya";
            else if (p[1] < p[0]) fout << "Petya";
            else fout << "Draw";
            return 0;
        }
        while (n > 0 && v[0] < r1 - l1 + 1 && v[1] < r2 - l2 + 1){
            n--;
            p[c]++;
            v[c]++;
            c = 1 - c;
        }
        while (n > 0){
            if ((v[0] == r1 - l1 + 1 && c == 0) || (v[1] == r2 - l2 + 1 && c == 1)){
                n--;
                c = 1 - c;
            } else {
                n--;
                p[c]++;
                v[c]++;
                c = 1 - c;
            }
        }
        if (p[1] > p[0]) fout << "Vasya";
        else if (p[1] < p[0]) fout << "Petya";
        else fout << "Draw";
        return 0;
    }
}
