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
	int step = 0, stepsz1 = 1,stepz2=1;
	while (1)
	{
		if (step % 2 == 0)
		{
			for (int i = 1; i <= stepsz1; i++)
			{
				mstep('D');
			}
			for (int i = 1; i <= stepsz2; i++)
			{
				mstep('L');
			}
		}
		else
		{
			for (int i = 1; i <= stepsz1; i++)
			{
				mstep('U');
			}
			for (int i = 1; i <= stepsz2; i++)
			{
				mstep('R');
			}
		}
		step++;
		if (rand() % 2)
		{
			stepsz1++;
		}
		else
		{
			stepz2++;
		}
	}

}