#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

class ifk
{
public:
	char name[20], secondname[20], otchestvo[20];
};

bool funk(char *s)
{
	for (int i = 19; i >= 3; i--)
	{
      
		if ((s[i] == 'h') && (s[i - 1] == 'c') && (s[i - 2] == 'i') && (s[i - 3] == 'v'))
		{
			return true;
		}
		else if ((s[i] == 'a') && (s[i - 1] == 'n') && (s[i - 2] == 'v'))
		{
			return true;
		}
	}
	return false;
}

bool dermo(ifk const &a, ifk const &b)
{
	if (strcmp(a.secondname, b.secondname) == 0)
	{
		if (strcmp(a.name, b.name) == 0)
		{
			if (strcmp(a.otchestvo, b.otchestvo) > 0)
				return 0;
			else
				return 1;
		}
		else
		{
			if (strcmp(a.name, b.name) > 0)
				return 0;
			else
				return 1;
		}
	}
	else
	{
		if (strcmp(a.secondname, b.secondname) > 0)
			return 0;
		else
			return 1;
	}
}

int main(void)
{
    freopen("names.in", "r", stdin);
    freopen("names.out", "w", stdout);  

	ifk kal[1000];
	int n;
	char a[20];

	scanf("%i", &n);

	for (int kk = 0; kk < n; kk++)

	{
		scanf("%s", kal[kk].secondname);
		scanf("%s", kal[kk].name);
		scanf("%s", kal[kk].otchestvo);

		if (funk(kal[kk].name))
		{
			strncpy(a, kal[kk].secondname, 20);
			strncpy(kal[kk].secondname, kal[kk].otchestvo, 20);
			strncpy(kal[kk].otchestvo, a, 20);

			strncpy(a, kal[kk].name, 20);
			strncpy(kal[kk].name, kal[kk].otchestvo, 20);
			strncpy(kal[kk].otchestvo, a, 20);
		}
	}

	sort(kal, kal + n, dermo);

	for (int kk1 = 0; kk1 < n; kk1++)

	{
		printf("%s %s %s\n", kal[kk1].secondname, kal[kk1].name, kal[kk1].otchestvo);
	}
	
return 0;
} 