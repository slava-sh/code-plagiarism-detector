#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
    int col = 0, sum;
    char c;
    for (int k = 0;1; k+=2){
        for (int i = 0; i < 110; i++){
            col++;
            sum++;
            if (col == 2 + k)
                col = 0;
            if (col != 0)
                cout << 'R' << endl;
            else
                cout << 'U' << endl;
            cout.flush();
            scanf("%s", &c);
            //cin >> s;
            if (c == 'Y')
                return 0;
        }
    }
    return 0;
}
