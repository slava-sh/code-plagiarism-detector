#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int *a = new int[n], **dp_up = new int*[n], **dp_down = new int*[n];
    for(int i = 0; i < n; i++) {
        dp_up[i] = new int[n];
        dp_down[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) {
        dp_up[i][i] = dp_down[i][i] = 0;
        for(int j = i+1; j < n; j++) {
            if(a[i] < a[j])dp_up[i][j] = dp_up[i][j-1] - 1;
            else dp_up[i][j] = dp_up[i][j-1] + 1;
        }
        for(int j = i-1; j >=0; j--) {
            if(a[i] < a[j])dp_down[i][j] = dp_down[i][j+1] + 1;
            else dp_down[i][j] = dp_down[i][j+1] - 1;
        }
    }
    int x = -2, y = -2, ans = -100000000;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) continue;
            if(x == -2 || dp_up[j][i] + dp_down[i][j] > ans) {
                x = j;
                y = i;
                ans = dp_up[j][i] + dp_down[i][j];
            }
        }
    }
    printf("%d %d\n", x+1, y+1);
}
