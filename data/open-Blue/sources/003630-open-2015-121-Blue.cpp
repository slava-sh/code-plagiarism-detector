#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int L;
    cin >> L;
    string s;
    cin >> s;
    if (s.size() <= L)
    {
        cout << 1 << endl;
        cout << s << endl;
        return 0;
    }
    else if (s.size() <= L * 2)
    {
        cout << 2 << endl;
        for (int i = 0; i < L; i++)
        {
            cout << s[i];
        }
        cout << endl;
        for (int i = L; i < s.size(); i++)
        {
            cout << s[i];
        }
        cout << endl;
        return 0;
    }
    int ca = 0, cb = 0, cc = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a') ca++;
        else if (s[i] == 'b') cb++;
        else cc++;
    }
    if (ca == 0 && cb == 0 || cb == 0 && cc == 0 || ca == 0 && cc == 0)
    {
        cout << 1 << endl;
        cout << s[0] << endl;
        return 0;
    }
    if (ca == 0)
    {
        cout << 2 << endl;
        cout << "b\nc" << endl;
        return 0;
    }
    if (cb == 0)
    {
        cout << 2 << endl;
        cout << "a\nc" << endl;
        return 0;
    }
    if (cc == 0)
    {
        cout << 2 << endl;
        cout << "a\nb" << endl;
        return 0;
    }
    cout << 3 << endl;
    cout << "a\nb\nc" << endl;
    return 0;
}
