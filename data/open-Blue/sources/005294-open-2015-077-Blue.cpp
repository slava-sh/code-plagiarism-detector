#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
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
						if(!a && b &&c){
							if(l<t)
								printf("2\nb\nc");
							else
								cout<<1<<endl<<s.substr(0,t);
						}else{
							if(l>=t)
								cout<<1<<endl<<s.substr(0,t);
							else
								if(l>=t/2+t%2)
									cout<<1<<endl<<s.substr(0,t/2)<<endl<<s.substr(t/2,t/2+t%2);
								else
									printf("3\na\nb\nc");
						}
}