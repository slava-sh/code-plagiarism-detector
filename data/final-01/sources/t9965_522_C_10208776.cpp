#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int testCount, m, k;
    cin >> testCount;
    while (testCount > 0) {
        testCount--;
        cin >> m >> k;
        m--;
        string result(k, 'N');
        vector<int> aInitial(k);

        for (int i = 0; i < k; i++) {
            cin >> aInitial[i];
        }
        int t, r;
        int undefinedInitialCount = 0;
        // Read until r == 1.
        while (m > 0) {
            cin >> t >> r;
            m--;
            if (r == 1) {
                break;
            }
            if (t == 0) {
                undefinedInitialCount++;
            } else {
                aInitial[t - 1]--;
            }
        }
        if (r == 0) {
            // All r's are non-zero.
            // Make the result.
            for (int i = 0; i < k; i++) {
                result[i] = aInitial[i] <= undefinedInitialCount ? 'Y' : 'N';
            }
        } else {
            // Read the rest.
            vector<int> aFinal(aInitial);
            vector<bool> isAvailable(k, false);
            int undefinedFinalCount = undefinedInitialCount;
            if (t == 0) {
                undefinedFinalCount++;
            } else {
                aFinal[t - 1]--;
                isAvailable[t - 1] = true;
            }
            while (m > 0) {
                cin >> t >> r;
                m--;
                if (t == 0) {
                    undefinedFinalCount++;
                } else {
                    aFinal[t - 1]--;
                    isAvailable[t - 1] = true;
                }
            }

            int minNotAvailable = INT_MAX;
            for (int i = 0; i < k; i++) {
                if (!isAvailable[i]) {
                    minNotAvailable = min(minNotAvailable, aInitial[i]);
                }
            }

            // Make the result.
            for (int i = 0; i < k; i++) {
                result[i] = ((!isAvailable[i] && aInitial[i] <= undefinedInitialCount)
                             || aFinal[i] <= undefinedFinalCount - minNotAvailable) ? 'Y' : 'N';
            }
        }
        cout << result << endl;
    }

    return 0;
}
