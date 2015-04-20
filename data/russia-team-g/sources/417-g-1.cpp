#include <fstream>

using namespace std;

int main () {
	unsigned int m,n;
	ifstream inf("prizes.in");
	inf>>m>>n;
	inf.close();
	if (m<n) swap(m,n);
	ofstream ouf("prizes.out");
	ouf<<(unsigned int)((n+1)/4);
	ouf.close();
	return 0;
}