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
	int a, b;

	fstream f;
	f.open("gcm.in", fstream::in);
	f >> a >> b;
	f.close();

	int w = a*b; 
    
	int x;
	int x0 = 0;
	int y0 = 0;
	int e = nod(a, b); 
	int q = w / e;  
	int r = q;
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