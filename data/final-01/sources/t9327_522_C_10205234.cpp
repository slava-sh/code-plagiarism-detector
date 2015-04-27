#include <iostream>
#include <stdio.h>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

#define INF 1000000
#define cond(z) cout<<(z?"Y":"N");

int main () {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // freopen ("C.txt", "r", stdin);
    vector <int> dishes_before(200000);
    vector <int> dishes_after (200000);

    int t;
    cin >> t;
    int temp;
    int minimum, dish, state, place, questions_before, questions_after, available, m, k; 

    for (int z = 0; z < t; ++z) {
        cin >> m >> k;
        m--;
        for (int i = 0; i < k; ++i) {
            cin >> dishes_before[i];
            dishes_after[i] = 0;
        }

        questions_before = 0;
        for (place = 0; place < m; ++place) {
            cin >> dish >> state;
            if (state == 1) break;
            if (dish == 0) questions_before++;
            else dishes_before[dish - 1]--;
        }

        questions_after = 0;
        for (; place < m; ++place) {
            if (dish == 0) questions_after++;
            else dishes_after[dish - 1]++;
            if (place != m - 1) {
                cin >> dish >> state;
            }
        }
                
        minimum = INF;
        for (int i = 0; i < k; ++i) {
            temp = dishes_before[i] - dishes_after[i];
            if (minimum > temp && dishes_after[i] == 0) {
                minimum = temp;
            }
        }

        available = questions_before + questions_after;
        for (int i = 0; i < k; ++i) {
            temp = dishes_before[i] - dishes_after[i];
            
            if (dishes_after[i] == 0) {
                if (dishes_before[i] <= questions_before) {
                    cout << "Y";
                    continue;
                }
            }

            cond (temp <= available - minimum);
        }

        cout << "\n";
    }

    return 0;
}

