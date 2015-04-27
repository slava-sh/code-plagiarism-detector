#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

pair<int, int> prov(string &s, int l){
    for(int i = 1; i <= min(l, (int)s.size()); i++){
        if((int)s.size() % i == 0){
            string s1;
            for(int j = 0; j < i; j++){
                s1.push_back(s[j]);
            }
            int fl = 0;
            for(int j = 1; j < s.size() / i; j++){
                for(int k = 0; k < s1.size(); k++){
                    if(s1[k] != s[k + j * i]){
                        fl = 1;
                        break;
                    }
                }
                if(fl){
                    break;
                }
            }
            if(!fl){
                pair<int, int> pr1;
                pr1.first = 1;
                pr1.second = i;
                return pr1;
            }
            s1.clear();
        }
    }
    pair<int, int> pr1;
    pr1.first = 0;
    pr1.second = 0;
    return pr1;
}

int try1(string &s, string &s1, int pos){
    if(s.size() < s1.size() + pos){
        return 0;
    }
    for(int i = 0; i < s1.size(); i++){
        if(s[pos + i] != s1[i]){
            return 0;
        }
    }
    return 1;
}

pair<int, pair<string, string> > prov2(string &s, string &s1, int l){
    int pos = 0;
    while(true){
        if(try1(s, s1, pos)){
            pos += s1.size();
        }
        else{
            break;
        }
    }
    //cerr << pos << endl;
    string s2;
    pair<int, pair<string, string> > pr1;
    for(int i = 0; i < l; i++){
        s2.push_back(s[pos + i]);
        //cerr << s2 << endl;
        int pos1 = pos;
        while(pos1 < s.size()){
            if(try1(s, s1, pos1)){
                pos1 += s1.size();
            }
            else if(try1(s, s2, pos1)){
                pos1 += s2.size();
            }
            else{
                break;
            }
        }
        if(pos1 == s.size()){
            pr1.first = 1;
            pr1.second.first = s1;
            pr1.second.second = s2;
            return pr1;
        }
        pos1 = pos;
    }
    pr1.first = 0;
    return pr1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int l;
    cin >> l;
    string s;
    cin >> s;
    vector<int> q;
    q.push_back(0);
    q.push_back(0);
    q.push_back(0);
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a'){
            q[0] = 1;
        }
        else if(s[i] == 'b'){
            q[1] = 1;
        }
        else if(s[i] == 'c'){
            q[2] = 1;
        }
    }
    pair<int, int> pr1;
    pr1 = prov(s, l);
    if(pr1.first == 1){
        cout << 1 << endl;
        for(int i = 0; i < pr1.second; i++){
            cout << s[i];
        }
        cout << endl;
        return 0;
    }
    if(q[0] + q[1] + q[2] < 3){
        cout << q[0] + q[1] + q[2] << endl;
        if(q[0] == 1){
            cout << 'a' << endl;
        }
        if(q[1] == 1){
            cout << 'b' << endl;
        }
        if(q[2] == 1){
            cout << 'c' << endl;
        }
    }
    else{
        string s1;
        pair<int, pair<string, string> > pr2;
        for(int i = 0; i < l; i++){
            s1.push_back(s[i]);
            //cerr << s1 << endl;
            pr2 = prov2(s, s1, l);
            if(pr2.first){
                cout << 2 << endl;
                cout << pr2.second.first << endl << pr2.second.second << endl;
                return 0;
            }
        }
        cout << 3 << endl << 'a' << endl << 'b' << endl << 'c' << endl;
        return 0;
    }
    return 0;
}
