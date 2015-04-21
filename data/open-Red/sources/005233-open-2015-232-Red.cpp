#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#define ll long long
#define mp make_pair

using namespace std;

ll max_ = 0;
ll mn = 1;
int n = 0;
/*ll d[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 2};

unordered_map<ll, bool> m;

void calc(ll arg){
    //cout << arg << ' ' << n << "\n";
    if(m.find(arg * 12 + n) != m.end() ) return;
    m[arg * 12 + n] = 1;
    if(n == 12 || arg <= d[n]) max_ = max(max_, mn);
    else{
        ll tmp = 1;
        while(arg){
            mn *= tmp;
            ++n;
            calc(arg);
            --n;
            mn /= tmp;
            arg /= d[n];
            ++tmp;
        }
    }
}
*/
ll a, b, c, d;

vector<pair<ll, int> > fact(ll a){
    //cout << a << "\n";
    vector<pair<ll, int> > ans;
    for(ll i = 2; i * i <= a; ++i){
        //cout << i << ' '<< a << "\n";
        if(!(a % i)) ans.push_back(make_pair(i, 0));
        while(!(a % i)){
            prev(ans.end())->second++;
            a /= i;
        }
    }
    if(a != 1) ans.push_back(make_pair(a, 1));
    return ans;
}

ll st[30];
ll hash_ = 0;
ll hash2 = 0;
ll sum = 0;
int lvl = 0;
vector<pair<ll, int> > v;
unordered_map<ll, ll> s;

ll hashing(ll a, ll b, ll c){
    return ((a * 29 % (ll)(1E9 + 7)) * (b * 29 * 29 % (ll)(1E9 + 7)) * c) % (ll)(1E9 + 7);
}

ll calc2(){
    //if(hash_ > 1024 || hash2 > 1024) exit(666);
    //cout << lvl << "\n";
    ll hash_ = hashing(sum, mn, lvl);
    if(sum == 1 || lvl == b - 1) return (sum * mn + 1) / 2;
    auto tmp = s.find(hash_);
    if(tmp != s.end()) return tmp->second;
    ll ans = 1E18;
    ll mn_ = mn;
    //ll hash__ = hash_;
    //ll hash2_ = hash2;
    for(int i = 0; i < v.size(); ++i)
    if(v[i].second > 0){
        sum /= v[i].first;
        --v[i].second;
        lvl++;
        //hash2 = 0;
       // hash_ += st[i];
        mn = 1;
        ans = min(ans, (mn_ * v[i].first + 1) / 2 * calc2());
        mn = mn_ * v[i].first;
       // hash2 = hash2_ + st[i];
        --lvl;
        ans = min(ans, calc2());
        mn = mn_;
        //hash2 = hash2_;
       // hash_ = hash__;
        ++v[i].second;
        sum *= v[i].first;
    }
    s[hash_] = ans;
    return ans;
}

int main(){
    //calc(1E13);
    //cout << max_;
    //cin >> a >> b;
    a = 641055305251831470LL;
    b = 10;
    sum = a;
    v = fact(a);
    st[0] = 1;
    for(int i = 0; i < v.size(); ++i)
        st[i + 1] = st[i] * v[i].second;
    cout << calc2();
}
