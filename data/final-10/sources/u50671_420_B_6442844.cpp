#include <bits/stdc++.h>
using namespace std;

const int N = int(1e6), HERE = 1, LEFT = 2;

set<int> here, lefts, ever;
int S[N], n, m, no[N];
vector<int> ans;

int main ()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
	{
		char op[20]; int x;
		scanf("%s%d", op, &x);
		if (op[0] == '+')
		{
			if (lefts.count(x)) lefts.erase(x);
			if (here.size()) no[x] = 1;
			if (!S[x] && i != 1) no[x] = 1;
			for (int y : lefts) no[y] = 1;
			lefts.clear();
			here.insert(x);
			ever.insert(x);
			S[x] = HERE;
		}
		else
		{
			if (here.count(x)) here.erase(x);
			if (here.size()) no[x] = 1;
			if (!S[x])
			{
				for (int y : ever) no[y] = 1;
				ever.clear();
				for (int y : lefts) no[y] = 1;
				lefts.clear();
			}
			S[x] = LEFT;
			lefts.insert(x);
		}
	}
	for (int i = 1; i <= n; ++i) if (!no[i]) ans.push_back(i);
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); ++i)
		printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
	return 0;
}

