#include <iostream>

using namespace std;

int main()
{
    cout<<"U"<<endl;
    char p;
    cin>>p;
    int k=1;
    int f=1;
    int a=1;
    while(p=='N')
    {
        if(f==0)
        {
            a++;
            a%=4;
            if(a%2==0)
                k++;
            f=k;
        }
        f--;
        if(a==0)
            cout<<"U";
        else
            if(a==1)
                cout<<"R";
            else
                if(a==2)
                    cout<<"D";
                else
                    cout<<"L";
        cout<<endl;
        cout.flush();
        cin>>p;
    }
    return 0;
}
