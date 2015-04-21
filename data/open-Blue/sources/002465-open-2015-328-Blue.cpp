#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

string s;

int f[3];
int p[100500];

int main()
{
    int l;
    cin >> l;
    cin >> s;
    for(int i = 1; i < s.size(); ++i){
        p[i] = p[i-1];
        while(p[i] && s[i] != s[p[i]])
            p[i] = p[p[i]-1];
        p[i] += (s[i] == s[p[i]]);
    }
    int k = s.size() - p[s.size()-1];
    if(k && s.size() % k == 0 && k <= l){
        cout << 1 << '\n';
        for(int i = 0; i < k; ++i)
            cout << s[i];
    }
    else{
        cout << 2 << '\n';
        cout << "a\nb\n";
    }
    return 0;
}
