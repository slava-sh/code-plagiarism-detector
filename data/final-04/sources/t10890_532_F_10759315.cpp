#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2 * 100000 + 100;
const int MAXC = 26;

int n, m;
char s[MAXN], t[MAXN];

class Hash {
 public:
  int len;
  int MOD;
  vector<int> pow;

  vector<vector<int> > hash;
 public:
  Hash(int len, char* ss, int MOD, bool verbose=false, int BASE=239): len(len), MOD(MOD) {
    pow.resize(MAXN);
    pow[0] = 1;
    long long z = 1;
    for (int i = 1; i < (int)(pow.size()); ++i) {
      z = (z * BASE) % MOD;
      pow[i] = z;
    }
    hash.resize(len + 1);
    for (int i = 0; i < (int)(hash.size()); ++i) {
      hash[i].resize(MAXC);
      hash[i][0] = 0;
    }
    for (int i = 0; i < len; ++i) {
      for (int c = 0; c < MAXC; ++c) {
        hash[i + 1][c] = hash[i][c];
        if (ss[i] == 'a' + c) {
          hash[i + 1][c] += pow[i];
          if (hash[i + 1][c] >= MOD) hash[i + 1][c] -= MOD;
        }
      }
    }
  }

  int get(int from, int to, int c) const {
    long long ans = hash[to][c];
//    cerr << ans << endl;
    if (from >= 0) ans -= hash[from][c];
    if (ans < 0) ans += MOD;
    ans = (ans * pow[len - from]) % MOD;
    if (ans < 0) ans += MOD;
//    cerr << "from " << from << " to " << to << " - " << ans << endl;
    return ans;
  }
};

bool check(int c1, int c2, int pos, const Hash& h_s1, const Hash& h_s2, const Hash& h_t1, const Hash& h_t2) {
  long long h1s = h_s1.get(pos, pos + m, c1);
  long long h1t = h_t1.get(0, m, c2);
  h1t = (h1t * h_t1.pow[n - m]) % h_t1.MOD;
  if (h1t < 0) h1t += h_t1.MOD;
//  cerr << "pos= " << pos << "; c1=" << c1 << "; c2=" << c2 << ". H1 = " << h1s << ", H2 = " << h1t << endl;
  if (h1s != h1t) return false;
  long long h2s = h_s2.get(pos, pos + m, c1);
  long long h2t = h_t2.get(0, m, c2);
  h2t = (h2t * h_t2.pow[n - m]) % h_t2.MOD;
  if (h2t < 0) h2t += h_t2.MOD;
  if (h2s != h2t) return false;
  return true;
}


int main() {
  scanf("%d%d%s%s", &n, &m, s, t);
  Hash h_s1(n, s, 1000 * 1000 * 1000 + 7);
  Hash h_s2(n, s, 1000 * 1000 * 1000 + 9);
  Hash h_t1(m, t, 1000 * 1000 * 1000 + 7);
  Hash h_t2(m, t, 1000 * 1000 * 1000 + 9);
  int first[MAXC];
  for (int c = 0; c < MAXC; ++c) first[c] = -1;
  for (int i = m - 1; i >= 0; --i) first[t[i] - 'a'] = i;
  vector<int> ans;
  for (int pos = 0; pos < n - m + 1; ++pos) {
    bool ok[MAXC];
    for (int c = 0; c < MAXC; ++c) ok[c] = false;
    for (int c = 0; c < MAXC; ++c) if (!ok[c]) {
      if (first[c] == -1) {
         ok[c] = true;
         continue;
      }
      int c1 = c;
      int c2 = s[pos + first[c]] - 'a';
      if (!check(c1, c2, pos, h_s1, h_s2, h_t1, h_t2)) {
        ok[c1] = ok[c2] = false;
        break;
      }
      if (c1 != c2 && !check(c2, c1, pos, h_s1, h_s2, h_t1, h_t2)) {
        ok[c1] = ok[c2] = false;
        break;
      }
      ok[c1] = ok[c2] = true;
    }
    bool y = true;
    for (int c = 0; c < MAXC; ++c) if (!ok[c]) {y = false; break; }
    if (y) ans.push_back(pos);
  }

  printf("%d\n", (int)(ans.size()));
  for (int i = 0; i < (int)(ans.size()); ++i) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  return 0;
}

