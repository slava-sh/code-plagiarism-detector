#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream in("numbers.in");
ofstream out("numbers.out");

int main()
{
    size_t n;
    in >> n;

    vector <string> countries(n);
    vector < vector <string> > codes(n);
    size_t amountOfCodes;

    for (size_t i = 0; i != n; ++i)
    {
        in >> countries[i] >> amountOfCodes;
        codes[i].resize(amountOfCodes);

        for (size_t j = 0; j != amountOfCodes; ++j)
        {
            in >> codes[i][j];
        }
    }

    size_t phones;
    string phone;

    in >> phones;

    for (size_t i = 0; i != phones; ++i)
    {
        in >> phone;

        for (size_t j = 0; j != n; ++j)
        {
            size_t currStart = 0;
            for (; currStart != countries[j].length(); ++currStart)
            {
                if (phone[currStart] != countries[j][currStart])
                {
                    goto nextCounry;
                }
            }

            size_t check;

            for (size_t k = 0; k != codes[j].size(); ++k)
            {
                for (check = 0; check != codes[j][k].length(); ++check)
                {
                    if (phone[currStart + check] != codes[j][k][check])
                    {
                        goto nextCode;
                    }
                }

                if (phone[currStart + check] == '0')
                {
                    goto nextCode;
                }

                out << "+" << countries[j] << "(" << codes[j][k] << ")";

                size_t done = countries[j].length() + codes[j][k].length();

                if (done == 4)
                {
                    out << phone[4] << phone[5] << phone[6] << "-" << phone[7] << phone[8] << "-" << phone[9] << phone[10];
                }
                else if (done == 5)
                {
                    out << phone[5] << phone[6] << "-" << phone[7] << phone[8] << "-" << phone[9] << phone[10];
                }
                else if (done == 6)
                {
                    out << phone[6] << phone[7] << phone[8] << "-" << phone[9] << phone[10];
                }
                else if (done == 7)
                {
                    out << phone[7] << phone[8] << "-" << phone[9] << phone[10];
                }
                else if (done == 8)
                {
                    out << phone[8] << phone[9] << phone[10];
                }

                out << "\n";

                goto nextPhone;

                nextCode: {}
            }

nextCounry: {}
        }

        out << "Incorrect\n";

nextPhone: {}
    }

    in.close();
    out.close();

    return 0;
}