#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")
#define inf 1000000000
#define MP make_pair
#define PI acos(-1.0)
#define eps 1e-7
#define MAXN 110
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
int hl,hr,n,res;
int v[MAXN],a[MAXN],b[MAXN];
char c[MAXN];
int used[MAXN];

int get(double x,int dir){
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        if(c[i]=='T'){
            if(dir==-1&&(1.0*a[i]-eps)<=x&&x<=(1.0*b[i]+eps))return i;
        }
        else{
            if(dir==1&&(1.0*a[i]-eps)<=x&&x<=(1.0*b[i]+eps))return i;
        }
    }
    return -1;
}

void go(int dir){
    int h=hr;

    for(int i=1;i<=n;i++){

        //cout<<h<<endl;

        double talf,x;
        int tdir=dir,can=1,cur=0,diff;



        if(dir==-1){h=-h;talf=100000.0/(hl+(-h));diff=(hl-h);}
        else{h=100+(100-h);talf=100000.0/(h-hl);diff=(h-hl);}

        memset(used,0,sizeof(used));


        if(tdir==-1)x=1.0*hl*100000/diff;
        else x=1.0*(100-hl)*100000/diff;
        tdir*=(-1);

        //if(i==1&&dir==-1)cout<<alf<<" "<<x<<endl;

        for(int j=1;j<=i;j++){

            int idx=get(x,tdir);

            if(idx==-1){can=0;break;}
            used[idx]=1; cur+=v[idx];

            x+=100.0*100000/diff;

            tdir*=-1;
        }

        if(can){res=max(res,cur);}
        //if(can)cout<<cur<<endl;

        dir*=-1;
    }


}

int main()
{

    cin>>hl>>hr>>n;

    for(int i=1;i<=n;i++)cin>>v[i]>>c[i]>>a[i]>>b[i];

    go(1);

    go(-1);

    cout<<res<<endl;

    return 0;
}
