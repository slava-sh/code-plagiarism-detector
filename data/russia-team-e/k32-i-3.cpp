 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>
 # include <set>

 using namespace std;

 const int N = (int) 1e6;

 int cur, n, d, a[N];

 set <int> st;
 set <int> :: iterator it;
 bool used[N];

 int main () {

    freopen ("sochi.in", "r", stdin);
    freopen ("sochi.out", "w", stdout);

    cin >> n >> d;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort (a + 1, a + n + 1);

    cur = a[n];
    st.insert (cur);

   // used[n] = true;
    for (int i = n - 1; i >= 1; --i) {
        it = st.end ();
        -- it;
        int len = *it;
        if (len - d >= d && a[i] - d >= d && (a[i] - d) + (cur - d) > cur) {
            cur = (cur - d) + (a[i] - d);
            st.insert (a[i] - d);
            st.erase (it);
            st.insert (len - d);
         //   used[i] = true;
        }
    }

    cout << cur << endl;
    return 0;
 }
