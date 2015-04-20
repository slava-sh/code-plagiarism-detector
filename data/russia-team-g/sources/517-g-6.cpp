#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("prizes.in");
ofstream out("prizes.out");
long long int n,m,mi,ma,s;
int kol(int k){
    return (k-2)/4+int((k-2)%4>0);
}
int main(){
    in>>n>>m;
    mi = min(n,m);
    ma = max(n,m);
    //cout<<mi<<" "<<ma;
    if (mi==1) out<<kol(ma); else out<<kol(mi);
    /*if (mi==0) out<<ma/4+int(ma%4>=2);
    else {out<<mi/4+int(mi%4>=2);}*/
}
