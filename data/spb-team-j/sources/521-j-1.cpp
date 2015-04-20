#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;


int main()
{
	ifstream in("seq.in");
	ofstream out("seq.out");
	int n, h, arr[200000], b = 1, cnt = 0, x = 2000000;
	in >> n >> h;
	for (int i(0); i < n; i++)
		in >> arr[i];
	for (int i(0); i < n; i++)
	{
		if (arr[i] == 1)
		{
		   for (int j(1); j < h; j++)
		     {
			   if (arr[i + j - 1] <= arr[i + j - 1] + 1)
			   {
				   
				   cnt += j + 1 - arr[i + j];
			   }
			   b++;
		     }	
		}
		if (b == h)
		{
			if(x >= cnt)
			    x = cnt;
		}
		b = 1;

		cnt = 0;
	}
	if (x == 2000000)
		x = -1;
	out << x;
	out.close();
	return 0;
}