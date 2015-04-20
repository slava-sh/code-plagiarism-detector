
#include <stdio.h>
#include <math.h>
#include <algorithm>

int main(void)
{
  char str;
  int a[4], n, k;
  
  freopen("abcd.in", "r", stdin);
  freopen("abcd.out", "w", stdout);

  scanf("%i", &n);

  for (int i = 0; i < n; i++)
  {
	  int m;
	  scanf("%c", &m);
	  for (int j = 0; j < 4; j++)
	  {
		  scanf("%c", &str);
		  a[j] = str - '0';
	  }
   

   if (((a[0] * 10 + a[1]) * (a[0] * 10 + a[1]) +
	   (a[2] * 10 + a[3]) * (a[2] * 10 + a[3])) % 7 == 1)
	   printf("YES\n");
   else
	   printf("NO\n");
  }

  return 0;
}