#include <bits/stdc++.h>
 
using namespace std;
 
// TEMPLATE {{{
#ifndef LOCAL
#define OJ 1
#else
#define OJ 0
#endif
 
#define endl '\n'
#define TIMESTAMP merr << "Execution time: " << (double)clock()/CLOCKS_PER_SEC << " s.\n"
class C_ {}; template <typename T> C_& operator <<(C_& __m, const T& __s) { if (!OJ) cerr << "\E[91m" << __s << "\E[0m"; return __m; }
C_ merr;
 
struct __s { __s() { if (OJ) { ios_base::Init i; cin.sync_with_stdio(0); cin.tie(0); } } ~__s(){ TIMESTAMP; } } __S;
/// END OF TEMPLATE }}}

long long m, k;
long long A[111111];
long long B[111111];
long long C[111111];

string solve() {
  long long unknown = 0;
  bool was_one = false;
  vector<long long> SA(k, 0);
  vector<char> U(k,0);
  vector<int> last(k,-1);
  for (int i = 0; i < m-1; i++) {
    if (B[i] == 0) continue;
    last[B[i]-1] = i;
  }
  for (int i = 0; i < m-1; i++) {
    if (C[i] && !was_one) {
      was_one = 1;
      long long mn = 1000000000;
      for (int j = 0; j < k; j++) {
        if (A[j]-SA[j] <= unknown && last[j] < i) {
          mn = min(mn, A[j]-SA[j]);
          U[j] = 1;
        }
      }
      unknown -= mn;
    }
    if (B[i]) {
      SA[B[i]-1]++;
      U[B[i]-1] = false;
    } else {
      unknown++;
    }
  }
  string ans;
  for (int i = 0; i < k; i++) {
    if (A[i]-SA[i] <= unknown) U[i] = 1;
    if (U[i]) {
      ans += 'Y';
    } else {
      ans += 'N';
    }
  }
  return ans;
}

int main(void) {
  int T;
  cin >> T;
  for (int tt = 0; tt < T; tt++) {
    cin >> m >> k;
    for (int i = 0; i < k; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < m-1; i++) {
      cin >> B[i] >> C[i];
    }
    cout << solve() << endl;
  }
  return 0;
}
