#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	char in;
	char out[2] = { 'U', 'L' };
	while (true)
	{
		cout << out[rand() % 2] << endl;
		cout.flush();
		cin >> in;
		if (in == 'Y' || in == 'E')
			return 0;
	}
	return 0;
}