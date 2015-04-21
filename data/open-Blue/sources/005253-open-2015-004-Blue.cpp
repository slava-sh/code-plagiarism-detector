#include <iostream>

using namespace std;

int ct[3];
int z[20001];

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++){
        ct[s[i] - 'a']++;
    }
    int x = (ct[0] > 0) + (ct[1] > 0) + (ct[2] > 0);
    if (x == 1){
        cout << "1\n";
        if (ct[0] > 0){
            cout << "a";
        }
        if (ct[1] > 0){
            cout << "b";
        }
        if (ct[2] > 0){
            cout << "c";
        }
        return 0;
    }
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++){
        if (i < r){
            z[i] = min(z[i - l], r - i);
            if (i + z[i] == r){
                l = i;
                for (; i + z[i] < n && s[i + z[i]] == s[z[i]]; z[i]++);
                r = l + z[i];
            }
        }
        else{
            l = i;
            for (z[i] = 0; i + z[i] < n && s[i + z[i]] == s[z[i]]; z[i]++);
            r = l + z[i];
        }
    }
    for (int i = 1; i <= k; i++){
        if (i + z[i] == n && (n % i == 0)){
            cout << "1\n";
            for (int j = 0; j < i; j++){
                cout << s[j];
            }
            return 0;
        }
    }
    if (x == 2){
        cout << "2\n";
        if (ct[0] > 0){
            cout << "a\n";
        }
        if (ct[1] > 0){
            cout << "b\n";
        }
        if (ct[2] > 0){
            cout << "c\n";
        }
        return 0;
    }

    return 0;
}
