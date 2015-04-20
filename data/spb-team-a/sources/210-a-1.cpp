
#include <stdio.h>
#include <math.h>
#include <algorithm>

int main(void)
{
  int a[4], n, k;
  freopen("abcd.in", "r", stdin);
  freopen("abcd.out", "w", stdout);

  scanf("%i", &n);

  for (int i = 0; i < n; i++)
  {
   scanf("%i", &k);
   a[0] = k / 1000;
   a[1] = (k / 100) % 10;
   a[2] = (k % 100) / 10;
   a[3] = k % 10;

   if (((a[0] * 10 + a[1]) * (a[0] * 10 + a[1]) +
	   (a[2] * 10 + a[3]) * (a[2] * 10 + a[3])) % 7 == 1)
	   printf("YES\n");
   else
	   printf("NO\n");
  }

  return 0;
} 