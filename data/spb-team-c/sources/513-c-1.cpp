#include <cstdio>
#include <algorithm>

using namespace std;

int globalA;
int resC = 100000001;
int n;

typedef struct tagTOWN
{
    int a, c;
} TOWN;

typedef struct tagVERTEX
{
    int a, c;
} VERTEX;

TOWN towns[1000];

void dfs(VERTEX *v)
{
    int i, bufta;
    VERTEX nextv;
    if (v->a == globalA)
        resC = min(resC, v->c);
    else
    {
        for (i = 0; i < n; i++)
            if (v->a > towns[i].a && towns[i].a > 0)
            {
                nextv.a = v->a + towns[i].a;
                nextv.c = v->c;
                bufta = towns[i].a;
                towns[i].a = 0;
                dfs(&nextv);
                towns[i].a = bufta;
            }
            else if (towns[i].a > 0)
            {
                nextv.a = v->a + 1;
                nextv.c = v->c + towns[i].c;
                bufta = towns[i].a;
                towns[i].a--;
                dfs(&nextv);
                towns[i].a = bufta;
            }
    }

}

int main(void)
{
    FILE *file_in, *file_out;
    int a, c, i;

    VERTEX v;

    v.a = 0;
    v.c = 0;

    file_in = fopen("conquest.in", "rt");
	file_out = fopen("conquest.out", "wt");

    fscanf(file_in, "%d", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(file_in, "%d%d", &a, &c);
        towns[i].a = a;
        towns[i].c = c;
        globalA += a;
    }

    dfs(&v);

    fprintf(file_out, "%d", resC);

    fclose(file_in);
    fclose(file_out);
    return 0;
}
