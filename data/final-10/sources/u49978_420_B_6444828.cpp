#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_N = 100002;


int N, M;
int A[MAX_N][2];
vector < int > v;
bool sol[MAX_N], in[MAX_N];

int main() {
    #ifndef ONLINE_JUDGE
        ifstream cin("data.in");
    #endif

    memset(sol, 1, sizeof(sol));

    cin >> N >> M;

    int nr = 0;
    for(int i = 1, x = 0; i <= M; ++i) {
        char c;

        cin >> c >> x;

        if(c == '+') {
            in[x] = 1;
            A[i][1] = 1;
        }
        else {
            if(in[x] == 0)
                ++nr;
            else in[x] = 0;

            A[i][1] = -1;
        }

        A[i][0] = x;
    }

    int leader = 0;
    for(int i = 1, x = 0, c; i <= M; ++i) {

        x = A[i][0], c = A[i][1];

        if(c == 1) {
            if(nr > 0)
                sol[x] = 0;
            else if(leader) {
                if(leader != x) {
                    sol[leader] = 0;
                    sol[x] = 0;
                    leader = 0;
                }
            }
            else leader = x;
            ++nr;
        }
        else {
            --nr;
            if(nr > 0) {
                sol[x] = 0;
                if(x == leader)
                    leader = 0;
            }
            else if(leader) {
                if(leader != x) {
                    sol[leader] = 0;
                    sol[x] = 0;
                    leader = 0;
                }
            }
            else leader = x;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= N; ++i)
        cnt += sol[i];

    cout << cnt << "\n";
    for(int i = 1; i <= N; ++i)
        if(sol[i])
            cout << i << " ";
    cout << "\n";



    return 0;
}
