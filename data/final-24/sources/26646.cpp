#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <ctime>


using namespace std;
typedef long long ll;

int main()
{   srand(time(0));
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = s.size();
    n = min(n, c);
    for (int i = 1; i <= n; ++i)
    {
        int f = 0;
        if (s.size() % i != 0)
            continue;
        for (int j = 0; j < s.size(); ++j)
            if (s[j] != s[j % i])
            {
                f = 1;
                break;
            }
        if (!f)
        {
            cout << 1 << endl;
            for(int j = 0; j < i; ++j)
                cout << s[j];
            return 0;
        }
    }
    cout << 2 << endl << "a" << endl << "b" << endl;

    return 0;
}
