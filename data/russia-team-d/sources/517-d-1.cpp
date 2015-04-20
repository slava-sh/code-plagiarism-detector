#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("fence.in");
ofstream out("fence.out");
int n,k,xb,ost=0,xn;
vector<int> a;
int main(){
    in>>n>>k;
    a.assign(n+1,0);
    c(i,1,n) in>>a[i];
    xb = *min_element(++a.begin(),a.end());
    c(i,1,n) ost+=a[i]-xb;
    xn=xb;
    out<<min(xn,k/n);
    //out<<xb<<" "<<ost;
}
