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
    int N;
    cin >> N;
    vector<int> v(N), d(N);
    //int max1 = 0, max2 = 0;
    int max_ind1 = -1, max_ind2 = -1;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        //d[i] = abs(v[i] - i);
    }
    int MIN = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[i] > v[j])
            {
                ++MIN;
            }
        }
    }
    //cout << MIN << endl;
    int ind1 = -1, ind2 = -1;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            swap(v[i], v[j]);
            int now_c = 0;
            for (int i1 = 0; i1 < N; i1++)
            {
                for (int j1 = i1 + 1; j1 < N; j1++)
                {
                    if (v[i1] > v[j1])
                    {
                        ++now_c;
                    }
                }
            }
            if (now_c < MIN)
            {
                MIN = now_c;
                ind1 = i;
                ind2 = j;
            }
            swap(v[i], v[j]);
        }
    }
    if (ind1 != -1) cout << ind1 + 1 << " " << ind2 + 1 << endl;
    else cout << -1 << " " << -1 << endl;
    //cout << MIN << endl;
}
