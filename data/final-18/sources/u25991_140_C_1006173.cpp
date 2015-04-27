#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<map>
using namespace std;
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define abs(x) (((x)>0)?(x):(-(x)))
#define INF (1<<29)
#define eps (1e-8)

struct rep{
    int id,num;
    
    rep(){}
    rep(int id,int num):id(id),num(num){}
    bool operator<(const rep &d)const{
        return num<d.num;
    }
} a[100005];

struct node{
    int a,b,c;
    
    node(){}
    node(int a,int b,int c):a(a),b(b),c(c){} 
    void out(){
        int x[5]; x[0]=a; x[1]=b; x[2]=c; sort(x,x+3);
        printf("%d %d %d\n",x[2],x[1],x[0]);
    }
} ans[100005];

int b[100005],n,r[100005],p1,p2,num;
priority_queue<rep> q;

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i) scanf("%d",&r[i]);
    sort(r,r+n);
    
    p1=p2=0;
    int ct=1,tar=r[0];
    for (int i=1;i<n;++i){
        if (r[i]!=tar){
            if (ct>1) q.push(rep(tar,ct));//a[p1++]=rep(tar,ct);
            else b[p2++]=tar;
            ct=1; tar=r[i];
        }
        else ++ct;
    }
    if (ct>1) q.push(rep(tar,ct));//a[p1++]=rep(tar,ct);
    else b[p2++]=tar;
    
    num=0;
    while (q.size()>=3){
        //rep t1=a[--p1]; rep t2=a[--p1]; rep t3=a[--p1];
        rep t1=q.top(); q.pop(); rep t2=q.top(); q.pop(); rep t3=q.top(); q.pop();
        t1.num--; t2.num--; t3.num--;
        ans[num++]=node(t1.id,t2.id,t3.id);
        if (t1.num>1) q.push(t1); else b[p2++]=t1.id;
        if (t2.num>1) q.push(t2); else b[p2++]=t2.id;
        if (t3.num>1) q.push(t3); else b[p2++]=t3.id;
    }
    while (q.size()>=2 && p2>=1){
        rep t1=q.top(); q.pop(); rep t2=q.top(); q.pop(); int t3=b[--p2];
        t1.num--; t2.num--;
        ans[num++]=node(t1.id,t2.id,t3);
        if (t1.num>1) q.push(t1); else b[p2++]=t1.id;
        if (t2.num>1) q.push(t2); else b[p2++]=t2.id;
    }
    while (q.size()>=1 && p2>=2){
        rep t1=q.top(); q.pop(); int t2=b[--p2]; int t3=b[--p2];
        t1.num--;
        ans[num++]=node(t1.id,t2,t3);
        if (t1.num>1) q.push(t1); else b[p2++]=t1.id;
    }
    while (p2>=3){
        int t1=b[--p2]; int t2=b[--p2]; int t3=b[--p2];
        ans[num++]=node(t1,t2,t3);
    }
    printf("%d\n",num);
    for (int i=0;i<num;++i) ans[i].out();
    return 0;
}
