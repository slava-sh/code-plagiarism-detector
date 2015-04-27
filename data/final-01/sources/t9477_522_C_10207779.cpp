#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
#define MAXN 500000
#define INF 10001
#define EPS 0.00000001
#define LL long long
#define re return
#define M 100010
#define K 100010
using namespace std;

int m, k;
typedef struct{
	int summary,
		still,
		occurs;
}ta;
ta all[K];

int used[M];
int foo[M];

int can[M];
char res[K];

void solve(){
	for (int i = 1; i <= k; ++i)
		all[i].occurs = all[i].still = 0;

	can[0] = 0;
	for (int i = 0; i < m; ++i) {
		can[i + 1] = can[i];
		if (used[i] == 0)
			can[i + 1] += 1;
		else
			all[used[i]].occurs += 1;
	}
	set<pair<int, int>> fr;
	set<int> cfr;
	for (int i = 1; i <= k; ++i) {
		if (all[i].occurs == 0){
			fr.insert(make_pair(all[i].summary, i));
			cfr.insert(i);
		}
		all[i].still = all[i].occurs;
	}

	int needForMin = -1, firstFoo = m;
	for (int i = 0; i < m; ++i) {
		if (firstFoo >= m) {
			if (foo[i]) {
				firstFoo = i;
				//int imin = fr.begin()->second;
				//needForMin = all[imin].summary - all[imin].occurs;
				needForMin = fr.begin()->first;
				break;
			}
			if (used[i]) {
				int ki = used[i];
				all[ki].still -= 1;
				if (all[ki].still == 0){
					fr.insert(make_pair(all[ki].summary - all[ki].occurs, ki));
					cfr.insert(ki);
				}
			}
		}
	}
	
	res[k] = 0;
	for (int i = 1; i <= k; ++i) {
		res[i - 1] = 'N';
		
		if (cfr.find(i) != cfr.end()) {
			int could = can[firstFoo] + all[i].occurs;
			if (could >= all[i].summary)
				res[i - 1] = 'Y';
		}
		if (needForMin != -1) {
			int could = can[m] + all[i].occurs - needForMin;
			if (could >= all[i].summary)
				res[i - 1] = 'Y';
		}
	}
}

char resNaive[K];
void solve_naive(){
	int suma = 0; for (int i = 1; i <= k; ++i){
		resNaive[i - 1] = 'N';
		suma += all[i].summary;
	}

	int perm[20], orig[20]; for (int i = 0; i < suma; ++i)perm[i] = i + 1;
	for (int i = 1, csum = 0; i <= k; ++i)for (int j = 0; j < all[i].summary; ++j, ++csum)orig[csum] = i;
	int used1[100];

	do{
		bool bOk = true;
		for (int i = 0; i < m; ++i){
			used1[i] = orig[perm[i] - 1];
			if (used[i] != 0 && orig[perm[i] - 1] != used[i]){ bOk = false; break; }
		}
		if (!bOk)continue;

		for (int i = 1; i <= k; ++i){
			all[i].occurs = 0;
			all[i].still = 0;
		}

		set<int>foos;
		for (int i = 0; i < m; ++i){
			int ki = orig[perm[i] - 1];

			if (foos.find(ki) != foos.end()){
				bOk = false;
				break;
			}
			if (foo[i]){
				if (foos.size() == 0){
					bOk = false;
					break;
				}
			}

			all[ki].occurs++;
			if (all[ki].occurs >= all[ki].summary){
				foos.insert(ki);
			}
		}
		if (bOk){
			for (set<int>::iterator it = foos.begin(); it != foos.end(); ++it){
				resNaive[*it - 1] = 'Y';
			}
		}
	} while (next_permutation(perm, perm + suma));
	int u = 0;
}

#define forn(i,n) for(int i = 0; i < n; ++i)
int a[200];
int SUM;
void gen(){
	forn(i, k) all[i + 1].summary = 1;
	int s = 0;
	forn(i, k) s += all[i + 1].summary;
	while (s < SUM) all[1 + rand() % k].summary += 1, s += 1;
	forn(i, k) a[1 + i] = all[1 + i].summary;
	memset(foo, 0, sizeof(int) * 100);
	forn(i, m - 1) {
		used[i] = rand() % k;
		if (a[1 + used[i]] == 0) {
			foo[i] = 1;
			do{
				used[i] = rand() % k;
			} while (a[1 + used[i]] == 0);
		}
		a[1 + used[i]] -= 1;
	}
	forn(i, m - 1) if (rand() & 4) used[i] = 0; else used[i] += 1;
}

void stress(){
	for (int u = 0;; ++u){
		m = 6; k = 5;
		SUM = 8;
		gen();

		m -= 1;
		solve_naive();
		solve();

		for (int i = 1; i <= k; ++i)cout << all[i].summary << " ";
		cout << endl;
		for (int i = 0; i < m; ++i){
			cout << used[i] << " " << foo[i] << endl;
		}

		for (int i = 0; i < k; ++i)if (resNaive[i] != res[i]){
			cout << "Fuck";
		}
	}
}

int main(){
	//stress();
#ifndef ONLINE_JUDGE
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int T; cin >> T;
	for (int T1 = 0; T1 < T; ++T1){
		cin >> m >> k;
		--m;

		for (int i = 1; i <= k; ++i)
			cin >> all[i].summary;

		for (int i = 0; i < m; ++i)
			cin >> used[i] >> foo[i];
		
		solve();
		cout << res << endl;
	}
	re 0;
}