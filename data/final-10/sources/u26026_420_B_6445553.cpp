#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<math.h> 
#include<iostream>
#include<algorithm>
#include<ctype.h>
#define LL long long
#define oo 1000000000
#define N 300005
#define P 1000000007 
using namespace std;
int T[N];
int mark[N];
int is[N]; 
set<int>se;
set<int>::iterator it;
int In[N];int ans[N];

int main(){
    int n,m,i,j,k;
    char str[10];
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(mark,0,sizeof(mark));
        for(i=1;i<=n;i++)
            is[i]=1;
        for(i=1;i<=m;i++){
            scanf("%s %d",str,&k);
            if(str[0]=='-'){// 
                if(mark[k]==0)mark[k]=-1;
                k*=-1;
            }else{
                if(mark[k]==0)mark[k]=1;
                //printf("k=%d %d\n",k,mark[k]);
            }
            T[i]=k;
        }
        int cnt=0;
        for(i=1;i<=n;i++){
            if(mark[i]==-1)
                cnt++; 
        }
    //  printf("cnt=%d\n",cnt);
        for(i=1;i<=m;i++){
            if(T[i]>0){
                int x=T[i];
                if(cnt!=0){
                    is[x]=0;
                }
                cnt++;In[x]=i;
                if(i==1||T[i-1]==-x)continue;
                is[x]=0;
            }else{
                int x=-T[i]; 
                cnt--;In[x]=-i;
            }
        }
        for(i=1;i<=n;i++){
            if(mark[i]==0)continue;
            if(In[i]<0){
                if(In[i]==-m&&cnt==0)continue;
                is[i]=0;
            }
        }
    //  printf("1111 %d\n",In[1]);
        k=0;
        for(i=1;i<=n;i++)
            if(is[i])ans[k++]=i;
        printf("%d\n",k);
        for(i=0;i<k;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}