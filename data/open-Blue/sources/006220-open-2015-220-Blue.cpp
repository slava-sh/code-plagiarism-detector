#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <map>

#define SC(x) scanf("%d",&x)
#define mp make_pair

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;

int n,m,i,j,k,l,z[800500],last,g,l1;
string s,s2;
bool fl;

void calcz(string s){
	int n=s.size(), j=0;
	s='$'+s;
	for (int i=0; i<=n*2; ++i)
		z[i]=0;
	z[1]=n;
	z[0]=0;
	for (int i=2; i<=n; ++i){
		z[i]=max(0,min(z[i-j+1],j+z[j]-i));
		while (s[1+z[i]]==s[i+z[i]]) ++z[i];
		if (i+z[i]>j+z[j])
			j=i;
	}
}

int gcd(int x, int y){
	while (x && y){
		if (x>y) x%=y;
		else y%=x;
	}
	return x+y;
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SC(l); getline(cin, s);
	getline(cin, s);
	n=s.size();
	l=min(l,n);
	calcz(s);
	for (i=1; i<=l; ++i){
		//if (n%i) continue;
		fl=1;
		for (j=i+1; j<=n; j+=i)
			if (j+z[j]!=n+1){
				fl=0;
				break;
			}
		if (fl){
			printf("1\n");
			for (j=0; j<i; ++j)
				printf("%c",s[j]);
			printf("\n");
			return 0;
		}
	}
	string pref="";
	for (l1=1; l1<=l; ++l1){
		pref=pref+s[l1-1];
		calcz(pref+'$'+s);
		m=l1+1+n;
		last=g=0;
		s2="";
		for (i=l1+2; i<=m; ++i){
			if (z[i]!=l1 || last+l1>i){
				if (!last || last+l1<=i) s2=s2+s[i-l1-1-1];
				continue;
			}
			if (last && i>=last+l1) g=gcd(g,i-last-l1);
			last=i;
		}
		g=gcd(g,m+1-last-l1);
		calcz(s2);
		for (i=1; i<=min(l,(int)s2.size()); ++i){
			//if (s2.size()%i) continue;
			fl=1;
			for (j=i+1; j<=(int)s2.size(); j+=i)
				if (j+z[j]!=(int)s2.size()+1){
					fl=0;
					break;
				}
			if (fl){
				printf("2\n");
				cout<<pref<<'\n';
				for (j=0; j<i; ++j)
					printf("%c",s2[j]);
				printf("\n");
				return 0;
			}
		}
	}
	bool fa=0,fb=0,fc=0;
	for (i=0; i<(int)s.size(); ++i)
		if (s[i]=='a') fa=1;
		else if (s[i]=='b') fb=1;
		else if (s[i]=='c') fc=1;
	printf("%d\n",fa+fb+fc);
	if (fa) printf("a\n");
	if (fb) printf("b\n");
	if (fc) printf("c\n");
	return 0;
}
