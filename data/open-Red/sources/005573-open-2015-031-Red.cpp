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
    long long a, b, t, i, iobr;
};

const long long maxn = 100010;
const long long maxm = 200010;

vector<ttt> g[maxn];
long long dist[6 * maxm];
queue<ttt> que;

int main()
{
    long long n, m, D;
    scanf("%lld %lld %lld", &n, &m, &D);
    long long ind = 0;
    for (long long i = 0; i < m; ++i)
    {
        ttt tmp;
        scanf("%lld %lld %lld", &tmp.a, &tmp.b, &tmp.t);
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

    long long Q;
    scanf("%lld", &Q);
    for (long long iii = 0; iii < Q; ++iii)
    {
        long long A, B;
        scanf("%lld %lld", &A, &B);
        A -= 1;
        B -= 1;
        for (long long i = 0; i < ind; ++i)
        {
            dist[i] = -1;
        }
        for (long long i = 0; i < g[A].size(); ++i)
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
            for (long long i = 0; i < g[e.b].size(); ++i)
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
        long long answ = -1;
        for (long long i = 0; i < g[B].size(); ++i)
        {
            long long ind = g[B][i].iobr;
            if (dist[ind] != -1)
            {
                if (answ == -1) answ = dist[ind];
                else answ = min(answ, dist[ind]);
            }
        }

        printf("%lld\n", answ);
    }

    return 0;
}

