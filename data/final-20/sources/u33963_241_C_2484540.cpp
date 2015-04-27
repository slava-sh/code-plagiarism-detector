#include<cstdio>
#include<set>
using namespace std;
struct MIR{
    int l,r;
    int v;
};
bool operator<(const MIR&a,const MIR&b){
    return a.l<b.l;
}
set<MIR>mir[2];
void Max(int&a,const int&b){if(b>a)a=b;}
const int width=100000;
const int height=100;
int get(double x,double stp,int at){
    int res=0;
    MIR cm;
    set<int>flag[2];
    while(1){
        x+=stp;
        if(x>=width)break;
        cm.l=x;
        cm.r=0;
        set<MIR>::iterator it=mir[at].upper_bound(cm);
        if(it==mir[at].begin())return 0;
        --it;
        if(it->l<=x&&it->r>=x){
            res+=it->v;
            if(flag[at].find(it->l)!=flag[at].end())return 0;
            flag[at].insert(it->l);
        }
        else return 0;
        at^=1;
    };
    return res;
}
int main(){
    int hl,hr,n;
    while(~scanf("%d%d%d",&hl,&hr,&n)){
        mir[0].clear();
        mir[1].clear();
        int i;
        MIR cm;
        char at[2];
        for(i=0;i<n;++i){
            scanf("%d%s%d%d",&cm.v,at,&cm.l,&cm.r);
            if(at[0]=='T')mir[0].insert(cm);
            else mir[1].insert(cm);
        }
        int res=0;
        int hs;
        for(i=1;i<=n;++i){
            if(i&1)hs=height-hr;
            else hs=hr;
            Max(res,get(-width*(double)hl/(hs+height*i-hl),((double)width)/(hs+height*i-hl)*height,0));
            Max(res,get(-width*(double)(height-hl)/(hl+height*i-hs),((double)width)/(hl+height*i-hs)*height,1));
        }
        printf("%d\n",res);
    }
    return 0;
}
/*
50 50 1
100 F 49999 50001

80 72 9
15 T 8210 15679
10 F 11940 22399
50 T 30600 44789
50 F 32090 36579
5 F 45520 48519
120 F 49250 55229
8 F 59700 80609
35 T 61940 64939
2 T 92540 97769
*/