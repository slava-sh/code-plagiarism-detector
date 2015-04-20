// *** ADDED BY HEADER FIXUP ***
#include <algorithm>
#include <set>
#include <string>
// *** END ***
// *** ADDED BY HEADER FIXUP ***
#include <cstdio>
#include<fstream>
// *** END ***
// *** ADDED BY HEADER FIXUP ***
#include <vector>
// *** END ***
#include <iostream>
typedef long long ll;
using namespace std;
set<string> regi[100];
vector<string> codes;
void form(string a,string b,string c){
    cout<<'+';
    cout<<a;
    cout<<'(';
    cout<<b;
    cout<<')';
    switch(c.size()){
    case 3:
        cout<<c;
        break;
    case 4:
        cout<<c[0]<<c[1]<<'-'<<c[2]<<c[3];
        break;
    case 5:
        cout<<c[0]<<c[1]<<c[2]<<'-'<<c[3]<<c[4];
        break;
    case 6:
        cout<<c[0]<<c[1]<<'-'<<c[2]<<c[3]<<'-'<<c[4]<<c[5];
        break;
    case 7:
        cout<<c[0]<<c[1]<<c[2]<<'-'<<c[3]<<c[4]<<'-'<<c[5]<<c[6];
    }
}
int main()
{
    //freopen("C:\\Users\\orspc\\Documents\\Visual Studio 2010\\Projects\\numbers.in.txt","r",stdin);
    freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
    int n;
    cin>>n;
    codes = vector<string> (n);
	int gosco = 0;
    for(int i = 0;i<n;++i)
    {
        int tt;
		string cod;
        cin>>cod>>tt;
		int sepo = i;
        for(int j = 0;j<i;++j) if(codes[j]==cod) sepo=j;
		if(sepo==i) gosco++;
		codes[sepo] = cod;
		for(int j  =0;j<tt;++j){
            string a;
            cin>>a;
            regi[sepo].insert(a);
        }
    }
    int p;
    cin>>p;
    for(int i1 = 0;i1<p;++i1)
    {
        string num;
        cin>>num;
        string tmp="";
        tmp += num[0];
        bool sep = false;
        for(int i = 1;i <= 3;++i)
        {
            int idx = -1;
            for(int j = 0;j<gosco;++j) if(codes[j]==tmp) idx=j;
			if(idx==-1) {
				tmp+=num[i];
				continue;
			}
            string tmp2="";
            tmp2+=num[i];
            for(int j = i+1;j<=i+1+5;++j)
            {
                if(regi[idx].count(tmp2)){
                    string tmp3 = "";
                    for(int kk = j;kk<11;++kk)
                        tmp3+=num[kk];
					if(tmp[0]!='0'&&tmp2[0]!='0'&&tmp3[0]!='0'){
						form(tmp,tmp2,tmp3);
						sep = true;
					}
                }
				tmp2+=num[j];
            }
            tmp+=num[i];
        }
        if(!sep) cout<<"Incorrect";
        cout<<endl;
	}
}
