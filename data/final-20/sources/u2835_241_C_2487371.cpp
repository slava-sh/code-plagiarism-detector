#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

int L[101],R[101],pos[101],v[101],hl,hr,n;
bool ok[101];
char ch;

long long prod(long long x1,long long y1,long long x2,long long y2){
    return x1*y2-x2*y1;
}

int solve(int k,int f){
    int dev=0;
    int posL=hl,posR=hr;
    
    for(int i=1;i<=k;i++){
        if(f==1)posR=200-posR;
        else posR=-posR;
        f=1-f;
    }
    
    f=1-f;
    memset(ok,0,sizeof(ok));
    
    for(int i=1;i<=k;i++){
        int aux=-1;
        for(int j=1;j<=n;j++){
            if(pos[j]==f*100 &&!ok[j]){
                if(f==0&& prod(100000,posR-posL,L[j],pos[j]-posL)<=0&&
                    prod(100000,posR-posL,R[j],pos[j]-posL)>=0){
                        dev+=v[j];
                        ok[j]=1;
                        aux=j;
                        break;
                }
                else if (f==1&& prod(100000,posR-posL,L[j],pos[j]-posL)>=0&&
                    prod(100000,posR-posL,R[j],pos[j]-posL)<=0){
                    dev+=v[j];
                    ok[j]=1;
                    aux=j;
                    break;
                }
            }
        }
        
        if(aux==-1)return 0;
        if(f==1){
            posL=200-posL;
            posR=200-posR;
        }else{
            posL=-posL;
            posR=-posR;    
        }
        
        f=1-f;
    }
    return dev;
}

int main(){
    
	//freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    while(cin>>hl>>hr>>n){
        int dev=0;
        for(int i=1;i<=n;i++){
            cin>>v[i]>>ch>>L[i]>>R[i];
            pos[i]=0;
            if(ch=='T')
                pos[i]=100;
        }
        
        for(int i=1;i<=n;i++){
            dev=max(dev,solve(i,0) );
            dev=max(dev,solve(i,1) );
        }   
        
        cout<<dev<<endl;
    }
    return 0;
}
