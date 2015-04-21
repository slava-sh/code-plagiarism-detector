#include <iostream>

using namespace std;

int A, B, n;
int x[400][400];
int y[400][400];
int L[400];

double h(int x1, int y1, int x2, int y2, int x, int y)
{
    double a = y2 - y1;
    double b = x1 - x2;
    double c = -(a * x1 + b * y1);
    return y - ((-c - a * x) / b);
}

int sign(double x)
{
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

bool intersects(int a, int b)
{
    int sgn = sign(y[a][0] - y[b][0]);
    int i2 = 0;
    for (int i1 = 0; i1 < L[a]; i1++)
    {
        while (x[b][i2 + 1] < x[a][i1])
        {
            i2++;
        }
        double dist = h(x[b][i2], y[b][i2], x[b][i2 + 1], y[b][i2 + 1], x[a][i1], y[a][i1]);
        if (sign(dist) == -sgn && sgn != 0 && sign(dist) != 0)
        {
            return true;
        }
        else if (sgn == 0)
        {
            sgn = sign(dist);
        }
    }

    int t = a; a = b; b = t;
    sgn = sign(y[a][0] - y[b][0]);
    i2 = 0;
    for (int i1 = 0; i1 < L[a]; i1++)
    {
        while (x[b][i2 + 1] < x[a][i1])
        {
            i2++;
        }
        double dist = h(x[b][i2], y[b][i2], x[b][i2 + 1], y[b][i2 + 1], x[a][i1], y[a][i1]);
        if (sign(dist) == -sgn && sgn != 0 && sign(dist) != 0)
        {
            return true;
        }
        else if (sgn == 0)
        {
            sgn = sign(dist);
        }
    }

    return false;
}

int main()
{
    cin >> A >> B >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
        L[i]++;
        for (int j = 0; j < L[i]; j++)
        {
            cin >> x[i][j] >> y[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (intersects(i, j))
            {
                cout << "No" << endl << (i + 1) << " " << (j + 1);
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
