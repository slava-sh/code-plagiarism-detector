#include <fstream>

using namespace std;

int main () {
	ifstream inf("sochi.in");
	long n,d,sum=0,t1=0,t2=0,i,read,max=0;
	inf>>n>>d;
	for (i=0;i<n;++i) {
		inf>>read;
		if (max<read) {
			max = read;
		}
		if (read>=3*d) {
			sum+=read-2*d;
		}
		else {
			if (read>=2*d) {
				if (t1<(read - d)) {
					t2 = t1;
					t1 = read - d;
				}
				else {
					if (t2<(read - d)) {
						t2 = read - d;
					}
				}
			}
		}
	}
	if (t1!=0) {
		sum+=t1;
	}
	else {
		sum+=d;
	}
	if (t2!=0) {
		sum+=t2;
	}
	else {
		sum+=d;
	}
	if (max<2*d) {
		sum = max;
	}
	else {
		if (max<3*d) {
			sum = t1 + t2;
		}
	}
	ofstream ouf("sochi.out");
	ouf<<sum;
	ouf.close();
	return 0;
}