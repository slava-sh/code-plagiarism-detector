#include <stdio.h>
#include <string.h>

int hl,hr;

int T[100001];
int F[100001];
int idT[100001];
int idF[100001];

char taken[128];

int calc(int ix) {
    int par=ix&1,dest=100*ix+hr,i,cross,x,*y,*z,score=0,p;
    if(par) dest=dest+100-2*hr;
    memset(taken,0,sizeof(taken));
    for(i=-105;i<106;i++) {
        cross=i*100;
        p=i&1;
        x=(cross-hl)*100000LL/(dest-hl);
        if(x<0 || x>99999) continue;
        y=p?T:F;
        z=p?idT:idF;
        if(z[x]<0) return 0;
        if(taken[z[x]]) return 0;
        taken[z[x]]=1;
        score+=y[x];
    }
    return score;
}

int main() {
    int i,j,n,L,R,score,best=0,cur;
    char s[2],c;
    scanf("%d %d %d",&hl,&hr,&n);
    memset(T,0,sizeof(T));
    memset(F,0,sizeof(F));
    memset(idT,-1,sizeof(idT));
    memset(idF,-1,sizeof(idF));
    for(i=0;i<n;i++) {
        scanf("%d %s %d %d",&score,s,&L,&R);
        c=s[0];
        for(j=L;j<R;j++) j[c=='F'?F:T]=score,j[c=='F'?idF:idT]=i;
    }
    for(i=-103;i<104;i++) if(i) {
        cur=calc(i);
        if(best<cur) best=cur;
    }
    printf("%d\n",best);
    return 0;
}
