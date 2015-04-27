#include <iostream>
#include <vector>
#include <memory.h>
#include <string>

using namespace std;

const int S = 100100;
const int inf = 1000000000;
int n, m;
int a[S], used[S];
pair<int ,int> ask[S];
string ans;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < S; i++) {
        ans += 'N';
    }
    
    for (int I = 1; I <= T; I++) {
        cin >> m >> n;
        for (int i = 0; i < n; i++) {
            ans[i] = 'N';
        }
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    
        for (int i = 0; i < m - 1; i++) {
            cin >> ask[i].first >> ask[i].second;
        }
    
        int k1 = 0;
        for (int i = 0; i < m - 1; i++) {
            if (ask[i].second == 0) {
                if (ask[i].first == 0) {
                    k1++;
                } else {
                    a[ask[i].first - 1]--;
                }
            }
            else {
                for (int j = i; j < m - 1; j++) {
                    if (ask[j].first != 0) {
                        used[ask[j].first - 1] = I;
                    }
                }
            
                int mn = inf, id = -1;
                for (int j = 0; j < n; j++) {
                    if (used[j] != I && a[j] - k1 <= 0) {
                        ans[j] = 'Y';
                    }
                    if (a[j] < mn && (used[j] != I)) {
                        mn = a[j];
                        id = j;
                    }
                }
                
                k1 -= mn;
            
                for (int j = i; j < m - 1; j++) {
                    if (ask[j].first == 0) {
                        k1++;
                    }
                    else {
                        a[ask[j].first - 1]--;
                    }
                }
                
                break;
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (a[i] - k1 <= 0) {
                ans[i] = 'Y';
            }
        }
    
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
}