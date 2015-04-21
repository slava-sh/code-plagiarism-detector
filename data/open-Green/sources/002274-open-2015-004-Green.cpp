#include <iostream>

using namespace std;

long long rc[11] = {0, 10000000000000000ll, 1000000000ll, 1000000ll, 10000ll, 2000ll, 100ll, 200ll, 200ll, 100ll, 40ll};

long long get(long long m, long long k){
    long long ans = 1;
    for (int i = 0; i < k; i++){
        ans *= m;
    }
    return ans;
}

int main(){
    long long n, k;
    cin >> n >> k;
    int ct = 0;
    long long n1 = n;
    while (n1 % 2 == 0){
        n1 /= 2;
        ct++;
    }
    if (ct >= k){
        for (int i = 0; i < k; i++){
            n /= 2;
        }
        cout << n;
        return 0;
    }
    while (n % 2 == 0){
        n /= 2;
    }
    long long l = 0;
    long long r = min(n + 1, rc[k - ct]);
    while (l < r - 1){
        long long m = (l + r) / 2;
        if (get(m, k - ct) > n){
            r = m;
        }
        else{
            l = m;
        }
    }
    long long ans = 1;
    long long i = l;
    int j;
    for (j = 0; j < k - ct; j++){
        if (i <= n){
            while (n % i != 0){
                i++;
            }
            n /= i;
            ans *= (i + 1) / 2;
        }
        else{
            break;
        }
    }
    if (n > 1){
        ans *= (n + 1) / 2;
    }
    cout << ans;
    return 0;
}
