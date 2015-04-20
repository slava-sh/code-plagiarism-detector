#include <iostream>
#include <stdio.h>

using namespace std;

static FILE* inFile = fopen("seq.in", "r");
static FILE* outFile = fopen("seq.out", "w");

int main()
{
    int n, h, res = -1, tempres;
    fscanf(inFile, "%d %d", &n, &h);
    int* nums = new int[n];
    for(int i = 0; i < n; i++)
        fscanf(inFile, "%d", &(nums[i]));

    for(int i = 0; i < (n - h + 1); i++)
    {
        tempres = 0;
        for(int i2 = 1; i2 <= h; i2++)
        {
            if(nums[i2 - 1 + i] > i2)
            {
                tempres = -1;
                break;
            }
            tempres += (i2 - nums[i2 - 1 + i]);
        }
        if(tempres != -1 && ((tempres < res) || (res == -1))) res = tempres;
    }

    fprintf(outFile, "%d", res);

    return 0;
}
