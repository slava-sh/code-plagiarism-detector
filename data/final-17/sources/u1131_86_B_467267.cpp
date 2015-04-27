#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

char mm[1001][1001];
int n, m;

int num[1000000];
int col[1000000];
vector <int> con[1000000];
int nid;
int id[1001][1001];

void assign_col()
{

    int i, j;
    for (i=0; i<n; i++) for (j=0; j<m; j++) if (mm[i][j] == '.')
    {
        if (i < n-1 && mm[i+1][j] == '.' && id[i][j] != id[i+1][j])
        {
            con[ id[i][j] ].push_back( id[i+1][j] );
            con[ id[i+1][j] ].push_back( id[i][j] );
        }

        if (j < m-1 && mm[i][j+1] == '.' && id[i][j] != id[i][j+1])
        {
            con[ id[i][j] ].push_back( id[i][j+1] );
            con[ id[i][j+1] ].push_back( id[i][j] );
        }
    }

    memset(col, -1, sizeof(col));
    bool valid[10];
    int a;
    for (i=0; i<nid; i++)
    {
        memset(valid, 1, sizeof(valid));
        for (j=0; j<con[i].size(); j++)
        {
            a = con[i][j];
            if (col[a] != -1) valid[col[a]] = false;
        }
        for (j=0; j<10; j++) if (valid[j]) break;
        col[i] = j;
    }

    return;
}

int main()
{
    //freopen("B.in", "r", stdin);

    scanf("%d %d", &n, &m);
    int i, j;
    for (i=0; i<n; i++) scanf("%s", mm[i]);

    memset(id, -1, sizeof(id));
    memset(num, 0, sizeof(num));

    for (i=0; i<n; i++) for (j=0; j<m; j++) if (mm[i][j] == '.' && id[i][j] == -1)
    {
        // can put
        if (j < m-1 && mm[i][j+1] == '.' && id[i][j+1] == -1)
        {
            id[i][j] = id[i][j+1] = nid;
            num[nid] = 2;
            nid++;
            continue;
        }

        if (i < n-1 && mm[i+1][j] == '.' && id[i+1][j] == -1)
        {
            id[i][j] = id[i+1][j] = nid;
            num[nid] = 2;
            nid++;
            continue;
        }

        if (i > 0 && mm[i-1][j] == '.' && num[ id[i-1][j] ] < 5)
        {
            id[i][j] = id[i-1][j];
            num[ id[i][j] ]++;
            continue;
        }

        if (j > 0 && mm[i][j-1] == '.' && num[ id[i][j-1] ] < 5)
        {
            id[i][j] = id[i][j-1];
            num[ id[i][j] ]++;
            continue;
        }

        if (j < m-1 && mm[i][j+1] == '.' && num[ id[i][j+1] ] < 5)
        {
            id[i][j] = id[i][j+1];
            num[ id[i][j] ]++;
            continue;
        }

        if (i < n-1 && mm[i+1][j] == '.' && num[ id[i+1][j] ] < 5)
        {
            id[i][j] = id[i+1][j];
            num[ id[i][j] ]++;
            continue;
        }


        goto xx;
    }

xx:;
    if (i < n)
    {
        printf("-1\n");
    }
    else
    {
        assign_col();
        for (i=0; i<n; i++)
        {
            for (j=0; j<m; j++)
            {
                if (mm[i][j] == '#') printf("#");
                else printf("%d", col[ id[i][j] ]);
            }
            printf("\n");
        }
        
    }

    return 0;
}