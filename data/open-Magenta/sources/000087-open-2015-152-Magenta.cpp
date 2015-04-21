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
	while (x=='N')
	{
		if (kol>300)
		{
			cout<<'L'<<endl;
			kol=0;
		}
		else
		{
			cout<<'D'<<endl;
			kol++;
		}
		cout.flush();
		cin>>x;
	}
	return 0;
}