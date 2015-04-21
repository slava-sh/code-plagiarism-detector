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
	char ran[]={'U','D','L','R'};
	int fl=0;
	char t='L';
	char pred='L';
	int num=0;
	while (x=='N')
	{
		cout<<t<<endl;
		cout.flush();
		cin>>x;
		int y=rand()%4;
		t=ran[y];
		if (x!='N')
			return 0;
	}
		
	return 0;
}