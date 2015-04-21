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
        if(n==1)
        {
            cout<<n<<endl;
            if(a[0]!=0)
                cout<<"a"<<endl;
            if(a[1]!=0)
                cout<<"b"<<endl;
            if(a[2]!=0)
                cout<<"c"<<endl;
        }
        else
        {
            int p=2;
            int ind=0;
            while(p<=l&&ind==0)
            {
                if(s.size()%p==0)
                {
                    ind=1;
                    for(int i=0;i<s.size();i+=p)
                    {
                        for(int j=0;j<p;j++)
                            if(s[j]!=s[i+j])
                                ind=0;
                    }
                    if(ind==0)
                        p++;
                }
                else
                    p++;
            }
            if(ind==1)
            {
                cout<<"1"<<endl;
                for(int i=0;i<p;i++)
                    cout<<s[i];
            }
            else
                if(l*2>=s.size())
                {
                    cout<<"2"<<endl;
                    for(int i=0;i<l;i++)
                        cout<<s[i];
                    cout<<endl;
                    for(int i=l;i<s.size();i++)
                        cout<<s[i];
                }
                else
                    if(n==2)
                    {
                        cout<<n<<endl;
                        if(a[0]!=0)
                            cout<<"a"<<endl;
                        if(a[1]!=0)
                            cout<<"b"<<endl;
                        if(a[2]!=0)
                            cout<<"c"<<endl;
                    }
                    else
                    {
                        p=2;
                        ind=0;
                        int d=1;
                        while(p<=l&&ind==0)
                        {
                            string s2;
                            s2.clear();
                            int i=0;
                            int uk;
                            while(i<s.size())
                            {
                                uk=0;
                                if(i+p<=s.size())
                                    for(int j=0;j<p;j++)
                                        if(s[j]==s[i+j])
                                            uk++;
                                if(uk==p)
                                    i+=p;
                                else
                                {
                                    if(i+d<=s.size())
                                    {
                                        for(int j=0;j<d;j++)
                                            s2=s2+s[i+j];
                                        i+=d;
                                    }
                                    else
                                        i=s.size()+5;
                                }
                            }
                            uk=0;
                            if(i==s.size())
                            {
                                for(int j=0;j<s2.size();j+=d)
                                    for(int g=0;g<d;j++)
                                        if(s2[g]!=s2[j+g])
                                            uk=1;
                            }
                            else
                                uk=1;
                            if(uk==0)
                            {
                                cout<<"2"<<endl;
                                for(int j=0;j<p;j++)
                                    cout<<s[j];
                                cout<<endl;
                                for(int j=0;j<d;j++)
                                    cout<<s2[j];
                                cout<<endl;
                                p=l;
                                ind=1;
                            }
                            else
                            {
                                d++;
                                if(d==l+1)
                                {
                                    p++;
                                    d=1;
                                }
                            }
                        }
                        if(ind==0)
                        {
                            cout<<n<<endl;
                            if(a[0]!=0)
                                cout<<"a"<<endl;
                            if(a[1]!=0)
                                cout<<"b"<<endl;
                            if(a[2]!=0)
                                cout<<"c"<<endl;
                        }
                    }
        }
    }
    return 0;
}
