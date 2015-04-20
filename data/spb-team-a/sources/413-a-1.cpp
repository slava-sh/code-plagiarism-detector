#include <fstream>

using namespace std;

int main()
{
    ifstream in("abcd.in");
    ofstream out("abcd.out");

    int t;
    in >> t;

    for(int i = 0; i < t; i++)
    {
        int a;
        in >> a;
        int a1, a2;
        a1 = a/100;
        a2 = a%100;
        int r = a1*a1+a2*a2;
        if(r%7 == 1) out << "YES" << endl;
        else out << "NO" << endl;
    }


    return 0;
}
