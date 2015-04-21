#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    for (int a = 2; ; a += 2)
    {
        int x = 0, y = 0, dd = 0;
        int d = 1;
        while (1)
        {
            if (y + d >= 0 && y + d < a)
            {
                y += d;
                if (d == 1) cout << 'R';
                else cout << 'L';
                cout << "\n";
                cout.flush();
                char c;
                cin >> c;
                if (c == 'Y' || c == 'E') return 0;
            }
            else
            {
                if (d == 1)
                {
                    cout << 'D' << "\n";
                    ++x;
                    d = -1;
                    cout.flush();
                    char c;
                    cin >> c;
                    if (c == 'Y' || c == 'E') return 0;
                }
                else if (x != a - 1)
                {
                    cout << 'D' << "\n";
                    ++x;
                    d = 1;
                    cout.flush();
                    char c;
                    cin >> c;
                    if (c == 'Y' || c == 'E') return 0;
                }
                else
                {
                    for (int i = 0; i < a - 1; i++)
                    {
                        cout << 'U' << "\n";
                        cout.flush();
                        char c;
                        --x;
                        cin >> c;
                        if (c == 'Y' || c == 'E') return 0;
                    }
                    break;
                }
            }
        }
    }

}


