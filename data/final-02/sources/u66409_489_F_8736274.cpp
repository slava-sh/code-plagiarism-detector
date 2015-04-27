#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<string> vs;

#define For(i,a,b) for (int i=(a); i<=(b); i++)
#define Ford(i,a,b) for (int i = (a); i>= (b); i--)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i!= (v).end(); i++)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a,x,sizeof(a))
#define el "\n"

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); }

const ld PI = acos(-1.0);
const ld eps = 1e-9;
const ll inf = (ll) 1e9 + 7;
const ll linf = (ll) 1e16 + 5;
const ll mod = (ll) 1e9 + 7;
const int maxn = 20000;

//#define TEST
int x[10];
int n,m;
ll mo;
int luu[510][510];
ll ans;
ll tinh(int a,int b){
    int c = n - a - b;
    int k = a + b / 2;
    if (a > n || a < 0 || b > n || b < 0 || c > n || c < 0) {
        return 0;
    }
    if (luu[a][b] != -1)
        return luu[a][b];
    if (a == n && k == n && b == 0 && c == 0) {
        luu[a][b] = 1;
        return luu[a][b];
    }
    ll temp = 0;
    //cout << a << " " <<  b << " " << c << el;
    temp += b * (b -1 ) / 2* tinh(a+2,b-2); temp = temp % mo;
    temp += c * (c -1 ) / 2 * tinh(a,b+2); temp = temp % mo;
    temp += b * c * tinh(a+1,b); temp = temp % mo;
    luu[a][b] = temp;
    return luu[a][b];
}
int main(){
    #ifdef TEST
        freopen("input.txt","r",stdin);
    #endif
    //std:ios_base::sync_with_stdio(0);
    //cin.tie(0);
    /*===============================*/
    cin >> n >> m >> mo;
    int tong[600];
    string s;
    cin.ignore();
    ms(tong,0);
    For(i,0,n){
        For(j,0,n){
            For(k,0,n){
                luu[i][j] = -1;
            }
        }
    }
    For(i,1,m){
        getline(cin,s);
        For(j,0,s.length()-1){
            if (s[j] == '1') tong[j]++;
        }
    }
    x[0] = x[1] = x[2] = 0;
    For(i,0,n-1){
        x[tong[i]]++;
    }
    //cout << x[2] << " " << x[1] << " " << x[0] << el;
    ans = tinh(x[2],x[1]);
    cout << ans << el;
    /*===============================*/
    return 0;
}

