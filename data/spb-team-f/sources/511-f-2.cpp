#include <iostream>
#include <fstream>
using namespace std;

int nod(int x,int y) {
	if (x%y == 0){
		return y;
	}
	else if (y%x == 0){
		return x;
	}
	else{
		while (x != 0 & y != 0){
			if (x >= y){
				x = x%y;
			}
			else{
				y = y%x;
			}
		}
		if (x == 0){
			return y;
		}
		else{
			return x;
		}
	}
}

int main(){
	long long a, b;

	fstream f;
	f.open("gcm.in", fstream::in);
	f >> a >> b;
	f.close();

	long long w = a*b; 
    
	long long x;
	long long x0 = 0;
	long long y0 = 0;
	long long e = nod(a, b);
	long long q = w / e;
	long long r = w;
	for (x = 1; x <= sqrt(w); x++) 
    {
		if ((w % x == 0) & (abs(x - (w / x))<r)) {
			if (nod(x, w / x) == e){
				x0 = x;
				y0 = w / x;
				r = abs(x - (w / x));
			}
		}
	}

	f.open("gcm.out", fstream::out);
	f << x0 << " " << y0;
	f.close();
	return 0;
}