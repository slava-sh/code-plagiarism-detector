#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, Q;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int pr = 1;
    int now_c = v[0];
    for (int i = 1; i < N; i++)
    {
        if (now_c == v[i]) {}
        else
        {
            now_c = v[i];
            ++pr;
        }
    }
    cin >> Q;
    //cout << pr << endl;
    for (int i = 0; i < Q; i++)
    {
        int p, c;
        cin >> p >> c;
        p--;
        if (p == N - 1)
        {
            if (v[p] != c && p > 0 && v[p - 1] == c)
            {
                --pr;
            }
            else if (p > 0 && v[p] == v[p - 1] && v[p] != c)
            {
                ++pr;
            }
        }
        else if (p == 0)
        {
            if (v[p] != c && v[p + 1] == c)
            {
                --pr;
            }
            else if (v[p] != c && v[p] == v[p + 1])
            {
                ++pr;
            }
        }
        else
        {
            if (v[p - 1] == c && v[p + 1] == c && v[p] != c)
            {
                pr -= 2;
            }
            else if (v[p - 1] == c && v[p] != c && v[p + 1] != c && v[p + 1] != v[p])
            {
                --pr;
            }
            else if (v[p + 1] == c && v[p] != c && v[p - 1] != c && v[p - 1] != v[p])
            {
                --pr;
            }
            else if (v[p - 1] == c && v[p] == v[p + 1] && v[p] != c)
            {
            }
            else if (v[p + 1] == c && v[p] == v[p - 1] && v[p] != c)
            {
            }
            else if (v[p - 1] == v[p] && v[p] == v[p + 1] && v[p] != c)
            {
                pr += 2;
            }
            else if (v[p - 1] == v[p] && v[p] != v[p + 1] && v[p] != c && v[p + 1] != c)
            {
                ++pr;
            }
            else if (v[p + 1] == v[p] && v[p] != v[p - 1] && v[p] != c && v[p - 1] != c)
            {
                ++pr;
            }
        }
        v[p] = c;
        cout << pr << endl;
    }
}
