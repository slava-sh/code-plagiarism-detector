#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);

	int n;
	int a[1000];
    char c[65];
	string b[1000];
	cin >> n;
	for (int counter = 0; counter < 1000; counter++)
	{
		cin >> a[counter];
	}
	int x = 0, y = 0;
	int counter = 0;
	while ((x + 1 <= n) && (y + 1 <= a[counter]))
	{
		_itoa(x+1,c,10);
		b[counter] += c ;
		b[counter] += " ";
		_itoa(y + 1, c, 10);
		b[counter] += c;
		
		x++;
		y++;
		counter++;
	}
	cout << counter  << endl;
	int counter1 = 0;
		while (counter1 < counter)
		{
			if (counter1 + 1 < counter){

				cout << (b[counter1]) << endl;
			}
			else {

				cout << (b[counter1]);
			}
		counter1++;
		}
	
}