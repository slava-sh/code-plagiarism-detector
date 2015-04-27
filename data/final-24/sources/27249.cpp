
#include <iostream>
#include <stdlib.h>
using namespace std;
void solve();
void input();
void output();
char inp[20000];
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int L;
int main()
{	
	
	input();
	solve();
	output();
	return 0;
}

void input()
{
	scanf("%d", &L);
	char a = getchar();
	gets(inp);	
}
void solve()
{
for(int i = 0; inp[i] != 0;i++)
	{
		if(inp[i] == 'a')
			flag1 = 1;
		else if(inp[i] == 'b')
			flag2 = 1;
		else if(inp[i] == 'c')
			flag3 = 1;
	}
}
void output()
{
	cout << flag1 + flag2 + flag3 << endl;
	if(flag1)
		cout << 'a' << endl;
	if(flag2)
		cout << 'b' << endl;
	if(flag3)
		cout << 'c' << endl;
}