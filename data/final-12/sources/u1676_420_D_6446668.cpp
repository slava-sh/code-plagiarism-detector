#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <sstream>
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef vector <int> VI;
typedef vector <LL> VL;
typedef vector <string> VS;

const int MAXN = 1 << 21;

int tree[MAXN + 10];
int val[MAXN + 10];
int N, Q;
bool used[MAXN];

void update (int k, int v)
{
    while (k < MAXN)
    {
        tree[k] += v;
        k += k & -k;
    }   
}

int find_Kth (int k)
{
    int idx = 0;
    for (int i = 21; i >= 0; -- i)
    {
        idx |= 1 << i;
        if (idx >= MAXN || tree[idx] >= k)  idx ^= 1 << i;
        else    k -= tree[idx]; 
    }
    return idx + 1;
}

int main()
{
    cin >> N >> Q;
    for (int i = 0; i < N; ++ i)
    {
        update ((1 << 20) + i, 1);
        val[(1 << 20) + i] = -1;    
    }
    
    int e, p;
    bool error = false;
    int idx = (1 << 20);
    while (Q --)
    {
        cin >> e >> p;
        if (error)  continue;
        int k = find_Kth (p);
        if (val[k] == -1 && !used[e])   val[k] = e, used[e] = true;
        if (val[k] != e)    error = true;
        else
        {
            val[-- idx] = e;
            update (idx, 1);
            update (k, -1); 
        }   
    }
    
    if (error)
    {
        puts ("-1");
        return 0;   
    }
    
    idx = 0;
    for (int i = 0; i < N; ++ i)
    {
        int k = (1 << 20) + i;
        if (val[k] == -1)
        {
            while (used[++ idx]);
            val[k] = idx;   
        }   
        cout << val[k] << " ";
    }
    
//  while (1);
    return 0;   
}
