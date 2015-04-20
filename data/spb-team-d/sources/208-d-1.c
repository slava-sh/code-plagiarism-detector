#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *in, *out;
	int storms[1000][3], *storm;
	int numStorms, numAreas;
	int i;
	int area, areaHeight;

	in = fopen("dunes.in", "r");
	out = fopen("dunes.out", "w");

	fscanf(in, "%d %d", &numStorms, &numAreas);
	storm = (int *)storms;
	for (i = 0; i < numStorms; ++i, storm += 3)
		fscanf(in, "\n%d %d %d", storm, storm + 1, storm + 2);

	while (numAreas-- > 0)
	{
		fscanf(in, "\n%d", &area);
		areaHeight = 0;
		storm = (int *)storms;
		for (i = 0; i < numStorms; ++i, storm += 3)
		{
			if ((area >= storm[0]) && (area <= storm[1]))
				areaHeight += storm[2] * (((area - storm[0] & 1) ^ 1) * 2 - 1);
		}
		fprintf(out, "%d\n", areaHeight);
	}

	fclose(out);
	return 0;
}