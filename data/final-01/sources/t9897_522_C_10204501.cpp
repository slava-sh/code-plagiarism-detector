#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef vector <pii> vii;
typedef vector <double> vd;

#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define MP(a, b) make_pair((a), (b))

#define TASK "quotient"
#define MOD 1000000007
#define X first
#define Y second

void solution();
double rass(double x[2][3]);
string tolower(string s);

stack <clock_t> times;
const int N = 2;

void start_t()
{
    times.push(clock());
}

void stop_t(string out)
{
    clock_t now = clock();
    clock_t past = times.top();
    times.pop();
    double delta = now - past;
    cout << out << ": " << fixed << delta / (double)CLOCKS_PER_SEC << endl;
}

int main()
{
    ios::sync_with_stdio(false);
#ifdef _HOME_
    freopen("input.txt", "r", stdin);
    start_t();
#else
    //freopen(TASK ".in", "r", stdin);
    //freopen(TASK ".out", "w", stdout);
#endif // _HOME_
    int t;
    cin >> t;
    for(int i = 0;i < t;i++)
        solution();
#ifdef _HOME_
    stop_t("Total time");
#endif // _HOME_
    return 0;
}

void solution()
{
    int m, k, j = -1, s = 0;
    cin >> m >> k;
    int* a = new int[k];
    for(int i = 0;i < k;i++)
        cin >> a[i];
    m--;
    int* t = new int[m], *l = new int[m];
    string st;
    for(int i = 0;i < k;i++)
        st+= 'N';
    for(int i = 0;i < m;i++)
    {
        cin >> t[i] >> l[i];
        if(j == -1)
        {
            if(l[i])
                j = i;
            else
            {
                if(t[i])
                    a[t[i] - 1]--;
                else
                    s++;
            }
        }
    }
    
    if(j != -1)
    {
        bool* used = new bool[k];
        for(int i = 0;i < k;i++)
            used[i] = false;
        for(int i = j;i < m;i++)
            if(t[i])
                used[t[i] - 1] = true;
        bool q = true;
        for(int i = 0;i < k;i++)
            if(a[i] == 0)
                q = false;
        if(q)
        {
            int vmin = 0, imin = -1;
            for(int i = 0;i < k;i++)
                if(!used[i])
                {
                    vmin = a[i];
                    imin = i;
                    if(a[i] <= s)
                        st[i] = 'Y';
                }
            for(int i = 0;i < k;i++)
                if(!used[i])
                    if(vmin > a[i])
                    {
                        vmin = a[i];
                        imin = i;
                    }
            if(imin != -1)
                a[imin] = 0;
            s-= vmin;
        }
    }
    if(j != -1)
        for(;j < m;j++)
            if(t[j])
                a[t[j] - 1]--;
            else
                s++;
    for(int i = 0;i < k;i++)
        if(a[i] <= s)
            st[i] = 'Y';
    cout << st << endl;
}
