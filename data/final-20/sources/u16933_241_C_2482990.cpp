#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <cstring>


using namespace std;
typedef long long LL;
#define x1 x1_
#define y1 y1_
template<typename T>
inline T Abs(const T& value) { return value < 0 ? -value : value; }
template<typename T>
inline T Sqr(const T& value) { return value * value; }

const int maxn = 110;

LL hl, hr, n;
LL v[maxn], a[maxn], b[maxn], tp[maxn];
int w[maxn];

int Model(int last) {
	memset(w, 0, sizeof(w));
	int ans = 0;
	LL H;
	if (last > 0) {
		if (last % 2 == 1)
			H = 100 * last + 100 - hr;
		else
			H = 100 * last + hr;
		for (int i = 1; i <= last; ++i) {
			bool was = false;
			for (int j = 0; j < n; ++j)
				if (tp[j] == i%2 && (100*i-hl)*100000 >= a[j]*(H-hl) && (100*i-hl)*100000 <= b[j]*(H-hl)) {
					ans += v[j];
					w[j] += 1;
					was = true;
				}
			if (!was)
				return 0;
		}
	} else {
		if ((-last) % 2 == 1)
			H = 100 * last + 100 - hr;
		else
			H = 100 * last + hr;
		for (int i = -1; i >= last; --i) {
			bool was = false;
			for (int j = 0; j < n; ++j)
				if (tp[j] == (-i+1)%2 && (100*i-hl+100)*100000 <= a[j]*(H-hl) && (100*i-hl+100)*100000 >= b[j]*(H-hl)) {
					ans += v[j];
					w[j] += 1;
					was = true;
				}
			if (!was)
				return 0;
		}
		
	}
	for (int i = 0; i < n; ++i)
		if (w[i] > 1)
			return 0;
    return ans;
}

int main() {
//    freopen("input.txt", "r", stdin);


    cin >> hl >> hr >> n;
    for (int i = 0; i < n; ++i) {
    	char c;
    	cin >> v[i] >> c >> a[i] >> b[i];
    	if (c == 'F')
    		tp[i] = 0;
        else
            tp[i] = 1;
    }

    int mx = 0;
    for (int i = -n-1; i <= n+1; ++i) {
    	mx = max(mx, Model(i));	
    }

    cout << mx << endl;

    return 0;
}
