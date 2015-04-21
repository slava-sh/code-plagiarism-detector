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
            cout<<"R"<<endl;
            cin>>p;
            if(p=='N')
            {
                cout<<"R"<<endl;
                cin>>p;
                int x=0;
                while(p=='N')
                {
                    if(x==22)
                    {
                        cout<<"R"<<endl;
                        x++;
                    }
                    else
                        if(x%2==0)
                            cout<<"U"<<endl;
                        else
                            cout<<"R"<<endl;
                    x++;
                    cin>>p;
                }
            }
        }
    }
    return 0;
}
