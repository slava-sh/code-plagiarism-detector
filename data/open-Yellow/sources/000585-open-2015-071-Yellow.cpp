#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>


using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;

const int M = 1e5 + 177;
int a[M];
set<pair<int, int> > se;

int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, n, j, l, r, q, p, c;
	pair<int, int> cur;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	i = 0;
	while (i < n){
		j = i;
		while (j < n && a[j] == a[i])
			j++;
		se.insert(mp(i, j - 1));
		i = j;
	}
	scanf("%d", &q);
	while (q--){
		scanf("%d%d", &p, &c);
		p--;
		if (a[p] == c){
			printf("%d\n", (int)se.size());
			continue;
		}
		set<pair<int, int> > :: iterator it = se.lower_bound(mp(p, p));
		if ((it == se.end()) || ((*it) != mp(p, p)))
			it--;
		cur = *it;
		l = cur.first;
		r = cur.second;

		if (r == l){
			set<pair<int, int> > :: iterator it1 = it;
			it1--;
			if (it != se.begin() && a[(*it1).first] == c){
					set<pair<int, int> > :: iterator it2 = it;
					it2++;
					if (it2 != se.end() && a[(*it2).first] == c){
						cur.first = (*it1).first;
						cur.second = (*it2).second;
						se.erase(it2);
						se.erase(it);
						se.erase(it1);
						se.insert(cur);
					}
					else{
						cur.first = (*it1).first;
						cur.second = r;
						se.erase(it);
						se.erase(it1);
						se.insert(cur);
					
					}
				}
				else{
					set<pair<int, int> > :: iterator it2 = it;
					it2++;
					if (it2 != se.end() && a[(*it2).first] == c){
						cur.first = l;
						cur.second = (*it2).second;
						se.erase(it2);
						se.erase(it);
						se.insert(cur);
						
					}
					else{
						cur.first = r;
						cur.second = r;
						se.erase(it);
						se.insert(cur);
					}

				}
		}
		else{
			if (p != l && p != r){
				se.erase(it);
				se.insert(mp(l, p - 1));
				se.insert(mp(p, p));
				se.insert(mp(p + 1, r));
			}
			else{
				if (p == l){
					set<pair<int, int> > :: iterator it1 = it;
					it1--;
					if (it != se.begin() && a[(*it1).first] == c){
						cur.first = (*it1).first;
						cur.second = l;
						se.erase(it);
						se.erase(it1);
						se.insert(cur);
						se.insert(mp(l + 1, r));
					}
					else{
						se.erase(it);
						se.insert(mp(l, l));
						se.insert(mp(l + 1, r));
					}
				}
				else{
					set<pair<int, int> > :: iterator it2 = it;
					it2++;
					if (it2 != se.end() && a[(*it2).first] == c){
						cur.first =r;
						cur.second = (*it2).second;
						se.erase(it2);
						se.erase(it);
						se.insert(mp(l, r - 1));
						se.insert(cur);
					}
					else{
						se.erase(it);
						se.insert(mp(l, r - 1));
						se.insert(mp(r, r));
					}
				
				}
			}
		}
		a[p] = c;
		printf("%d\n", (int)se.size());
	}
	return 0;
}