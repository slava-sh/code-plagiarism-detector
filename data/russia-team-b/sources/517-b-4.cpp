#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("che.in");
ofstream out("che.out");
int n,nr,t,l,r;
long long int num=0;
vector<int> d;
int main(){
    in>>n>>nr;
    d.assign(n+1,0);
    c(i,1,n) in>>d[i];
    c(i,1,n){
        l=i;r=n+1;
        while (r-l>1){
            if (d[(r+l)/2]-d[i]<=nr) l=(r+l)/2; else r=(r+l)/2;
        }
        //cout<<i<<" "<<l<<" "<<r<<endl;
        if (r>=i+1&&r<=n) num+=n-r+1;
    }
    out<<num;
}
