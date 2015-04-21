#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int n;
bool ans = false;

void dfs(int pos, bool *can1, bool *can2, int l1, int l2){
    if (pos > n || ans)
        return;
    //if (l1 == 3 && l2 == 3)
    //    cout << pos << " "<< n << endl;
    if (pos == n){
        ans = true;
        return;
    }
    if (can1[pos])
        dfs(pos + l1, can1, can2, l1, l2);
    if (can2[pos])
        dfs(pos + l2, can1, can2, l1, l2);
}

int main(){
    //ios_base::sync_with_stdio(0);
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    string s;
    set<char> v;
    int l;
    cin >> l >> s;
    n = s.size();
    for (int i = 0; i < s.size(); i++)
        if (v.count(s[i]) == 0)
            v.insert(s[i]);
    if (l >= n){
        cout << 1 << endl << s;
    }else
    if (v.size() == 1){
        cout << v.size() << endl;
        for (set<char>::iterator i = v.begin(); i != v.end(); i++)
            cout << (*i) << endl;
    }else{
        int z[n + 1], left = 0, r = 0;
        z[0] = n;
        for (int i = 1; i < n; i++){
            if (i <= r)
                z[i] = min(r - i + 1, z[i - left]);
            else
                z[i] = 0;
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r){
                left = i;
                r = i + z[i] - 1;
            }
        }
        for (int i = 1; i <= l; i++){
            bool bb = false;
            for (int j = 0; j < n; j += i)
                if (z[j] < i)
                    bb = true;
            if (!bb){
                cout << 1 << endl << s.substr(0, i) << endl;
                return 0;
            }
        }
        bool can1[n];
        bool can[n];
        string s1;
        if (v.size() == 3){
            if (l * 2 >= n){
                cout << 2 << endl << s.substr(0, l) << endl << s.substr(l, s.size() - l + 1);
                return 0;
            }

            for (int l1 = 1; l1 <= l; l1++){
                memset(can, false, sizeof(can));
                for (int i = 0; i < n; i++)
                    if (z[i] >= l1)
                        can[i] = true;
                for (int j = l1; j < n; j++)
                    for (int l2 = 1; l2 <= l; l2++){
                        s1 = s.substr(l1, s.size() - l1 + 1);
                        int z1[n + 1], left = 0, r = 0, nn = s1.size();
                        z1[0] = nn;
                        for (int i = 1; i < nn; i++){
                            if (i <= r)
                                z1[i] = min(r - i + 1, z1[i - left]);
                            else
                                z1[i] = 0;
                            while (i + z[i] < n && s1[z1[i]] == s1[i + z1[i]])
                                z1[i]++;
                            if (i + z1[i] - 1 > r){
                                left = i;
                                r = i + z1[i] - 1;
                            }
                        }
                        memset(can1, false, sizeof(can1));
                        for (int i = 0; i < nn; i++)
                        if (z1[i] >= l2)
                            can1[j + i] = true;
                        ans = false;
                        dfs(0, can, can1, l1, l2);
                        if (ans){
                            cout << 2 << endl << s.substr(0, l1) <<  endl << s.substr(j, l2);
                            return 0;
                        }
                    }
            }
        }
        if (!ans){
            cout << v.size() << endl;
            for (set<char>::iterator i = v.begin(); i != v.end(); i++)
                cout << (*i) << endl;
        }
    }
    return 0;
}
