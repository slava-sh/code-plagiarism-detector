#if 1
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>


using namespace std;

typedef unsigned long long li;
typedef long double ld;
typedef double dd;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define X first
#define Y second
#define file "file"
#define mp make_pair
#define pb push_back

int main()
{
#ifdef _DEBUG
//    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin>>T;
    while(T-->0)
    {
        int m,k;
        cin>>m>>k;
        m--;
        vector<int>b(k), bNext(k), used(k,0);
        vector<pii>chel(m);
        int flag = 0;
        for(int i=0;i<k;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>chel[i].X>>chel[i].Y;
            if(chel[i].X > 0)
                bNext[chel[i].X - 1]++;
        }
        int neopr = 0;
        for(int i=0;i<m;i++)
        {
            if(chel[i].Y==1 && flag == 0)
            {
                flag = 1;
                int mi = 100500;
                int ind = 0;
                for(int j=0;j<k;j++)
                {
                    if(bNext[j])
                        continue;
                    if(b[j] <= neopr)
                        used[j] = 1;
                    if(b[j] < mi)
                    {
                        mi = b[j];
                        ind = j;
                    }
                }
                neopr -= mi;
            }
            if(chel[i].X == 0)
                neopr++;
            else
            {
                b[chel[i].X - 1]--;
                bNext[chel[i].X - 1]--;
            }
        }
        for(int i=0;i<k;i++)
        {
            if(used[i]==1)
            {
                cout<<'Y';
                continue;
            }
            if(b[i] - neopr <= 0)
            {
                cout << 'Y';
                continue;
            }
            cout<<'N';
        }
        cout<<endl;
    }
    return 0;
}
#endif