#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string s;
bool l[5];
int L;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin >> L;
    cin >> s;
    int typelt = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i)
        l[s[i]-'a'] = 1;
    for (int i = 0; i < 5; ++i) typelt+=l[i];

    if (s.length() <= L)
    {
        cout << 1 << endl << s;
        return 0;
    }

    if (typelt == 1)
    {
        cout << 1 << endl;
        for (int i = 0; i < 5; ++ i)
            if (l[i] != 0) cout << (char)(i+'a');
        return 0;
    }

    for (int i = 1; i <= L; ++i)
    {
            bool p = true;//                cout << s1 << " " << s2 << endl;

            string ex = s.substr(0,i);
//            cout << ex << endl;
            for (int j = 0; j < n;)
            {
                if (s.substr(j,i) != ex) {
                    p = false; break; }
                j+=i;
            }
            if (p)
            {
                cout << 1 << endl << ex;
                return 0;
            }
    }

    if (typelt == 2)
    {
        cout << 2 << endl;
        int c = 0;
        for (int i = 0; i < 5; ++i)
            if (l[i] != 0 )
            {
                cout << (char)(i+'a');
                if (c == 0) cout << endl;
                c++;
            }
        return 0;
    }


    for (int i = 2; i <= L+L; ++i)
    {
            string ex = s.substr(0,i);
//            cout << "string = " << ex << endl;
            for (int j = 1; j < ex.length()-1; ++j)
            {
                string s1 = ex.substr(0,j);
                string s2 = ex.substr(j, ex.length());
                if (s1 == s2) continue;
                int l1 = s1.length();
                int l2 = s2.length();
                bool p = true;
                for (int k = 0; k < n;)
                {
                    if (s.substr(k,l1) != s1 && s.substr(k,l2) != s2) {
                        p = false; break; }
                    if (s.substr(k,l1) == s1)
                    {
                        k+=l1;
                    }
                    if (s.substr(k,l2) == s2)
                    {
                        k+=l2;
                    }
                }
                if (p)
                {
                    cout << 2 << endl << s1 << endl << s2;
                    return 0;
                }
        }
    }



        cout << 3 << endl << "a\nb\n\c";

    return 0;
}
