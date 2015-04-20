#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string a[102][10002];
int sizes[1002];

int sizeint(int x)
{
	int i,b;
	b=0;
	while(x!=0)
	{
		b++;
		x=x/10;
	}
	return b;
}
int main()
{
	string s,s1,s2;
	bool check,outputed;
	string ans;
	int b,c,d,e,f,n,k,m,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i][0]>>sizes[i];
		for(j=1;j<=sizes[i];j++)
			cin>>a[i][j];
	}
	cin>>m;
	for(k=1;k<=m;k++)
	{
		cin>>s;
		s1=s;
		check=true;
		ans.clear();
		outputed=false;
		
		if(s[1]=='0')
		{
			cout<<"Incorrect"<<endl;
			outputed=true;
			check=false;
		}
		else
		for(i=1;i<=n;i++)
		{
			if(s1.find(a[i][0])==0)
			{
				s1.erase(0,a[i][0].size());
				ans=ans+'+'+a[i][0];
				for(j=1;j<=sizes[i];j++)
					if(s1.find(a[i][j])==0)
					{
						check=true;
						ans=ans+'(';
						ans=ans+a[i][j];
						ans=ans+')';
						s1.erase(0,a[i][j].size());
						if(s1.size()==3)
						{
							if(s1[0]=='0')
							{
								check=false;
								
							}
							else
							{
								ans=ans+s1;
							}
						}
						else
							if(s1.size()==4)
							{
								if(s1[0]=='0' || s1[2]=='0')
								{
									check=false;
									
								}
								else
									ans=ans+s1[0]+s1[1]+'-'+s1[2]+s1[3];
							}
							else
								if(s1.size()==5)
								{
									if(s1[0]=='0' || s1[3]=='0')
									{
										check=false;
									
									}
									else
										ans=ans+s1[0]+s1[1]+s1[2]+'-'+s1[3]+s1[4];
								}
								else
									if(s1.size()==6)
									{
										if(s1[0]=='0' || s1[2]=='0' || s1[4]=='0')
										{
											check=false;
											
										}
										else
											ans=ans+s1[0]+s1[1]+'-'+s1[2]+s1[3]+'-'+s1[4]+s1[5];
									}
									else
										if(s1.size()==7)
										{
											if(s1[0]=='0'  || s1[3]=='0' || s1[5]=='0')
											{
												check=false;
												
											}
											else
												ans=ans+s1[0]+s1[1]+s1[2]+'-'+s1[3]+s1[4]+'-'+s1[5]+s1[6];
										}
								if(check==true)
								{
									cout<<ans<<endl;
									i=n+1;
									outputed=true;
									break;
								}
					}
			}
		}
			if(outputed==false)
				cout<<"Incorrect"<<endl;

		
	}

	return 0;
}








				
	