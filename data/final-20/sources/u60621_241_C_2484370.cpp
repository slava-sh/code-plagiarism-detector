#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define eps (1e-9)

double hl,hr,be,ed;
char ts[10];
int mt,mf,ans,i,n,a;

struct mirror{
    int po;
    double be,ed;
    void init(int a,double _be,double _ed){
       po=a;be=_be;ed=_ed;
    }
}mi[2][200];

inline bool cmp(mirror x,mirror y){return x.be<y.be;}

inline int find(double now,int flag){
    int nn=(flag==0?mf:mt);
    for(i=1;i<=nn;i++){
       if (mi[flag][i].be-eps<=now&&now<=mi[flag][i].ed+eps) return i;
       if (mi[flag][1].be>now+eps)   return 0;
    }
    return 0;
}

void work1(int function){
    int i,flag,right,tmp,pre[2],tsum,j;
    double x,step,now;
    for(i=0;i<=n;i++){
       flag=function;
       right=1;
       tsum=0;
       pre[0]=pre[1]=0;
       
       if (function==0){
          if (i%2==0){
            x=100.0*i/hl+1+hr/hl;
          }
          else {
            x=100.0*i/hl+1+(100-hr)/hl;
          }
       }
       else {
          if (i%2==0){
            x=100.0*i/(100-hl)+1+(100-hr)/(100-hl);
          }
          else {
            x=100.0*i/(100-hl)+1+hr/(100-hl);
          }
       }
       x=100000.0/x;
       if (function==0) step=x/hl*100.0;
       else step=x/(100-hl)*100;
       now=x;
       tmp=find(now,flag);
       if (!tmp) {right=0;continue;}
       else {pre[flag]=tmp;tsum+=mi[flag][tmp].po;flag=1-flag;}
       for(j=1;j<=i;j++){
           now=now+step;
           tmp=find(now,flag);
           if (!tmp||tmp<=pre[flag]) {right=0;break;}
           else {
              pre[flag]=tmp;tsum+=mi[flag][tmp].po;
              flag=1-flag;
           }
       }
       if (right==0) continue;
       else if (tsum>ans) ans=tsum;
    }
}
       


int main(){
    scanf("%lf%lf%d",&hl,&hr,&n);
    mf=0;mt=0;
    for(i=1;i<=n;i++){
       scanf("%d%s%lf%lf",&a,ts,&be,&ed);
       if (ts[0]=='F'){mf++;mi[0][mf].init(a,be,ed);}
       else {mt++;mi[1][mt].init(a,be,ed);}
    }
    if (mf>0) sort(mi[0]+1,mi[0]+mf+1,cmp);
    if (mt>0) sort(mi[1]+1,mi[1]+mt+1,cmp);
    
    ans=0;
    work1(0);
    work1(1);
    printf("%d\n",ans);
    return 0;
}
