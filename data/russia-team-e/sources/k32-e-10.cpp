# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <map>
# include <string>
# include <cstring>
# include <set>

using namespace std;

int n, m, k;
string s;
map < string, set < int > > mp;
set < pair < string, int > > st;
set < int > temp;

bool f (string s1)
{
    for (int i = 1; i <= 3; ++i)
    {
        string str1 = "";
        str1.insert (0, s1, 0, i);
        if (mp.count (str1) && str1[0] != '0')
        {
            string s2 = s1;
            s2.erase (0, i);
            for (int j = 3; j <= 5; ++j)
            {
                string str2 = "";
                str2.insert (0, s2, 0, j);
                bool mark = true;

                for (set < int > :: iterator it = mp[str1].begin (); it != mp[str1].end (); ++it)
                    if (st.count (make_pair (str2, *it)))
                    {
                        mark = false;
                        break;
                    }

                if (!mark && str2[0] != '0')
                {
                    string s3 = s2;
                    s3.erase (0, j);
                    if (s3[0] != '0')
                    {
                    cout << "+" << str1 << "(" << str2 << ")";
                    if (s3.size () == 3)
                        cout << s3;
                    if (s3.size () == 4)
                        cout << s3[0] << s3[1] << "-" << s3[2] << s3[3];
                    if (s3.size () == 5)
                        cout << s3[0] << s3[1] << s3[2] << "-" << s3[3] << s3[4];
                    if (s3.size () == 6)
                        cout << s3[0] << s3[1] << "-" << s3[2] << s3[3] << "-" << s3[4] << s3[5];
                    if (s3.size () == 7)
                        cout << s3[0] << s3[1] << s3[2] << "-" << s3[3] << s3[4] << "-" << s3[5] << s3[6];
                    cout << "\n";
                    return true;
                    }
                }
            }
        }
    }
    return false;
}

int main ()
{
    freopen ("numbers.in", "r", stdin);
    freopen ("numbers.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> s >> m;
        mp[s] = temp;
        mp[s].insert (i);
        for (int j = 1; j <= m; ++j)
        {
            cin >> s;
            st.insert (make_pair (s, i));
        }
    }

    cin >> k;

    for (int i = 1; i <= k; ++i)
    {
        cin >> s;
        if (!f (s))
            cout << "Incorrect\n";
    }

    return 0;
}
