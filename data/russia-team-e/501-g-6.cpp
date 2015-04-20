#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	ifstream in("prizes.in");
	ofstream out("prizes.out");
	
	long long x,y,sum;
	in >> x >> y;
	sum = 0;
	if ((x!=1)&&(y==1))
	{
		if(x>2)
			{
				sum=(x-3)/4+1;
			}
	}
	else if ((x==1)&&(y!=1))
	{
		if(y>2)
			{
				sum=(y-3)/4+1;
			}
	}
	else 
	{ 
		if (x>y) swap(x,y);
		if(x>2)
		{
			sum=(x-3)/4+1;
		}
	}
	out << sum;
	return   0;
}
