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
    /*for (int i = 0; i < 50; i++){
        if (n % 2){
        cout << "R\n";
        cout.flush();
        cin >> s;
        if (s == "Y" || s == "E") return 0;
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
        cout << "D\n";
        cout.flush();
        cin >> s;
        if (s == "Y" || s == "E") return 0;
        for (int i = 0; i < n; i++){
            cout << "R\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        for (int i = 0; i < n; i++){
            cout << "U\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        }
        n++;
    }*/
    while (true){
        for (int i = 0; i < (500 / n); i++){
            cout << "R\n";
            cout.flush();
            cin >> s;
            if (s == "Y" || s == "E") return 0;
        }
        cout << "U\n";
        cout.flush();
        cin >> s;
        if (s == "Y" || s == "E") return 0;
        n++;
    }
    return 0;
}
