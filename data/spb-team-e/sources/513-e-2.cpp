#include <cstdio>
#include <algorithm>

using namespace std;

#define ololo

static bool mas[1000000001];

int main(void)
{
	FILE *file_in, *file_out;
	int n, m, l1, r1, l2, r2, l, r, i, num, pl, res, arr[4], flag;
    file_in = fopen("game.in", "rt");
	file_out = fopen("game.out", "wt");

	fscanf(file_in, "%d%d", &n, &m);
	fscanf(file_in, "%d%d", &l1, &r1);
	fscanf(file_in, "%d%d", &l2, &r2);

    for (i = 0; i < n; i++)
    {
        fscanf(file_in, "%d", &num);
        mas[num] = 1;
    }

    l = max(l1, l2);
    r = min(r1, r2);
    pl = 0;
    res = 0;

    for (i = l; i <= r && m > 0; i++)
    {
        if (mas[i])
        {
            res += 1 - pl * 2;
            pl = 1 - pl;
            m--;
        }
    }

    arr[0] = l1;
    arr[1] = l2;
    arr[2] = r1;
    arr[3] = r2;
    while (m > 0 && ((arr[0] < l || arr[1] < l) || (arr[2] > r || arr[3] > r)))
    {
        flag = 0;

        while (!mas[arr[pl]] && arr[pl] < l)
            arr[pl]++;
        while (!mas[arr[pl + 2]] && arr[pl] > r)
            arr[pl + 2]--;


        if (m > 0 && arr[pl] < l)
          res += 1 - pl * 2, arr[pl]++, m--, pl = 1 - pl, flag = 1;


        while (!mas[arr[pl]] && arr[pl] < l)
            arr[pl]++;
        while (!mas[arr[pl + 2]] && arr[pl] > r)
            arr[pl + 2]--;


        if (m > 0 && arr[pl + 2] > r && m > 0)
          res += 1 - pl * 2, arr[pl + 2]--, m--, pl = 1 - pl, flag = 1;

        if (!flag)
            pl = 1 - pl;
    }
    if (res > 0)
        fprintf(file_out, "Petya\n");
    else if (res == 0)
        fprintf(file_out, "Draw\n");
    else
        fprintf(file_out, "Vasya\n");

    return 0;
}
