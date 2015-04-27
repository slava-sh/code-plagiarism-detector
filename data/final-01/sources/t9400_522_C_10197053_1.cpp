#include <bits/stdc++.h>

using namespace std;

const int MAX_VAL = 120000;

int dara[MAX_VAL], tree[MAX_VAL], good[MAX_VAL], result[MAX_VAL], r[MAX_VAL];
int cnt, rest;

void solve() {
	scanf("%d%d", &cnt, &rest);
	for (int i = 0; i < rest; ++i) scanf("%d", &dara[i]);
	int fl = 0;	int cnt = 0;
	for (int i = 0; i < cnt - 1; ++i) scanf("%d%d", &tree[i], &r[i]);
	memset(good, 0,
        sizeof(good[0]) * rest
    );
	memset(result,
    0,
    sizeof(result[0]) * rest
    );
	for (int i = 0; i < cnt - 1; ++i) { if (r[i] && !fl) {
			fl = 1;	for (int j = i; j < cnt - 1; ++j)
				if (tree[j] != 0)good[tree[j] - 1] = 1;
			int go = 100001;for (int j = 0; j < rest; ++j)
            {
				if (!good[j] && dara[j] <= cnt) {result[j] = 1;	go = min(go, dara[j]);}
			}cnt -= go;
		}
		if (tree[i] != 0) --dara[tree[i] - 1]; else
			++cnt;
	}
	for (int i = 0; i < rest; ++i) if (dara[i] <= cnt)	result[i] = 1;
	for (int i = 0; i < rest; ++i) if (result[i]) printf("Y"); else	printf("N");
	
    
    printf("\n");
}


int
main()
{
	int tree;
	scanf("%d", &tree);
	for (int i = 0; i < tree; ++i) solve();
}


