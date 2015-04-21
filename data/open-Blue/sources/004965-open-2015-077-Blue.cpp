#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	int l;
	char a=0,b=0,c=0;
	scanf("%d",&l);
	string s;
	cin>>s;
	for(int i=0;i<s.size() && (!a || !b || !c);i++)
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
					if(l<s.size())
						printf("2\na\nb");
					else
						cout<<1<<endl<<s;
				}else
					if(a && !b && c){
						if(l<s.size())
							printf("2\na\nc");
						else
							cout<<1<<endl<<s;
					}else
						if(!a && b && c){
							if(l<s.size())
								printf("2\nb\nc");
							else
								cout<<1<<endl<<s;
						}else{
						}
}