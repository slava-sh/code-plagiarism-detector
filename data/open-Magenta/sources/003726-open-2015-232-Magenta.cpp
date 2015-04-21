#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int fun(int a){
	int ans = 0;
	for(int i = 1; i <= a; ++i)
		ans += (a / i);
	return (ans + a) * 2;
}

int n = 0;

int min_ = 10;
short int f[6004][6004];

//int m[11] = {10, 32, 81, 180, 361, 665, 1143, 1849, 2847, 4208, 6000};
//int m1[8] = {10, 42, 140, 396, 988, 2232, 4653, 6000};
//int m[6] = {10, 55, 234, 838, 2601, 7254};
//int m[37] = {10, 24, 49, 88, 144, 224, 324, 448, 596, 769, 961, 1170, 1397, 1638, 1888,
//2142, 2401, 2662, 2916, 3168, 3416, 3655, 3885, 4101, 4316, 4512, 4704, 4888, 5049, 
//5200, 5340, 5476, 5610, 5730, 5838, 5931, 6026};

int m1[12] = {10, 30, 76, 169, 339, 624, 1074, 1744, 2697, 3996, 5706, 6000};

int m2[15] = {10, 27, 61, 123, 224, 378, 600, 904, 1302, 1805, 2420, 3152, 4002,
4968, 6000};

int m[13] = {10, 33, 85, 188, 369, 660, 1092, 1689, 2461, 3400, 4470, 5604, 6000};
int m3[12] = {10, 34, 90, 204, 409, 748, 1263, 1995, 2970, 4192, 5634, 6000};

int step = 0;
int x = 1;
int y = 1;
bool rv = 0;

int& get_f(int x, int y){
	return (rv ? f[y][x] : f[x][y]);
}

void tform(char& a){
	if(a == 'U') a = 'L';
	else if(a == 'L') a = 'U';
	else if(a == 'D') a = 'R';
	else a = 'D';
}

char command(char a){
	if(rv) tform(a);
	cout << a << endl;
	if(a == 'U') ++x;
	if(a == 'D') --x;
	if(a == 'L') ++y;
	if(a == 'R') --y;
	a = 'N';
	cin >> a;
	get_f(y, x) = step;
	++n;
	return a;
}


vector<int> v;

int main(){
	/*int sum = 0;
	for(int i = 10; i <= 6000; ++i){
		while(sum + fun(i) < 32 * min_) ++i;
		v.push_back(i);//cout << i << ' ' << fun(i) << "\n";
		min_ = i;
		sum += i * 2;
	}
	cout << "int m[" << v.size() + 1 << "] = {10, ";
	for(int i = 0; i + 1 < v.size(); ++i)
		cout << v[i] << ", ";
	cout << v[v.size() - 1] << "};\n";
	return 0;*/

	char ch = 'N';
	for(int i = 1; ch == 'N'; ++i){
		if(i >= 12) cout << "I";
		step = i + 1;
		for(int q = 1; q <= m[i] && ch == 'N'; ++q){
			while(y * (x + 1) <= m[i] && ch == 'N') ch = command('U');
			while(x > 1 && get_f(y, x - 1) != step - 1 && ch == 'N') ch = command('D');
			if(ch == 'N') ch = command('L');
		}
		rv ^= 1;
		/*for(int q = 1; q <= m[i] && ch == 'N'; ++q){
			for(int z = 0; z < m[i] / q && ch == 'N'; ++z)
				ch = command('U');
			for(int z = 0; z < m[i] / q && ch == 'N'; ++z)
				ch = command('D');
			ch = command('L');
		}
		for(int q = 0; q < m[i] && ch == 'N'; ++q)
			ch = command('R');*/
		//cout << i << m[i] << "\n";
		//cout << n << "\n";
		//cout << fun(m[i]) << "\n";
		//if(n > 27 * m[i - 1]) cout << "I";
	}

}