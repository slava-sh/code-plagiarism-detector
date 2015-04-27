#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>

#define mp make_pair
#define pb push_back

#define file "f"

using namespace std;

const int N = (int)(2e5) + 100;
const int p = 239, p2 = 239017;
const int mod = 1000000009, mod2 = 1000000007;

typedef long long ll;
typedef long double ld;

ll poly[26], poly2[26];
int n, m;
char s[N], t[N];
int pos[26];
ll st[N], st2[N];
char pairr[26];
vector<int> ans;

int main()
{
  //freopen(file".in", "r", stdin);
  //freopen(file".out", "w", stdout);

  scanf("%d%d\n", &n, &m);
  scanf("%s", s);
  scanf("%s", t);

  for (int i = 0; i < 26; i++)
  	pos[i] = -1;
  for (int i = 0; i < m; i++)
  {
    if (pos[t[i] - 'a'] == -1)
      pos[t[i] - 'a'] = i;
  }

  st[0] = 1;
  st2[0] = 1;
  for (int i = 1; i <= m; i++)
  {
  	st[i] = (st[i - 1] * p) % mod;
    st2[i] = (st2[i - 1] * p2) % mod2;
  }

  ll hash = 0, hash2 = 0;

  for (int i = 0; i < m; i++)
  {
    poly[t[i] - 'a'] += st[m - i - 1];
    poly[t[i] - 'a'] %= mod;

    poly2[t[i] - 'a'] += st2[m - i - 1];
    poly2[t[i] - 'a'] %= mod2;
  }
  
  ll h = 0;
  ll h2 = 0;
  for (int i = 0; i < m; i++)
  {
    h *= p;
    h += s[i];
    h %= mod;

    h2 *= p2;
    h2 += s[i];
    h2 %= mod2;
  }

  for (int id = 0; id < n - m + 1; id++)
  {
    for (int i = 0; i < 26; i++)
      pairr[i] = 'a' - 1;

    bool ok = true;
    for (int i = 0; i < 26; i++)
    {
      if (pos[i] == -1)
      	continue;
      if (pairr[i] != 'a' - 1 && pairr[i] != s[id + pos[i]])
      	ok = false;
      pairr[i] = s[id + pos[i]];
      if (pairr[s[id + pos[i]] - 'a'] != 'a' - 1 && pairr[s[id + pos[i]] - 'a'] != i + 'a')
      	ok = false;
      pairr[s[id + pos[i]] - 'a'] = i + 'a';
    }

    hash = 0;
    hash2 = 0;
    for (int i = 0; i < 26; i++)
    {
      hash += pairr[i] * poly[i];
      hash %= mod;

      hash2 += pairr[i] * poly2[i];
      hash2 %= mod2;
    }

    if (hash == h && hash2 == h2 && ok)
      ans.pb(id + 1);
    h -= s[id] * st[m - 1];
    h += (ll)mod * mod;
    h %= mod;
    h *= p;
    h += s[id + m];
    h %= mod;

    h2 -= s[id] * st2[m - 1];
    h2 += (ll)mod2 * mod2;
    h2 %= mod2;
    h2 *= p2;
    h2 += s[id + m];
    h2 %= mod2;
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++)
  	printf("%d ", ans[i]);


  return 0;
}