#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cstdio>
#include <cmath>
#define int long long int
using namespace std;


main()
{
    freopen("input.txt", "r", stdin);
    int L;
    cin>>L;
    string s;
    cin>>s;
    int N = s.size();
    vector<int> H(N+1);
    int p = 10;
    int mod = 1e9+7;
    vector<int> pp(N+1, 1);
    for(int i = 1; i < N+1; ++i)
    {
        H[i] = ((H[i-1]*p) % mod + s[i-1] - 'a'+1) % mod;
        ////cout<<s[i]<<' '<<H[i]<<' ';
        pp[i] = (pp[i-1] * p) % mod;
    }
    vector<unordered_map<string, set<string> > > D(N);
    vector<set<string> > One(N);
    for(int i = 0; i < N; ++i)
    {
        //cout<<"I: "<<i<<endl<<endl;
        for (int len = 1; len <= min(L, i); ++len)
        {
            string word = s.substr(i-len+1, len);//((H[i+1] - (H[i-len+1] * pp[len]) % mod) + mod) % mod;
            ////cout<<word<<" : "<<endl;
            for(auto x:D[i-len][word])
            {
                //if (x!= )
                //cout<<x<<' ';
                D[i][word].insert(x);
                D[i][x].insert(word);
            }
            for(auto x:One[i - len])
            {
                if (x!= word)
                {
                    //cout<<x<<' ';
                    D[i][word].insert(x);
                    D[i][x].insert(word);
                }
                else
                {
                    One[i].insert(word);
                }
            }
            //cout<<endl;
        }
        int len = i+1;
        //cout<<"LAAL"<<endl;
        if (len <= L)
        {
            string word = s.substr(i-len+1, len);//((H[i+1] - (H[i-len+1] * pp[len]) % mod + mod)) % mod;
            One[i].insert(word);
        }
        for(auto x:One[i])
        {
            //cout<<x<<' '<<endl;
        }
    }
    //cout<<"HOME"<<endl;
    if (One[N-1].size() > 0)
    {
        cout<<1<<endl;
        cout<<*One[N-1].begin()<<endl;
        return 0;
    }
    ////cout<,2<,endl
    int i = N-1;
    for (int len = 1; len <= min(L, i); ++len)
    {
        string word = s.substr(i-len+1, len);//((H[i+1] - (H[i-len+1] * pp[len]) % mod) + mod) % mod;
        ////cout<<word<<" : "<<endl;
        if (D[N-1][word].size())
        {
            cout<<2<<endl;
            cout<<word<<endl;
            cout<<*D[N-1][word].begin()<<endl;
            return 0;
        }
    }
    cout<<3<<endl;
    cout<<'a'<<endl<<'b'<<endl<<'c'<<endl;

    ////cout<<D[N]
//    int i = N-1;
//    for (int len = 1; len = min(L, i))
//        {
//            int word = ((H[i+1] - (H[i-len+1] * pp[len]) % mod + mod) % mod;
//            D[i][word].resize(2);
//            D[i][word][1] += D[i-len][word][1];
//            D[i][word][1] += Sum[i-len] - D[i-len][word][0];
//            D[i][word][0] += D[i-len][word][0];
//            Sum[i] += D[i][word][0];
//        }
//        int len = i+1;
//        if (len <= L)
//        {
//            int word = ((H[i+1] - (H[i-len+1] * pp[len]) % mod + mod) % mod;
//            D[i][word][0] = 1;
//            Sum[i] += 1;
//        }

}

