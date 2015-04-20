#include <iostream>
#include <fstream>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("game.in");
	ofstream fout("game.out");
	int n, m, l1, r1, l2, r2;
	int x = 0, y = 0, c = 0;
	fin >> n >> m >> l1 >> r1 >> l2 >> r2;
	for (int i = 0; i < n; i++)
	{
		int a;
		fin >> a;
		if (a >= l1 && a <= r1 && a >= l2 && a <= r2){
			c++;
		}
		else
		{
			if (a >= l1 && a <= r1)
				x++;

			if (a >= l2 && a <= r2)
				y++;
		}
	}

	int a = min(m, c);
	bool isPetya = true;
	int p = 0;
	int v = 0;
	if (a % 2 == 0){
		isPetya = true;
		p = v = a / 2;
	}
	else
	{
		isPetya = false;
		p = a / 2 + 1;
		v = a / 2;
	}
	m -= a;
	if (isPetya){
		x -= m / 2 + m % 2;
		y -= m / 2;
	}
	else{
		x -= m / 2 ;
		y -= m / 2+m%2;
	}
	if (x < 0){
		fout << "Vasya";
	}
	else
		if (x != y)
			fout << "Petya";
		else
			fout << "Draw";




	/*int b = min(x, min(y, m));
	x -= b;
	y -= b;
	m -= b;*/

	/*if (isPetya){

		v += b / 2;
		p += b / 2 + b % 2;

	}
	else{
		v += b / 2 + b % 2;
		p += b / 2;
	}
	isPetya = !(b % 2 && isPetya);
	if (m != 0){
		if (x == 0){
			b = min(m, y);
			if (isPetya){
				v += b / 2;
			}
			else
			{
				v += b / 2+b%2;
			}
		}
		else{
			b = min(m, x);
			if (isPetya){
				p += b / 2+b%2;
			}
			else
			{
				p += b / 2 ;
			}
		}
	}
	if (p == v)
		fout << "Draw";
	else
	{
		if (p > v)
			fout << "Petya";
		else
		{
			fout << "Vasya";
		}
	}*/
	fout.close();
	return 0;
}