#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int n;

int foo()
{
    return 42;
}

int do_nothing()
{
    return foo();
}


int fib(int x)
{
    return (x > 1) ? fib(x - 1) + fib(x - 2) : 1;
}

void solve()
{
	freopen("inventory.in","r",stdin);
	freopen("inventory.out","w",stdout);
	cin.tie(0);
	cin>>n;
	string s;
	getline(cin,s);
	ull pow41[100001];
	pow41[0]=1;
	for (int i=1; i<=100000; i++)
		pow41[i] = pow41[i-1]*41;
	for (int r=0; r<n; r++){
		getline(cin,s);
		s+=s;
		string srev=s;
		reverse(srev.begin(),srev.end());
		vector<ull> hash(s.length() + 1), hash_r(s.length() + 1);
		for (unsigned q=0; q<s.length(); q++){
			hash[q+1] = hash[q] * 41 + (s[q]-'a'+1);
			hash_r[q+1]= hash_r[q] * 41 + (srev[q]-'a'+1);
		}
		int i=s.length()/2;
		while (i<=s.length() && hash[i]-hash[i-s.length()/2]*pow41[s.length()/2] != hash_r[s.length()*3/2-i]-hash_r[s.length()-i]*pow41[s.length()/2]){
			i++;
		}
		printf("%d\n", i>s.length()? -1 : i-s.length()/2);
		//puts("---");
	}
	fclose(stdin);
	fclose(stdout);
}

int main(){
	solve();
    return 0;
}
