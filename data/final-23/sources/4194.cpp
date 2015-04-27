#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <memory.h>
#include <limits>
#include <time.h>

using namespace std;

#define vv vector
#define pb push_back
#define mp make_pair
#define px first
#define py second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define abs(x) ((x)<0?-(x):(x))
#define sqr(x) ((x)*(x))
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define fore(i,a,b) for(int i = (a); i <= (b); ++i)
#define in cin
#define out cout
#pragma warning(disable: 4996)

const int inf = numeric_limits<int>::max();

vv< vv<int> > g, gr;
vv<bool> used;
vv<int> order, comp;

class RSQ {
public:
    
    int sum(int l, int r) {
        l += T.size() / 2;
        r += T.size() / 2;
        int ans = 0;
        while (l <= r) {
            if (l % 2 == 1)
                ans += T[l++];
            if (r % 2 == 0)
                ans += T[r--];
			l /= 2;
			r /= 2;
        }
        return ans;
    }

    void set(int i, int k) {
        i += T.size() / 2;
        T[i] = k;
        upd(i / 2);
    }

    void upd(int v) {
        for (v; v > 0; v /= 2)
            T[v] = T[2 * v] + T[2 * v + 1];
    }
    
    RSQ(int n) {
        int len = 1; 
        while (len < n)
            len *= 2;
        T.resize(len * 2);
    }


    vv<int> T;
};


int main() {
	freopen("signchange.in", "rt", stdin);
	freopen("signchange.out", "wt", stdout);

	int n; in >> n;
	RSQ T1(n + 10), T2(n + 10);

	fr(i, 0, n) {
		int x;
		in >> x;
		if (i % 2 == 0)
			T1.set(i, x);
		else
			T2.set(i, x);
	}

	int m; in >> m;
	fr(i, 0, m) {
		int t, x, y;
		in >> t >> x >> y;
		if (t) {
			x--, y--;
			if (x % 2 == 0)
				out << T1.sum(x, y) - T2.sum(x, y) << endl;
			else
				out << T2.sum(x, y) - T1.sum(x, y) << endl;
		} else {
			x--;
			if (x % 2 == 0)
				T1.set(x, y);
			else
				T2.set(x, y);
		}
	}

	return 0;
}

