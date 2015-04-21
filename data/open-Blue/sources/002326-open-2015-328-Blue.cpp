#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

string s;

int f[3];

int main()
{
    int l;
    cin >> l;
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        f[ (s[i]-'a') ]++;
    }
    if(!f[0] || !f[1]){
        cout << 1 << '\n';
        if(f[0])
            cout << 'a';
        else
            cout << 'b';
    }
    else{
        cout << 2 << '\n';
        cout << "a\nb\n";
    }
    return 0;
}
