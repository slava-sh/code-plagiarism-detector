/*
Author: 1412kid1412@UESTC
*/

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

const int N=1100;

char mat[1100][11][11];

int p[1100];

int fi(int x){
    return p[x]==x?x:p[x]=fi(p[x]);
}

void pushup(int x,int y){
    int fx=fi(x);
    int fy=fi(y);
    if(fx!=fy){
        p[fx]=fy;
    }
}

int g[1100][1100];
vector<pair<int,int> > ans;
int lowcost[1100];
int closeset[1100],used[1100];
int fa[1100];

int main(){
    int n,m,K,w;
    scanf("%d%d%d%d",&n,&m,&K,&w);
    
    for(int i=0;i<K;i++){
        for(int j=0;j<n;j++){
            scanf("%s",mat[i][j]);
        }
    }
    
    int cnt=0;
    for(int i=0;i<K;i++){
        for(int j=i+1;j<K;j++){
            int s=0;
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    int idx1,idx2;
                    if(mat[i][k][l]=='.'){
                        idx1=0;
                    }
                    else if(mat[i][k][l]>='a'&&mat[i][k][l]<='z'){
                        idx1=mat[i][k][l]-'a'+27;
                    }
                    else if(mat[i][k][l]>='A'&&mat[i][k][l]<='Z'){
                        idx1=mat[i][k][l]-'A'+1;
                    }
                    
                    if(mat[j][k][l]=='.'){
                        idx2=0;
                    }
                    else if(mat[j][k][l]>='a'&&mat[j][k][l]<='z'){
                        idx2=mat[j][k][l]-'a'+27;
                    }
                    else if(mat[j][k][l]>='A'&&mat[j][k][l]<='Z'){
                        idx2=mat[j][k][l]-'A'+1;
                    }
                    if(idx1!=idx2){
                        s++;
                    }
                }
            }
            g[i][j]=w*s;
            g[j][i]=w*s;
        }
    }
    
    int ret=0;
    ret+=n*m;
    ans.push_back(make_pair(1,0));
    int i,j,k;
    

int minc;
memset(fa,-1,sizeof(fa));
    for (i=0;i<K;i++)
        {

/* 最短距离初始化为其他节点到1号节点的距离 */
        lowcost[i]=g[0][i];

    /* 标记所有节点的依附点皆为默认的1号节点 */


        closeset[i]=0; 
        used[i]=0;
        fa[i]=-1; 
        }
    used[0]=1;  /*第一个节点是在U集合里的*/

/* vcount个节点至少需要vcount-1条边构成最小生成树 */
    for (i=1;i<=K-1;i++)
        {
        j=0;

    minc = (1<<20);

       /* 找满足条件的最小权值边的节点k */
        for (k=1;k<K;k++)

         /* 边权值较小且不在生成树中 */
            if ((!used[k])&&(lowcost[k]<minc)) 

          {

              minc =  lowcost[k];

              j=k;

           }
        fa[j]=closeset[j]; 
        used[j]=1;;//把第j个顶点并入了U中
        if(minc<=n*m){
        ret+=minc;  
        ans.push_back(make_pair(j+1,fa[j]+1));
        }
        else{
            ret+=n*m;
            ans.push_back(make_pair(j+1,0));
        }
        
        
        for (k=1;k<K;k++)

         /* 发现更小的权值 */
            if (!used[k]&&(g[j][k]<lowcost[k]))
                { 

                  lowcost[k]=g[j][k];/*更新最小权值*/
                  closeset[k]=j;;/*记录新的依附点*/

                 }
        }
    
    cout<<ret<<endl;
    int sz=ans.size();
    for(int i=0;i<sz;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    
    return 0;
}