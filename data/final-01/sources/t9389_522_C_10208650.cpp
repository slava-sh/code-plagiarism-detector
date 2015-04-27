#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back

int a[100005];
set<pair<int, int> > myset;

int main()
{
    int t, m, k, num, r, undef;
    bool ok;
    scanf("%d", &t);
    for (int t1=0; t1<t; ++t1)
    {
        myset.clear();
        ok = false;
        undef=0;
        scanf("%d", &m);
        scanf("%d", &k);

        for (int i=1; i<=k; ++i)
            scanf("%d", &a[i]);
        for (int i=0; i<m-1; ++i)
        {
            scanf("%d", &num);
            scanf("%d", &r);

            if (r)
            {
                if (!ok)
                {
                    for (int j=1; j<=k; ++j)
                        if (a[j] <= undef)
                            myset.insert(mp(a[j], j));
                    ok=true;
                }
            }
            if (!num)
                ++undef;
            else
            {
                myset.erase(mp(a[num], num));
                --a[num];
            }
        }
        if (myset.size()==0)
            myset.insert(mp(0, 0));
        for (int i=1; i<=k; ++i)
        {
            if (myset.find(mp(a[i], i)) != myset.end())
                printf("Y");
            else
            {
                if (a[i] - undef + (*(myset.begin())).first > 0)
                    printf("N");
                else
                    printf("Y");
            }
        }
        printf("\n");
    }



    return 0;
}
