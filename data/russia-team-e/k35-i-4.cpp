#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <stdlib.h>
#include <queue>
using namespace std;
priority_queue <int> q;
int n,d,a;
int main(){
   ifstream cin("sochi.in");
   ofstream cout("sochi.out");
    cin>>n>>d;
   for(int i=0;n>i;i++)
   {
       cin>>a;
       q.push(a);
   }

   while(q.size()>1)
    {
        int f,s,inde;
        f=q.top();
        q.pop();

        s=q.top();
        q.pop();
        s-=d;
        f-=d;
        if(s < 0) s = 0;
        if(f < 0) f = 0;
        q.push(f+s);
    }
    cout<<q.top()<<endl;
}
