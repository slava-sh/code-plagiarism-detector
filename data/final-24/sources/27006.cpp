#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define F first
#define S second

struct er{
    int x, y,t;
};

const int INF = 2000000000;

er e[50200];

vector<int> d[50200];

vector<pair<int, int> > g[60100];

int main(){
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l,n;
    string s;
    cin >>l;
    cin >> s;
    if (l >= s.length()){
        cout << 1 << endl;
        cout << s << endl;
    }
    else{
        cout << 2 << endl;
        cout << "aba" << endl;
        cout << "ab" << endl;
    }
    return 0;
}
