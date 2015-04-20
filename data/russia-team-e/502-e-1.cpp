#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF=1000000000;

int getint() {
    int x;
    scanf("%d",&x);
    return x;
}

bool inRange(int x, int l, int r) {
    if (l>r) swap(l,r);
    return x>=l && x<=r;
}

set<pair<int,int> > sett;

int toInt(string t) {
    int res=0;
    for (size_t i=0;i<t.length();i++)
        res=res*10+t[i]-'0';
    return res;
}

bool check(string a, string b, string c) {
    if (!inRange(a.length(),1,3) || !inRange(b.length(),3,5) || !inRange(c.length(),3,7)) {
        return false;
    }
    if (a[0]=='0' || b[0]=='0' || c[0]=='0') return false;
    int n1=toInt(a),n2=toInt(b);
    if (sett.find(make_pair(n1,n2))==sett.end()) return false;
    printf("+%s(%s)",a.c_str(),b.c_str());
    if (c.length()==3) cout << c;
    else if (c.length()==4) cout << c[0] << c[1] << '-' << c[2] << c[3];
    else if (c.length()==5) cout << c[0] << c[1] << c[2] << '-' << c[3] << c[4];
    else if (c.length()==6) cout << c[0] << c[1] << '-' << c[2] << c[3] << '-' << c[4] << c[5];
    else cout << c[0] << c[1] << c[2] << '-' << c[3] << c[4] << '-' << c[5] << c[6];
    cout << '\n';
    return true;
}

void solve() {
    string s;
    cin >> s;
    int n=11;
    for (int len1=1;len1<=3;len1++)
        for (int len2=3;len2<=5;len2++) {
            if (check(s.substr(0,len1),s.substr(len1,len2),s.substr(len1+len2,max(0,11-len1+len2)))) return;
        }
    cout << "Incorrect\n";
}

int main()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    int n,m,c,k,x;
    cin >> n;
    while (n--) {
        cin >> c >> k;
        while (k--) {
            cin >> x;
            sett.insert(make_pair(c,x));
        }
    }
    cin >> m;
    while (m--) {
        solve();
    }
    return 0;
}
