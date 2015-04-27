#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 222222;
bool v[N];
int id[N];
char op[N];
int main() {
    int n, m;
    cin >> n >> m;
    char s[10];
    int man = 0;
    for(int i = 1; i <= m; i++) {
        cin >> s >> id[i];
        op[i] = s[0];
        if(!v[id[i]]) {
            v[id[i]] = true;
            if(s[0] == '-') {
                man++;
            } 
        }
    }
    memset(v, false, sizeof(v));
    for(int i = 1; i <= m; i++) {
        if(op[i] == '-') {
            man--;
            if(man > 0) {
                v[id[i]] = true;
            } else if(i < m && id[i] != id[i + 1]) {
                v[id[i]] = true;
            }
        } else {
            if(man > 0) {
                v[id[i]] = true;
            } else if(i > 1 && id[i] != id[i - 1]) {
                v[id[i]] = 1;
            }
            man++;
        }
    }
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        if(!v[i]) {
            ret++;
        }
    }
    printf("%d\n",ret);
    for(int i = 1; i <= n; i++) {
        if(!v[i]) {
            printf("%d ",i);
        }
    }
    if(ret > 0) puts("");
    return 0;
}
