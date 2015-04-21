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

    char c = 'U';

    while (1)
    {
        cout << c << "\n";
        cout.flush();
        char x;
        cin >> x;
        if (x == 'Y' || x == 'E') return 0;
        if (c == 'U') c = 'R';
        else c = 'U';
    }

}


