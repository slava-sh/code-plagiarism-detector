#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("numbers.in");
ofstream out("numbers.out");
const int inf = 1000000000;
int n,y,k,e;
string c,u,t;
map<string,int> m;
string mista(string s){
    int t=int(s.length());
    switch(t){
    case 3:return s;break;
    case 4:return s.substr(0,2)+"-"+s.substr(2,2);break;
    case 5:return s.substr(0,3)+"-"+s.substr(3,2);break;
    case 6:return s.substr(0,2)+"-"+s.substr(2,2)+"-"+s.substr(4,2);break;
    case 7:return s.substr(0,2)+"-"+s.substr(3,2)+"-"+s.substr(5,2);break;
    }
}
string f(string s){
    t=s.length();
    string ss;
    int op,r;
    c(i,1,s.length()){
        ss = s.substr(0,i);
        if (m.count(ss)==1) op=m[ss]; else continue;
        if (s[i]=='0') continue;
        r=ss.length();
        return "+"+ss.substr(0,op)+"("+ss.substr(op)+")"+mista(s.substr(i));
    }
    return "Incorrect";
}
int main(){
    in>>n;
    c(i,1,n){
        in>>c>>k;
        y=c.length();
        c(j,1,k){
            in>>u;
            m[c+u]=y;
        }
    }
    in>>e;
    c(i,1,e) {in>>t;out<<f(t)<<endl;}
}
