#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL int
#define LD long double
#define SIZE 500000
#define FILENAME "numbers"

using namespace std;

LL n, i, r, a[SIZE], cut[SIZE], ans, l, d, oper;
LL w, j, k, len, step, counter, num, country, m, numbers;
char number[20], kod[20], op[20], s[20];
bool boo;

int qqsort(LL *arr, LL l, LL r) {
	LL i = l, j = r, m = arr[(l + r) / 2];
	while (i <= j) {
		while (arr[i] < m) i++;
		while (m < arr[j]) j--;
		if (i <= j) {   
			LL temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			temp = cut[i];
			cut[i] = cut[j];
			cut[j] = temp;
			
			i++;
			j--;
		}
	}                            
	if (l < j) qqsort(arr, l, j);
	if (i < r) qqsort(arr, i, r);
	return 0;
}

int main() 
{
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
	cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%s", kod);
		scanf("%d", &oper);
		for (j = 0; j < oper; j++)
		{
			scanf("%s", op);  
			//cerr << op << " " << kod << endl;   
			cut[counter] = strlen(op);
			step = 1;
			sprintf(s, "");
			sprintf(s, "%s%s", kod, op);
			//cerr << s << endl;
			len = strlen(s);
			for (k = len-1; k >= 0; k--)
			{
				a[counter] += (s[k] - '0')*step;
				step *= 10;
			}
			
			counter++;
		}
	}
	qqsort(a, 0, counter-1);
	//for (i = 0; i<counter; i++)
	//	cerr << a[i] << " ";
	cin >> numbers;
	for (i = 0; i < numbers; i++)
	{
		boo = false;
		scanf("%s", number);
		len = strlen(number);
		if (len != 11)
		{
			printf("Incorrect\n");
			continue;
		}
		for (j = 4; j < 9; j++)
		{
			step = 1;
			w = 0;
			for (k = j-1; k>=0; k--)
			{
				w += step*(number[k] - '0');
				step *= 10;
			}
			//cerr << w << endl;

			l = 0;
			r = counter + 1;	
			while (r > l + 1)
			{
				m = (r + l) / 2;
				if (a[m] > w)
					r = m;
				if (a[m] <= w)
					l = m;
		
			}
			if ((a[l] != w)||(number[j] == '0'))
				continue;
			printf("+");
			step = 1;
			boo = true;
			for (k = 0; k<cut[l]; k++)
				step *= 10;
			oper = a[l] % step;
			country = a[l] / step;

			printf("%d(%d)", country, oper);
			step = 1;
			for (k = 10; k >= j; k--)
			{
				num += step*(number[k] - '0');
				step *= 10;
			}
			cerr << num << endl;
			if ((num > 1000)&&(num <= 9999))
				printf("%d\n", num);
			if ((num > 10000)&&(num <= 99999))
			{
				if (num / 100 < 10)
					printf("0");
				printf("%d-", num / 100);
				if (num % 100 < 10)
					printf("0");
				printf("%d", num % 100);
			}
			if ((num > 100000)&&(num <= 999999))
			{
				if (num / 100 < 100)
					printf("0");
				printf("%d-", num / 100);
				if (num % 100 < 10)
					printf("0");
				printf("%d", num % 100);
			}
			if ((num > 1000000)&&(num <= 9999999))
			{
				if (num / 10000 < 10)
					printf("0");
				printf("%d-", num / 10000);
				if ((num % 10000)/100 < 10)
					printf("0");
				printf("%d-", (num % 10000)/100);
				if (num % 100 < 10)
					printf("0");
				printf("%d", num % 100);
			}
			if ((num > 10000000)&&(num <= 99999999))
			{
				if (num / 10000 < 100)
					printf("0");
				printf("%d-", num / 10000);
				if ((num % 10000)/100 < 10)
					printf("0");
				printf("%d-", (num % 10000)/100);
				if (num % 100 < 10)
					printf("0");
				printf("%d", num % 100);
			}
			break;

		}
		if (!boo)
			printf("Incorrect\n");
		else
			printf("\n");
	}
	return 0; 
}