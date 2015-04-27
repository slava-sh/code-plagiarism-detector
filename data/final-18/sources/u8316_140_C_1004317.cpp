#pragma comment(linker, "/STACK:256000000")   

#include <fstream>   
#include <iostream>   
#include <string>   
#include <cmath>   
#include <map>   
#include <set>   
#include <numeric>   
#include <vector>   
#include <sstream>  
#include <algorithm>   
#include <queue>   
//#include <iomanip>  
#include <deque>   
//#include <hash_map>   
#include <time.h>   

using namespace std;   

const double PI = 3.1415926535897932384626433832795;   

#define fori(i,n) for(int i = 0; i < (n); i++)  

const string IN_NAME = "input.txt";   
const string OUT_NAME = "output.txt"; 

//const string NAME = "eve";
//const string IN_NAME = NAME + ".in";   
//const string OUT_NAME = NAME + ".out";  

#define sz(x) ((int)((x).size()))   
#define ll long long   
typedef pair<int,int> ii;   
#define MP make_pair   
#define sqr(x) ((x)*(x))   
#define all(v) (v).begin(), (v).end()   

#define int long long  
#define SZ 300000

double eps = 1e-5;

int n;
double R,r;

int x;

struct sh
{
    int size;
    int cnt;
    sh(int _size, int _cnt)
        : cnt(_cnt), size(_size)
    {}
    sh(){}
    const bool operator < (const sh & b) const
    {
        return cnt < b.cnt;
    }
};

priority_queue<sh> q;

map<int, int> mp;

sh s1,s2,s3;

vector<vector<int> > ans;

#undef int  
int main()  
#define int long long  
{   
    #ifndef ONLINE_JUDGE  
    freopen(IN_NAME.c_str(), "r", stdin);   
    freopen(OUT_NAME.c_str(), "w", stdout);   
    #endif   
    //-----------------------------------------------------------------------------------------------------------------   
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }

    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        q.push(sh(it->first, it->second));

    int sum = 0;
    while (q.size() >= 3)
    {
        s1 = q.top(); q.pop();
        s2 = q.top(); q.pop();      
        s3 = q.top(); q.pop();
        s1.cnt--;
        s2.cnt--;
        s3.cnt--;
        vector<int> sn;
        sn.push_back(s1.size);
        sn.push_back(s2.size);
        sn.push_back(s3.size);
        ans.push_back(sn);
        if (s1.cnt > 0) q.push(s1);
        if (s2.cnt > 0) q.push(s2);
        if (s3.cnt > 0) q.push(s3);
    }

    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); i++)
    {
        sort(all(ans[i]));
        reverse(all(ans[i]));
        for (int j = 0; j < sz(ans[i]); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}