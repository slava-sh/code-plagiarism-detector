#include <fstream>

using namespace std;

int main () {
	unsigned int m,n;
	ifstream inf("prizes.in");
	inf>>m>>n;
	inf.close();
	if (m<n) swap(m,n);
	ofstream ouf("prizes.out");
	switch (n) {
	case 1:
		ouf<<(unsigned int)((m+1)/4);
		break;
	case 2:
		ouf<<0;
		break;
	default:
		ouf<<1;
		break;
	}
	ouf.close();
	return 0;
}