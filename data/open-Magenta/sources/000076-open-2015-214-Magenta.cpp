#include<iostream>
using namespace std;
int main()
{
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			cout << "U" << endl;
			fflush(stdout);
			char c;
			cin >> c;
			if (c != 'N') return 0;
		}
		cout << "R" << endl;
		fflush(stdout);
		char c;
		cin >> c;
		if (c != 'N') return 0;
	}
}