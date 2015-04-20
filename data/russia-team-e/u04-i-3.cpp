#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("sochi.in");
    int n, d;
    in >> n >> d;
    int s = 0;
    int input;
    for(int i = 0; i < n; ++i)
    {
        in >> input;
        if((i!=0 && i!=(n-1) && input >= d*3) || input >= d*2)
            s+=input;
    }
    s-=(d*2)*n;
    s+=d*2;
    ofstream out;
    out.open("sochi.out");
    out << s;
    return 0;
}
