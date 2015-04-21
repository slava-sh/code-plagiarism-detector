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
    for (int i = 0; i < s.size(); i++)
        if (v.count(s[i]) == 0)
            v.insert(s[i]);
    cout << v.size() << endl;
    for (set<char>::iterator i = v.begin(); i != v.end(); i++)
        cout << (*i) << endl;

    return 0;
}
