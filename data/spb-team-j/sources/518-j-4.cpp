
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("seq.in");
	ofstream fout("seq.out");
	int n, h, max=-1, max1;
	bool d;
	fin >> n >> h;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		fin >> a[i];
	ll c=0;
	ll mincans = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= 1){
			ll cans = 1 - a[i];
			bool good = true;
			for (int k = 1; k <= h; k++)
			{
				if (a[i+k]>k){
					good = false;
					break;
				}
				else
				{
					cans += k - a[i+k];
				}


			}
			if (good)
			    if (mincans == -1)
				    mincans = cans;
			    else{
				    if (cans < mincans)
					    mincans = cans;
			    }

		}
	}
	fout << mincans;
    fout.close(); 
}