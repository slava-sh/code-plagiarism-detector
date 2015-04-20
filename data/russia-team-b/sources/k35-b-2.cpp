#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <stdlib.h>
using namespace std;
vector <int> a;
int j,n,r,s=0;
int main(){
   ifstream cin("virus.in");
   ofstream cout("virus.out");
   //freopen("input.in","r",stdin);
   //freopen("output.in","w",stdout);
   cin>>n>>r;
   a.resize(n+1);
   for(int i=0; i<n; i++)
            cin>>a[i];

   for(int i=0; i<n; i++) {
        int check=a[i]-r;
        j= int( lower_bound(a.begin(),a.end(),check)-a.begin() );
       // cout<<j<<" ";
       // if(j!=i && j<i && a[i]-r>=a[j])
             s+=(j);
   }
   cout<<s<<endl;
   //system("pause");
}
/*
4 4
1 3 5 8
*/
