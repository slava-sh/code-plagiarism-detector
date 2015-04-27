
/*
ID: wengsht1
LANG: C++
TASK: test
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;

//#define HOME 

#define MX 100001
#define W 100000
int N, M, K;
int h1, h2;
int p, st, ed;
char c;

int color[2][MX];
int point[201];
int m = 1;
bool go[201];

int work(int i, int h1, int h2, int now)
{
    double a = i - 1 + double(h1 + h2) / 100;

    double x = W / a;

    double x1 = x * h1 / 100.0;

    int tmp = 0;

    memset(go, false, sizeof(go));
    for(int j = 0;j < i;j++)
    {
        int co = color[now][int(x1)];
        if(co == 0 || go[co])
        {
            tmp = -1;
            break;
        }
        go[color[now][int(x1)]] = true;
        now ^= 1;
        x1 += x;
        tmp += point[co];
    }

    return tmp;
}
int main()
{
#ifdef HOME
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d %d", &h1, &h2, &N);

    int ret = 0; 
    for(int i = 0;i < N;i++)
    {
        cin>>p>>c>>st>>ed;

        point[m] = p;

        int j = 0;
        if(c == 'F') j = 1;

        for(int k = st;k < ed;k++) color[j][k] = m;
        m++;
    }

    for(int i = 1;i <= 100;i++)
    {
        if(i % 2)
        {
            int tmp = work(i, h1, h2, 1);

            if(ret < tmp) ret = tmp;

            tmp = work(i, 100-h1, 100-h2, 0);

            if(ret < tmp) ret = tmp;
        }
        else
        {
            int tmp = work(i, h1, 100-h2, 1);
            if(ret < tmp) ret = tmp;

            tmp = work(i, 100-h1, h2, 0);

            if(ret < tmp) ret = tmp;

        }
    }
    cout<<ret<<endl;

    return 0;
}

