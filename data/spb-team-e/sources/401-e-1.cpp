#include <bits\stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back

void solve(int n)
{
    int m;
    cin >> m;

    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    // P, V

    vector<int> lens(n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &lens[i]);

    int Petya = 0;
    int Vasya = 0;
    int both = 0;

    for (int i = 0; i < n; i++)
    {
        bool canP = (lens[i] >= l1 && lens[i] <= r1);
        bool canV = (lens[i] >= l2 && lens[i] <= r2);

        if (canP && canV)
            both++;
        if (canV && !canP)
            Vasya++;
        if (canP && !canV)
            Petya++;
    }

    int ansP = 0;
    int ansV = 0;

    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            if (both > 0)
                both--, ansP++;
            else if (Petya > 0)
                Petya--, ansP++;
        }
        else
        {
            if (both > 0)
                both--, ansV++;
            else if (Vasya > 0)
                Vasya--, ansV++;
        }
    }

    if (ansP > ansV)
        printf("Petya\n");
    else if (ansP == ansV)
        printf("Draw\n");
    else
        printf("Vasya\n");

}

int main()
{
   // freopen("input.txt", "rt", stdin);
   // freopen("output.txt", "w", stdout);
    freopen("game.in", "rt", stdin);
    freopen("game.out", "w", stdout);

    int n;
    while (cin >> n)
        solve(n);
}
