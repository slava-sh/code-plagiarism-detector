#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

char put(char x)
{
	if (x=='D')
		return 'L';
	if (x=='U')
		return 'R';
	if (x=='L')
		return 'U';
	if (x=='R')
		return 'D';
}

int main()
{
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	char x='N';
	int kol=0;
	int need=1;
	int fl=0;
	char t='L';
	int num=0;
	for (int i=0;i<300;i++)
	{
		for (int j=0;j<300;j++)
		{
			cout<<'D'<<endl;
			cout.flush();
			cin>>x;
			if (x!='N')
				return 0;
		}
		cout<<'L'<<endl;
		cout.flush();
			cin>>x;
			if (x!='N')
				return 0;
	}
	for (int i=0;i<2000;i++)
	{
		for (int j=0;j<2000;j++)
		{
			cout<<"D"<<endl;
			cout.flush();
			cin>>x;
			if (x!='N')
				return 0;
		}
		cout<<"L"<<endl;
		cout.flush();
			cin>>x;
			if (x!='N')
				return 0;
	}
	return 0;
}