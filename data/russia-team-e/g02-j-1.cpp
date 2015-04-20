#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
ifstream fin("travel.in");
ofstream fout("travel.out");
const int MAX = 502;
int n,m,k, a[MAX][MAX];
int i,j, i0, j0;
int abs (int a) {
	return a>0 ? a : -a;
}
int main()
{	
	fin >> m >> n >> k;
	for (i=1; i<=n; ++i) {
		for (j=1; j<=m; ++j) {
			char c; fin >> c;
			if (c == 'T') {
				a[i][j] = 1;
				if (a[i-1][j]==1) {
					a[i-1][j] = 2; a[i][j] = 2;
				}
				if (a[i][j-1] == 1)
				{
					a[i][j-1] = 2; a[i][j] = 2;
				}
			}
			else a[i][j] = 0;
			if (c=='V') {
				i0 = i; j0 = j;
			}
		}
	}
	int min1=1002, min1i, min1j;int min2=1002, min2i, min2j;
	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			if (a[i][j] == 1 && abs(i-i0)+abs(j-j0) < min1) {
				min1 = abs(i-i0)+abs(j-j0);
				min1i = i; min1j = j;
			}
			if (a[i][j] == 2 && abs(i-i0)+abs(j-j0) < min2) {
				min2 = abs(i-i0)+abs(j-j0);
				min2i = i; min2j = j;
			}
		}
	}
	if (2 * min1 < min2) {
		if (min1i > i0) {
			for (i=0; i<abs(min1i - i0); i++) 
				fout << "S";
		}
		if (min1j > j0) {
			for (i=0; i<abs(min1j - j0); i++) 
				fout << "E";
		}
		if (min1i <= i0) {
			for (i=0; i<abs(min1i - i0); i++) 
				fout << "N";
		}
		if (min1j <= j0) {
			for (i=0; i<abs(min1j - j0); i++) 
				fout << "W";
		}
		if (min1i == n-1 && min1j == m-1) {
			if (n==1) 
			{
				for (i=0; i<k-1; i++) {
					fout << "WE";
				}
			}
			else {
				for (i=0; i<k-1; i++) {
					fout << "NS";
				}
			}
		}
		else {
			if (n==1) 
			{
				for (i=0; i<k-1; i++) {
					fout << "EW";
				}
			}
			else {
				for (i=0; i<k-1; i++) {
					fout << "SN";
				}
			}
		}
	}
	else {
		if (min2i > i0) {
			for (i=0; i<abs(min2i - i0); i++) 
				fout << "S";
		}
		if (min2j > j0) {
			for (i=0; i<abs(min2j - j0); i++) 
				fout << "E";
		}
		if (min2i <= i0) {
			for (i=0; i<abs(min2i - i0); i++) 
				fout << "N";
		}
		if (min2j <= j0) {
			for (i=0; i<abs(min2j - j0); i++) 
				fout << "W";
		}
		if (a[min2i-1][min2j] == 2) {
			if (k%2 == 1) {
				for (i=0; i<(k-1)/2; i++)
					fout << "NS";
			}
			else {
				for (i=0; i<k/2-1; i++)
					fout << "NS";
				fout << "N";
			}
		}
		if (a[min2i+1][min2j] == 2) {
			if (k%2 == 1) {
				for (i=0; i<(k-1)/2; i++)
					fout << "SN";
			}
			else {
				for (i=0; i<k/2-1; i++)
					fout << "SN";
				fout << "S";
			}
		}
		if (a[min2i][min2j-1] == 2) {
			if (k%2 == 1) {
				for (i=0; i<(k-1)/2; i++)
					fout << "WE";
			}
			else {
				for (i=0; i<k/2-1; i++)
					fout << "WE";
				fout << "W";
			}
		}
		if (a[min2i][min2j+1] == 2) {
			if (k%2 == 1) {
				for (i=0; i<(k-1)/2; i++)
					fout << "EW";
			}
			else {
				for (i=0; i<k/2-1; i++)
					fout << "EW";
				fout << "E";
			}
		}
	}
	fout<<"\n";
	return 0;
}