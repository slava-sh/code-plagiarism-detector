#include <iostream>
#include <fstream>

using namespace std;

int a, b; 
int m[1000001];

int main(){
	cin >> a;
	for(int i = 1; i <= a; ++i)
		cin >> m[i];
	int max_ = 0;
	int a1 = -1, a2 = -1;
	for(int i = 1; i <= a; ++i)
		for(int q = i + 1; q <= a; ++q)
			if(m[i] > m[q] && max_ > abs(q - m[i]) - abs(m[i] - i) + abs(i - m[q]) - abs(m[q] - q))
				max_ = abs(q - m[i]) - abs(m[i] - i) + abs(i - m[q]) - abs(m[q] - q), a1 = i, a2 = q;
	cout << a1 << ' ' << a2 << "\n";

	return 0;
}