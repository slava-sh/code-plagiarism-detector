#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("che.in");
ofstream out("che.out");
int n,r,num=0,t;
vector<int> d;
int main(){
    in>>n>>r;
    d.assign(n+1,0);
    c(i,1,n) in>>d[i];
    c(i,1,n){
        t=i;
        while (d[t]-d[i]<=r && t<=n) t++;
        if (t<=n) num+=n-t+1;
    }
    out<<num;
}
