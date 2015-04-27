#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef unsigned long long  LL;
using namespace std ;
typedef pair<int,int> PII;

char s[110000][10],c[110000];
int p[110000],t[110000],cnt;
bool flag[110000],before[110000],later[110000];
vector<int> print;
set<int> now;

int main(){
    int N,M,i;
    scanf("%d%d",&N,&M);
    for (i=1;i<=M;i++){
        scanf("%s%d",s[i],&p[i]);
        if (!c[p[i]]) c[p[i]]=*s[i];
    }
    for (i=1;i<=N;i++){
        if (c[i]=='-'){
            now.insert(i); flag[i]=1;
        }
        if (!c[i]) flag[i]=1;
    }
    int leader=0;
    if (now.size()==0){
        flag[p[1]]=1; leader=p[1];
    }
    for (i=1;i<=M;i++){
        if (*s[i]=='+'){
            if (now.size()==0 && p[i]!=leader) flag[leader]=0;
            now.insert(p[i]);
        }else{
            if (now.size()==1 && flag[p[i]]) leader=p[i];
            if (now.size()>1) flag[p[i]]=0;
            now.erase(p[i]);
        }
    }
    for (i=1;i<=N;i++) 
        if (flag[i]) print.push_back(i);
    printf("%d\n",print.size());
    for (i=0;i<print.size();i++) printf("%d ",print[i]);
}
