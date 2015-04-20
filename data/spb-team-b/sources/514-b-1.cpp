#include <fstream>
#define MAX 1000

using namespace std;

int main()
{
    int n, buff[MAX], answer = 0;
    ifstream in ("chess.in");
    in>>n;
    for (int i = 0; i < n; i++)
        in>>buff[i];
    in.close();
    for (int i = 0; i < n; i++)
    {
        answer++;
        if (!((i + 1) < buff[i + 1] and (i + 1) != n))
            break;
    }
    ofstream out ("chess.out");
    out<<answer<<endl;
    for(; answer != 0; answer--)
        out<<answer<<' '<<answer<<endl;
    out.close();
    return 0;
}
