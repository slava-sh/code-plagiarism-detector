#include <iostream>

using namespace std;

int main()
{
    cout<<"R"<<endl;
    char p;
    cin>>p;
    int k=5999;
    while(p=='N')
    {
        if(k==0)
        {
            cout<<"U";
            k=6000;
        }
        else
            cout<<"R";
        cout<<endl;
        cin>>p;
    }
    return 0;
}
