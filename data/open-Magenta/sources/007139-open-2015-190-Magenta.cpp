#include <iostream>

using namespace std;

int main()
{
    int f=2;
    cout<<"R"<<endl;
    char p;
    cin>>p;
    if(p=='N')
    {
        cout<<"U"<<endl;
        cin>>p;
        if(p=='N')
        {
            cout<<"L"<<endl;
            cin>>p;
            if(p=='N')
            {
                cout<<"L"<<endl;
                cin>>p;
                int x=0;
                while(p=='N')
                {
                    if(x==0)
                    {
                        cout<<"U"<<endl;
                        x=1;
                    }
                    else
                    {
                        cout<<"R"<<endl;
                        x=0;
                    }
                    cin>>p;
                }
            }
        }
    }
    return 0;
}
