#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>

using namespace std;

map<string, map<string, bool> >meniki;
void chiqar(string a, int k){
    int n = 11 - k;
    if(n % 2) cout << a[k++];
    cout << a[k] << a[k+1];
    for(k = k +2; k<11; k += 2){
        cout << "-"; cout << a[k] << a[k+1];
    }
}

bool result(string ip, string buf, int k){
    string a = "";
    for(int i=0; i<5; i++){
        a = a + buf[i+k];
        if(buf[i+k+1] != '0' && meniki[ip].find(a) != meniki[ip].end()){
            cout << "+" << ip << "(" << a << ")" ;
            chiqar(buf,i+k+1); cout << endl;
            return true;
        }
    }
    return false;
}
void solved(string buf){
    string a = "";
    for(int i=0; i<3; i++){
        a = a + buf[i];
        if(meniki.find(a) != meniki.end())
            if(result(a,buf,i+1)) return ;
    }
    cout << "Incorrect" << endl;
}

int main(){
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    int n, m;
    string a, b;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> m;
        for(int j=0; j<m; j++){
            cin >> b;
            meniki[a][b] = true;
        }
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> a;
        solved(a);
    }
    return 0;
}
