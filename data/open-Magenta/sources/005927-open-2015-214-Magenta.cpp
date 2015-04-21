#include<iostream>
#include<vector>
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
	int step = 0, stepsz1 = 1,stepsz2=1;
	while (1)
	{		
		mstep('R');
		mstep('D');		
		if (rand() % 2)
		{
			mstep('R');
		}
	}

}