#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    int col = 0, sum;
    string s;
    for (int k = 0;1; k++){
        for (int i = 0; i < 100; i++){
            col++;
            sum++;
            if (col == 2 + k)
                col = 0;
            if (col != 0)
                cout << "R" << endl;
            else
                cout << "U" << endl;
            cout.flush();
            cin >> s;
            if (s[0] == 'Y')
                return 0;
        }
    }
    return 0;
}
