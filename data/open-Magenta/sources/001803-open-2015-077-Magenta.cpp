#include<iostream>
#include<stdio.h>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	for(;;){
		int x=rand()%2;
		if(!x)
			printf("R\n");
		else
			printf("D\n");
		fflush(stdout);
		char c;
		scanf("%c",&c);
		if(c=='Y' || c=='E')
			return 0;
		scanf("%c",&c);
	}
}