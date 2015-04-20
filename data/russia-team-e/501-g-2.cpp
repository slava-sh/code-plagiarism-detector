#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
	ifstream in("prizes.in");
	ofstream out("prizes.out");
	
	int x,y,sum;
	in >> x >> y;
	sum = 0;
	if (x <= y)
	{
		if(x>2)
		{
			sum=(x-3)/4+1;
		}
	}
	else
	{
		if(y>2)
		{
			sum=(y-3)/4+1;
		}
		
	}

	out << sum;
	return   0;
}
