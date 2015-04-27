#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>

#define pb push_back
#define mp make_pair

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");


int main()
{
    int l;
    in >> l;
    string s;
    in >> s;
    for (int k = 1; k <= l; k++)
    {
        string t = "";
        for (int i = 0; i < k; i++)
            t += s[i];
        if(s.size() % t.size() != 0)
            continue;
        bool f = 0;
        for (int i = 0; i < s.size(); i += t.size())
        {
            string h = "";
            for (int j = i; j < i + t.size(); j++)
                h += s[j];
            if(h != t)
            {
                f = 1;
                break;
            }
        }

        if(!f)
        {
            out << 1 << endl << t;
            return 0;
        }
    }

    out << 2 << endl << "a" << endl << "b";
    return  0;
}


