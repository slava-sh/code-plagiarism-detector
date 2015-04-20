#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("fence.in");
ofstream out("fence.out");
int n,k,xb,ost=0,xn,xa,t=0,nm,gm=1000000,me,d=0;
vector<int> a;
vector<int> b;
bool isx(int x){
    t=0;
    int tn=0;
    c(i,1,n){
        if (t<a[i]-x) tn=a[i];
        else tn=t+x;
        if (tn-t<x) return false;
        if (tn>k) return false;
        t=tn;
    }
    return true;
}
int main(){
    in>>n>>k;
    a.assign(n+1,0);
    //b.assign(n+1,0);
    c(i,1,n) {in>>a[i];/*b[i]=k-a[i];*/}
    sort(++a.begin(),a.end());
    me = *min_element(++a.begin(),a.end());
    //cout<<isx(2);
    for(int i=me;i>=0;i--) if (isx(i)) {d=i;break;}
    out<<d;
    /*t=0;
    c(i,1,n){
        nm=min(k-t,a[i]);
        gm=(min(gm,nm));
        t+=nm;
        cout<<nm<<" "<<gm<<" "<<t<<endl;
    }
    out<<gm;
    */
    /*
    xa = *min_element(++a.begin(),a.end());
    xb = *min_element(++b.begin(),b.end());
    //c(i,1,n) ost+=a[i]-xb;
    //xn=xb;
    //out<<min(xa,k/n);
    out<<min(xa,xb);
    //out<<xb<<" "<<ost;
    */
}
