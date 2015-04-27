#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

int run(istream &inp) {
    int K, M;
    inp >> M >> K;
    vector<int> food(K);
    for (int i = 0; i < K; ++i) {
        inp >> food[i];
    }

    vector<int> sfood;
    unordered_set<int> after_firstpart;
    int freep = 0;
    int freep1 = 0;
    bool firstpart = true;
    for (int i = 0; i < M - 1; ++i) {
        int t, r;
        cin >> t >> r;
        if (r && firstpart) {
            firstpart = false;
            sfood = food;
            freep1 = freep;
        }
        if (t > 0) {
            food[t - 1]--;

            if (!firstpart) {
                after_firstpart.insert(t - 1);
            }
        } else {
            freep++;
        }
    }

    unordered_set<int> bad_guys;
    if (!firstpart) {
        int minval = 100500;
        for (int i = 0; i < sfood.size(); ++i) {
            if (sfood[i] <= freep1 && after_firstpart.find(i) == after_firstpart.end()) {
                minval = min(minval, sfood[i]);
                bad_guys.insert(i);
            }
        }
        freep -= minval;
    }

    for (int i = 0; i < food.size(); ++i) {
        if (food[i] <= freep || bad_guys.find(i) != bad_guys.end()) {
            cout << 'Y';
        } else {
            cout << 'N';
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        run(cin);
    }
    return 0;
}
