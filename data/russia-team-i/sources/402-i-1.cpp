#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

ifstream fin;
ofstream fout;

vector<int> v;

int main()
{
	fin.open("sochi.in");
	fout.open("sochi.out");
	int n, d, mx[100000];
	fin >> n >> d;
	{
		int a;

		for (int i = 0; i < n; i++) {
			fin >> a;
			v.push_back(a);
		}
	}

	sort(v.rbegin(), v.rend());

	int i = 1, k = v[0];
	mx[0] = k;

	if (k <= d) {
		fout << k;
		return 0;
	} else {
		k -= d;
	}

	while ((i < n) && (v[i] >= 3 * d)) {
		mx[i] = k + v[i] - d; 
		k += v[i] - 2 * d;
		i++;
	}
	
	if (v[i] > d) {
		k += v[i] - d;
		mx[i] = k;
		i++;
	}

	int mxx = 0;

	for (int j = 0; j < i; j++) {
		if (mx[j] > mxx) {
			mxx = mx[j];
		}
	}

	fout << mxx;
	return 0;
}