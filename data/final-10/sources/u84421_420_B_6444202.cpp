#include <stdio.h>

bool wasPlus[100001];

struct sQuery {
    char c;
    int id;
};

sQuery input[100000];

bool cantBe[100001];

bool fromBeg[100001];

int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);

    int cntInside = 0;

    for (int i = 0; i < m; i++) {
        scanf("%c %d\n", &input[i].c, &input[i].id);

        if (input[i].c == '-' && !wasPlus[input[i].id]) {
            cntInside++;
            fromBeg[input[i].id] = true;
        }
        else if (input[i].c == '+')
            wasPlus[input[i].id] = true;
    }

    for (int i = 0; i < m; i++) {
        if (i == 0 && input[i].c == '+')
            fromBeg[input[i].id] = true;

        if (input[i].c == '+') {
            if (cntInside > 0 || !fromBeg[ input[i].id ]) {
                cantBe[ input[i].id ] = true;
            }

            cntInside++;
        }
        else {
            if (cntInside >= 2 || (i < m-1 && (input[i+1].id != input[i].id || input[i+1].c != '+'))) {
                cantBe[ input[i].id ] = true;
            }
            cntInside--;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) if (!cantBe[i]) ans++;
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) if (!cantBe[i]) printf("%d ", i);
}
