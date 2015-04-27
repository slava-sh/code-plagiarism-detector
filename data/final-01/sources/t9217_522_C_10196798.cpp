#include <cstdio>
#include <iostream>

using namespace std;

int serves[100000];
int last[100000];
bool isEmpty[100000];

struct client
{
    int serve;
    bool unhappy;
} clients[100000];

void exec()
{
    int m, k;
    cin >> m >> k;
    --m;
    //int *serves = new int[k];
    for (int i = 0; i < k; ++i)
    {
        cin >> serves[i];
        last[i] = -1;
        isEmpty[i] = false;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> clients[i].serve >> clients[i].unhappy;
        --clients[i].serve;
        if (clients[i].serve >= 0)
            last[clients[i].serve] = i;
    }
    int threshold = 0;
    bool noEmptyServe = true;
    for (int i = 0; i < m; ++i)
    {
        if (clients[i].unhappy && noEmptyServe)
        {
            int reserve = -1;
            for (int j = 0; j < k; ++j)
            {
                if (last[j] < i)
                {
                    if (serves[j] <= threshold)
                        isEmpty[j] = true;
                    if (reserve < 0 || reserve > serves[j])
                        reserve = serves[j];
                }
            }
            threshold -= reserve;
            noEmptyServe = false;
        }
        if (clients[i].serve >= 0)
        {
            --serves[clients[i].serve];
        }
        else
        {
            ++threshold;
        }
    }
    for (int i = 0; i < k; ++i)
    {
        if (serves[i] <= threshold || isEmpty[i])
            cout << 'Y';
        else
            cout << 'N';
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        if (i)
            cout << endl;
        exec();
    }
    /*
#ifdef _DEBUG
    {
        char x;
        cin >> x;
    }
#endif
    */
    return 0;
}