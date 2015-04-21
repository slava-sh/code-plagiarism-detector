#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	for(;;){
		int x=rand()%4;
		if(!x)
			printf("U\n");
		else
			if(x==1)
				printf("R\n");
			else
				if(x==2)
					printf("D\n");
				else
					printf("L\n");
		fflush(stdout);
		char c;
		scanf("%c",&c);
		if(c=='Y' || c=='E')
			return 0;
		scanf("%c",&c);
	}
}