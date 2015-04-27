#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define NMAX 1024

int A[NMAX][NMAX], SP[NMAX][NMAX];
int M, N, nchanged;

void ReadInput() {
	int i, j;
	char ch;
	scanf("%d %d", &M, &N);
	for (nchanged = 0, i = 1; i <= M; i++)
		for (j = 1; j <= N; j++) {
			scanf(" %c", &ch);
			if (ch == 'X') {
				A[i][j] = 1;
				nchanged++;
			}
		}
}

void ComputePrefixSums() {
	int i, j;
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++) {
			SP[i][j] = SP[i - 1][j] + SP[i][j - 1] - SP[i - 1][j - 1];
			SP[i][j] += A[i][j];
		}
}

int GetSum(int r1, int c1, int r2, int c2) {
	return SP[r2][c2] - SP[r2][c1 - 1] - SP[r1 - 1][c2] + SP[r1 - 1][c1 - 1];
}

int R, C;

void FindUpperLeftCorner() {
	int i, j;
	for (i = 1; i <= M; i++)
		for (j = 1; j <= N; j++)
			if (A[i][j] == 1) {
				R = i;
				C = j;
				return;
			}
}

int RMAX, CMAX;

void FindExtremities() {
	for (RMAX = R; RMAX <= M && A[RMAX + 1][C] == 1; RMAX++);
	for (CMAX = C; CMAX <= N && A[R][CMAX + 1] == 1; CMAX++);
	if (DEBUG) fprintf(stderr, "R=%d RMAX=%d C=%d CMAX=%d\n", R, RMAX, C, CMAX);
}

int ANS;

void Test(int r1, int c1, int r2, int c2) {
	int nrows = r2 - r1 + 1, ncols = c2 - c1 + 1;
	int area = nrows * ncols;
	if (ANS >= 0 && area >= ANS) return;
	int i = r1, j = c1, cnt, nviz;

	cnt = GetSum(r1, c1, r2, c2);
	if (cnt != area) return;
	nviz = cnt;
	
	while (1) {
		if (i + nrows <= M && A[i + nrows][j] == 1 &&
			j + ncols <= N && A[i][j + ncols] == 1) return;
		if (i + nrows <= M && A[i + nrows][j] == 1) {
			// Move down.
			i++;
			cnt = GetSum(i, j, i + nrows - 1, j + ncols - 1);
			if (cnt != area) return;
			nviz += ncols;
		} else if (j + ncols <= N && A[i][j + ncols] == 1) {
			// Move right.
			j++;
			cnt = GetSum(i, j, i + nrows - 1, j + ncols - 1);
			if (cnt != area) return;
			nviz += nrows;
		} else
			break;
	}
	
	if (nviz != nchanged) return;
	ANS = area;
}

int main() {
//	freopen("x.txt", "r", stdin);
	ReadInput();
	ComputePrefixSums();
	FindUpperLeftCorner();
	FindExtremities();

	ANS = -1;
	for (int i = R; i <= RMAX; i++)
		Test(R, C, i, CMAX);
	for (int j = C; j <= CMAX; j++)
		Test(R, C, RMAX, j);

	printf("%d\n", ANS);
	
	return 0;
}
