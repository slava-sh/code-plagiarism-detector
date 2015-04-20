#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int strhash(string str, int size)
{
    int h = 0;
    for(int i = 0; i < str.size(); i++)
    {
        h += (int)str[i]*256;
        h %= size;
    }
    return h;
}

struct Pep
{
    string str1;
    string str2;
    string str3;
};

struct Data
{
    string str;
    int n;
};

vector<Data> hash[48619];
void add(string str)
{
    int h = strhash(str, 48619);
    bool was = false;
    for(int i = 0; i < hash[h].size(); i++)
    {
        if(hash[h][i].str == str)
        {
            was = true;
            hash[h][i].n++;
        }
    }
    if(!was)
    {
        Data data1;
        data1.str = str;
        data1.n = 1;
        hash[h].push_back(data1);
    }
}

Data hash_find(string str)
{
    int h = strhash(str, 48619);
    Data notFound;
    notFound.str = "";
    notFound.n = -1;
    for(int i = 0; i < hash[h].size(); i++)
    {
        if(hash[h][i].str == str)
        {
            return hash[h][i];
        }
    }
    return notFound;
}

int main()
{
    ifstream in("names.in");
    ofstream out("names.out");

    int n;
    in >> n;

    Pep pep[1001];
    for(int i = 0; i < n; i++)
    {
        string str1, str2, str3;
        in >> str1 >> str2 >> str3;
        pep[i].str1 = str1;
        pep[i].str2 = str2;
        pep[i].str3 = str3;

        add(str1);
        add(str2);
        add(str3);
    }

    for(int i = 0; i < n; i++)
    {
        Data found = hash_find(pep[i].str1);
        if(found.n != 1)
        {
            string tmp = pep[i].str1;
            pep[i].str1 = pep[i].str3;
            pep[i].str3 = pep[i].str2;
            pep[i].str2 = tmp;
        }
    }

    for(int i = 0; i < n-1; i++)
    {
        for(int k = i+1; k < n; k++)
        {
            if(pep[i].str1 > pep[k].str1)
            {
                Pep tmp = pep[i];
                pep[i] = pep[k];
                pep[k] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        out << pep[i].str1 << " " << pep[i].str2 << " " << pep[i].str3 << endl;
    }



    return 0;
}
