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

    int p = 1, start = 1;
    char c = 'U';

    while (1)
    {
        cout << c << "\n";
        --p;
        if (p == 0)
        {
            if (c == 'U') {c = 'R'; p = start;}
            else if (c == 'R') {c = 'D'; ++start; p = start;}
            else if (c == 'D') {c = 'L'; p = start;}
            else {c = 'U'; ++start; p = start;}
        }
        cout.flush();
        char x;
        cin >> x;
        if (x == 'Y' || x == 'E') return 0;
    }

}


