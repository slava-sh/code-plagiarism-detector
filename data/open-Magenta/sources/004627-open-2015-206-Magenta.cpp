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
    while (true) {
    	/*have.insert(mp(rr, cc));
    	f = false;
    	for (int i = 0; i < 5; i++) {
    		x = rand() % 4;
    		rr = r + dx[x];
    		cc = c + dy[x];
    		if (have.count(mp(rr, cc)) <= 2) {
    			cout << res[x] << endl;
    			f = true;
    			break;
    		}
    	}
    	if (!f) {
    		x = rand() % 10;
    		x %= 4;
    		if (rand() % 2 == 0) x = (x + 1) % 4;
    		rr = r + dx[x];
    		cc = c + dy[x];
    		cout << res[x] << endl;
    	} */
    	while (true) {
    		x = rand() % 4;
    		if (cnt[x] < -10) continue;
    		rr = r + dx[x];
    		cc = c + dy[x];
    		break;
    	}
    	cout << res[x] << endl;
    	r = rr;
    	c = cc;	                              
    	cin >> cr;
    	 if (cr == 'E' || cr == 'Y') break;
  	}
	return 0;
}