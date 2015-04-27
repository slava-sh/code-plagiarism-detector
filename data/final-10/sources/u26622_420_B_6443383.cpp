#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int N = 1e5 + 9;
set<int> in, out, ans, maybe;
char s[N][11];
int ids[N];
int tag[N];
int main() {
    int n, m, id, i;

    while(scanf("%d%d", &n, &m) != EOF) {
        memset(tag, 0, sizeof(tag));
        ans.clear();
        maybe.clear();
        in.clear();

        for(i = 0; i < m; ++i) {
            scanf("%s%d", s[i], ids + i);

            if(!tag[ids[i]]) {
                tag[ids[i]] = (s[i][0] == '+') ? 1 : -1;
            }
        }

        for(i = 1; i <= n; ++i) {
            if(!tag[i]) {
                ans.insert(i);
            } else if(tag[i] == -1) {
                in.insert(i);
            } else {
                out.insert(i);
            }
        }

        if(in.size() == 0) {
            for(i = 1; i <= n; ++i) {
                if(tag[i]) {
                    out.insert(i);
                    maybe.insert(i);
                }
            }
        } else {
            for(i = 1; i <= n; ++i) {
                if(tag[i] == -1) {
                    maybe.insert(i);
                } else if(tag[i] == 1) {
                    out.insert(i);
                }
            }
        }

        for(i = 0; i < m; ++i) {
            id = ids[i];

            if(s[i][0] == '+') {
                if(in.size()) {
                    maybe.erase(id);
                }

                in.insert(id);
                out.erase(id);
            } else {
                if(in.size() > 1) {
                    maybe.erase(id);
                }

                in.erase(id);
                out.insert(id);
            }

            if(in.size() > 0) {
                for(set<int>::iterator it = out.begin(); it != out.end();) {
                    set<int>::iterator tmp = it;
                    ++tmp;
                    maybe.erase(*it);
                    out.erase(*it);
                    it = tmp;
                }
            }
        }

        ans.insert(maybe.begin(), maybe.end());
        printf("%u\n", ans.size());
        bool f = false;

        for(set<int>::iterator sit = ans.begin(); sit != ans.end(); ++sit) {
            if(f) {
                printf(" ");
            }

            printf("%d", *sit);
            f = true;
        }

        if(f) {
            puts("");
        }
    }

    return 0;
}
