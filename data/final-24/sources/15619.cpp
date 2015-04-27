#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int MAX_SIZE = 1e+5 + 10, mc = 37;
int hash[MAX_SIZE], pow[MAX_SIZE];

int l, n;
string str;

void ok1(int pos)
{
    cout << 1 << endl << str.substr(0, pos) << endl;
    exit(0);
}

void ok2(int q, int oldPos, int i)
{
    --oldPos;
    cout << 2 << endl
        << str.substr(0, q) << endl
        << str.substr(oldPos, i) << endl;
    exit(0);
}

void init_hash()
{
    hash[0] = 0;
    pow[0] = 1;
    for (int q = 1; q <= n; ++q)
    {
        hash[q] = mc * hash[q - 1] + str[q - 1];
        pow[q] = pow[q - 1] * mc;
    }
}

inline int getHash(int l, int r)
{ // numerate from 1 to n
    return hash[r] - hash[l - 1] * pow[r - l + 1];
}

void findCycle()
{
    for (int q = n - 1, endQ = (n + 1) / 2; q >= endQ; --q)
        if ((n % (n - q) == 0) && getHash(1, q) == getHash(n - q + 1, n) && n - q <= l)
            ok1(n - q);
}

int main()
{
  /*
    #pragma message "FREOPEN"
    freopen("tmp", "r", stdin);
//  */

    cin >> l >> str;
    n = str.size();

    if (l >= n)
        ok1(n);

    init_hash();
    findCycle();

    for (int q = 1; q <= l; ++q)
    {
        //cout << "Q = " << q << endl;
        int s1 = getHash(1, q);
        int pos = 1;
        while (true)
        {
            if (pos + q <= n && getHash(pos, pos + q - 1) == s1)
                pos += q;
            else
                break;
        }
        if (pos == n + 1)
            ok1(q);
        //cout << pos << endl;
        for (int i = 1; i <= l && pos + i - 1 <= n; ++i)
        {
            int oldPos = pos;
            int s2 = getHash(pos, pos + i - 1);
            while (true)
            {
                if (pos + q - 1 <= n && getHash(pos, pos + q - 1) == s1)
                    pos += q;
                else if ((pos + i - 1 <= n) && getHash(pos, pos + i - 1) == s2)
                    pos += i;
                else
                    break;
            }
            if (pos == n + 1)
                ok2(q, oldPos, i);
            //cout << "POS = " << pos << endl;
            pos = oldPos;
        }
    }

    printf("3\na\nb\nc\n");

	return 0;
}
