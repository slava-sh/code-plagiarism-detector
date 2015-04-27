#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#pragma comment(linker,"/STACK:16777216")
#define inf 1000000000
#define MP make_pair
using namespace std;
typedef long long L;
typedef unsigned long long UL;
struct point{
    int x,y;
};
map<pair<int,int>,bool> hm;
vector<pair<int,int> > res;
int n;
point A[20000];

int f(point a,point b){
    if(a.x!=b.x)return a.x<b.x;
    return a.y<b.y;
}

void find(int l,int r){
    if(l>=r)return;
    if(r==l+1){
        if(A[l].x==A[r].x||A[l].y==A[r].y)return;
        pair<int,int> temp=MP(A[l].x,A[r].y);
        if(!hm[temp]){
            hm[temp]=true;
            res.push_back(temp);
        }
    }
    else{
        int mid=(l+r)/2;
        find(l,mid);  find(mid+1,r);
        int x=A[mid].x;
        for(int i=l;i<=r;i++){
            pair<int,int> temp=MP(x,A[i].y);
            if(!hm[temp]){
                hm[temp]=true;
                res.push_back(temp);
            }
        }
    }
}

int main()
{

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i].x>>A[i].y;
        hm[MP(A[i].x,A[i].y)]=true;
        res.push_back(MP(A[i].x,A[i].y));
    }

    sort(A+1,A+(n+1),f);

    find(1,n);
    cout<<res.size()<<endl;
    int ss=res.size();
    for(int i=0;i<ss;i++)
        cout<<res[i].first<<" "<<res[i].second<<endl;

    return 0;
}
