#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int pd[2100][1100],n,m,l[2100],r[2100],x[4100000][2],gox[2]={1,0},goy[2]={0,1},s,t;
char getin(){
    char ch=getchar(); while (ch!='X'&&ch!='.') ch=getchar(); return ch;
}
int bfs(int k1,int k2){
    x[1][0]=k1; x[1][1]=k2; int head=1,now=0; pd[k1][k2]=2;
    while (head>now){
        now++;
        int a=x[now][0],b=x[now][1]; s=min(s,a); t=max(t,a);
        pd[a][b]=2; l[a]=min(l[a],b); r[a]=max(r[a],b);
        for (int i=0;i<=1;i++){
            int c=a+gox[i],d=b+goy[i];
            if (pd[c][d]==1){
                head++; x[head][0]=c; x[head][1]=d; pd[c][d]=2;
            }
        }
    }
}
int check(int k){
    for (int i=t-k+1;i<t;i++) if (r[i]!=r[i+1]) return -1;
    for (int i=s;i<s+k-1;i++) if (l[i]!=l[i+1]) return -1;
    int nummin=1,nummax=m;
    for (int i=s;i<t-k+1;i++){
        int k1=r[i]-l[i+k]+1;
        if (nummin>k1||nummax<k1) return -1;
        nummin=max(k1,nummin); nummax=min(k1,nummax);
    }
    int k1=r[t]-l[t]+1;
    if (nummin>k1) return -1;
    return nummin;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char ch=getin(); if (ch=='X') pd[i][j]=1;
        }
    for (int i=1;i<=n;i++){
        int flag=0;
        for (int j=1;j<=m;j++){
            if (pd[i][j]==1&&flag==0) {flag=1; continue;}
            if (pd[i][j]==0&&flag==1) {flag=2; continue;}
            if (pd[i][j]==1&&flag==2) {cout<<-1<<endl; return 0;}
        }
    }
    int num=n*m,flag=0; s=n+1;
    for (int i=1;i<=n;i++) l[i]=m+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (pd[i][j]==1){
                if (flag==1){cout<<"-1"<<endl; return 0;} flag=1; bfs(i,j);
            }
    for (int i=s;i<t;i++) if (l[i+1]<l[i]||r[i+1]<r[i]){cout<<-1<<endl; return 0;}
    flag=0;
    for (int i=1;i<=n;i++){
        int k1=check(i);
        if (k1>0){
            flag=1; num=min(num,i*k1);
        }
    }
    if (flag==0) cout<<-1<<endl; else cout<<num<<endl; return 0;
}