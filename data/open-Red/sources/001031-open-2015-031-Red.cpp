#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>
#include <queue>

using namespace std;

struct ttt
{
    int a, b, t, i, iobr;
};

const int maxn = 50100;
const int maxm = 50100;

vector<ttt> g[maxn];
int dist[6 * maxm];
queue<ttt> que;

int main()
{
    int n, m, D;
    scanf("%d %d %d", &n, &m, &D);
    int ind = 0;
    for (int i = 0; i < m; ++i)
    {
        ttt tmp;
        scanf("%d %d %d", &tmp.a, &tmp.b, &tmp.t);
        tmp.a -= 1;
        tmp.b -= 1;
        tmp.i = ind;
        tmp.iobr = ind + 1;
        ind += 1;
        g[tmp.a].push_back(tmp);
        swap(tmp.a, tmp.b);
        tmp.i = ind;
        tmp.iobr = ind - 1;
        ind += 1;
        g[tmp.a].push_back(tmp);
    }

    int Q;
    scanf("%d", &Q);
    for (int iii = 0; iii < Q; ++iii)
    {
        for (int i = 0; i < 6 * m; ++i)
        {
            dist[i] = -1;
        }
        int A, B;
        scanf("%d %d", &A, &B);
        A -= 1;
        B -= 1;
        for (int i = 0; i < g[A].size(); ++i)
        {
            ttt tmp = g[A][i];
            tmp.b = tmp.a;
            tmp.a = -1;
            tmp.i = ind + i;
            dist[tmp.i] = 0;
            que.push(tmp);
        }
        while(que.size() != 0)
        {
            ttt e = que.front();
            //cout << e.a + 1<< ' ' << e.b + 1 << "  ^^ : \n";
            que.pop();
            for (int i = 0; i < g[e.b].size(); ++i)
            {
                ttt nw = g[e.b][i];
                if (abs(e.t - nw.t) > D) continue;

                if (dist[nw.i] == -1)
                {

                    dist[nw.i] = dist[e.i] + 1;
                    //cout << nw.a  + 1<< ' ' <<nw.b + 1<< ' ' << dist[nw.i] << '\n';
                    que.push(nw);
                }
            }
        }
        int answ = -1;
        for (int i = 0; i < g[B].size(); ++i)
        {
            int ind = g[B][i].iobr;
            if (dist[ind] != -1)
            {
                if (answ == -1) answ = dist[ind];
                else answ = min(answ, dist[ind]);
            }
        }

        printf("%d\n", answ);
    }



    return 0;
}

