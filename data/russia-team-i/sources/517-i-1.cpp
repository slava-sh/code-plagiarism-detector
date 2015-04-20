#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("sochi.in");
ofstream out("sochi.out");
int n,d,t;
vector<int> a;
int main(){
    in>>n>>d;
    a.assign(n+1,0);
    c(i,1,n) in>>a[i];
    sort(++a.begin(),a.end());
    t=a[1];
    c(i,2,n){
        t=t+a[i]-2*d;
    }
    out<<t;
}
