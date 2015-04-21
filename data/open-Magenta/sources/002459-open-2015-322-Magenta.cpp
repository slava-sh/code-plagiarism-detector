#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>

using namespace std;

int main(){
    int col = 0, sum;
    char c;
    int k = 607;
    for (int j = 0;1; j++){
        //col = 0;
        //k += 2;
        //k %= 11111;
        for (int i = 0; i < 150; i++){
            col++;
            //sum++;
            if (col == 2 + k)
                col = 0;
            if (col != 0)
                printf("R\n");
                //cout << 'R' << endl;
            else
                printf("U\n");
                //cout << 'U' << endl;
            cout.flush();
            scanf("%s", &c);
            //cin >> s;
            if (c == 'Y')
                return 0;
        }
        for (int i = 0; i < 150; i++){
            col++;
            //sum++;
            if (col == 2 + k)
                col = 0;
            if (col != 0)
                printf("U\n");
                //cout << 'R' << endl;
            else
                printf("R\n");
                //cout << 'U' << endl;
            cout.flush();
            scanf("%s", &c);
            //cin >> s;
            if (c == 'Y')
                return 0;
        }
        k++;
    }
    return 0;
}
