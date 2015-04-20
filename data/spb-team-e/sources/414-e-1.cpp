#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Gamer
{
	int Start, End, Points = 0, Availibe = 0;
};

int main(void)
{
	FILE *in, *out;
	int m, n, stolb, count = 0, mV, mP;
	Gamer Petya, Vasya;
	if ((in = fopen("game.in", "r")) == NULL)
		return -1;
	if ((out = fopen("game.out", "w")) == NULL)
		return -1;
	
	fscanf(in, "%i %i", &n, &m);
	fscanf(in, "%i  %i", &Petya.Start, &Petya.End);
	fscanf(in, "%i  %i", &Vasya.Start, &Vasya.End);
	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%i", &stolb);
		if (stolb <= Petya.End && stolb >= Petya.Start && stolb >= Vasya.Start && stolb <= Vasya.End)
			count++;
		else
		{
			if (stolb <= Petya.End && stolb >= Petya.Start)
				Petya.Availibe += 1;
			if (stolb <= Vasya.End && stolb >= Vasya.Start)
				Vasya.Availibe += 1;
		}
	}

	if (count > m)
		count = m;
	
	if (count % 2 == 0)
	{
		Petya.Points += count / 2;
		Vasya.Points += Petya.Points;
		m -= count;
		mV = m / 2, mP = m / 2;
		if (m % 2 != 0)
			mP += 1;
	}
	else
	{
		Petya.Points += count / 2 + 1;
		Vasya.Points += count / 2;
		m -= count;
		mV = m / 2, mP = m / 2;
		if (m % 2 != 0)
			mP += 1;
	}
	if (mV <= Vasya.Availibe)
		Vasya.Points += mV;
	else
		Vasya.Points += Vasya.Availibe;
	if (mV <= Petya.Availibe)
		Petya.Points += mV;
	else
		Petya.Points += Petya.Availibe;

	if (Petya.Points > Vasya.Points)
		fprintf(out, "Petya");
	else if (Petya.Points < Vasya.Points)
		fprintf(out, "Vasya");
	else
		fprintf(out, "Draw");
	fclose(in);
	fclose(out);
	return 0;
}