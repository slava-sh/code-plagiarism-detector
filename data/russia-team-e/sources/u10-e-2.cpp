#include <iostream>
#include <string>
#include <map>
using namespace std;
bool REALLY(map<string,bool>a, string Id, string b, int k){
    string c = "";
    for(int i = 0; i < 5; i ++){
        c = c + b[i + k];
        if(b[i + k + 1] != '0' && a.find(c) != a.end()){
            cout<<"+"<<Id<<"("<<c<<")";
            k = i + k + 1;
            int n = 11 - k;
            if(n % 2 == 1){cout<<b[k++]; n--;}
            cout<<b[k]<<b[k+1]; n -= 2; k += 2;
            while(n){
                cout<<"-"<<b[k]<<b[k+1]; n -= 2; k += 2;
            }
            cout<<endl;
            return true;
        }
    }
    return false;
}
void PRINT(map<string,map<string,bool> >a, string b){
    string c = "";
    for(int i = 0; i < 3; i ++){
        c = c + b[i];
        if(a.find(c) != a.end() && REALLY(a[c],c,b,i+1)) return ;
    }
    cout<<"Incorrect"<<endl;
}
int main(){
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    map<string,map<string,bool> >a;
    string b, c;
    int n,m;
    cin>>n;
    for(int i = 0; i < n; i ++){
        cin >> b >> m;
        while(m --){
            cin>>c;
            a[b][c] = true;
        }
    }
    cin >> m;
    for(int i = 0; i < m ; i ++){
        cin >> b;
        PRINT(a,b);
    }
    return 0;
}
