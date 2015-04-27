#include<bits/stdc++.h>
#define MP make_pair
#define R second
#define L first
using namespace std;
typedef long long lint;
const lint mod=1000000007;
const int maxn=100000+10;
lint fact[maxn];
lint sum[maxn];

lint p(lint a, lint b){
	if(b==0)
		return 1;
	lint mid=p(a, b/2);
	mid=(mid*mid)%mod;
	return (b%2)?mid*a%mod:mid;
}

lint C(int r, int n){
	if(r>n)
		return 0;
	return fact[n]*p(fact[r], mod-2)%mod*p(fact[n-r], mod-2)%mod;
}
string s;

int main(){
	fact[0]=1;
	for(int i=1;i<maxn;i++)
		fact[i]=fact[i-1]*i%mod;
	int n, k;
	cin >> n >> k >> s;
	for(int i=0;i<n;i++){
		lint cur=0;
		cur=p(10, i);
		cur=cur*C(k-1, n-2-i)%mod;
		sum[i]=cur;
		if(i!=0)
			sum[i]=(sum[i-1]+sum[i])%mod;
	}
	lint res=0;
	reverse(s.begin(), s.end());
	for(int i=0;i<n;i++){
		res=(res+(s[i]-'0')*sum[i-1]%mod)%mod;
		res=(res+(s[i]-'0')*p(10, i)%mod*C(k, n-i-1))%mod;
	}
	cout << res << endl;
}
