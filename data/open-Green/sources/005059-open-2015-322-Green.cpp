#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int> > p;

long long n, pr = 1, nm;
int k;
long long a[11];
long long ans = 1e18;


void dfs(long long sum, int level, int last){
    if (level == k){
        //cout << a[1] << " " << a[2] << endl;
        long long res = 1;
        for (int i = 1; i < k; i++){
            res *= ((a[i] + 1) / 2);
        }
        res *= (n / pr + 1) / 2;
        ans = min(ans, res);
        return;
    }
    if (sum >= a[level - 1]){
        a[level] = sum;
        pr *= a[level];
        if (n / pr < sum){
            pr /= a[level];
            return;
        }
        if (pr <= n)
            dfs(1, level + 1, 0);
        else{
            pr /= a[level];
            return;
        }
        pr /= a[level];
    }
    for (int i = last; i < p.size(); i++)
        if (p[i].second != 0){
            p[i].second--;
            dfs(sum * p[i].first, level, i);
            p[i].second++;
        }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    cin >> n >> k;
    int nn = sqrt(n);
    int col = 0;
    nm = n;
    while (nm % 2 == 0){
        col ++;
        nm /= 2;
    }
    a[0] = 0;
    if (col != 0)
        p.push_back(make_pair(2, col));
    for (int i = 3; i <= nn; i+=2){
        col = 0;
        while (nm % i == 0){
            col++;
            nm /= i;
        }
        if (col != 0)
            p.push_back(make_pair(i, col));
    }
    if (nm != 1)
        p.push_back(make_pair(nm, 1));
    dfs(1, 1, 0);
    cout << ans;
    return 0;
}
