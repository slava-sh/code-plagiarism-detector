#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
char s[1011][1011];
int N,M,sx,sy;
int tot;
vector<pair<int,pair<int,int> > > V;
int check(int x,int y){
	int retmax=N*M+1;
	for(int i=0;i<x;++i){
		if(V[i].second.first!=V[0].second.first) return retmax;
	}
	for(int i=tot-x;i<tot;++i){
		if(V[i].second.second!=V[tot-1].second.second) return retmax;
	}
	int nc=sy+y-1;
	for(int i=0;i<=tot-x;++i){
		nc=V[i].second.second;
		if(i==tot-x) break;
		if(V[i+x].second.first!=nc-y+1) return retmax;
	}
	return x*y;
}
int main(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i) scanf("%s",s[i]);
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j) if(s[i][j]=='X'){
			int k=j;
			while(k<M&&s[i][k]=='X') ++k;
			V.push_back(make_pair(i,make_pair(j,k-1)));
			j=k-1;
		}
	}
	for(int i=0;i<int(V.size())-1;++i){
		if(V[i].first!=V[i+1].first-1){
			printf("-1\n");
			return 0;
		}
		if(V[i].second.second>V[i+1].second.second||V[i].second.first>V[i+1].second.first||V[i].second.second<V[i+1].second.first){
			printf("-1\n");
			return 0;
		}
	}
	if(!V.size()){
		printf("0\n");
		return 0;
	}
	int BN=0;
	int BM=0;
	{
		int xx=V[0].first,yy=V[0].second.first;
		while(yy+BM<M&&s[xx][yy+BM]=='X') ++BM;
		while(xx+BN<N&&s[xx+BN][yy]=='X') ++BN;
		sx=xx,sy=yy;
	}
	tot=V.size();
	int ANS=N*M+1;
	for(int i=1;i<=BN;++i){
		ANS=min(ANS,check(i,BM));
	}
	for(int i=1;i<=BM;++i){
		ANS=min(ANS,check(BN,i));
	}
	printf("%d\n",ANS==N*M+1?-1:ANS);
	return 0;
}
