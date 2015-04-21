#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <ctime>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

char c;
                     
int main() {           
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	srand(time(NULL));
    while (true) {
    	int x = rand() % 2;
    	if (x == 0) cout << "L" << endl;
    		else if (x == 1) cout << "D" << endl;
    			else if (x == 2) cout << "D" << endl;
    				else if (x == 3) cout << "U" << endl;
    	 cin >> c;
    	 if (c == 'E' || c == 'Y') break;
  	}
	return 0;
}