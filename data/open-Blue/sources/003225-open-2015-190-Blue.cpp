#include <iostream>
#include <string>

using namespace std;

int main()
{
    int l;
    cin>>l;
    int a[3];
    string s;
    cin>>s;
    if(s.size()<=l)
        cout<<"1"<<endl<<s<<endl;
    else
    {
        int n=s.size();
        for(int i=0;i<3;i++)
            a[i]=0;
        for(int i=0;i<n;i++)
            if(s[i]=='a')
                a[0]++;
            else
                if(s[i]=='b')
                    a[1]++;
                else
                    a[2]++;
        n=0;
        for(int i=0;i<3;i++)
            if(a[i]!=0)
                n++;
        if(n>2&&l*2>=s.size())
        {
            cout<<"2"<<endl;
            for(int i=0;i<l;i++)
                cout<<s[i];
            cout<<endl;
            for(int i=l;i<s.size();i++)
                cout<<s[i];
        }
        else
        {
            cout<<n<<endl;
            if(a[0]!=0)
                cout<<"a"<<endl;
            if(a[1]!=0)
                cout<<"b"<<endl;
            if(a[2]!=0)
                cout<<"b"<<endl;
        }
    }
    return 0;
}
