#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define DB(v) cerr << #v << ' ' << v << endl;

string s,cur = "",now;
int l;

string dubl(string need,int k)
{
    string ans = need;
    for(int i = 1;i < k;++i){ans += need;}
    return ans;
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin >> l;
    cin >> s;
    int n = (int)s.length();
    bool have_a = false,have_b = false,have_c = false;
    if(l >= n){cout << 1 << endl << s;return 0;}
    for(int i = 0;i < n;++i){
        if(s[i] == 'a'){have_a = true;}
        else if(s[i] == 'b'){have_b = true;}
        else {have_c = true;}
    }
    string need;
    for(int i = 0;i <= min(l-1,n-1);++i)
    {
        cur += s[i];
        if(n % (i+1) == 0){
            need = dubl(cur,n/(i+1));
            if(need == s){
                cout << 1 << endl << cur;
                return 0;
            }
        }
    }
    cout << have_a + have_b + have_c << endl;
    if(have_a){cout << 'a' << endl;}
    if(have_b){cout << 'b' << endl;}
    if(have_c){cout << 'c' << endl;}
    return 0;
}
