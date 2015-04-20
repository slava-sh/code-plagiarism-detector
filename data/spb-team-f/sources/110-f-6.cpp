#include <iostream>
#include <fstream>

using namespace std;

long long evklid(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return evklid(b, a % b);
}


int main() {
	long long a, b, p, ev1,j;
	ifstream in("gcm.in");
	ofstream out("gcm.out");
	in >> a >> b;
	p = a*b;
	if (a > b) 
		ev1 = evklid(a, b);
	else ev1 = evklid(b, a);
	for (long long i = sqrt(p); i > 0; i--) {
		if (p % i == 0) {

			if (ev1 == evklid(p / i, i)) {

				j = i;
				i = 0; 
			}

		}
	}
	out << j << " " <<  p / j;

	//system("pause");

	in.close();
	out.close();
}