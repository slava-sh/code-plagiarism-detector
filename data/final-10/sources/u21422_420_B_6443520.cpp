// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int n,m;
int s[100010],id[100010];
int appear[100010],A;
vector<pair<int,int>> seg[100010];
ll sum[100010];
ll sum2[100010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	char C;
	rep(i,m){
		cin>>C>>id[i];
		id[i]--;
		if(C=='+')s[i] = +1;
		else s[i] = -1;
		appear[id[i]] = 1;
		if(s[i] == -1 && sz(seg[id[i]]) == 0){
			seg[id[i]].pb(mp(0,m+1));
			sum[0] += 1;
		}
		if(s[i] == 1){
			seg[id[i]].pb(mp(i+1,m+1));
			sum[i+1] += 1;
		}else{
			seg[id[i]][sz(seg[id[i]])-1].sec = i+1;
			sum[i+1] -= 1;
		}
	}
	rep(i,n){
		if(sz(seg[i]) >= 1 && seg[i][sz(seg[i])-1].sec == m+1){
			sum[m+1] -= 1;
		}
	}
	//rep(i,m+3){
	//	cout<<sum[i]<<" ";
	//}cout<<endl;
	rep(i,n)A += appear[i];
	rep2(i,1,m+2){
		sum[i] += sum[i-1];
	}

	/*rep(i,n){
		rep(j,sz(seg[i])){
			cout<<seg[i][j].fir<<"-"<<seg[i][j].sec<<endl;
		}
	}*/
	//rep(i,m+3)cout<<sum[i]<<" ";cout<<endl;
	rep(i,m+2){
		sum2[i+1] = sum2[i] + sum[i];
	}
	//rep(i,m+3)cout<<sum2[i]<<" ";cout<<endl;
	set<int> ans;
	rep(i,n){
		if(!appear[i]){ans.insert(i);continue;}
		ll total = 0;
		rep(j,sz(seg[i])){
			total += sum2[seg[i][j].sec] - sum2[seg[i][j].fir];
		}
		//cout<<i<<" "<<total<<" "<<sum[m+1]<<endl;
		if(total == sum2[m+2])ans.insert(i);
	}
	cout<<sz(ans)<<endl;
	foreach(it,ans){
		cout<<*it+1<<" ";
	}
}
