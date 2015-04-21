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
	while (x=='N')
	{
		cout<<t<<endl;
		cout.flush();
		kol++;
		if (kol>=need)
		{
			if (fl==0)
			{
				fl=1;
			}
			else
			{
				need++;
			}
			kol=0;
			t=put(t);
		}
		cin>>x;
	}
		
	return 0;
}