#include <iostream>
#include <cstdio>
using namespace std;
//
const int MAXN=100000;
const int MAXSTEP=131072;
//
int n,m;
int step,sz;
//
int tree[MAXSTEP*2-1];
//
void set(int i,int v){
    int ind=i+step-1;
    if(ind%2==0)v=-v;
    int old=tree[ind];
    int diff=v-old;
    //tree[ind]=v;
    while(ind>0){
        tree[ind]+=diff;
        ind=(ind-1)/2;
    }
    tree[0]+=diff;
}
int xget(int L,int R,int a,int b,int v){
    if(a>R||b<L){
        return 0;
    }
    else if(a>=L&&b<=R)return tree[v];
    else return xget(L,R,a,(a+b-1)/2,v*2+1)+xget(L,R,(a+b-1)/2+1,b,v*2+2);
}
int get(int L,int R){
    return xget(L+step-1,R+step-1,step-1,sz-1,0);
}
//
int main()
{
    freopen("signchange.in","rw",stdin);
    freopen("signchange.out","w",stdout);
    cin>>n;
    //
    step=1;
    while(step<n)step*=2;
    sz=step*2-1;
    //
    for(int i=step-1;i<step-1+n;i++){
        cin>>tree[i];
        if(i%2==0)tree[i]=-tree[i];
    }
    for(int i=step-2;i>=0;i--){
        tree[i]=tree[2*i+1]+tree[2*i+2];
    }
    //
    cin>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        if(a==0){
            set(b-1,c);
        }
        else{
            int tmp=get(b-1,c-1);
            if(b%2==0)cout<<-tmp<<endl;
            else cout<<tmp<<endl;
        }
    }
    /*cout<<"---"<<endl;
    for(int i=0;i<sz;i++){
        cout<<tree[i]<<endl;
    }*/
    return 0;
}
