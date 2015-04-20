#include <fstream>

using namespace std;

int main()
{
    ifstream in("dunes.in");
    ofstream out("dunes.out");

    int l[1000];
    int r[1000];
    int x[1000];

    int n, m;
    in >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int lt, rt, xt;
        in >> lt >> rt >> xt;
        l[i] = lt;
        r[i] = rt;
        x[i] = xt;
    }

    for(int i = 0; i < m; i++)
    {
        int q;
        in >> q;
        long long res = 0;
        for(int k = 0; k < n; k++)
        {
            if(q >= l[k] && q <= r[k])
            {
                if((q-l[k])%2 == 0) res += x[k];
                else res -= x[k];
            }
        }
        out << res << endl;
    }

    //return 0;


    return 0;
}
