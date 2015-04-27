#include <iostream>

using namespace std;

int main()
{
    long long l, i, p, c;
    string s, k, z;
    cin >> l;
    cin >> s;
    z = "";
    c = 0;
    if (l >= s.size()){
        cout << 1 << endl;
        cout << s;
        return 0;
    }
    for (i = 0; i < l; i++){
        k = s.substr(0, i + 1);
        p = 0;
        z = "";
        if (s.size() % (i + 1) != 0){
            p = 1;
        }
        for (int j = 0; j < (s.size() / (i + 1)) + p; j++){
            z += k;
        }
        if (z == s){
            cout << 1 << endl;
            cout << k;
            c = 1;
            break;
        }
    }
    if (c == 0){
        cout << 2 << endl;
        cout << "a" << endl;
        cout << "b" << endl;
    }
    return 0;
}
