#include<bits/stdc++.h>
using namespace std;
const int nmax=1009;
int n,m;
string ch[nmax];
int s[nmax][nmax];
int ans=1e9;
int sum(int x1,int y1,int x2,int y2){
   return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int dfs(int x,int y,int shirx,int shiry){
   if(sum(x,y+1,x+shirx-1,y+shiry)==shirx*shiry)return shirx+dfs(x,y+1,shirx,shiry);
   if(sum(x+1,y,x+shirx,y+shiry-1)==shirx*shiry)return shiry+dfs(x+1,y,shirx,shiry);
   return 0;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cin>>n>>m;
   int fl=0,px,py;
   for(int i=1;i<=n;i++){
      string s1;
      cin>>s1;
      ch[i]='#'+s1;
   }
   for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
         if(ch[i][j]=='X'){
            if(!fl){
               fl=1;
               px=i;
               py=j;
            }
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+1;
         }
         else s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
      }
   }
   int tmp,shirx,shiry;
   for(tmp=px;ch[tmp][py]=='X';tmp++);
   shirx=tmp-px;
   for(int i=py;ch[px][i]=='X';i++){
      if(dfs(px,py,shirx,i-py+1)+shirx*(i-py+1)==s[n][m]){
         ans=min(ans,shirx*(i-py+1));
      }
   }
   for(tmp=py;ch[px][tmp]=='X';tmp++);
   shiry=tmp-py;
   for(int i=px;ch[i][py]=='X';i++){
      if(dfs(px,py,i-px+1,shiry)+(i-px+1)*shiry==s[n][m]){
         ans=min(ans,(i-px+1)*shiry);
      }
   }
   if(ans<=n*m)cout<<ans<<endl;
   else cout<<-1<<endl;
}
