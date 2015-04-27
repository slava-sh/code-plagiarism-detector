#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct A
{
	long long pos;
	long long chis;
};
bool rav(string a,string b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])
		{
			return false;
		}
	}
	return true;
}
vector<string> rec(int min,int n,string l)
{
	/*vector < vector<string> > resalt;
	vector < vector<string> > state1;
	vector < A > state;
	for(int i=2;i<=n;i++)
	{
		vector<string> k;
		string h=l.substr(0,i);
		k.push_back(h);
		bool yes=false;
		for(int j=i-1;j<l.size();j++)
		{
			if(j+i<l.size()){
			string o=l.substr(j,i);
		    yes=false;
			for(int e=0;e<k.size();e++)
			{
				if(k[e]==o)
				{
					yes=true;
				}
			}
			if(!yes)
			{
				if(min>k.size())
				{
					if(state.size()==0){
					A a;
					a.pos=j;
					a.chis=1;
					state.push_back(a);
					state1.push_back(k);
					k.push_back(l.substr(j,1));
					}else
					{
						j=state[0].pos;
						state[0].chis++;
						k=state1[0];
						if(state[0].chis<=n&&state[0].chis<l.size())
						{
							k.push_back(l.substr(j,state[0].chis));
						}
					}
				}else
				{
					j=l.size();
				}
			}else
			{
				j=j+i;
			}
			}else
			{
				if(min>k.size())
				{
					resalt
				}
			}
		}
		}*/
	if(min==1)
	{
		for(int i=2;i<=n;i++)
		{
			string h=l.substr(0,i);
			if(l.size()%i==0){
				bool yes=true;
			for(int j=i;j<l.size();j=j+i)
			{
				string o=l.substr(j,i);
				if(o!=h)
				{
					yes=false;
				}
				if(!yes)
				{
				j=l.size();
				}
			}
			if(yes)
			{
				vector<string> a;
				a.push_back(h);
				return a;
				}
			}
		}
		vector<string> a;
		return a;
	}
}

int main()
{
	long long n;
	cin>>n;
	bool k[3];
	k[0]=false;k[1]=false;k[2]=false;
	string l;
	cin>>l;
	if(l.size()>n){
		for(int i=0;i<l.size();i++)
		{	
		switch(l[i])
		{
			case 'a' : k[0]=true; break;
			case 'b' : k[1]=true; break;
			case 'c' : k[2]=true; break;
			}
		}
		int min=0;
		for(int i=0;i<3;i++)
		{
			if(k[i])
			{
				min++;
			}
		}
		if(min!=1){
			vector<string>  p=rec(min-1,n,l);
			if(p.size()!=0)
			{
				cout<<p.size()<<endl;
				for(int i=0;i<p.size();i++)
				{
					cout<<p[i];
				}
			}else
			{
				cout<<min<<endl;
				if(k[0])
				{
					cout<<'a'<<endl;
				}
				if(k[1])
				{
					cout<<'b'<<endl;
				}
				if(k[2])
				{
					cout<<'c'<<endl;
				}
			}
		}else
		{
			if(k[0])
			{
				cout<<1<<endl<<'a';
			}else
			{
				if(k[1])
				{
					cout<<1<<endl<<'b';
				}else
				{
					cout<<1<<endl<<'c';
				}
			}
		}
	}
	else{
	cout<<1<<endl<<l;
	}
}