#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define REP(i, N) for(int i = 0; i < (N); i++)

using namespace std;
int n,m;
char type[111111][5];
int id[111111];
int status[111111];
vector<int> conAtStart;
vector<int> notCon;

void setup() {
	REP(i, n) status[i] = -1;
	REP(i, conAtStart.size()) status[conAtStart[i]] = 1;
	REP(i, notCon.size()) status[notCon[i]] = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	REP(i, n) status[i] = -1;
	REP(i, m) {
		scanf("%s %d\n", type[i], id+i);
		id[i]--;
	}
	int atStartAtLeast = 0;
	REP(i, m) {
		if(type[i][0] == '+') {
			if(status[id[i]] == -1) {
				notCon.pb(id[i]);
			}
			status[id[i]] = 1;
		} else {
			if(status[id[i]] == -1) {
				conAtStart.pb(id[i]);
			}
			status[id[i]] = 0;
		}
	}

	setup();
	int arbit = 0;
	set<int> noleaders;
	int onlyleader = -1;
	bool ok = true;
	
	int connected = conAtStart.size();
	REP(i, m) {
		if(type[i][0] == '+') {
			if(connected > 0)
				noleaders.insert(id[i]);
			connected++;
			if(connected == 1) {
				if(onlyleader == -1) onlyleader = id[i];
				else if(onlyleader != id[i]) ok = false;
			}
		} else {
			if(connected == 1) {
				if(onlyleader == -1) onlyleader = id[i];
				else if(onlyleader != id[i]) ok = false;
			}
			connected--;
			if(connected > 0)
				noleaders.insert(id[i]);
		}
	}
	if(!ok) REP(i, n) if(status[i] != -1) noleaders.insert(i);

	int cnt = n-(int)noleaders.size();
	printf("%d\n", cnt);
	if(cnt == 0) return 0;
	REP(i, n) {
		if(noleaders.find(i) == noleaders.end())
			printf("%d ", i+1);
	}
	
	return 0;
}
