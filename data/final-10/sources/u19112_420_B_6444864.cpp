#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=300000;
int arr[MX] , state[MX] , n,m , meet[MX] , cur , is[MX] , lastoff[MX];
int pres[MX];
pair<int,int>last;
vector< pair<int,int> >v[MX];
vector<int>ans;

char cc;
int main(){
    memset(meet,-1,sizeof(meet));
    memset(is,0,sizeof(is));
    scanf("%d %d",&n,&m);
    for(int j=1;j<=m;j++){
        cin>>cc>>arr[j];
        if(cc=='+') state[j]=1;
        else state[j]=0;
        if(meet[arr[j]]==-1)
            meet[arr[j]]=state[j];

        v[arr[j]].push_back(P(j,state[j]));
    }
    for(int j=1;j<=n;j++){
        lastoff[j]=m*10;
        if(meet[j]==-1) ans.push_back(j);
        if(meet[j]==0) {
            cur++;
            is[j]=1;
        }
    }
    if(state[1]==1 && cur==0) is[arr[1]]=1;
    for(int j=1;j<=m;j++){
        if(state[j]==0) cur--;
        else cur++;
        pres[j]=cur;
    }

    for(int j=1;j<=m;j++){
        if(!is[arr[j]]) continue;
        if(state[j]==0){
            if(pres[j]>0){
                is[arr[j]]=0;
            }
            lastoff[arr[j]]=j;
        }
    }
    int ret;
    for(int j=1;j<=n;j++){
        if(!is[j]) continue;
        ret=1; int szo=v[j].size();
        for(int i=0;i<szo;i++){
            if(v[j][i].second==1 && i){
                if(v[j][i].first != v[j][i-1].first+1)
                    ret=0;
            }
            last=v[j][i];
        }
        if(last.second ==0 && last.first < m) ret=0;
        is[j]&=ret;
        if(is[j]) ans.push_back(j);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int j=0;j<ans.size();j++)
        printf("%d ",ans[j]);
}
