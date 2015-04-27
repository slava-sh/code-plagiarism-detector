#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;
const double E = double(1e-7);


int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int a = 0, b = 0, c = 0, l;
    cin >> l;
    cin >> s;
    if (l >= s.length()){
        cout << 1 << "\n" << s;
        return 0;
    }
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'a'){
            a++;
        }
        if (s[i] == 'b'){
            b++;
        }
        if (s[i] == 'c'){
            c++;
        }
    }
    if (a != 0 && b == 0 && c == 0){
        cout << 1 << "\na";
        return 0;
    }
    if (a == 0 && b != 0 && c == 0){
        cout << 1 << "\nb";
        return 0;
    }
    if (a == 0 && b == 0 && c != 0){
        cout << 1 << "\nc";
        return 0;
    }
    if (a != 0 && b != 0 && c == 0){
        if (s.length() % l != 0){
            cout << 2 << "\na\nb";
        } else {
            string s1 = "", s2 = "";
            bool f = 1;
            for (int i = 0; i < l; i++){
                s1 += s[i];
            }
            for (int k = 1; k < s.length() / l; k++){
                s2 = "";
                for (int i = 0; i < l; i++){
                    s2 += s[i + k];
                }
                if (s2 != s1){
                    bool f = 0;
                    break;
                }
            }
            if (f){
                cout << 1 << "\n" << s1;
            }
        }
    }
    return 0;
}
