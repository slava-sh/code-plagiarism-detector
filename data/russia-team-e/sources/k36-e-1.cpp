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
string s[200],s1,a[200],s2;
vector<string>v[200];
int n,b,k,ii,jj,ch=0;
bool check(){
    int i,j;
    for(i=0;i<n;i++){
        if(s1.substr(0,a[i].size())==a[i]){
            s2=s1;
            s2.replace(0,a[i].size(),"");
            for(j=0;j<v[i].size();j++)
                if(s2.substr(0,v[i][j].size())==v[i][j]){
                    ch=1;
                    ii=i,jj=j;
                    return 1;
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
        ch=0;
        if(check())
        if(ch){
            s1.replace(0,a[ii].size()+v[ii][jj].size(),"");
            if(s1[0]=='0')cout<<"Incorrect"<<endl;
            else{
                cout<<"+"<<a[ii]<<"("<<v[ii][jj]<<")";
                if(s1.size()==3)
                    cout<<s1<<endl;
                else
                if(s1.size()==4)
                    cout<<s1[0]<<s1[1]<<"-"<<s1[2]<<s1[3]<<endl;
                else
                if(s1.size()==5)
                    cout<<s1[0]<<s1[1]<<s1[2]<<"-"<<s1[3]<<s1[4]<<endl;
                else
                if(s1.size()==6)
                    cout<<s1[0]<<s1[1]<<"-"<<s1[2]<<s1[3]<<"-"<<s1[4]<<s1[5]<<endl;
                else
                if(s1.size()==7)
                    cout<<s1[0]<<s1[1]<<s1[2]<<"-"<<s1[3]<<s1[4]<<"-"<<s1[5]<<s1[6]<<endl;
            }
        }
        if(ch==0)
            cout<<"Incorrect"<<endl;
    }
    return 0;
}
/*
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
