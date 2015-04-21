#include <iostream>

using namespace std;

int main()
{
	for (int i = 0; i < 400; i++)
	{
		for (int q = 0; q < 400; q++)
		{
			cout << "L" << endl;
			cout.flush();
			char in;
			cin >> in;
			if (in == 'Y' || in == 'E')
				return 0;
		}
		cout << "U" << endl;
		cout.flush();
		char in;
		cin >> in;
		if (in == 'Y' || in == 'E')
			return 0;
	}
	return 0;
}