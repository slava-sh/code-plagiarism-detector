#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
//#include "bigint.h"

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define init(st) memset(st, 0, sizeof(st))
#define ll long long

// String operations
template<class T>
void splitstr(const string &s, vector<T> &out) {
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

string read_line() {
    string ret_val;
    getline(std::cin, ret_val);
    return ret_val;
}

template<class T>
void init_array(T *arr, int size, T value) {
    for (int i = 0; i < size; i++)
        arr[i] = value;
}

// Arithmetic operations
template<class T>
inline T gcd(T a, T b) {
    return (!a) ? b : gcd(b % a, a);
}

template<class T>
inline T mod(T a, T p) {
    a %= p;
    return (a < 0) ? a + p : a;
}

template<class T>
inline int num_bits(T n) {
    return (!n) ? 0 : 1 + numbits(n & (n - 1));
}

template<class T>
inline T inverse(T a, T m) {
    a = mod<T>(a,m);
    return (a==1) ? 1 : mod((1-m*inverse(m%a,a))/a,m);
}

template<class T>
inline bool is_prime(T a) {
    T lim = (T)sqrt((double)a);
    for (T i = 2; i <= T(lim+1E-9); i++)
        if (a % i == 0)
           return false;
    return true;
}

template<class T>
inline T power(T a, T p, T mod) {
    if (!p) return 1;
    T temp = power(a, p>>1, mod);
    temp = (temp * temp) % mod;
    if (p&1)
        temp = (temp * a) % mod;
    return temp;
}

void get_primes(int start, int end, vector<int> &vi) {
        int *p = new int[end + 1];
        init_array<int>(p, end+1, 0); p[1] = 1;
        for (int i = 2; i <= end; i++) {
                if (!p[i]) {
                        if (i >= start)
                                vi.push_back(i);
                        for (int j = 2*i; j <= end; j += i)
                                p[j] = 1;
                }
        }
    delete [] p;
}

// Graph operations
bool dfs(int current, int final, int total, int* visited, int **edges, bool flow) {
        if (current == final)
                return true;
        if (visited[current])
                return false;
        visited[current] = true;
        for (int i = 0; i < total; i++)
                if (edges[current][i] && dfs(i, final, total, visited, edges, flow)) {
                        if (flow) {
                                edges[current][i]--;
                                edges[i][current]++;
                        }
                        return true;
                }
        return false;
}

int flow(int in, int out, int total, int **edges) {
        int result = 0;
        int *visited = new int[total];
        while (init_array<int>(visited, total, 0), dfs(in, out, total, visited, edges, true))
                result++;
    delete [] visited;
        return result;
}

// Disjoint datasets
void create_set(int x, int *P, int *rank) {
        P[x] = x;
        rank[x] = 0;
}

int find_set(int x, int *P) {
        if (x != P[x])
                P[x] = find_set(P[x], P);
        return P[x];
}

bool merge_sets(int x, int y, int *P, int *rank) {
        int Px = find_set(x, P);
        int Py = find_set(y, P);
        if(Px == Py)
                return false;
        if (rank[Px] > rank[Py]) P[Py] = Px;
        else P[Px] = Py;
        if (rank[Px] == rank[Py])
                rank[Py]++;
        return true;
}

// Binary tree operations
template <typename T>
int read_cum_freq(int index, T *tree) {
        int sum = 0;
        while (index) {
                sum += tree[index];
                index -= (index & -index);
        }
        return sum;
}

template <typename T>
void upd_freq(int index, int mxIndex, int value, T *tree) {
        while (index <= mxIndex) {
                tree[index] += value;
                index += (index & -index);
        }
}

template <typename T>
int read_freq(int index, T *tree) {
        return read_cum_freq(index, tree) - read_cum_freq(index-1, tree);
}

// String algos.
void build_failure_function(const string &str, int *temp_arr) {
    temp_arr[0] = temp_arr[1] = 0;
    for (int i = 2; i <= sz(str); i++) {
        temp_arr[i] = -1;
        for (int ind = temp_arr[i-1]; temp_arr[i] == -1; ind = temp_arr[ind]) {
            if (str[ind] == str[i-1]) {
                temp_arr[i] = ind + 1;
            } else if (ind == 0) {
                temp_arr[i] = 0;
            }
        }
    }
}

void KMP(const string &text, const string &pattern, int *res) {
    int *temp_arr = new int[sz(pattern) + 1];
    build_failure_function(pattern, temp_arr);
    int i = 0;
    int ind = 0;
    while (i < sz(text)) {
        if (text[i] == pattern[ind]) {
            res[i] = ++ind;
            if (res[i] == sz(pattern)) {
                ind = temp_arr[ind];
            }
            i++;
        } else if (ind == 0) {
            res[i++] = 0;
        } else {
            ind = temp_arr[ind];
        }
    }
    delete [] temp_arr;
}

// Setup
void setup(int value, string name) {
    string name_in = name + ".in";
    string name_out = name + ".out";
    freopen(name_in.c_str(), "r", stdin);
    if (value) {
        freopen(name_out.c_str(), "w", stdout);
    }
}

void join(vector<int> &vi1, vector<int> &vi2) {
    int i = 0;
    int j = 0;
    while (i < vi1.size() && j < vi2.size()) {
        if (vi1[i] == vi2[j]) {
            i++;
            j++;
        } else if (vi1[i] < vi2[j]) {
            vi2.push_back(vi1[i]);
            i++;
        } else {
            j++;
        }
    }
    while (i != vi1.size()) {
        vi2.push_back(vi1[i++]);
    }
    sort(vi2.begin(), vi2.end());
}

vector< pair<int, int> > input;
set< pair<int, int> > ret_val;

void go(int f, int l) {
    if (input[f].first == input[l].first)
        return;
    int mid = input[(f + l) / 2].first;
    for (int i = f; i <= l; i++) {
        if (input[i].first != mid)
            ret_val.insert(make_pair(mid, input[i].second));
    }
    int ind1 = (f + l) / 2;
    while (ind1 >= f && input[ind1].first == input[(f + l) / 2].first) {
        ind1--;
    }
    if (ind1 >= f)
        go(f, ind1);
    int ind2 = (f + l) / 2;
    while (ind2 <= l && input[ind2].first == input[(f + l) / 2].first) {
        ind2++;
    }
    if (ind2 <= l)
        go(ind2, l);
}

int main() {
#ifdef LOCAL_HOST
    setup(0, "temp");
#endif
    int n; std::cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> input[i].first >> input[i].second;
        ret_val.insert(input[i]);
    }
    sort(input.begin(), input.end());
    go(0, input.size()-1);
    std::cout << ret_val.size() << std::endl;
    for (set< pair<int, int> >::iterator it = ret_val.begin(); it != ret_val.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }
    return 0;
}
