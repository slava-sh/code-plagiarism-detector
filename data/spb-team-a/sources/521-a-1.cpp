#include<iostream>
#include<fstream>

using namespace std;

int a(int x)
{
	return x*x;
}


int main()
{
	int n, b;
	fstream in("abcd.in");
	ofstream out("abcd.out");
	in >> n;
	for (int i(0); i < n; i++)
	{
		in >> b;
		if ((a(b / 100) + a(b % 100)) % 7 == 1)
			out << "YES" << endl;
		else out << "NO" << endl;
	}
	out.close();
	return  0;
}