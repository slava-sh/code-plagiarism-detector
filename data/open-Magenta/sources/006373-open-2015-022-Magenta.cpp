#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime> 
using namespace std;

void read()
{
	string s;
	cin >> s;
	if(s != "N")
		exit(0);
}

void can()
{
	while(1)
	{
		if(rand() % 2)
		{
			printf("R\n");
			cout.flush();
		}
		else
		{
			printf("D\n");
			cout.flush();
		}
		read();
	}
}

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	srand(time(NULL));
	can();
	return 0;
}
