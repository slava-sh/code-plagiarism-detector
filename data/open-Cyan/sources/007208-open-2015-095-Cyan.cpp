#include <iostream>
#include <stdio.h>

using namespace std;

#define ll long long

ll x[409][409];
ll y[409][409];
int L[409];

bool Check(int i, int j)
{
    int p = 0;
    for (int t = 0; t < L[i]; t++) {
        while (p <= L[j] && x[j][p] < x[i][t]) p++;
        while (p <= L[j] && x[j][p] <= x[i][t+1]) {

            if ( (x[j][p]-x[i][t])*(y[i][t+1]-y[j][p]) < (y[j][p]-y[i][t])*(x[i][t+1]-x[j][p]) )
                return false;

            p++;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    int A, B; cin >> A >> B;
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> L[i];

        for (int j = 0; j <= L[i]; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            if (!Check(i, j) && !Check(j, i)) {
                printf("No\n");
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("Yes\n");
    return 0;
}
