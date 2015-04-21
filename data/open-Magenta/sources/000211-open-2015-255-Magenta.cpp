#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dc[] = {'R', 'U', 'L', 'D'};


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int dir = 0;
	int l = 1;
	int m = 0;
	int l0 = 0;
	char res;

	bool done = 0;
	while(done == 0)
	{
		for(int i = 0; i < 100; i++)
		{
			cout << dc[dir] << endl;
			cout.flush();
			cin >> res;
			if(res == 'Y' || res == 'E')
			{
				done = 1;
				break;
			}

			l0++;
			if(l0 == l)
			{
				l0 = 0;
				m++;
				dir = (dir + 1) % 4;
			}
			if(m == 2)
			{
				m = 0;
				l++;
			}
		}
		if(done)
			break;
		for(int i = 0; i < 150; i++)
		{
			cout << 'R' << endl;
			cout.flush();
			cin >> res;
			if(res == 'Y' || res == 'E')
			{
				done = 1;
				break;
			}
		}
		if(done)
			break;
		for(int i = 0; i < 150; i++)
		{
			cout << 'U' << endl;
			cout.flush();
			cin >> res;
			if(res == 'Y' || res == 'E')
			{
				done = 1;
				break;
			}
		}
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}