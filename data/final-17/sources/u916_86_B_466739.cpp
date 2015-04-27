#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 
#include <memory.h>

using namespace std; 

#define rep(i,n) for(int i=0;i<(n);++i)
#define clr(a,b) memset(a,b,sizeof(a)); 
#define all(c) (c).begin(), (c).end() 
#define inf 1000000000 

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;

char table[1001][1001];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif

    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", table[i]);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (table[i][j] == '#' || table[i][j] != '.')
                continue;

            bool found = false;

            int bk = -1;

            for (int k = 0; k < 4; k++)
            {
                int ni = i + dy[k];
                int nj = j + dx[k];

                if (ni < 0 || ni >= N)
                    continue;

                if (nj < 0 || nj >= M)
                    continue;

                if (table[ni][nj] == '#')
                    continue;


                if (table[ni][nj] != '.')
                {
                    bk = k;
                }
                else
                {
                    int dig = ((i % 3) * 3) + j % 3;

                    table[i][j] = '0' + dig;
                    table[ni][nj] = '0' + dig;
                    found = true;
                    break;
                }
            }

            if (!found && bk != -1)
            {
                int ni = i + dy[bk];
                int nj = j + dx[bk];

                table[i][j] = table[ni][nj];
                found = true;

            }


            if (!found)
            {
                printf("-1");
                return 0;



            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%s\n", table[i]);
    }



    return 0;  
}

