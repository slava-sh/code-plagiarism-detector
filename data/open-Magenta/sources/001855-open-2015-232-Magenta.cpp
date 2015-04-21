#include <iostream>
#include <fstream>

using namespace std;

int fun(int a){
	int ans = 0;
	for(int i = 1; i * i <= a; ++i)
		ans += (a / i);
	return ans;
}

int m[10] = {32, 81, 180, 361, 665, 1143, 1849, 2847, 4208, 6000};
int m1[7] = {42, 140, 396, 988, 2232, 4653, 6000};

char command(char a){
	cout << a << endl;
	cin >> a;
	return a;
}

int main(){
	/*int min_ = 10;
	for(int i = 10; i <= 6000; ++i){
		while(fun(i) < 7 * min_) ++i;
		cout << i << ' ' << fun(i) << "\n";
		min_ = i;
	}
	return 0;*/
	char ch = 'N';
	for(int i = 0; ch == 'N'; ++i){
		for(int q = 1; q <= m[i] && ch == 'N'; ++q){
			for(int z = 0; z < m[i] / q && ch == 'N'; ++z)
				ch = command('U');
			for(int z = 0; z < m[i] / q && ch == 'N'; ++z)
				ch = command('D');
			ch = command('L');
		}
		for(int q = 0; q < m[i] && ch == 'N'; ++q)
			ch = command('R');
	}
}