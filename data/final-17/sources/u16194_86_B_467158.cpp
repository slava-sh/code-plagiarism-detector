#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

const int mr[]={-1,0,0,1};
const int mc[]={0,-1,1,0};
typedef pair<int,int> PII;

char a[1010][1010];
vector<vector<PII>> b;

bool check(int r, int c){
    for(int i=0;i<4;i++)
        if(a[r+mr[i]][c+mc[i]]=='.') return false;
    return true;
}

int floodfill(int r, int c, int tag, int cnt){
    int ret=1;
    a[r][c]='#';
    b.back().push_back({r,c});
    for(int i=0;i<4;i++){
        int tr=r+mr[i];
        int tc=c+mc[i];
        if(a[tr][tc]=='.' && check(tr,tc))
            ret+=floodfill(tr,tc,tag,cnt+1);
    }
    if(ret>=2) return ret;
    if(cnt==0){
        for(int i=0;i<4;i++){
            int tr=r+mr[i];
            int tc=c+mc[i];
            if(a[tr][tc]=='.'){
                ret+=floodfill(tr,tc,tag,cnt+1);
                break;
            }
        }
    }
    return ret;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
    int tag=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(a[i][j]!='.') continue;
        b.push_back(vector<PII>());
        int cnt=floodfill(i,j,++tag,0);
        if(cnt<2 || cnt>5) return puts("-1");
    }
    for(int i=0;i<int(b.size());i++){
        vector<PII>& u=b[i];
        int use[10]={};
        for(int j=0;j<int(u.size());j++){
            int r=u[j].first;
            int c=u[j].second;
            for(int o=0;o<4;o++){
                char ch=a[r+mr[o]][c+mc[o]];
                if(ch>='0' && ch<='9') use[ch-'0']=1;
            }
        }
        for(tag=0;tag<10;tag++) if(!use[tag]) break;
        for(int j=0;j<int(u.size());j++)
            a[u[j].first][u[j].second]=tag+'0';
    }
    for(int i=1;i<=n;i++) puts(a[i]+1);
}
