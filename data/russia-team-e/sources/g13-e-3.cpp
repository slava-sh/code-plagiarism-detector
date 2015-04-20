#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue> 
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inf 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define For(i,s,n) for (int i=s;i<=n;i++)
#define FOR(i,s,n) for (int i=s;i<n;i++)
#define Ford(i,s,n) for (int i=s;i>=n;i--)
#pragma comment(linker, "/STACK:16777216")


#define MD 1000000007


typedef long long ll;

using namespace std;


int n[4],N,M;
pair <int,bool> edge[3][700000][11];
char st[100],mud[100],COPY[100];
string ans;
map  <pair <string,string>,bool> MMM;


void AddWord(int idx,int v,int pos,int MAX){
	if (pos>=MAX) return;
	int k=st[pos]-'0';
	if (!edge[idx][v][k].f) n[idx]++,edge[idx][v][k].f=n[idx];
	if (pos==MAX-1){
		edge[idx][v][k].s=true;
		return;
	} 
	AddWord(idx,edge[idx][v][k].f,pos+1,MAX);
}


bool FindWord(int idx,int v,int pos,int MAX){
	int k=COPY[pos]-'0';
	if (!edge[idx][v][k].f) return false;
	if (pos==MAX-1)
		return edge[idx][v][k].s ;
	return FindWord(idx,edge[idx][v][k].f,pos+1,MAX);
}



int main(){
	//freopen("i.txt","r",stdin);freopen("o.txt","w",stdout);
	freopen("numbers.in","r",stdin);freopen("numbers.out","w",stdout);
	scanf("%d",&N);
	For(i,1,N){
		string QQQ;
		cin>>QQQ;
		FOR(i,0,QQQ.length()) st[i]=QQQ[i];
		AddWord(0,0,0,QQQ.length());
		scanf("%d",&M);
		gets(mud);
		For(i,1,M){
			gets(st);
			string tmp="";
			FOR(j,0,strlen(st)) tmp+=st[i];
			MMM[mp(QQQ,tmp)]=true;
			AddWord(1,0,0,strlen(st));
		}
	}
	scanf("%d",&M);
	gets(mud);
	For(i,1,M){
		gets(st);
		if (st[0]=='0'){
			puts("Incorrect");
			continue;
		}
		bool ind=false;
		For(j,0,2){
			if (ind) break;
			string tmp1="";
			For(k,0,j) COPY[k]=st[k],tmp1+=COPY[k];
			if (FindWord(0,0,0,j+1)){
				ans="+";
				For(k,0,j) ans+=COPY[k];
				For(k,j+3,j+5){
					if (ind) break;
					string tmp2="";
					For(p,j+1,k) COPY[p-j-1]=st[p],tmp2+=st[p];
					if (MMM.find(mp(tmp1,tmp2))!=MMM.end()) break;
					if (st[j+1]=='0') break;
					if (FindWord(1,0,0,k-j)){
						ans+="(";
						For(p,j+1,k) ans+=st[p];
						ans+=")";
						int ST=0;
						if (st[k+1]=='0') break;
						if (!((11-k)%2))
							For(p,k+1,k+3) ans+=st[p],ST=k+4;else
							For(p,k+1,k+2) ans+=st[p],ST=k+3;
						ind=true;
						for (int i=ST;i<11;i+=2){
							ans+="-";
							ans+=st[i];ans+=st[i+1];
						}
					}
				}
			}
		}
		if (ind) cout<<ans<<endl;else puts("Incorrect");
	}
}