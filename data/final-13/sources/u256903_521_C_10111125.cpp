#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <ll> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ld> VD;
typedef vector <VD> VVD;
typedef vector <string> VS;
typedef vector <char> VC;
typedef vector <VC> VVC;
typedef pair <ll, ll> PII;
typedef pair <ll, PII> PIII;
typedef pair <ld, ld> PD;
typedef map <ll, ll> MII;
typedef map <string, int> MSI;
typedef queue <int> QI;
typedef queue <PII> QPI;
typedef set <ll> SI;
typedef SI::iterator IT;
typedef vector <PII> VPI;

#define F first
#define S second
#define pb push_back

const ll m = 1e9 + 7;

ll pot (ll a, ll b){
    if (b == 0) return 1;
    ll x = pot (a,b/2);
    x = (x*x)%m;
    if (b%2 == 1) return (a*x)%m;
    return x;
}

ll inv (ll x){
    return pot(x, m-2);
}

int main(){
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ls = 1;
    ll lt = n-1;
    for (int i = 0; i < k; ++i){
        ls = (ls*(n-1-i))%m;
        ls = (ls*(inv(i+1)))%m;
    }
    //cout << ls << endl;
    ll xx = s[n-1] - '0';
    ll suma = (xx*ls)%m;
    ll part = 0;
    for (ll i = n-2; i >= 0; --i){
        ll x = s[i] - '0';
        ll lss = (ls*k)%m;
        lss = (lss*inv(lt))%m;
        //cout << lss << endl;
        ls = (ls*(lt-k))%m;
        ls = (ls*inv(lt))%m;
        ls = (ls*10)%m;
        //cout << ls << endl;
        part = (part + lss)%m; 
        suma = (suma + x*(part + ls))%m;
        --lt;
    }
    cout << suma << endl;
}
