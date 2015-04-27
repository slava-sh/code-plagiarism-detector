#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

set<pair<int, int> > r;

void go(vector<pair<int, int> > p) {
    if (p.size() <= 1) return;
    vector<pair<int, int> > L, M, R;
    int n = p.size();
    int m = n / 2;
    int xm = p[m].first;
    for (int i = 0; i < n; ++i)
        if (p[i].first < xm) L.push_back(p[i]);
        else if (p[i].first > xm) R.push_back(p[i]);
    go(L);
    go(R);
    for (int i = 0; i < n; ++i)
        r.insert(make_pair(xm, p[i].second));
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > p;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back(make_pair(x, y));
        r.insert(make_pair(x, y));
    }
    sort(p.begin(), p.end());

    go(p);

    cout << r.size() << endl;
    for (set<pair<int, int> >::iterator i = r.begin(); i != r.end(); ++i) 
        cout << i->first << " " << i->second << endl;

    return 0;
}