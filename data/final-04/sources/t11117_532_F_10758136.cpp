#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

#define endl '\n'

const int MAXN = 200005;

int sn, tn;
char s[MAXN];
char t[MAXN];
char f[2*MAXN];

bool go[MAXN][26][26];
int pi[2*MAXN];

int ans[MAXN];

bool thas[26];
int to[26];

void solve() {
    for(int i = 0; i < sn; i++) {
        s[i] -= 'a';
    }
    memset(thas,0,sizeof(thas));
    for(int i = 0; i < tn; i++) {
        t[i] -= 'a';
        thas[(int)t[i]] = true;
    }

    int len = tn+sn+1;
    memset(go,0,sizeof(go));
    for(int s1 = 0; s1 < 26; s1++) {
        for(int s2 = 0; s2 < 26; s2++) {
            bool is = false;
            for(int i = 0; i < tn; i++) {
                if(t[i]==s1) {
                    f[i] = s2;
                    is = true;
                } else {
                    f[i] = '*';
                }
            }
            if(!is) {
                continue;
            }
            f[tn] = '#';
            for(int i = 0; i < sn; i++) {
                if(s[i]==s2) {
                    f[tn+1+i] = s[i];
                } else {
                    f[tn+1+i] = '*';
                }
            }
//          for(int i = 0; i < len; i++) {
//              if(f[i]<26) {
//                  cout << char(f[i]+'a');
//              } else {
//                  cout << f[i];
//              }
//          }
//          cout << endl;
            for(int i = 1; i < len; i++) {
                int j = pi[i-1];
                while(j > 0 && f[i] != f[j]) {
                    j = pi[j-1];
                }
                if(f[i] == f[j]) {
                    j++;
                }
                pi[i] = j;
                if(i>=2*tn) {
                    go[i-2*tn][s1][s2] = (pi[i]==tn);
                }
            }
        }
    }

//  for(int i = 0; i < sn; i++) {
//  for(int s1 = 0; s1 < 26; s1++) {
//      for(int s2 = 0; s2 < 26; s2++) {
//              if(s1!=s2 && go[i][s1][s2]) {
//                  cout << i << ' ' << char(s1+'a') << ' ' << char(s2+'a') << endl;
//              }
//              }
//  }
//  }

    int cnt = 0;
    for(int i = 0; i < sn; i++) {
        ans[i] = 1;
        memset(to,-1,sizeof(to));
        for(int s1 = 0; s1 < 26; s1++) {
            if(thas[s1]) {
                for(int s2 = 0; s2 < 26; s2++) {
                    if(go[i][s1][s2]) {
                        to[s1] = s2;
                    }
                }
                if(to[s1] == -1) {
                    ans[i] = false;
                    break;
                }
            }
        }
        for(int s1 = 0; s1 < 26; s1++) {
            int s2 = to[s1];
            if(s2!=-1 && to[s2]!=-1 && to[s2]!=s1) {
                ans[i] = false;
                break;
            }
        }
        cnt += ans[i];
    }
    printf("%d\n", cnt);
    for(int i = 0; i < sn; i++) {
        if(ans[i]) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}

int main() {
//  freopen("input.in", "r", stdin);
//  freopen("output.out", "w", stdout);
    while(scanf("%d %d", &sn, &tn)==2) {
        scanf("%s", s);
        scanf("%s", t);
        solve();
    }
}
