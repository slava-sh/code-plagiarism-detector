#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define N 2100000
int l[N],r[N],s[N],key[N],ans[N],root,n,m,num=0,p[N];
void l_rotate(int &t){
     int k=r[t];
     r[t]=l[k];
     l[k]=t;
     s[k]=s[t];
     s[t]=s[l[t]]+s[r[t]]+1;
     t=k;
}
void r_rotate(int &t){
     int k=l[t];
     l[t]=r[k];
     r[k]=t;
     s[k]=s[t];
     s[t]=s[l[t]]+s[r[t]]+1;
     t=k;
}
void maintain(int &t,bool flag){
     if(!flag){
       if(s[l[l[t]]]>s[r[t]])r_rotate(t);
       else 
         if(s[r[l[t]]]>s[l[t]])l_rotate(l[t]),r_rotate(t);
         else return;
     }
     else{
       if(s[r[r[t]]]>s[l[t]])l_rotate(t);
       else 
         if(s[l[r[t]]]>s[l[t]])r_rotate(r[t]),l_rotate(t);
         else return;
     }
     maintain(l[t],0);
     maintain(r[t],1);
     maintain(t,0);
     maintain(t,1);
}
void add(int &t,int x){
     if(!t){
            t=++num;
            l[t]=r[t]=0;
            key[t]=x;
            s[t]=1;
            return;
            }
     s[t]++;
     add(l[t],x);
     maintain(t,0);
}
int del(int &t,int z){
    s[t]--;
    if(s[l[t]]+1==z || z<s[l[t]]+1 && !l[t] || z>s[l[t]]+1 && !r[t]){
      int tt=key[t];
      if(!l[t] || !r[t])t=l[t]+r[t];
      else key[t]=del(l[t],s[l[t]]+2);
      return tt;
    }
    else
      if(z<s[l[t]]+1)return del(l[t],z);
      else return del(r[t],z-s[l[t]]-1);
}
int find(int t,int x){
    if(s[l[t]]+1==x)return t;
    if(x<=s[l[t]])return find(l[t],x);
    return find(r[t],x-s[l[t]]-1);
}
int main(){
    scanf("%d%d",&n,&m);
    root=0;
    for(int i=n;i;i--)add(root,i);
    while(m--){
               int x,y;
    scanf("%d%d",&x,&y);
    int t=find(root,y);
    int tt=key[t];
  //  cout<<key[t]<<endl;
    if(ans[key[t]] && ans[key[t]]!=x || p[x] && key[t]!=p[x]){
                    cout<<-1<<endl;
                    return 0;
                    }
    ans[key[t]]=x;
    p[x]=key[t];
    del(root,y);
 //  cout<<key[t]<<endl;
    add(root,tt);
    }
    int z=1;
    for(int i=1;i<=n;i++)
      if(!ans[i]){
                  while(p[z])z++;
                  ans[i]=z;
                  z++;
                  }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
   // system("pause");
    return 0;
}
