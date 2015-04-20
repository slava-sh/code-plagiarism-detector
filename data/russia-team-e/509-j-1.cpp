// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

int w,h;
char s[501][501];
bool was[501][501];
int mask[501][501];
int d[501][501],xqueue[10000],yqueue[10000];
int xmove[4]={1,-1,0,0};
int ymove[4]={0,0,1,-1};
char c[4]={'N','S','W','E'};

bool f(int x,int y)
{
	if(x<h && x>=0 && y<w && y>=0)
		return true;
	else
		return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,s1,s2;
	cin >> w >> h >> n;
	int startx,starty;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> s[i][j];
			if(s[i][j]=='V')
			{
				s1=i;
				s2=j;
				startx=i;
				starty=j;
			}
		}
	}
	int st=0,fn=0;
	was[startx][starty]=true;
	d[startx][starty]=0;
	while(fn<=st)
	{
		for(int i=0;i<4;i++)
		{
			if(!was[startx+xmove[i]][starty+ymove[i]] && f(startx+xmove[i],starty+ymove[i]))
			{
				xqueue[st]=startx+xmove[i];
				yqueue[st++]=starty+ymove[i];
				d[startx+xmove[i]][starty+ymove[i]]=d[startx][starty]+1;
				was[startx+xmove[i]][starty+ymove[i]]=true;
			}
		}
		startx=xqueue[fn];
		starty=yqueue[fn++];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='T')
			{
				mask[i][j]=1;
				for(int k=0;k<4;k++)
				{
					if(s[i+xmove[k]][j+ymove[k]]=='T')
					{
						mask[i][j]=2;
					}
				}
			}
			else
				mask[i][j]=0;
		}
	}
	int m=10000000,min=10000000,minx,miny;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(mask[i][j]!=0)
			{
				if(mask[i][j]==2)
					m=d[i][j]+n-1;
				else
					m=d[i][j]+(n-1)*2;
			}
			if(m<min)
			{
				min=m;
				minx=i;
				miny=j;
			}
		}
	}
	int finishx=minx;
	int finishy=miny;
	int k=0;
	char res[10000];
	while(finishx!=s1 || finishy!=s2)
	{
		for(int i=0;i<4;i++)
		{
			if(d[finishx+xmove[i]][finishy+ymove[i]]==d[finishx][finishy]-1 && f(finishx+xmove[i],finishy+ymove[i]))
			{
				finishx+=xmove[i];
				finishy+=ymove[i];
				res[k++]=c[i];
			}
		}
	}
	for(int i=k-1;i>=0;i--)
	{
		cout << res[i];
	}
	if(mask[minx][miny]==1)
	{
		char res1,res2;
		for(int i=0;i<4;i++)
		{
			if(f(minx+xmove[i],miny+ymove[i]))
			{
				if(i==0)
				{
					res1='N';
					res2='S';
				}
				if(i==1)
				{
					res1='S';
					res2='N';
				}
				if(i==2)
				{
					res1='W';
					res2='E';
				}
				if(i==3)
				{
					res1='E';
					res2='W';
				}
			}
		}
		for(int i=0;i<n-1;i++)
		{
			cout << res2 << res1; 
		}
	}
	else
	{
		int ind;
		for(int i=0;i<4;i++)
		{
			if(s[minx+xmove[i]][miny+ymove[i]]=='T')
			{
				ind=i;
			}
		}
		for(int i=0;i<(n-1)/2;i++)
		{
			if(ind==0)
				cout << "SN";
			if(ind==1)
				cout << "NS";
			if(ind==2)
				cout << "EW";
			if(ind==3)
				cout << "WE";
		}
		if(n%2==0)
		{
			if(ind==0)
				cout << "S";
			if(ind==1)
				cout << "N";
			if(ind==2)
				cout << "E";
			if(ind==3)
				cout << "W";
		}
	}
	return 0;
}

