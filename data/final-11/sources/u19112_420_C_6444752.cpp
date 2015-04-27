#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int> jdad[300004];
int n,p,_a,_b;
int repetit[300003];
int repetit_bs[300003];
int nn[300003];
int thelazynn[300003];
int thelazy=0;
long long thenumber=0,nm;
long long wholysol=0;
int get_nn(int ind){
        if(thelazynn[ind]==thelazy){
                return nn[ind];
        } else {
                return repetit[ind];
        }
}
void updateIII(int ind,int val){
        if(thelazynn[ind]!=thelazy){
                thelazynn[ind]=thelazy;
                nn[ind]=repetit[ind];
        }
        nn[ind]+=val;
}
int main(){
        scanf("%d %d",&n,&p);
        for(int i=0;i<n;i++){
                scanf("%d %d",&_a,&_b);
                _a--;
                _b--;
                repetit[_a]++;
                repetit[_b]++;
                jdad[_a].push_back(_b);
                jdad[_b].push_back(_a);
        }
        for(int i=0;i<n;i++){
                repetit_bs[i]=repetit[i];
        }
        sort(repetit_bs,repetit_bs+n);
 
        for(int i=0;i<n;i++){
                thelazy++;
                int l=-1,r=n;
                while(r-l>1){
                        if(p-repetit[i]<=repetit_bs[(r+l)/2]){
                                r=(r+l)/2;
                        } else {
                                l=(r+l)/2;
                        }
                }
                thenumber=n-r;
                if(repetit[i]>=p-repetit[i]){
                        thenumber--;
                }
                for(int j=0;j<jdad[i].size();j++){
                        int gg=jdad[i][j];
                        updateIII(gg,-1);
                        if(get_nn(gg)==p-repetit[i]-1){
                                thenumber--;
                        }
                }
                wholysol+=thenumber;
        }
        printf("%I64d\n",wholysol/2);
}