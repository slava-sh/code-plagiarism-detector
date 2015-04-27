#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

const int N = 100005;
int a[N];
int m, k;
int arr[N][2];  
char ans[N];
int lst[N];     

int main()
{
    int t;
    cin >> t;
    for (; t; --t)
    {
        scanf("%d%d", &m, &k);
        --m;
        for (int i = 1; i <= k; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < m; ++i)
            scanf("%d%d", &arr[i][0], &arr[i][1]);

        int id = -1, q0 = 0;
        memset(lst, -1, sizeof(lst));

        for (int i = 0; i < m; ++i)
        {
            if (arr[i][1] && id == -1)
                id = i;
            if (arr[i][0])
                lst[arr[i][0]] = i;
            else
                q0++;
        }
        memset(ans, 'N', k+1);
        ans[k+1] = 0;

        int val = -1;
        if (id == -1)
            val = 0;
        else
        {
            int q0id = 0;   
            for (int i = 0; i < id; ++i)
            {
                if (arr[i][0])
                    a[arr[i][0]]--;     
                else
                    q0id++;
            }

            for (int i = 1; i <= k; ++i)
            if (q0id >= a[i] && lst[i] < id)    
            {
                ans[i] = 'Y';
                if (val == -1 || val > a[i])    
                    val = a[i];
            }

            for (int i = 0; i < id; ++i)    
                if (arr[i][0])
                    a[arr[i][0]]++;
        }
        
        for (int i = 0; i < m; ++i)     
        if (arr[i][0])
            a[arr[i][0]]--;
        for (int i = 1; i <= k; ++i)    
        if (a[i] <= q0 - val)
            ans[i] = 'Y';

        printf("%s\n", ans+1);
    }
    
    return 0;
}

/*




*/
