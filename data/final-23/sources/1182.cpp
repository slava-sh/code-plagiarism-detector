#include <iostream>
#include <cstdio>

using namespace std;

const int half=131072;
const int size=262144;

int a[size],a_index;
int b[size],b_index;
int n,m;

void make_tree(){
    cin>>n;
    for(int i=0;i<n;++i){
        if(i%2==0){
            cin>>a[half-1+i];
        }else{
            cin>>b[half-1+i];
        };
    };
    for(int i=half-2;i>=0;--i){
        a[i]=a[2*i+1]+a[2*i+2];
        b[i]=b[2*i+1]+b[2*i+2];
    };
};

int query(int l,int r){
    bool what=l%2;
    l+=half-2;
    r+=half-2;
    int ans_a=0;
    int ans_b=0;
    while(l<r){
        if(l%2==0){
            ans_a+=a[l];
            ans_b+=b[l];
            ++l;
        };
        if(r%2==1){
            ans_a+=a[r];
            ans_b+=b[r];
            --r;
        };
        r=(r-1)/2;
        l=(l-1)/2;
    };
    if(r==l){
        ans_a+=a[r];
        ans_b+=b[r];
    };
    if(what){
        return ans_a-ans_b;
    };
    return ans_b-ans_a;
};

void set(int i,int x){
    i+=half-1;
    if(i%2==1){
        int q=x-a[i];
        a[i]=x;
        while(i!=0){
            i=(i-1)/2;
            a[i]+=q;
        };
    }else{
        int q=x-b[i];
        b[i]=x;
        while(i!=0){
            i=(i-1)/2;
            b[i]+=q;
        };
    };
};

int main()
{
    freopen("signchange.in","rt",stdin);
    freopen("signchange.out","wt",stdout);
    make_tree();
    cin>>m;
    int x,y,z;
    for(int i=0;i<m;++i){
        cin>>x>>y>>z;
        if(!x){
            set(y-1,z);
        }else{
            cout<<query(y,z)<<endl;
        };
    };
    return 0;
}
