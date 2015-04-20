#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("conquest.in", "rt");
    fout = fopen ("conquest.out", "wt");

    int n, coins = 0;
    fscanf (fin, "%d", &n);
    vector<pair<int, int>> cities;
    vector<int> psum;
    
    for (int i = 0; i < n; i++)
    {
        int c, num;
        fscanf (fin, "%d %d", &num, &c);
        cities.push_back (make_pair (num, c));
    }

    sort (cities.begin (), cities.end ());
    psum.push_back (0);

    for (int i = 0, sum = 0; i < n; i++)
    {
        sum += cities[i].first;
        psum.push_back (sum);
    }

    int curr = n - 1, army = 0;

    while (curr >= 0)
    {
        int tmp = cities[curr].first - psum[curr] - army;

        if (tmp >= 0)
        {
            int t = tmp / 2 + 1;
            army += t;
            coins += t * cities[curr].second;
        }

        curr--;
    }

    fprintf (fout, "%d", coins);

    return 0;
}
