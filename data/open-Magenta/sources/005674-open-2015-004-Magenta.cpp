#include <iostream>
#include <string>

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
    string s;
    while (true){
        if (n % 2){
        for (int i = 0; i < n; i++){
            cout << "D\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        for (int i = 0; i < n; i++){
            cout << "L\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        }
        else{
        for (int i = 0; i < n; i++){
            cout << "U\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        for (int i = 0; i < n; i++){
            cout << "R\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        }
        n++;
    }
    return 0;
}

