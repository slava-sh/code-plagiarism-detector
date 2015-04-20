#include<fstream>

using namespace std;

ifstream fin;
ofstream fout;

int main()
{
	fin.open("sochi.in");
	fout.open("sochi.out");
	int n, d, mx[100000], k = 0;
	fin >> n >> d;

	for (int i = 0; i < n; i++) {
		fin >> mx[i];
		mx[i] -= 2 * d;
	}

	for (int i = 0; i < n; i++) {
		if (mx[i] >= d) {
			k += mx[i];
			mx[i] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (mx[i] >= 0) {
			k += mx[i];
			mx[i] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		if (mx[i] >= 0) {
			k += mx[i];
			mx[i] = -1;
		}
	}

	if (k == 0) {
		int mxx = -10000;

		for (int i = 0; i < n; i++) {
			if (mx[i] > mxx) {
				mxx = mx[i];
			}
		}

		k = mxx + 2 * d;
	} else {
		k += 2 * d;
	}

	fout << k;
	return 0;
}