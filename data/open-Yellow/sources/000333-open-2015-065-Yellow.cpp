#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int solve(int a, int b, int c)
{
    int ans = 3;
    if (b == a) --ans;
    if (c == b) --ans;
    return ans;
}

int main()
{

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;
    cin >> n;

    vector <int> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];

    int kol = 0;
    for (int i = 0; i < n; i++)
        if (!i || m[i] != m[i - 1]) ++kol;

    int q;
    cin >> q;

    while (q--)
    {
        int pos, color;
        cin >> pos >> color;
        --pos;
        if (n == 1) {cout << "1\n"; continue;}
        if (pos == 0)
        {
            if (m[1] == m[0] && color != m[1]) ++kol;
            else if (m[1] != m[0] && color == m[1]) --kol;
        }
        else if (pos == n - 1)
        {
            if (m[n - 2] == m[n - 1] && color != m[n - 2]) ++kol;
            else if (m[n - 2] != m[n - 1] && color == m[n - 2]) --kol;
        }
        else
        {
            int c1 = solve(m[pos - 1], m[pos], m[pos + 1]);
            int c2 = solve(m[pos - 1], color, m[pos + 1]);
            kol += c2 - c1;
        }
        m[pos] = color;
        cout << kol << "\n";
    }

}
