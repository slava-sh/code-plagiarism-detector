#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<set>

using namespace std;

int main()
{
    int l, n;
    string s;
    cin >> l;
    cin >> s;
    n = s.size();
    if (l >= n)
    {
        cout << "1" << endl << s << endl;
    }
    else
    {
        string q = "";
        for (int i = 0; i < n; i++)
        {
            q += s[i];
            string t = "";
            if (n % (int)q.size() == 0 && q.size() <= l)
            {
                while(t.size() < n)
                {
                    t += q;
                }
                if (t == s)
                {
                    cout << "1" << endl << q << endl;
                    return 0;
                }
            }
        }
        cout << "2" << endl << "a" << endl << "b" << endl;
    }
    return 0;
}
