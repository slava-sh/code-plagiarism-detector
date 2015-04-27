#include<iostream>
#include<cstdio>
using namespace std;


const int baza=131071;
int a[262145];
int k,n;


int sum(int v, int l, int r, int L, int R){
    if((l==L)&&(r==R))  return a[v];
    if(l<=(L+R)/2){
        if(r<=(L+R)/2){
            return sum(v*2,l,r,L,(L+R)/2);
        }else{
            return(sum(v*2,l,(L+R)/2,L,(L+R)/2)+sum(v*2+1,(L+R)/2+1,r,(L+R)/2+1,R));
        }
    }else{
        return sum(v*2+1,l,r,(L+R)/2+1,R);
    }
}


int main(){
    freopen("signchange.in","r",stdin);
    freopen("signchange.out","w",stdout);
    cin>>n;
    for(int i=baza+1; i<=baza+n; i++){
        cin>>k;
        if((i-baza)%2==0)  a[i]=-k;
        else               a[i]=k;
    }
    for(int i=baza; i>=1; i--){
        a[i]=a[2*i]+a[2*i+1];
    }
    cin>>n;
    for(int i=0; i<n; i++){
        int x,l,r;
        cin>>x>>l>>r;
        if(x==0){
            l+=baza;
            if((l-baza)%2==0)  a[l]=-r;
            else        a[l]=r;
            while(l>1){
                l/=2;
                a[l]=a[l*2]+a[l*2+1];
            }
        }else{
            if(l%2==1){
                cout<<sum(1,l,r,1,baza+1);
            }else{
                cout<<-(sum(1,l,r,1,baza+1));
            }
            cout<<endl;
        }
    }
    return 0;
}
