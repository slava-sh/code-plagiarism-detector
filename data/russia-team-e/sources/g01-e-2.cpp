#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> cod1[1002];
int n,cod11[102],x,m,i,j,cod2;
int t1,t2;
char ham[15];
int p;
int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d", &cod11[i], &x);
		for(j=1;j<=x;j++)
		{
			scanf("%d", &cod2);
			cod1[cod11[i]].push_back(cod2);
		}
		sort(cod1[cod11[i]].begin(),cod1[cod11[i]].end());
	}
	scanf("%d", &m);
	for(i=1;i<=m;i++)
	{
		//scanf("%s", &ham);
		cin>>ham;
		if(ham[0]=='0')
		{
			printf("Incorrect\n");
			continue;
		}
		t1 = ham[0]-'0';
		if(cod1[t1].size()>0)
		{
			t2 = (ham[1]-'0')*100+(ham[2]-'0')*10+(ham[3]-'0');
			if(ham[1]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2   /*find(0,cod1[t1].size()-1)*/ && ham[4]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 4;p<7;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 7;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
			//
			t2 = (ham[1]-'0')*1000+(ham[2]-'0')*100+(ham[3]-'0')*10+(ham[4]-'0');
			if(ham[1]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[5]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 5;p<7;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 7;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
			//
			t2 = (ham[1]-'0')*10000+(ham[2]-'0')*1000+(ham[3]-'0')*100+(ham[4]-'0')*10+(ham[5]-'0');
			if(ham[1]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[6]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 6;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
		}
		////2222222222222222222222222222
		t1 = (ham[0]-'0')*10+(ham[1]-'0');
		if(cod1[t1].size()>0)
		{
			t2 = (ham[2]-'0')*100+(ham[3]-'0')*10+(ham[4]-'0');
			if(ham[2]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[5]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 5;p<7;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 7;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
			//
			t2 = (ham[2]-'0')*1000+(ham[3]-'0')*100+(ham[4]-'0')*10+(ham[5]-'0');
			if(ham[2]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[6]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 6;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
			//
			t2 = (ham[2]-'0')*10000+(ham[3]-'0')*1000+(ham[4]-'0')*100+(ham[5]-'0')*10+(ham[6]-'0');
			if(ham[2]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[7]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 7;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
		}
		//3333333333333333333333333333333333333333333
		t1 = (ham[0]-'0')*100+(ham[1]-'0')*10+(ham[2]-'0');
		if(cod1[t1].size()>0)
		{
			t2 = (ham[3]-'0')*100+(ham[4]-'0')*10+(ham[5]-'0');
			if(ham[3]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[6]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 6;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
			//
			t2 = (ham[3]-'0')*1000+(ham[4]-'0')*100+(ham[5]-'0')*10+(ham[6]-'0');
			if(ham[3]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[7]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 7;p<9;p++)
				{
					cout<<ham[p];
				}
				cout<<"-";
				for(p = 9;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
			//
			t2 = (ham[3]-'0')*10000+(ham[4]-'0')*1000+(ham[5]-'0')*100+(ham[6]-'0')*10+(ham[7]-'0');
			if(ham[3]!='0' && lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)!=cod1[t1].end() && *lower_bound(cod1[t1].begin(),cod1[t1].end(),t2)==t2 /*find(0,cod1[t1].size()-1)*/ && ham[8]!='0')
			{
				cout<<"+";
				cout<<t1<<"("<<t2<<")";
				for(p = 8;p<11;p++)
				{
					cout<<ham[p];
				}
				cout<<endl;
				continue;
			}
		}
		cout<<"Incorrect"<<endl;
	}
	return 0;
}
/*
3
7 3
981
3517
812
351 3
34712
1234
963
111 2
111
122
1312
07981826645
*/