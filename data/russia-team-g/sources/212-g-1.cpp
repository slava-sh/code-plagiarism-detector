#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n > m)
        swap(n, m);
    if (n == 1) {
        if (m > 2)
            printf("%d\n", (m - 3) / 4 + 1);
        else
            printf("0\n");
        return 0;
    }
   
    if (n == 2) {
        printf("0\n");
        return 0;
    }
    printf("1\n");
    return 0;
    
}