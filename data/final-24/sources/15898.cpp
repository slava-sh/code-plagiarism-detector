#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>

using namespace std;


bool period(string t, string s, int l){
    for (int i = 0; i < s.length(); i += l)
        if (s.substr(i, l) != t)
            return false;
    return true;
}


int main()
{
    ifstream in("input.txt");

    int L;
    in >> L;
    string s;
    in >> s;

    int n = s.length();

    string t;
    for (int i = 1; i <= L; ++i)
    if (n % i == 0){
        t = s.substr(0, i);
        if (period(t, s, i)){
            cout << 1 << endl << t << endl;
            return 0;
        }
    }

    s = ' ' + s;
    string p, q;
    vector<bool> dp(n);
    int a, b;
    int a1 = 1, b1;
    for (int a2 = 1; a2 <= L; ++a2)
        for (int j = 1; j <= n / a2; ++j){
            b1 = a2 * j + 1;
                for (int b2 = b1; b2 <= b1 + L - 1; ++b2){
                    if (b2 <= n){
                        a = a2 - a1 + 1;
                        b = b2 - b1 + 1;
                        p = s.substr(a1, a);
                        q = s.substr(b1, b);
                        dp[0] = 1;
                        for (int i = 1; i <= n; ++i){
                            dp[i] = 0;
                            if (i >= a && dp[i - a] && s.substr(i - a + 1, a) == p)
                                dp[i] = 1;
                            if (i >= b && dp[i - b] && s.substr(i - b + 1, b) == q)
                                dp[i] = 1;

                        }
                        if (dp[n]){
                            cout << 2 << endl << p << endl << q << endl;
                            return 0;
                        }
                    }
                }
        }

    cout << 3 << endl << 'a' << endl << 'b' << endl << 'c' << endl;


    in.close();
    return 0;
}
