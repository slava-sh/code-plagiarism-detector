#include <iostream>

using namespace std;

int a[1000001];
int ls[1000001];
int s[1001][1001];

int main(){
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
    }
    int mxi = -2, mxj = -2;
    int mx = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int k = -(s[j][i] + s[i][j] - s[j][j] - s[i][i]);
            if (a[i] > a[j]) k++;
            else k--;
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
