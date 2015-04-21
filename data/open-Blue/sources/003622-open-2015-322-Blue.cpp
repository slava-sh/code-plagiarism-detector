#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    string s;
    set<char> v;
    int l;
    cin >> l >> s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
        if (v.count(s[i]) == 0)
            v.insert(s[i]);
    if (l >= n){
        cout << 1 << endl << s;
    }else
    if (v.size() == 1){
        cout << v.size() << endl;
        for (set<char>::iterator i = v.begin(); i != v.end(); i++)
            cout << (*i) << endl;
    }else{
        int z[n + 1], l = 0, r = 0;
        z[0] = n;
        for (int i = 1; i < n; i++){
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            else
                z[i] = 0;
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
        bool ans = false;
        for (int i = 1; i <= l; i++){
            bool bb = false;
            for (int j = 0; j < n; j += i)
                if (z[j] < i)
                    bb = true;
            if (!bb){
                ans = true;
                cout << 1 << endl << s.substr(0, i);
                break;
            }
        }
        if (!ans){
            cout << v.size() << endl;
            for (set<char>::iterator i = v.begin(); i != v.end(); i++)
                cout << (*i) << endl;
        }
    }
    return 0;
}
