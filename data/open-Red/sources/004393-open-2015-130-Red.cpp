#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mp make_pair
#define ll long long
#define mod 1000000007

static int m1[3000], m2[3000], m3[3000][3000], m4[3000][3000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	vector <int> vc, vc1, vc2;
	int n, m, d, a, b, c, q;
	cin >> n >> m >> d;
	for (int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        --a, --b;
        vc.push_back(a);
        vc1.push_back(b);
        vc2.push_back(c);
        vc.push_back(b);
        vc1.push_back(a);
        vc2.push_back(c);
	}
	m *= 2;
	for (int i = 0; i < m; ++i){
	    m1[i] = m2[i] = i;
        for (int j = 0; j < m; ++j)
            if (vc1[i] == vc[j] && abs(vc2[i] - vc2[j]) <= d){
                //m1[i] = min(m1[i], j);
                //m2[i] = max(m2[i], j);
                m3[i][j] = 1;
            }
	}
	cin >> q;
	int f, s, res;
	queue <int> qe, qe1;
	for (int qq = 0; qq < q; ++qq){
        cin >> f >> s;
        --f, --s;
        for (int i = 0; i < m; ++i)
            m1[i] = mod;
        for (int i = 0; i < m; ++i)
            if (vc[i] == f){
                qe.push(i);
                qe1.push(1);
            }
        while (!qe.empty()){
            a = qe.front();
            b = qe1.front();
            qe.pop();
            qe1.pop();
            if (m1[a] <= b){
                continue;
            }
            m1[a] = b;
            for (int i = 0; i < m; ++i)
                if (m3[a][i] && m1[i] > b + 1){
                    qe.push(i);
                    qe1.push(b + 1);
                }
        }
        res = mod;
        for (int i = 0; i < m; ++i)
            if (vc1[i] == s){
                res = min(res, m1[i]);
            }
        if (res == mod)
            cout << "-1\n";
        else
            cout << res << '\n';
	}
	//system("pause");
	return 0;
}
