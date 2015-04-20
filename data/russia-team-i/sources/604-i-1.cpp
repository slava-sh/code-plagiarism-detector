#include <cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int a[100000 + 7];

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n, d;
        long long res = 0;
	scanf("%d%d", &n, &d);
	for ( int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}	
	sort(a, a + n);
    //    if (a[n - 1] < d)
    //    {
    //      cout << a[n - 1] << endl;
     //     return 0;
     //   }
//	int fl = 0;
      //  int k1 = 0;
      //  int k2 = 0;
    res = a[n - 1];
	for ( int i = n - 2; i > -1; i--)
	{	
       
		if ( a[i] >=  2 * d)
		{
        		res = res + a[i] - 2 * d;
        		 
	//		k1++;
//		}
	//	if ( a[i] >= d && a[i] < 2 * d && fl != 2)
//		{
	//		fl++;
	//		k2++;
	//		res += a[i] - d;
		}
	}
//	if ( fl == 0)
//		res += 2 * d;	
//	if ( fl == 1)
//		res += d;
	printf("%I64d", res);


	return 0;	
}