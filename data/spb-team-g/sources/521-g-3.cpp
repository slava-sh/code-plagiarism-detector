
#include<iostream>
#include<fstream>

using namespace std;


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int n, cnt = 0, arr[10000], max = 1, max2 = 1, index = 0, max1 = 0;
	bool fl = false;
	ifstream in("merlin.in");
	ofstream out("merlin.out");
	in >> n;
	for (int i(0); i < n; i++)
	{
		in >> arr[i];
		if (i > 0)
			if (arr[i] != arr[i - 1]) fl = true;
	}
	if (fl)
	{
		for (cnt = 1;; cnt++)
		{
			max2 = max = 1;
			for (int i(0); i < n; i++)
				if (max < arr[i]) max = arr[i], index = i;
			//out <<" max " << max << " n " << n<< endl;
			swap(&arr[index], &arr[n - 1]);
			n--;
			index = 0;
			for (int i(0); i < n; i++)
				if (max2 < arr[i]) max2 = arr[i];
			//out << " max2 " << max2 << "n " << n << endl;
			int b = 0;
			max1 += max;
			for (int i(0); i < n; i++)
				b += max2 - arr[i];
			if (b < max1)
				break;
		}
	}
	out << cnt;
	out.close();
	return	0;
}