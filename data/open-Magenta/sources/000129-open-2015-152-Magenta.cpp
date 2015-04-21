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



int main()
{
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	char x='N';
	int kol=0;
	for (int i=1;i<=300;i++)
		for (int k=0;k<300;k++)
		{
			for (int j=0;j<i;j++)
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
		
	return 0;
}