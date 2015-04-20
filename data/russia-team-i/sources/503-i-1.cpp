#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n, d, bsum, cr, res, br;
int ropes[200000], sr[5];

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> cr;
        if (cr >= 3*d) {
            bsum+=cr;
            br++;
        }
        else {
            if ((sr[0] > sr[1]) && (cr > sr[1]) && (cr > d)) {
                sr[1] = cr;
            }
            if ((sr[0] < sr[1]) && (cr > sr[0]) && (cr > d)) {
                sr[0] = cr;
            }
            if ((sr[0] == sr[1]) && (cr > sr[1]) && (cr > d)) {
                sr[1] = cr;
            }
        }
    }
    res = bsum -((br - 1)*2*d);
    if ((sr[0]!=0) && (sr[1]!=0)) {
        res += sr[0]+sr[1] - 4*d;
    }
    else if (!((sr[0] == 0)&&(sr[1]==0))){
        res += sr[0]+sr[1] - 2*d;
    }
    cout << res;
}
