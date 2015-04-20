#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back

const int MAXN = 1e5;

int n, d;
vector < int > mas;


vector < int > ht;

bool comp(int a, int b) {
    return a > b;
}


int main() {

    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);

    int ans = 0;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        mas.pb(x);
    }                     
    sort(mas.begin(), mas.end(), comp);

    int col = 0;
    int t = 0;
    int sum = 0;
    for (int i = 0; i < n && t < 2; i++) {
        if (mas[i] < 2 * d) {
            if (i == 0) {
                printf("%d\n", mas[i]);
                return 0;
            }
            break;
        }
        if (mas[i] > d && mas[i] < 3 * d) {
            t++;
            col++;
            sum += mas[i];
        }
        if (mas[i] >= 3 * d) {
            col++;
            sum += mas[i];
        }    
       
    }

    printf("%d\n", sum - (col - 1) * 2 * d);

    return 0;
}