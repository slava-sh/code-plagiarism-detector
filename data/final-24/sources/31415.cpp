#include <iostream>
#include <string>

using namespace std;

int main()
{
    int l;
    cin >> l;

    string s;
    cin >> s;

    if (s.size() <= l)
    {
        cout << 1 << endl << s;
        return 0;
    }

    for (int i = 0; i < l; i++)
    {
        string cur = s.substr(0, i + 1), cop = s;

        int k = cop.find(cur);
        while (k != -1)
        {
            cop.erase(k, i + 1);
            k = cop.find(cur);
        }

        if (cop.empty())
        {
            cout << 1 << endl << cur;
            return 0;
        }
    }
    cout << 2 << endl << 'a' << endl << 'b';
}
