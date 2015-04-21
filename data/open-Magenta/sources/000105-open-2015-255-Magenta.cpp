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
	while(1)
	{
		cout << dc[dir] << endl;
		cout.flush();
		cin >> res;
		if(res == 'Y' || res == 'E')
			break;

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

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}