#include <fstream>

using namespace std;

int main()
{
    ifstream in("game.in");
    ofstream out("game.out");

    int n, m;
    int l1, r1;
    int l2, r2;
    int h[100001];

    in >> n >> m;
    in >> l1 >> r1;
    in >> l2 >> r2;
    for(int i = 0; i < n; i++)
    {
        in >> h[i];
    }

    int n1 = 0, n2 = 0, n3 = 0;

    for(int i = 0; i < n; i++)
    {
        if(h[i] >= l1 && h[i] <= r1)
        {
            if(h[i] >= l2 && h[i] <= r2)
            {
                n2++;
            }
            else
            {
                n1++;
            }
        }
        else
        {
            if(h[i] >= l2 && h[i] <= r2)
            {
                n3++;
            }
        }
    }

    int a = 0;
    int b = 0;

    for(int i = 0; i < m; i++)
    {
        if(n2 > 0)
        {
            n2--;
            if(i%2 == 0) a++;
            else b++;
        }
        else
        {
            if(i%2 == 0)
            {
                if(n1 > 0)
                {
                    n1--;
                    a++;
                }
                else if(n3 > 0)
                {
                    n3--;
                }
            }
            else
            {
                if(n3 > 0)
                {
                    n3--;
                    b++;
                }
                else if(n1 > 0)
                {
                    n1--;
                }
            }
        }
    }

    if(a==b) out << "Draw" << endl;
    else if(a > b) out << "Petya" << endl;
    else out << "Vasya" << endl;

    return 0;
}
