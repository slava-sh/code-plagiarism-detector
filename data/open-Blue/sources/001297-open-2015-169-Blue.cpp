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

    if(res <= leng)
    {
        cout << "1\n" << s.substr(0, res);
        return 1;
    }
    else
        return 0;
}

bool try2()
{
    bool lett[3] = {0, 0, 0};
    for(int i = 0; i < s.size(); i++)
        lett[ s[i] - 'a' ] = 1;
    if(lett[0] && lett[1] && lett[2])
        return 0;
    else
    {
        cout << "2\n";
        for(int i = 0; i < 3; i++)
            if(lett[i])
                cout << (char)(i + 'a') << '\n';
        return 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> leng >> s;

    if(try1())
        return 0;
    else if(try2())
        return 0;
    else
        cout << "3\na\nb\nc\n";

    return 0;
}
