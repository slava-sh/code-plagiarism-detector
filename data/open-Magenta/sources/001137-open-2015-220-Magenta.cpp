#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>

#define SC(x) scanf("%d",&x)
#define mp make_pair
#define fln cout<<endl

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
const char cd[4]={'D','L','R','U'};


int n,m,i,j,k,dir,x,y;

void move(int dir){
	printf("%c\n",cd[dir]);
	fflush(stdout);
	char result;
	scanf("%c",&result);
	while (result=='\n') scanf("%c",&result);
	//printf("%c",result);
	if (result!='N') exit(0);
	x+=dx[dir];
	y+=dy[dir];
}

int main(){
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	dir=0;
	x=y=0;
	for (i=1; ; ++i){
		move(0);
		while (y<x)
			move(2);
		while (x>0)
			move(3);
		move(2);
		while (x<y)
			move(0);
		while (y>0)
			move(1);
	}
	return 0;
}
