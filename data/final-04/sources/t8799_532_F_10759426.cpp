#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <memory.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (n); ++i)
#define forv(i, a) forn(i, (int)(a).size())

typedef long long lng;

const int maxn = 4*100*1000 + 500;
char s[maxn];
int n;
int text_len, pattern_len;
char text[maxn], pattern[maxn];
bool res[maxn];
char cur[26][maxn];
int pi[maxn];

void calc_prefix_function() {
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
}


void solve() {
    n = pattern_len + text_len + 1;

    s[pattern_len] = '#';

    forn(i, text_len) {
        res[i] = true;
    }
    memset(cur, 0, sizeof(cur));

    for(char ch = 'a'; ch <= 'z'; ++ch) {

        forn(i, text_len) {
            s[pattern_len + 1 + i] = (text[i] == ch) ? 'a' : 'b';
        }

        for(char match = 'a'; match <= 'z'; ++match) {
            forn(i, pattern_len) {
                s[i] = (pattern[i] == match) ? 'a' : 'b';
            }

            calc_prefix_function();

            for(int i = pattern_len + 1; i < n; ++i) {
                if(pi[i] == pattern_len) {
                    int pos = i - 2 * pattern_len;
                    if(cur[ch - 'a'][pos] == 0) {
                        cur[ch - 'a'][pos] = match;
                    }
                    else {
                        cur[ch - 'a'][pos] = -1;
                    }
                }
            }
        }
    }

    for(char ch = 'a'; ch <= 'z'; ++ch) {
        forn(i, text_len) {
            if(cur[ch - 'a'][i] != -1) {
                if(cur[ch - 'a'][i] == 0) {
                    res[i] &= 0;
                    continue;
                }

                char p = cur[ch - 'a'][i];
                if(!(cur[p - 'a'][i] == -1 || cur[p - 'a'][i] == ch)) {
                    res[i] &= 0;
                }
            }
        }
    }
}

void print_result() {
    vector<int> ans;

    forn(i, text_len) {
        if(res[i]) {
            ans.push_back(i + 1);
        }
    }

    cout << ans.size() << endl;
    for(int m : ans) {
        cout << m << " ";
    }
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    cin >> text_len >> pattern_len;
    cin >> text >> pattern;

    solve();
    print_result();
    
    return 0;
}
