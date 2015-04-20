#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Compare(char *Str1, char *Str2)
{
	while (*Str1 == *Str2 && *Str1 != 0)
		Str1++, Str2++;
	return *Str1 - *Str2;
}

void StrCopy(char *Dest, char *Src)
{
	while ((*Dest++ = *Src++) != 0)
		;
}

void MakeName(char *Name, char *Otch, char *Surname)
{
	char str[20];
	StrCopy(str, Name);
	StrCopy(Name, Surname);
	StrCopy(Surname, Otch);
	StrCopy(Otch, str);
}

int main(void)
{
	FILE *in, *out;
	int j = 0;
	char Names[1000][3][20], str[63];
	bool IsName = false;
	int n;
	if ((in = fopen("names.in", "r")) == NULL)
		return -1;
	if ((out = fopen("names.out", "w")) == NULL)
		return -1;

	fscanf(in, "%i", &n);
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			fscanf(in, "%s", str);
			StrCopy(Names[i][k], str);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			if (!(Compare(Names[i][0], Names[j][0])))
				MakeName(Names[j][0], Names[j][1], Names[j][2]), IsName = true;
			else if (!(Compare(Names[i][0], Names[j][1])))
				IsName = true;
		}
		if (IsName)
			MakeName(Names[i][0], Names[i][1], Names[i][2]), IsName = false;
	}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (Compare(Names[i][0], Names[j][0]) > 0)
				for (int k = 0; k < 3; k++)
				{
					char str[20];
					StrCopy(str, Names[i][k]);
					StrCopy(Names[i][k], Names[j][k]);
					StrCopy(Names[j][k], str);
				}

	for (int i = 0; i < n; i++)
		fprintf(out, "%s %s %s\n", Names[i][0], Names[i][1], Names[i][2]);
	fclose(in);
	fclose(out);
	return 0;
}