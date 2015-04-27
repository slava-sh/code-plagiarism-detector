#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 500 + 10;
int n, m;
long long MOD;
long long dp[2][MAX][MAX];
int rec[MAX][MAX];
int cnt[MAX] = {0};
int main(){
	memset(dp, 0, sizeof(dp));
	scanf("%d %d %I64d", &n, &m, &MOD);
	if(n==m) puts("1");
	else{
		for(int i = 0 ; i < m ; i++){
			getchar();
			for(int j = 0 ; j < n ; j++){
				rec[i][j] = getchar() == '1';
				if(rec[i][j] == 1) cnt[j]++;
			}
		}
		int p = 0, q = 0;
		for(int i = 0 ; i < n ; i++){
			if(cnt[i] == 0) p++;
			else if(cnt[i] == 1) q++;
		}
		int now = 0, next = 1;
		dp[now][n-m][0] = 1LL;
		while(p--){
			memset(dp[next], 0, sizeof(dp[next]));
			for(int i = 0 ; i <= n ; i++){
				for(int j = 0 ; j <= n ; j++){
					if(dp[now][i][j]){
						if(j-2>=0){
							dp[next][i][j-2] += j*(j-1)/2%MOD*dp[now][i][j]%MOD;
							dp[next][i][j-2] %= MOD;
						}
						if(i-1>=0&&j-1>=0){
							dp[next][i-1][j] += i*j%MOD*dp[now][i][j]%MOD;
							dp[next][i-1][j] %= MOD;
						}
						if(i-2>=0){
							dp[next][i-2][j+2] += i*(i-1)/2%MOD*dp[now][i][j]%MOD;
							dp[next][i-2][j+2] %= MOD;
						}
					}
				}
			}
			swap(now, next);
		}
		while(q--){
			memset(dp[next], 0, sizeof(dp[next]));
			for(int i = 0 ; i <= n ; i++){
				for(int j = 0 ; j <= n ; j++){
					if(dp[now][i][j]){
						if(i-1>=0){
							dp[next][i-1][j+1] += i*dp[now][i][j]%MOD;
							dp[next][i-1][j+1] %= MOD;
						}
						if(j-1>=0){
							dp[next][i][j-1] += j*dp[now][i][j]%MOD;
							dp[next][i][j-1] %= MOD;
						}
					}
				}
			}
			swap(now, next);
		}
		printf("%I64d\n", dp[now][0][0]);
	}
	return 0;
}