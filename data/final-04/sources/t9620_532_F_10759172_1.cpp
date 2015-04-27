#include <bits/stdc++.h>

using namespace std;

const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int P = 1232133;

const int maxn = 200010;

struct Huge {
    Huge():x(0),y(y) {}
	int x, y;
	//Huge(int x):x(x), y(x) {}
	Huge operator+(const Huge& o) const {
		Huge res(x + o.x, y + o.y);
		if (res.x >= mod1) res.x -= mod1;
		if (res.y >= mod2) res.y -= mod2;
		return res;
	}
    Huge(int x, int y):x(x),y(y) {}

    bool operator==(const Huge& o) const {
		return x == o.x && y == o.y;
	}


	bool operator<(const Huge& o) const {
		if (x == o.x) return y < o.y;
		return x < o.x;
	}
	Huge operator*(const Huge& o) const {
		return Huge(x * (long long)o.x % mod1, y * (long long)o.y % mod2);
	}
    Huge operator-(const Huge& o) const {
		Huge res(x - o.x, y - o.y);
		if (res.x < 0) res.x += mod1;
		if (res.y < 0) res.y += mod2;
		return res;
	}
};


int spos[30];

int tmp[30];
int nxt[maxn];
Huge sh[30];
int tpos[30];
Huge th[30];
Huge p[maxn];


int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	p[0] = Huge(1,1);
	for (int i = 1; i < maxn; ++i) p[i] = p[i-1] * Huge(P, P);

	int Slen, Tlen; scanf("%d%d", &Slen, &Tlen);
	string s, t; cin >> s >> t;
	memset(tpos, -1, sizeof(tpos));
	for(int i = int(t.size())-1; i >= 0; --i) tpos[t[i]-'a'] = i;
	for(int i = 0; i < int(t.size()); i++) {
        th[t[i]-'a'] = th[t[i]-'a'] + p[int(t.size())-1-i];
    }
	vector<pair<int, Huge> > tv;
	for(int i = 0; i < 26; i++) {
        if (tpos[i] != -1) {
            tv.push_back(make_pair(tpos[i], th[i]));
        }
    }
	sort(tv.begin(), tv.end());

	int n = int(s.size());
	for(int i = 0; i < 26; i++) tmp[i] = n;
	for (int i = n-1; i >= 0; --i)
		nxt[i] = tmp[s[i]-'a'], tmp[s[i]-'a'] = i;

	vector<int> ans;
	memset(spos, -1, sizeof(spos));
	for (int i = int(t.size())-1; i >= 0; --i) 
    {
        spos[s[i]-'a'] = i;
    }

	for(int i = 0; i < int(t.size()); i++) {
        sh[s[i]-'a'] = sh[s[i]-'a'] + p[int(t.size())-1-i];
    }

	for(int l = 0; l + int(t.size()) <= n; ++l) {
		vector<pair<int, Huge> > vs;
		bool ok = true;
		for(int i = 0; i < 26; i++) if (spos[i] != -1 && tpos[i] != -1
                    && spos[i] - l != tpos[i]) {
			if (!(t[spos[i]-l] == s[l+tpos[i]])) {
				ok = false;
				break;
			}
		}
		if (ok) {
			for(int i = 0; i < 26; i++)
                if (spos[i] != -1)
                    vs.push_back(make_pair(spos[i]-l, sh[i]));
			sort(vs.begin(), vs.end());
			if (vs == tv) ans.push_back(l);
		}
		for(int i = 0; i < 26; i++) sh[i] = sh[i] * p[1];
		int j = l + int(t.size());
		if (j >= n) break;
		sh[s[j]-'a'] = sh[s[j]-'a'] + p[0];
		sh[s[l]-'a'] = sh[s[l]-'a'] - p[int(t.size())];
		spos[s[l]-'a'] = -1;
		if (nxt[l] <= j) spos[s[l]-'a'] = nxt[l];
		if (spos[s[j]-'a'] == -1) spos[s[j]-'a'] = j;
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]+1);
	return 0;
}