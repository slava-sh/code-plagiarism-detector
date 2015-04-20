#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	int a, b;
	fstream f;
	f.open("abcd.in", fstream::in);
	f >> b;
	int *mas=new int[b];

	for (int i = 0; i < b; i++){
		f >> a;
		mas[i] = a;
	}
	f.close();
	f.open("abcd.out", fstream::out);
	for (int i = 0; i < b; i++){
		int c = (mas[i] / 100)*(mas[i] / 100) + (mas[i] % 100)*(mas[i] % 100);
		if (c % 7 == 1){
			f << "YES";
		}
		else{
			f << "NO";
		}
		f << endl;
	}
	f.close();
	delete[]mas;
	return 0;
}