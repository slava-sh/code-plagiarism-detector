#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

uint64_t base = 51, mod = 1000000007;
uint64_t pows[200010];

inline uint64_t get_hash(vector<uint64_t> const &hashes, size_t l, size_t r) {
    if (l == 0) {
        return hashes[r];
    }
    return ((hashes[r] - hashes[l - 1] + mod) % mod * pows[l]) % mod;
}

void init(size_t len) {
    pows[0] = 1;
    for (size_t i = 1; i != len; ++i) {
        pows[i] = (pows[i - 1] * base) % mod;
    }
}

vector<uint64_t> gen_hash(string const &str) {
    size_t len = str.length();
    vector<uint64_t> hashes(len);
    
    hashes[0] = ((str[0] - 'a' + 1) * pows[len - 1]) % mod;
    for (int i = 1; i != len; ++i) {
        hashes[i] = (hashes[i - 1] + (str[i] - 'a' + 1) * pows[len - i - 1] % mod) % mod;
    }
    
    return hashes;
}

uint64_t gen_hash(string const &str, char check) {
    size_t len = str.length();
    uint64_t hash = 0;
    
    if (str[0] == check) {
        hash = pows[len - 1];
    }
    
    for (int i = 1; i != len; ++i) {
        if (str[i] == check) {
            hash = (hash + pows[len - i - 1]) % mod;
        }
    }
    
    return hash;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    size_t s_len, t_len;
    string s, t;
    cin >> s_len >> t_len;
    getline(cin, s);
    getline(cin, s);
    getline(cin, t);
    
    init(s_len);
    auto sh = gen_hash(s);
    
    vector<size_t> occur(26, 1000000000);
    vector<uint64_t> hashes(26);
    
    for (char c = 'a'; c <= 'z'; ++c) {
        for (size_t i = 0; i != t_len; ++i) {
            if (t[i] == c) {
                occur[c - 'a'] = i;
                break;
            }
        }
        hashes[c - 'a'] = gen_hash(t, c);
    }
    
    vector<size_t> answer;
    
    for (size_t i = 0; i != s_len - t_len + 1; ++i) {
        uint64_t curr_hash = 0;
        vector<char> taken(26, 0);
        
        bool ok = true;
        
        for (size_t j = 0; j != 26; ++j) {
            if (occur[j] == 1000000000) continue;
            
            if (!taken[j]) {
                taken[j] = s[i + occur[j]];
            }
            if (taken[j] != s[i + occur[j]]) {
                ok = false;
                break;
            }
            if (!taken[s[i + occur[j]] - 'a']) {
                taken[s[i + occur[j]] - 'a'] = j + 'a';
            }
            if (taken[s[i + occur[j]] - 'a'] != j + 'a') {
                ok = false;
                break;
            }
        }
        
        if (!ok) continue;
        
        for (size_t j = 0; j != 26; ++j) {
            curr_hash = (curr_hash + hashes[j] * (taken[j] - 'a' + 1) % mod) % mod;
        }
        
        curr_hash = (curr_hash * pows[s_len - t_len]) % mod;
        
        if (curr_hash == get_hash(sh, i, i + t_len - 1)) {
            answer.push_back(i);
        }
    }
    
    cout << answer.size() << '\n';
    for (size_t ans : answer) {
        cout << ans + 1 << ' ';
    }
    
    return 0;
    
}