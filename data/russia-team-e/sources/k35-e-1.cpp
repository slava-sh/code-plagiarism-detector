#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int n,k,c,i,j,l,m;
string s;
int gos[10010]={0},reg[100010]={0};
int counter=0;
int main(){
    ifstream cin("numbers.in");
    ofstream cout("numbers.out");
    cin>>n;
    for (i=0;i<n;i++){
        cin>>c>>k;
        counter++;
        gos[c]=counter;
        for (j=0;j<k;j++){
            cin>>l;
            reg[l]=counter;
        }
    }
    cin>>m;
    for (i=0;i<m;i++){
        cin>>s;
        string s1="";
        string s2="";
        int a=0,b=0,c=0;
        bool f=true;
        for (j=0;j<3;j++){
            f=true;
            a=a*10+int(s[j]-48);
            if(gos[a]!=0){
                    b=0;
                for(l=j+1;l<s.length();l++){
                    b=b*10+int(s[l]-48);
                    if(b>99999){
                        break;
                    }
                    if(reg[b]==gos[a]){
                        reg[b]=0;
                        f=false;
                        break;
                    }
                }
            }
            if(f==false)break;
        }
        if(f==true){
            cout<<"Incorrect"<<endl;
            continue;
        }
        int counter=(s.length()-l-1);
        cout<<"+"<<a<<"("<<b<<")";
        if(counter==3){
        for (j=l+1;j<s.length();j++)
                cout<<s[j];
                cout<<endl;
            }
        if(counter==4){
                string s2="";
                for (j=l+1;j<s.length();j++)
                    s2+=s[j];
                cout<<s2[0]<<s2[1]<<"-"<<s2[2]<<s2[3]<<endl;
        }
        if(counter==5){
                string s2="";
                for (j=l+1;j<s.length();j++)
                    s2+=s[j];
                cout<<s2[0]<<s2[1]<<s2[2]<<"-"<<s2[3]<<s2[4]<<endl;
        }
        if(counter==6){
                string s2="";
                for (j=l+1;j<s.length();j++)
                    s2+=s[j];
                cout<<s2[0]<<s2[1]<<"-"<<s2[2]<<s2[3]<<"-"<<s2[4]<<s2[5]<<endl;
        }
        if(counter==7){
                string s2="";
                for (j=l+1;j<s.length();j++)
                    s2+=s[j];
                cout<<s2[0]<<s2[1]<<s2[2]<<"-"<<s2[3]<<s2[4]<<"-"<<s2[5]<<s2[6]<<endl;
        }
        }
}
