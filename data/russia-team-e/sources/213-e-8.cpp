#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
struct country
{
    string code;
    vector<string> op_code;
    country(){};
    country(string a, vector<string> b){code = a, op_code = b;};
};
vector<country> countries;
string split(string s)
{
    //cout << s << endl;
    if(s.size() == 3)
        return s;
    if(s.size() == 4)
    {
        string tmp = "";
        tmp += s[0];
        tmp += s[1];
        tmp += "-";
        tmp += s[2];
        tmp += s[3];
        return tmp;
    }
    if(s.size() == 5)
    {
         string tmp = "";
        tmp += s[0];
        tmp += s[1];
        tmp += s[2];
        tmp += "-";
        tmp += s[3];
        tmp += s[4];
        return tmp;
    }
    if(s.size() == 6)
    {
        string tmp = "";
        tmp += s[0];
        tmp += s[1];
        tmp += "-";
        tmp += s[2];
        tmp += s[3];
        tmp += "-";
        tmp += s[4];
        tmp += s[5];
        return tmp;
    }
    if(s.size() == 7)
    {
        string tmp = "";
        tmp += s[0];
        tmp += s[1];
        tmp += s[2];
        tmp += "-";
        tmp += s[3];
        tmp += s[4];
        tmp += "-";
        tmp += s[5];
        tmp += s[6];
        return tmp;
    }
}
int main()
{
    ifstream cin("numbers.in");
   ofstream cout("numbers.out");
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        string code;
        int cnt;
        cin >> code >> cnt;
        vector<string> codes;
        for(int j = 0; j < cnt; ++j)
        {
            string s;
            cin >> s;
            codes.push_back(s);
        }
        countries.push_back(country(code, codes));
    }
    int m;
    cin >> m;

    for(int i = 0; i < m; ++i)
    {
            bool ok = false;
        string curr_number;
        cin >> curr_number;
        for(vector<country>::iterator curr_country = countries.begin(); curr_country != countries.end(); curr_country++)
        {
            bool good_country = true;
            for(int pos = 0; pos < curr_country->code.size(); ++pos)
                if(curr_number[pos] != curr_country->code[pos])
                    good_country = false;
            if(!good_country)
                continue;
            for(vector<string>::iterator curr_code = curr_country->op_code.begin(); curr_code !=curr_country->op_code.end(); curr_code++)
            {
                for(int pos = 0; pos < curr_code->size(); ++pos)
                {
                    bool good_code = true;
                    if(curr_number[(curr_country->code).size() + pos] != (*curr_code)[pos])
                        good_code = false;
                    if(curr_number[curr_country->code.size() + curr_code->size()] == '0')
                        good_code = false;
                    if(!good_code)
                        break;
                    string tmp = "";
                    for(int p = (curr_country->code).size() + curr_code->size(); p < curr_number.size(); ++p)
                    {
                        tmp +=curr_number[p];
                    }
                    cout << "+" +curr_country->code + "(" + *curr_code + ")" + split(tmp) << endl;
                    ok = true;
                }
            }
        }
       // cout << ok << endl;
        if(!ok)
        {
            cout << "Incorrect" << endl;
        }
    }
    return 0;
}
