#include <fstream>

using namespace std;

int main() {
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	int n;
	fin >> n;
	int columns[1000];
	for (int i = 0; i < n; i++)
		fin >> columns[i];
	int ans = 0;
	while (columns[ans] >= ans + 1)
		ans++;
	fout << ans;
	for (int i = 0; i < ans; i++)
		fout << '\n' << i + 1 << ' ' << i + 1;

	return 0;
}