
#include <fstream>
using namespace std;

int main()
{
    ifstream in;
    in.open("che.in");
    int n, r;
    in >> n >> r;
    int d[n];
    for(int i = 0; i < n; i++)
        in >> d[i];
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(d[j] - d[i] == r)
            {
                answer += n - j;
                break;
            }

        }
    }

    ofstream out;
    out.open("che.out");
    out << answer;
    return 0;
}
