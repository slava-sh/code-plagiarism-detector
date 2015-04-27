#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

using namespace std;

// Input macros
#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define whole(a)                    a.begin(), a.end()
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz                          size()
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)               ( (n >> b) & 1)

using namespace std;

#if DEBUG && !ONLINE_JUDGE

#define debug(args...)     (Debugger()) , args

class Debugger
{
public:
    Debugger(const std::string& _separator = ", ") :
    first(true), separator(_separator){}
    
    template<typename ObjectType>
    Debugger& operator , (const ObjectType& v)
    {
        if(!first)
            std:cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger() {  std:cerr << endl;}
    
private:
    bool first;
    std::string separator;
};

template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
    bool first = true;
    os << "[";
    for(unsigned int i = 0; i < v.size(); i++)
    {
        if(!first)
            os << ", ";
        os << v[i];
        first = false;
    }
    return os << "]";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
{
    bool first = true;
    os << "[";
    for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if(!first)
            os << ", ";
        os << *ii;
        first = false;
    }
    return os << "]";
}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
    bool first = true;
    os << "[";
    for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if(!first)
            os << ", ";
        os << *ii ;
        first = false;
    }
    return os << "]";
}

#else
#define debug(args...)                  // Just strip off all debug tokens
#endif

typedef long long LL;

typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<LL, LL> PLL;

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<VL> VVL;


int ni()
{
    int _num; s(_num);
    return _num;
}

/*-------------------------Main code begins now ------------------------------*/
int testnum;

int A[1000005];
int N;
VI triples[1000005];
map<int,int> counts;

void preprocess()
{
    
}

void solve()
{
    
    set<PII> yo;
    foreach(it, counts)
        yo.insert(PII((*it).second, (*it).first));
    int done = 0;
    while(yo.size() >= 3)
    {
        PII top = *yo.rbegin();
        yo.erase(yo.find(top));
        PII other = *yo.rbegin();
        yo.erase(yo.find(other));
        PII another = *yo.rbegin();
        yo.erase(yo.find(another));
        triples[done].pb(top.second);
        triples[done].pb(other.second);
        triples[done].pb(another.second);
        done++;

        top.first --; other.first--; another.first--;
        if(top.first)
            yo.insert(top);
        if(other.first)
            yo.insert(other);
        if(another.first)
            yo.insert(another);
    }
    cout << done << endl;
    forall(i, 0, done)
    {
        sort(whole(triples[i]));
        reverse(whole(triples[i]));
        foreach(it, triples[i])
            cout << *it << " " ;
        cout << endl;
    }
}

bool input()
{
    s(N);
    forall(i, 0, N)
    {
        int x; s(x);
        counts[x]++;
    }
        
    return true;
}


int main()
{
    preprocess();
    int T = 1;
    for(testnum=1;testnum<=T;testnum++)
    {
        if(!input()) break;
             solve();
    }
}
