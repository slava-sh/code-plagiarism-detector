#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

int w,h,n;

int gaj[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
char out[4]={'E','N','W','S'}; //INVERT ?

int rez[10001];
bool T1,T2;

struct kord{
int x,y;
}ak,tmp,ptmp,ztmp;

struct mape{
int neliet,liet,no;
bool T;
}kar[501][501];

list<kord> sar;

void Rez(kord ptmp,int sk)
{
kord ztmp;
    while (kar[ptmp.x][ptmp.y].no!=-1){
        rez[sk]=kar[ptmp.x][ptmp.y].no;
        sk++;
        ztmp.x=ptmp.x+(-1*gaj[kar[ptmp.x][ptmp.y].no][0]);
        ztmp.y=ptmp.y+(-1*gaj[kar[ptmp.x][ptmp.y].no][1]);
        ptmp=ztmp;
    }

}


void BFS(){
int i,j,sk,p;
    while (T2==false && !sar.empty()){
        ak=sar.front();
        sar.erase(sar.begin());

        //printf("%d %d\n",ak.x,ak.y);

        for (i=0;i<4;i++){
            tmp.x=ak.x+(1*gaj[i][0]);
            tmp.y=ak.y+(1*gaj[i][1]);

            if (tmp.x>0 && tmp.x<=w && tmp.y>0 && tmp.y<=h){

                if (kar[ak.x][ak.y].T && kar[tmp.x][tmp.y].T){
                    p=kar[ak.x][ak.y].neliet+kar[ak.x][ak.y].liet+(n-kar[ak.x][ak.y].liet);
                    if (p<rez[0]){
                        rez[0]=p;

                    //printf("%d %d %d %d    %d %c",ak.x,ak.y,tmp.x,tmp.y,i,out[i]);

                    p=i;sk=1;
                    for (j=(n-kar[ak.x][ak.y].liet);j>0;j--){
                        rez[j]=p;
                        p=(p+2)%4;
                        sk++;
                    }
                    Rez(ak,sk);

                    }
                    T2=true;break;
                }

                if (kar[tmp.x][tmp.y].no==5){
                    kar[tmp.x][tmp.y].no=i;
                    if (kar[tmp.x][tmp.y].T){
                        kar[tmp.x][tmp.y].neliet=kar[ak.x][ak.y].neliet;
                        kar[tmp.x][tmp.y].liet=kar[ak.x][ak.y].liet+1;
                        sar.insert(sar.begin(),tmp);
                        if (T1==false){
                            //Izrekinam
                            rez[0]=kar[tmp.x][tmp.y].neliet+kar[tmp.x][tmp.y].liet+2*(n-kar[tmp.x][tmp.y].liet);
                            sk=1;
                            for (j=1;j<=(n-kar[tmp.x][tmp.y].liet);j++){
                                rez[sk]=i;
                                sk++;rez[sk]=(i+2)%4;sk++;
                            }
                            ptmp=tmp;
                            Rez(ptmp,sk);
                            T1=true;
                        }
                    }else{
                        kar[tmp.x][tmp.y].neliet=kar[ak.x][ak.y].neliet+1;
                        kar[tmp.x][tmp.y].liet=kar[ak.x][ak.y].liet;
                        sar.insert(sar.end(),tmp);
                    }
                }
            }
        }

    }
}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w+",stdout);
    int i,j;
    char z;

    rez[0]=100000;
    T1=false;
    T2=false;

    scanf("%d %d %d",&w,&h,&n);
    for (j=1;j<=h;j++){
        scanf("\n");
        for (i=1;i<=w;i++){
            scanf("%c",&z);
            kar[i][j].neliet=1000000;
            kar[i][j].liet=0;
            kar[i][j].no=5;
            if (z=='T'){
                kar[i][j].T=true;
            }else if (z=='V'){
               tmp.x=i;tmp.y=j;kar[i][j].T=false;
            }else kar[i][j].T=false;
        }
    }

    kar[tmp.x][tmp.y].neliet=0;
    kar[tmp.x][tmp.y].no=-1;

    sar.insert(sar.begin(),tmp);

    BFS();

    //printf("%d\n",rez[0]);
    for (i=rez[0];i>0;i--){
        printf("%c",out[rez[i]]);
    }
}
