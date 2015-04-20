#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int min(int x, int y){
	if (x > y){
		return y;
	}
	else {
		return x;
	}
}

int main(){
	int k = 0;
	fstream f;
	f.open("seq.in", fstream::in);
	int n, h;
	f >> n >> h;
	vector <int> vec;
	int* mas = new int[n];
	for (int i = 0; i < n; i++){
		int c;
		f >> c;
		mas[i] = c;
	}
	f.close();
	f.open("seq.out", fstream::out);
	for (int i = 0; i < n; i++){
		if (mas[i] == 0){
			for (int j = i; j < min(i+h, n); j++){
				if (j == i + h - 1 && mas[j] <= j - i + 1){
					k += h - mas[j];
					if (k != 0){ vec.push_back(k); }
				}
				else if (mas[j] > j - i + 1){
					k = 0;
					break;
				}
				else if (mas[j] <= j - i + 1){
					k += j - i + 1 - mas[j];
				}
			}
			
		}
		else if (mas[i] = 1){
			for (int j = i; j < min(i + h,n); j++){
				if (j == i + h - 1 && mas[j] <= j - i + 1){
					k += h - mas[j];
					if (k != 0){ vec.push_back(k); }
				}
				else if (mas[j] > j - i + 1){
					k = 0;
					break;
				}
				else if (mas[j] <= j - i + 1){
					k += j - i + 1 - mas[j];
				}
			}
		}
		k = 0;
	}
	if (vec.size() == 0){
		f << -1;
	}
	else{
		int c = vec[0];
		for (int i = 0; i < vec.size(); i++){
			c = min(c, vec[i]);
		}
		f << c;
	}
	f.close();
	return 0;
}





