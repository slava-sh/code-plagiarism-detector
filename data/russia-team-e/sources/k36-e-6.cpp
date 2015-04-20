#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <time.h>
#include <cassert>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
string a[20000];
vector<string>v[20000];
int n,b,k,ii,jj;
bool check(string s1){
    int i,j;
    string s2;
    //cout << "---------------------" << endl;
    for(i=0;i<n;i++){
        if(a[i][0]=='0')continue;
        if(s1.substr(0,a[i].size())==a[i]){
            s2=s1.substr(a[i].size());
            //cout << "code found " << a[i] << " " << s2 << endl;
            for(j=0;j<v[i].size();j++){
                if(v[i][j][0]=='0')continue;
                if(s2.substr(0,v[i][j].size())==v[i][j]) {
                    s2 = s1.substr(a[i].size()+v[i][j].size());
                    if ( s2.size() < 3 || s2.size() > 7 || s2[0] == '0' )
                        continue;
                    cout << "+" << a[i] << "(" << v[i][j] << ")";
                    if(s2.size()==3)
                        cout<<s2<<endl;
                    else
                    if(s2.size()==4)
                        cout<<s2[0]<<s2[1]<<"-"<<s2[2]<<s2[3]<<endl;
                    else
                    if(s2.size()==5)
                        cout<<s2[0]<<s2[1]<<s2[2]<<"-"<<s2[3]<<s2[4]<<endl;
                    else
                    if(s2.size()==6)
                        cout<<s2[0]<<s2[1]<<"-"<<s2[2]<<s2[3]<<"-"<<s2[4]<<s2[5]<<endl;
                    else
                    if(s2.size()==7)
                        cout<<s2[0]<<s2[1]<<s2[2]<<"-"<<s2[3]<<s2[4]<<"-"<<s2[5]<<s2[6]<<endl;
                    else continue;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main () {
    int i,j;
    freopen ("numbers.in", "r", stdin);
    freopen ("numbers.out", "w", stdout);

    cin >> n;

    string s1;
    for(i=0;i<n;i++){
        cin >> a[i]>>b;
        for(j=0;j<b;j++){
            cin>>s1;
            v[i].push_back(s1);
        }
    }
    cin>>k;
    for(i=1;i<=k;i++){
        cin>>s1;
        if ( !check(s1) )
            cout<<"Incorrect"<<endl;
    }
    return 0;
}
/*
1
996 8
770
550
700
7777
7
77
77777
77777
8
99677002345
99655012345
99670012345
99677771234
99677777123
99677123456
99671234567


2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040

*/
