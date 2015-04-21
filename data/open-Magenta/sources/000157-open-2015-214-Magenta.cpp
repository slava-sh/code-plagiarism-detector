#include<iostream>
using namespace std;
void mstep(char c)
{
	cout << c << endl;
	fflush(stdout);
	char a;
	cin >> a;
	if (a != 'N') exit(0);
}
int main()
{
	int step = 0,stepsz=1;
	while (1)
	{
		if (step % 2 == 0)
		{			
			for (int i = 1; i <= stepsz; i++)
			{
				mstep('D');
			}
			for (int i = 1; i <= stepsz; i++)
			{
				mstep('L');
			}
		}
		else
		{
			for (int i = 1; i <= stepsz; i++)
			{
				mstep('U');
			}
			for (int i = 1; i <= stepsz; i++)
			{
				mstep('R');
			}
		}
		step++;
		stepsz++;
	}
	
}