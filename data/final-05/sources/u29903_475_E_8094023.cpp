#include<stdio.h>
#include<string.h>
#include<stack>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
bool e[2001][2001];
bool ne[2001][2001];
bool in[2001];
bool instack[2001];
int Size[2001];
int st[2001],dfn[2001],low[2001],tot[2001];
stack<int> S;
int last,now;
int totans;
int N,M;
void dfs(int x,int fa){
	dfn[x]=low[x]=++now;
	in[x]=instack[x]=1;
	S.push(x);
	for(int i=1;i<=N;++i) if(e[x][i]&&i!=fa){
		if(!in[i]){
			dfs(i,x);
			low[x]=min(low[x],low[i]);
		}
		else if(instack[i]){
			low[x]=min(low[x],dfn[i]);
		}
	}
	if(low[x]==dfn[x]){
		++last;
		tot[last]=0;
		int y;
		do{
			y=S.top();
			S.pop();
			instack[y]=0;
			st[y]=last;
			++tot[last];
		}while(y!=x);
	}
}
int I;
int fa[2001];
vector<int> rec;
void calcSize(int x,int fa){
	in[x]=1;
	::fa[x]=fa;
	Size[x]=tot[x];
	rec.push_back(x);
	for(int i=1;i<=last;++i) if(i!=fa&&ne[x][i]){
		calcSize(i,x);
		Size[x]+=Size[i];
	}
}
int tryyCalc(int x,int fa){
	int now=tot[x];
	for(int i=1;i<=last;++i) if(i!=fa&&ne[x][i]){
		now+=tryyCalc(i,x);
	}
	totans+=(long long)now*tot[x];
	return now;
}

int main(){
	scanf("%d%d",&N,&M);
//	N=2000,M=N*(N-1)/2;
	for(int i=1;i<=M;++i){
		int x,y;
		scanf("%d%d",&x,&y);
//		x=rand()%N+1,y=rand()%N+1;
		e[x][y]=e[y][x]=1;
	}
	for(int i=1;i<=N;++i) if(!in[i]){
		dfs(i,-1);
	}
	for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) if(e[i][j]&&st[i]!=st[j]){
		ne[st[i]][st[j]]=1;
	}
	memset(in,0,sizeof(in));
	totans=0;
	for(int i=1;i<=last;++i) if(!in[i]){
		rec.clear();
		calcSize(1,-1);
		int sel=-1;
		for(int j=0;j<(int)rec.size();++j) if(Size[rec[j]]>=(Size[i]+1)/2){
			if(sel==-1||Size[rec[j]]<Size[sel]){
				sel=rec[j];
			}
		}
		bitset<2001> mask;
		mask.reset();
		mask[0]=1;
		{
			int rem=Size[1]-tot[sel];
			for(int j=0;j<(int)rec.size();++j) if(fa[rec[j]]==sel){
				mask|=mask<<Size[rec[j]];
				rem-=Size[rec[j]];
			}
			if(rem) mask|=mask<<rem;
		}
		int balancepos=(Size[1]-tot[sel])/2;
		while(!mask[balancepos]) --balancepos;
		totans+=balancepos*(Size[1]-tot[sel]-balancepos);
		tryyCalc(sel,-1);
	}
	printf("%d\n",totans);
	return 0;
}
