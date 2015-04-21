#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
vector<unsigned long long>h,p;
unsigned long long hs(int l, int r){
	return h[r]-h[l-1]*p[r-l+1];
}
int main(){
	int l,n,t;
	char a=0,b=0,c=0;
	scanf("%d",&l);
	string s;
	cin>>s;
	n=s.size();
	t=n;
	vector<int>z(n);
	for(int i=1,l=0,r=0;i<n;i++){
		if(i<=r)
			z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
		if(t==n && i+z[i]==n && n%i==0)
			t=i;
	}
	for(int i=0;i<n && (!a || !b || !c);i++)
		if(s[i]=='a')
			a=1;
		else
			if(s[i]=='b')
				b=1;
			else
				c=1;
	if(a && !b && !c)
		printf("1\na");
	else
		if(!a && b && !c)
			printf("1\nb");
		else
			if(!a && !b && c)
				printf("1\nc");
			else
				if(a && b && !c){
					if(l<t)
						printf("2\na\nb");
					else
						cout<<1<<endl<<s.substr(0,t);
				}else
					if(a && !b && c){
						if(l<t)
							printf("2\na\nc");
						else
							cout<<1<<endl<<s.substr(0,t);
					}else
						if(!a && b && c){
							if(l<t)
								printf("2\nb\nc");
							else
								cout<<1<<endl<<s.substr(0,t);
						}else{
							if(l>=t)
								cout<<1<<endl<<s.substr(0,t);
							else
								if(l>=t/2+t%2)
									cout<<2<<endl<<s.substr(0,t/2)<<endl<<s.substr(t/2,t/2+t%2);
								else{
									h.resize(n+1);
									p.resize(n+1);
									h[0]=0;
									p[0]=1;
									for(int i=1;i<=n;i++){
										h[i]=h[i-1]*5+(s[i-1]-'a'+1);
										p[i]=p[i-1]*5;
									}
									for(int i=0;i<l;i++){
										if(i==2)
											i=i;
										unsigned long long h1=hs(1,i+1);
										int j,l1=i+1;
										for(j=l1;j<n;)
											if(j<n && hs(j+1,j+l1)==h1)
												j+=l1;
											else
												break;
										for(int k=j;k<n && k-j+1<=l;k++){
											int l2=k-j+1;
											if(l1==3 && l2==3)
												i=i;
											unsigned long long h2=hs(j+1,j+l2);
											char flag=1;
											for(int e=j;e<n;)
												if(hs(e+1,e+l1)==h1)
													e+=l1;
												else
													if(hs(e+1,e+l2)==h2)
														e+=l2;
													else{
														flag=0;
														break;
													}
											if(flag){
												cout<<2<<endl<<s.substr(0,l1)<<endl<<s.substr(j,l2);
												return 0;
											}
										}
									}
									printf("3\na\nb\nc");
								}
						}
}