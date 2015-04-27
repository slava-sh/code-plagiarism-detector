#include<cstdio>
#include<algorithm>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	double pr[101];
	rep(i,n+1) scanf("%lf",pr+i);

	static double dp[310][310];
	rep(i,310) rep(j,310) dp[i][j]=-1e70;
	dp[0][0]=0;
	rep(i,3*n+1){ // i ��ڂ̑I��
		rep(j,3*n+1){ // �T���� j �l����
			rep(k,n+1){ // k �l���ߋ��o��҂Ƃ���
				if(0<=j+(n-2*k) && j+(n-2*k)<=3*n){
					dp[i+1][j+(n-2*k)]=max(dp[i+1][j+(n-2*k)],dp[i][j]+pr[k]);
				}
			}
		}
	}

	double ans=0;
	for(int m=1;m<310;m++) ans=max(ans,dp[m][0]/m);
	printf("%.9f\n",ans);

	return 0;
}
