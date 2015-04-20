#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("sochi.in");
ofstream out("sochi.out");
int n,d,t=0,k=0,s;
//bool u=true;
//vector<bool> isneed;
vector<int> a;
vector<int> l3d;
//vector<int> b
int main(){
    in>>n>>d;
    a.assign(n+1,0);
    //b.assign(n+1,0);
    //isneend.assign(n+1,1);
    c(i,1,n) in>>a[i];
    //c(i,1,n) if (a[i]>2*d) {t+=a[i];k++;}

    c(i,1,n) if (a[i]>2*d) {if (a[i]>=3*d) {t+=a[i];k++;} else {
        l3d.push_back(a[i]);
    }}
    s = l3d.size();
    sort(l3d.begin(),l3d.end());
    if (s>1) {t+=l3d[s-1]+l3d[s-2];k+=2;} else if (s==1) {t+=l3d[s-1];k+=1;}
    if (k==0) out<<*(max_element(++a.begin(),a.end()));
    else out<<t-(k-1)*2*d;
    /*sort(++a.begin(),a.end());
    b[1] = a[n];
    b[n] = a[n-1];
    c(i,2,n-1) b[i]=a[n-i];
    t=a[1];
    c(i,2,n){
        //cout<<t<<" "<<a[i]<<" "<<2*d;
        t=t+a[i]-2*d;
    }
    out<<t;
    */
}
