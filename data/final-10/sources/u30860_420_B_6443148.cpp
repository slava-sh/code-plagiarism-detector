#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>

#include <unordered_map>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;


#if !(defined LOCAL_DEBUG) || 0
const int SZ = 100500;
#else
const int SZ = 100;
#endif

vector<int> primes;

//ll cnk[
bool alwaysWas[SZ];
bool nowIn[SZ];
const int llt = SZ - 2;

bool run()
{
    int n, m;
    scanf("%d%d", &n, &m);
    rep(i, 0, n)
    {
        alwaysWas[i] = 1;
    }
    
    memset(nowIn, 0, sizeof(nowIn));
    int countIn = 0;
    
    vector<pii> moves;
    
    rep(i, 0, m)
    {
        char c;
        int num;
        scanf(" %c %d", &c, &num);
        num--;
        if (c == '+')
        {
            moves.push_back({1, num});
            nowIn[num] = true;
        }
        else
        {
            moves.push_back({-1, num});
            if (!nowIn[num])
                countIn++;
            nowIn[num] = false;
        }
    }
    
    int lastLeft = -1;
    
    rep(i, 0, m)
    {
        int cm = moves[i].second;
        
        if (moves[i].first == -1)
        {
            countIn--;
            nowIn[cm] = false;
            if (countIn != 0)
                alwaysWas[cm] = false;
            else
            {
                if (lastLeft != -1)
                {
                    if (lastLeft != cm)
                    {
                        alwaysWas[cm] = false;
                        alwaysWas[lastLeft] = false;
                        lastLeft = llt;
                    }
                    else
                    {
                        
                    }
                }
                else
                    lastLeft = cm;
            }
        }
        else //+
        {
            nowIn[cm] = true;
            if (countIn != 0)
                alwaysWas[cm] = false;
            else
            {
                if (lastLeft != -1)
                {
                    if (lastLeft != cm)
                    {
                        alwaysWas[cm] = false;
                        alwaysWas[lastLeft] = false;
                        lastLeft = llt;
                    }
                    else
                    {
                        
                    }
                }
                else
                    lastLeft = cm;
            }
            countIn++;
        }
    }
    
    vector<int> res;
    
    rep(i, 0, n)
    {
        if (alwaysWas[i])
            res.push_back(i+1);
    }
    
    printf("%d\n", (int)res.size());
    
    rep(i, 0, res.size())
    {
        printf("%d ", res[i]);
    }
    
    return false;
}

//#define prob "holygame"

int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    
    run();
    
#ifdef LOCAL_DEBUG
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}