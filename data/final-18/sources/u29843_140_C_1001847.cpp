///Pawel Michalak
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<string>
#include<numeric>
#define SIZE(X) ((int)X.size())
#define FOR(I,A,B) for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B) for(int (I) = (A); (I) < (B); (I)++)
#define FORD(I,A,B) for(int (I) = (A); (I) >= (B); (I)--)
#define FORDW(I,A,B) for(int (I) = (A); (I) > (B); (I)--)
#define FOREACH(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); ++a)
#define FOREACHR(a,b) for(typeof(b.rbegin()) a = b.rbegin(); a != b.rend(); ++a)
#define FOLDTO(B,E,S,O) ({typeof(B) ITER = B; typeof(S) ACC = S; for(;ITER!=E;++ITER) {ACC = ACC O (*ITER);} ACC;})
#define FOLD(X,S,O) FOLDOTO(X.begin(),X.end(),S,O)
#define LBOUND(P,R,PRED) ({typeof(P) X=P,RRR=(R), PPP = P; while(PPP<RRR) {X = (PPP+(RRR-PPP)/2); if(PRED) RRR = X; else PPP = X+1;} PPP;})

using namespace std;
typedef long double ldouble;
typedef signed long long slong;

const slong Infinity = 1000000001;
const ldouble Pi = 2.0L*asinl(1.0L);
const ldouble Epsilon = 0.000000001;

template<class T, class U> ostream& operator << (ostream& os, const pair<T,U>&p) {return os << "(" << p.first << "," << p.second << ")"; }
template<class T> ostream& operator << (ostream &os, const vector<T>& V) {FOREACH(i, V) os << *i << " ";    return os; }
template<class T> ostream& operator << (ostream &os, const set<T>& S) {FOREACH(i, S) os << *i << endl; return os; }
template<class T, class U> ostream& operator << (ostream &os, const map<T, U>& M){ FOREACH(i, M) os << *i << endl; return os; }

set<pair<int,int> > S;
vector<vector<int> > R;
int n;

void readData()
{
    map<int,int> M;
    scanf("%d", &n);
    FOR(i,1,n)
    {
        int a;
        scanf("%d", &a);
        M[a]++;
    }
    FOREACH(i,M)
    {
        S.insert(make_pair(-i->second,i->first));
    }
}

void solve()
{
    //cout << S;
    while(S.size() >= 3)
    {
        pair<int,int> a, b, c;
        a = *S.begin();
        S.erase(S.begin());
        b = *S.begin();
        S.erase(S.begin());
        c = *S.begin();
        S.erase(S.begin());
        vector<int> Q;
        Q.push_back(a.second);
        Q.push_back(b.second);
        Q.push_back(c.second);
        sort(Q.begin(), Q.end());
        reverse(Q.begin(), Q.end());
        R.push_back(Q);
        if(a.first < -1) S.insert(make_pair(a.first+1,a.second));
        if(b.first < -1) S.insert(make_pair(b.first+1,b.second));
        if(c.first < -1) S.insert(make_pair(c.first+1,c.second));
    }
    cout << R.size() << endl;
    FOREACH(i,R) cout << *i << "\n";
}

int main()
{
    readData();
    solve();
    return 0;
}
