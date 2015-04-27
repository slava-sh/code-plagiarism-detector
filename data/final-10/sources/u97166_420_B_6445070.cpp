#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
deque <int> s;
const int N = 100005;
int f[N];
int a[N], size, pre, p[N];
char b[2];
int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++) {
        scanf("%s%d", b, &x);
        if(b[0] == '+') {
            s.push_back(x);
            f[x] = 1;
        } else {
            s.push_back(-x);
            if(!f[x])
                s.push_front(x);
        }
    }
//  printf("    %d\n", s.size());
    memset(f, 0, sizeof f);
    while(s.size()) {
        x = s.front();
//      printf("    %d\n", x);
        s.pop_front();

/*      puts("*");
        printf("%d %d\n", pre, size);
        for(int i = 0; i < size; i ++) {
            printf("%d ", a[i]);
        } puts("");
        puts("*");
*/
        if(x > 0) {
            if(p[x] != 1 && (pre > 0 || size > 0)) {
                f[x] = 1;
//              printf("*%d\n", x);
            }
            pre ++;
            for(int i = 0 ;i < size; i ++) {
                if(a[i] == x) continue;
                f[ a[i] ] = 1;
//              printf("**%d\n", a[i]);
            }
            size = 0;
            p[x] = 1;
        } else {
            pre --;
            if(pre > 0) f[-x] = 1;
            a[size++] = -x;
            
        }
    }
    size = 0;
    for(int i = 1; i <= n; i ++) {
        if(!f[i]) a[size ++] = i;
    }
    printf("%d\n", size);
    for(int i = 0; i < size; i ++) {
        printf("%d%c", a[i], " \n"[i == size-1]);
    }puts("");
    return 0;
}
/*
int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i ++) {
        scanf("%s%d", b, &x);
        if(b[0] == '+') {
            a[size++] = x;
            p[x] = 1;
            pre ++;
        } else {
            if(i != m - 1 || pre > 0) {
                f[x] = 1;
            }
            pre --;
            if(p[x]) p[x] = 0;
            else {
                for(int i = 0; i < size; i ++) {
                    f[ a[i] ] = 1;
                    size = 0;
                }
            }
        }
    }
    size = 0;
    for(int i = 1; i <= n; i ++) {
        if(!f[i]) a[size ++] = i;
    }
    printf("%d\n", size);
    for(int i = 0; i < size; i ++) {
        printf("%d%c", a[i], " \n"[i == size-1]);
    }puts("");
    return 0;
}
*/