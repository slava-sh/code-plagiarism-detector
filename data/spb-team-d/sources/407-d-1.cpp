#include <fstream>

using namespace std;

int main() {
	ifstream fin("dunes.in");
	ofstream fout("dunes.out");
	int n, m;
	fin >> n >> m;
	int blow[1000][3];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			fin >> blow[i][j];
	for (int i = 0; i < m; i++) {
		int cur;
		fin >> cur;
		int height = 0;
		for (int j = 0; j < n; j++) {
			if ((cur >= blow[j][0]) && (cur <= blow[j][1])) {
				if ((cur - blow[j][0]) % 2)
					height -= blow[j][2];
				else
					height += blow[j][2];
			}
		}
		fout << height << '\n';
	}

	return 0;
}