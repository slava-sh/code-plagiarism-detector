#include<bits/stdc++.h>
using namespace std;
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
inline void pisz(int n) {
    printf("%d\n", n);
}
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
bool mat[500][500];
ll n, m, mod;
ll twos, ones;
ll dp[501][501];
ll rec(int i, int remt, int remo) {
    if (i == n - m)
        return (!remt) && (!remo);
    if (dp[i][remt] != -1)
        return dp[i][remt];
    ll s1 = 0;
    if (remt >= 2) {
        s1 = rec(i + 1, remt - 2, remo + 2) * (((remt * (remt - 1LL)) / 2LL) % mod);
        s1 %= mod;
    }
    ll s2 = 0;
    if (remo >= 2) {
        s2 = rec(i + 1, remt, remo - 2) * (((remo * (remo - 1LL)) / 2LL) % mod);
        s2 %= mod;
    }
    ll s3 = 0;
    if (remo && remt) {
        s3 = rec(i + 1, remt - 1, remo) * ((remo * remt) % mod);
        s3 %= mod;
    }
    return dp[i][remt] = (s1 + s2 + s3) % mod;
}
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> mod;
    F(i, 0, m) {
        char c;
        F(j, 0, n) {
            cin >> c;
            mat[i][j] = (c == '1');
        }
    }
    F(j, 0, n) {
        int c = 0;
        F(i, 0, m)
        c += mat[i][j];
        twos += (c == 0);
        ones += (c == 1);
    }
    clr(dp, -1);
    cout << rec(0, twos, ones) << endl;
}
