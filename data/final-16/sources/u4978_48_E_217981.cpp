#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN=201;


int tetes,queues,limite;
int maxTetes,maxQueues;
pair<int,int> pousseTetes[MAXN];
pair<int,int> pousseQueues[MAXN];
int distanc[MAXN][MAXN];

int DFS(int tetes,int queues){
	if (tetes+queues>limite)
		return 0;
	int &res=distanc[tetes][queues];
	if (res>0)
		return res;
	if (res==-2)
		return res=1e9;
	res=-2;
	int maxi=0;
	for (int nbT=1;nbT<=min(maxTetes,tetes);nbT++)
		maxi=max(maxi,DFS(tetes-nbT+pousseTetes[nbT-1].first,queues+pousseTetes[nbT-1].second));
	for (int nbQ=1;nbQ<=min(maxQueues,queues);nbQ++)
		maxi=max(maxi,DFS(tetes+pousseQueues[nbQ-1].first,queues-nbQ+pousseQueues[nbQ-1].second));
	return res=maxi+1;
}

int main(){
	scanf("%d%d%d%d",&tetes,&queues,&limite,&maxTetes);
	for (int i=0;i<maxTetes;i++)
		scanf("%d%d",&pousseTetes[i].first,&pousseTetes[i].second);
	scanf("%d",&maxQueues);
	for (int i=0;i<maxQueues;i++)
		scanf("%d%d",&pousseQueues[i].first,&pousseQueues[i].second);
	queue<pair<int,int> > aTraiter;
	aTraiter.push(make_pair(tetes,queues));
	fill(distanc[0],distanc[MAXN],1e9);
	distanc[tetes][queues]=0;
	while (!aTraiter.empty()){
		pair<int,int> cur=aTraiter.front();
		aTraiter.pop();
		for (int nbT=1;nbT<=min(maxTetes,cur.first);nbT++){
			pair<int,int> nouv(cur.first-nbT+pousseTetes[nbT-1].first,cur.second+pousseTetes[nbT-1].second);
			if (nouv.first+nouv.second>limite)
				continue;
			if (distanc[nouv.first][nouv.second]>distanc[cur.first][cur.second]+1){
				distanc[nouv.first][nouv.second]=distanc[cur.first][cur.second]+1;
				aTraiter.push(nouv);
			}
		}
		for (int nbQ=1;nbQ<=min(maxQueues,cur.second);nbQ++){
			pair<int,int> nouv(cur.first+pousseQueues[nbQ-1].first,cur.second-nbQ+pousseQueues[nbQ-1].second);
			if (nouv.first+nouv.second>limite)
				continue;
			if (distanc[nouv.first][nouv.second]>distanc[cur.first][cur.second]+1){
				distanc[nouv.first][nouv.second]=distanc[cur.first][cur.second]+1;
				aTraiter.push(nouv);
			}
		}
	}
	if (distanc[0][0]<1e9){
		printf("Ivan\n%d\n",distanc[0][0]);
		return 0;
	}
	fill(distanc[0],distanc[MAXN],-1);
	if (DFS(tetes,queues)>1e8)
		puts("Draw");
	else
		printf("Zmey\n%d\n",distanc[tetes][queues]);
	return 0;
}
