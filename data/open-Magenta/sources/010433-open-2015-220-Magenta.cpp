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


int n,m,i,j,k,x,y,S;
bool fl;

void move(int dir){
	x+=dx[dir];
	y+=dy[dir];
	printf("%c\n",cd[dir]);
	//printf("%c (%d %d)\n",cd[dir],x,y);
	fflush(stdout);
	char result;
	scanf("%c",&result);
	while (result=='\n') scanf("%c",&result);
	//printf("%c",result);
	if (result!='N') exit(0);
}

void Try(int S, int predS){
	x=y=1;
	for (i=1; ; ++i){
		fl=0;
		while (x*y<S){
			move(0);
			fl=1;
		}
		if (!fl) break;
		move(2);
		while (x+1!=y)
			move(3);
		fl=0;
		while (x*y<S){
			move(2);
			fl=1;
		}
		if (!fl) break;
		move(0);
		while (x+1!=y)
			move(1);
	}
}

int main(){
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	x=y=1;
	for (i=1; ; ++i){
		move(0);
		fl=0;
		while (x>y && y<20){
			move(2);
			fl=1;
		}
		if (fl) break;
		while (x>1){
			move(3);
		}
		move(2);
		fl=0;
		while (x<y && x<20){
			move(0);
			fl=1;
		}
		if (fl) break;
		while (y>1)
			move(1);
	}
	//Try(20, 0);
	//Try(300, 20);
	Try(2000, 300);
	//Try(6000, 2000);
	return 0;
}
