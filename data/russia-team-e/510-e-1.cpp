#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

const int N = 128;
const int M = 15;

char mas[N][N][M];
char country[N][M];

#define pb push_back
typedef int old_int;
//#define int long long

int n;

void format(char num[], int i, int j)
{
    if (i - j == 7)
    {
        printf("%c%c%c-%c%c-%c%c\n", num[j], num[j + 1], num[j + 2], num[j + 3], num[j + 4], num[j + 5], num[j + 6]);
    }
    else if (i - j == 6)
    {
        printf("%c%c-%c%c-%c%c\n", num[j], num[j + 1], num[j + 2], num[j + 3], num[j + 4], num[j + 5]);
    }
    else if (i - j == 5)
    {
        printf("%c%c%c-%c%c\n", num[j], num[j + 1], num[j + 2], num[j + 3], num[j + 4]);
    }
    else if (i - j == 4)
    {
        printf("%c%c-%c%c\n", num[j], num[j + 1], num[j + 2], num[j + 3]);
    }
    else if (i - j == 3)
    {
        printf("%c%c%c\n", num[j], num[j + 1], num[j + 2]);
    }
}

int print(char cnt[], char op[], char num[])
{
    printf("+%s(%s)", cnt, op);

   // char numb_str[20];
   // char cntr[10];

   // itoa(op, cntr, 10);

    int j = 0;

    j = strlen(cnt);

   // itoa(cnt, cntr, 10);

    j += strlen(op);

//    itoa(num, numb_str, 10);

    int i = strlen(num);

    format(num, i, j);
}

int new_check(char cntr[], char op[], char numb_str[])
{
    if (cntr[0] == '0')
        return 0;
    if (op[0] == '0')
        return 0;

  //  itoa(num, numb_str, 10);
  //  itoa(cnt, cntr, 10);

    int j = strlen(cntr);

 //   itoa(op, cntr, 10);

    int i;

    for (i = 0; op[i]; i++)
        if (op[i] != numb_str[i + j])
            return 0;

    if (numb_str[j + strlen(op)] == '0')
        return 0;


    return 1;
}

int check(char numb[])
{
    int i, j;

   // char numb_str[20];
   // char cntr[10];

  //  itoa(a, numb_str, 10);

   // cerr << numb << endl;

    bool flag = 0;

    for (i = 1; i <= n; i++)
    {
     //   itoa(country[i], cntr, 10);

        flag = true;

        for (j = 0; country[i][j]; j++)
          if (numb[j] != country[i][j])
          {
              flag = false;
          }

        if (!flag)
            continue;

        for (j = 0; j < N; j++)
        {
            if (mas[i][j][0] == 0)
                break;

            if (new_check(country[i], mas[i][j], numb))
            {
                print(country[i], mas[i][j], numb);
                return 0;
            }
        }
    }

    printf("Incorrect\n");
    return 0;
}

old_int main()
{
    freopen("numbers.in", "rt", stdin);
    freopen("numbers.out", "w", stdout);


    int c, k;

    int m;

    int i, j;

    cin >> n;

    char temp[M];

    for (i = 1; i <= n; i++)
    {
        cin >> country[i];

        cin >> k;

        for (j = 0; j < k; j++)
        {
            cin >> mas[i][j];
        }
    }

 // for (i = 1; i <= n; i++)
  //
  //      for (j = 0; j <k; j++)
  //       cout << mas[i][j] << endl;
  //}

    char numb[M];

    cin >> m;

    for (i = 1; i <= m; i++)
    {
        cin >> numb;

        check(numb);
    }

    return 0;
}
