#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<complex>
#include<bitset>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#include<utility>

#define pb push_back
#define pp pop_back
#define xx first
#define yy second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int maxn=500+10;
char c[maxn][maxn];
ll dp[2*maxn][maxn];
int n,m,num[maxn],cnt;
ll mod;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++)num[i]=2;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]=='1')num[j]--;
		}
	}
	for(int i=1;i<=n;i++)if(num[i]==2)cnt++;
	dp[0][cnt]=1;
	int len=2*(n-m);
	//cout<<cnt<<endl;
	for(int i=0;i<=len-2;i+=2){
		for(int j=0;j<=cnt;j++){
			ll rem=len-i;
			rem-=2*j;
			if(rem>=2){
				ll mul=(rem*(rem-1)/2)%mod;
				dp[i+2][j]=(dp[i+2][j]+(dp[i][j]*mul)%mod)%mod;
			}
			if(j>=2){
				ll mul=((ll)j*((ll)j-1)/2)%mod;
				//if(i==0 && j==2)cout<<mul<<endl;
				dp[i+2][j-2]=(dp[i+2][j-2]+(dp[i][j]*mul)%mod)%mod;
			}
			if(rem>0 && j>=1){
				ll mul=((ll)j*rem)%mod;
				dp[i+2][j-1]=(dp[i+2][j-1]+(dp[i][j]*mul)%mod)%mod;
			}

		}
	}
	//cout<<dp[2][0]<<endl;
	cout<<dp[len][0]<<endl;
	return 0;
}
