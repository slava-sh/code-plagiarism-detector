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

char cr;
int x;
int rr, cc;
char res[4] = {'R', 'L', 'U', 'D'};
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int cnt[4] = {2000, 2000, 2000, 2000};
                     
int main() {           
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	srand(time(NULL));
	multiset < pair < int, int > > have;
	int r = 0;
	int c = 0;
	bool f = false;
    for (int i = 0; i < 2000; i++) {
    	cout << "D" << endl;                  
    	cin >> cr;
    	 if (cr == 'E' || cr == 'Y') return 0;
    	 for (int j = 0; j <= 2000 / (i + 1); j++) {
    	 	cout << "L" << endl;
    	 	cin >> cr;
    	 if (cr == 'E' || cr == 'Y') return 0;
    	}	
  	}
	return 0;
}