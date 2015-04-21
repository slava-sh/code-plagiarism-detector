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

    int p = 0, start = 0;
    char c = 'U';

    while (1)
    {
        if (!p)
        {
            cout << "R\n";
            cout.flush();
            ++start;
            p = start;
            if (p % 2) c = 'U';
            else c = 'D';
            char x;
            cin >> x;
            if (x == 'Y' || x == 'E') return 0;
            for (int i = 0; i < 10; i++)
            {
                cout << 'R';
                cout << "\n";
                cout.flush();
                cin >> x;
                if (x == 'Y' || x == 'E') return 0;
            }
        }
        cout << c << "\n";
        cout.flush();
        --p;
        char x;
        cin >> x;
        if (x == 'Y' || x == 'E') return 0;
    }

}


