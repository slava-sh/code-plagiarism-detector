#include <iostream>
#include <string>
using namespace std;

int main()
{
    int L;
    cin >> L;
    int cnta = 0;
    int cntb = 0;
    int cntc = 0;
    string s;
    cin >> s;
    for (int i = 0; i < int(s.size()); i++)
    {
        if (s[i] == 'a')
            cnta++;
        if (s[i] == 'b')
            cntb++;
        if (s[i] == 'c')
            cntc++;
    }
    //cout << L;
    if (cntc == 0)
    {

        if (cnta == 0)
        {
            cout << 1 << "\n" << 'b';
            return 0;
        }
        if (cntb == 0)
        {
            cout << 1 << "\n" << 'a';
            return 0;
        }
        for (int k = 1; k <= L; k++)
        {

            for (int i = 0; i< (1 << k ); i++)
            {
                int m = i;
                string s2 = "";
                bool fl = true;
                for (int j =0; j < k; j++)
                {
                    if (m%2)
                        s2 =s2 + 'a';
                    else
                        s2 = s2 + 'b';
                    m/=2;
                }
                //cout << i << "\n";
                if (int(s.size()) % int(s2.size()) != 0)
                    fl = false;
                else
                    for (int l = 0; l< s.size(); l++)
                        if (s[l] != s2[l % int(s2.size())])
                            fl = false;
                if (fl)
                {
                  cout << 1 << "\n" << s2;
                  return 0;
                }
            }

        }
        cout << 2 << "\n" << 'a' << "\n" << "b" ;
    }
}
