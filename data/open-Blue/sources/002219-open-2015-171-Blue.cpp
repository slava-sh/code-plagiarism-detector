#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    int l, i;
    bool a = false, b = false;
    cin >> l;
    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a') a = true;
        if (s[i] == 'b') b = true;
    }
    cout << a + b << endl;
    if (a) cout << 'a' << endl;
    if (b) cout << 'b' << endl;

    return 0;
}
