#include <iostream>
#include <fstream>

#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>

#define INF 1488100500
#define lli long long int
#define MAX_N 20400


using namespace std;

string s;
int L;

bool tryone()
{
    int len = s.length();
    for (int ll = 2; ll <= L; ++ll)
    {
        if ((len % ll) == 0)
        {
            bool curok = true;
            for (int i = 0; i < ll; ++i)
            {
                for (int j = i; j < len; j+=ll)
                {
                    if (s[i] != s[j])
                    {
                        curok = false;
                        goto exit1;
                    }
                }
            }
            exit1:
            if (curok)
            {
                cout << 1 << endl << s.substr(0, ll) << endl;
                return true;
            }
        }
    }
    return false;
}

bool trytwo()
{
    return true;
}


int main()
{
    cin >> L >> s;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'a')
            ++a;
        else if (s[i] == 'b')
            ++b;
        else
            ++c;
    }
    if (a == 0 && b == 0) cout << 1 << endl << "c" << endl;
    else if (c == 0 && b == 0) cout << 1 << endl << "a" << endl;
    else if (a == 0 && c == 0) cout << 1 << endl << "b" << endl;
    else
    {
        if (tryone())
            return 0;
        else if (c == 0)
        {
            cout << 2 <<endl<<  "a" << endl <<"b"<< endl;

        }
        else if (b == 0)
        {
            cout << 2 <<endl<< "a" << endl <<"c"<< endl;

        }
        else if (a == 0)
        {
            cout << 2 <<endl<<  "c" << endl <<"b"<< endl;
        }
    }

    return 0;
}







































