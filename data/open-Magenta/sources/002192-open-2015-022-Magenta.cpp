#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

void read()
{
	string s;
	cin >> s;
	if(s != "N")
		exit(0);
}

void can(int s)
{
	for(int i = 0; i < s; i++)
	{
		for(int j = 0; j < s; j++)
		{
			printf("R\n");
			cout.flush();
			read();
		}
		printf("D\n");
		cout.flush();
		read();
	}
}

/*void bin()
{
	int l = 1, r = 6000;
	while(1)
	{
		int mid = (l + r) / 2;
	}
}*/

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//bin();
	can(21);
	can(301);
	can(6001);
	return 0;
}
