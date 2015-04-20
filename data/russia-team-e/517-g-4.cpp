#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define c(i,s,f) for(int i=s;i<=f;i++)
ifstream in("prizes.in");
ofstream out("prizes.out");
long long int n,m,mi,ma,s;
int main(){
    in>>n>>m;
    mi = min(n,m) - 1;
    ma = max(n,m) - 1;
    //cout<<mi<<" "<<ma;
    if (mi==0) out<<ma/4+int(ma%4>=2);
    else {out<<mi/4+int(mi%4>=2);}
}
