#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <random>
#include <string>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

mt19937_64 mt;

struct treenode{
	int val, ltype, rtype;
};

const int MAXSIZE = 1<<17;
int N, Q;

treenode tree[MAXSIZE<<1];

inline void upv(int pos){
	int l = pos<<1;
	int r = l+1;
	if(tree[r].val > 0 && tree[l].val > 0){
		tree[pos].ltype = tree[l].ltype;
		tree[pos].rtype = tree[r].rtype;
		tree[pos].val = tree[l].val + tree[r].val -
			int(tree[l].rtype == tree[r].ltype);
	} else {
		if(tree[l].val){
			tree[pos] = tree[l];
		} else {
			tree[pos] = tree[r];
		}
	}
}


void build(){
	cin >> N;
	int t;
	for(int i = MAXSIZE; i < MAXSIZE + N; i++){
		tree[i].val = 1;
		scanf("%d", &t);
		tree[i].ltype = tree[i].rtype = t;
	}
	for(int i = MAXSIZE - 1; i > 0; i--){
		upv(i);
	}
}

void update(int pos, int ntype){
	int cp = pos + MAXSIZE - 1;
	tree[cp].ltype = tree[cp].rtype = ntype;
	cp >>= 1;
	while(cp){
		upv(cp);
		cp >>= 1;
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	build();
	cin >> Q;
	int p, t;
	for(int i = 0; i < Q; i++){
		scanf("%d%d", &p, &t);
		update(p, t);
		cout << tree[1].val << "\n";
	}
	return 0;
}