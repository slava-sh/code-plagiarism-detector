#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;

int leng;
string s;

int z[20000];

bool try1()
{
    int l = 0, r = 0;
    for(int i = 1; i < s.size(); i++)
    {
        z[i] = 0;
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < s.size() && s[ z[i] ] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }

    int res = s.size();

    for(int i = 1; i < s.size(); i++)
        if(i + z[i] == s.size() && s.size() % i == 0)
        {
            res = i;
            break;
        }

    return res <= leng;
}

bool try2()
{
    bool lett[3] = {0, 0, 0};
    for(int i = 0; i < s.size(); i++)
        lett[ s[i] - 'a' ] = 1;
    if(lett[0] && lett[1] && lett[2])
        return 0;
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> leng >> s;

    if(try1())
        cout << "1\n";
    else if(try2())
        cout << "2\n";
    else
        cout << "3\n";

    return 0;
}