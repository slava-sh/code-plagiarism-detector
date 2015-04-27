#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int chet[1000000],nechet[1000000],n,m,x,y,tip;

void changechet(int i){
	if (i==0) return;
	chet[i]=chet[2*i]+chet[2*i+1];
	changechet(i/2);
}

void changenechet(int i){
	if (i==0) return;
	nechet[i]=nechet[2*i]+nechet[2*i+1];
	changenechet(i/2);
}

int summchet(int l,int r){
	int summ=0;
	while (l<=r)
	{
		if (l%2==1) summ+=chet[l];
		if (r%2==0) summ+=chet[r];
		l=(l+1)/2;
		r=(r-1)/2;
	}
	return summ;
}

int summnechet(int l,int r){
	int summ=0;
	while (l<=r)
	{
		if (l%2==1) summ+=nechet[l];
		if (r%2==0) summ+=nechet[r];
		l=(l+1)/2;
		r=(r-1)/2;
	}
	return summ;
}

int main(){
	freopen("signchange.in","r",stdin);
	freopen("signchange.out","w",stdout);
	scanf("%d",&n);
	int sz=1;
	for (; sz<n; sz*=2);
	for (int i=0; i<n; i++)
	{
		scanf("%d",&x);
		if ((i+1)%2==0) chet[i+sz]=x;
		else nechet[i+sz]=x;
	}
	for (int i=0; i<n; i++)
	{
		changechet((i+sz)/2);
		changenechet((i+sz)/2);
	}
	scanf("%d",&m);
	for (int i=0; i<m; i++)
	{
		scanf("%d %d %d",&tip,&x,&y);
		if (tip==0)
		{
			if (x%2==0) 
			{
				chet[x+sz-1]=y;
				changechet((x+sz-1)/2);
			} else
			{
				nechet[x+sz-1]=y;
				changenechet((x+sz-1)/2);
			}
		} else
		{
			/*if (x%2==0 && y%2==0)
				cout << summchet(x/2,y/2)-summnechet(x/2+1,y/2);
			else if (x%2==1 && y%2==0)
				cout << summnechet(x/2+1,y/2)-summchet(x/2+1,y/2);
			else if (x%2==0 && y%2==1)
				cout << summchet(x/2,y/2)-summnechet(x/2+1,y/2+1);
			else cout << summnechet(x/2+1,y/2+1)-summchet(x/2+1,y/2);*/
			if (x%2==0) cout << summchet(x+sz-1,y+sz-1)-summnechet(x+sz-1,y+sz-1);
			else cout << summnechet(x+sz-1,y+sz-1)-summchet(x+sz-1,y+sz-1);
			cout << endl;
		}
	}
	return 0;
}