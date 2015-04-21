#include <iostream>

using namespace std;

bool move(string s){
    cout << s << endl;
    cout.flush();
    cin >> s;
    if (s == "N") return false;
    return true;
}

int main(){
    int n = 1;
    while (true){
        if (n % 2){
        if(move("R"))return 0;
        for (int i = 0; i < n; i++){
            if(move("D"))return 0;
        }
        for (int i = 0; i < n; i++){
            if(move("L"))return 0;
        }
        }
        else{
        if(move("D"))return 0;
        for (int i = 0; i < n; i++){
            if(move("R"))return 0;
        }
        for (int i = 0; i < n; i++){
            if(move("U"))return 0;
        }
        }
        n++;
    }
    return 0;
}
