#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <string>
using namespace std;
int n,s=0,a[100007],t[100007],r[100007],last[100007];
vector<vector<int> > v;
vector<int> ok(2);
void solve(){
    int i,j,k,h1,w1,m,s=0,mi=1e9;
    bool oko=true;
    scanf("%d%d",&m,&k);
    for(i=0;i<k+5;i++){
        a[i]=0;
        t[i]=0;
        r[i]=0;
        last[i]=-1;
    }
    for(i=1;i<=k;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<m-1;i++){
        scanf("%d%d",&t[i],&r[i]);
        last[t[i]]=i;
    }

    for(i=0;i<m-1;i++){
        //scanf("%d%d",&t[i],&r[i]);
        
        if(r[i]==1&&oko){
            for(j=1;j<=k;j++){
                if(last[j]<i&&a[j]<=s){
                    mi=min(mi,a[j]);
                    a[j]=0;
                }
            }
            oko=false;
            s-=mi;
        }
        if(t[i]==0){
            s++;
        }else{
            a[t[i]]--;
        }
    }
    for(i=1;i<=k;i++){
        if(a[i]-s>0){
            printf("N");
        }else{
            printf("Y");
        }
    }
    printf("\n");
}
int main() {
    #pragma comment(linker, "/STACK:67108864") 
   
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        solve();
    }
    return 0;
}