#include <iostream>
#include <cstdio>

using namespace std;

int a[1000001];
int ls[1000001];
int s[1001][1001];
int s1[1001][1001];

int get(int i, int j){
    int sa = s[i][i] + s1[i][i] + s[j][j] + s1[j][j];
    int sb = s[i][j] + s1[i][j] + s[j][i] + s1[j][i] + 2 * (a[i] > a[j]);
    return sa - sb;
}

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        s[i][n - 1] = 0;
        for (int j = n - 2; j >= 0; j--){
            s[i][j] = s[i][j + 1];
            if (a[i] > a[j + 1]){
                s[i][j]++;
            }
        }
        s1[i][0] = 0;
        for (int j = 1; j < n; j++){
            s1[i][j] = s1[i][j - 1];
            if (a[i] < a[j - 1]){
                s1[i][j]++;
            }
        }
    }
    int mxi = -2, mxj = -2;
    int mx = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int k = get(i, j);
            if (k > mx){
                mxi = i;
                mxj = j;
                mx = k;
            }
        }
    }
    cout << mxi + 1 << " " << mxj + 1 << endl;
    return 0;
}
