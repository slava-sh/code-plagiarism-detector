#include<iostream>
#include<fstream>

using namespace std;

int a(int x)
{
	return x*x;
}


int main()
{
	int n,cnt = 0, arr[10000], max = 1, index = 0, max1 = 0;
	bool fl = true;
	fstream in("merlin.in");
	ofstream out("merlin.out");
	in >> n;
	for (int i(0); i < n; i++)
	{
		in >> arr[i];
		if (i > 0)
			if (arr[i] != arr[i - 1]) fl = false;
	}
	if (!fl)
	{
		for (cnt = 1;; cnt++)
		{
			for (int i(0); i < n; i++)
				if (max < arr[i]) max = arr[i], index = i;
			arr[index] = arr[n - 1];
			n--;
			int b = 0;
			max1 += max;
			for (int i(0); i < n; i++)
				b += max - arr[i];
			if (b < max1)
				break;
		}
	}
	out << cnt;
	out.close();
	return  0;
}