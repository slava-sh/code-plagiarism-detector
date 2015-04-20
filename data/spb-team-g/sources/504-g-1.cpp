#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("merlin.in", "r", stdin);
	freopen("merlin.out", "w", stdout);
	long long a[100000];
	long long nowread, max,prevmax = 0,prevprevmax = 0, tofill,toread;
	cin >> toread;
	tofill = 0;
	bool anyChange = false;
	max = 0;
	int counter = 0,counter1 = 0;
	while (counter < toread)
	{
		scanf("%I64d", &nowread);
		if (max == 0)
		{
			max = nowread;
		} else
		if (max != 0 && nowread > max)
		{
			prevprevmax = prevmax;
			prevmax = max;
			max = nowread;			
			a[counter1] = nowread;		
			anyChange = true;
			counter1++;
		}else
		
		if (prevmax < nowread && nowread != max)
		{
			prevprevmax = prevmax;
			prevmax = nowread;
			counter1++;
			anyChange = true;
		} else
		if (prevprevmax < nowread && nowread != max && nowread != prevmax){
			prevprevmax = nowread;
				counter1++;
			anyChange = true;
		} else
			
			{
			    tofill += prevmax - nowread;
			}
			if (anyChange && prevprevmax != 0)
			{

				tofill += (prevmax - prevprevmax)*(counter);
				anyChange = false;
			}
		
		counter++;
	}
	int counter3 = 0;
	if (tofill > 0 || counter1 >0)
	{
		tofill -= max;
		while (tofill > 0)
		{
			counter1--;
			tofill -= a[counter1];
			counter3++;
			
		}
		if (tofill <= 0)
		{

			cout << counter3 + 1;
		}
	}
	else
	{
		cout << 0;
	}
	
}