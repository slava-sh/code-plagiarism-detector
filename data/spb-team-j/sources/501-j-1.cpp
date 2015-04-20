#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int curr, h, n, globsum = -1, lastsum;

int f (const vector<int> &nums)
{
    int i = curr, min = 200001, sum = 0;

    if (curr + h > n)
        return -1;

    for (; i < curr + h; i++)
    {
        int tmp = i - curr + 1 - nums[i];

        if (nums[i] > 1)
            if (min > tmp)
            {
                min = tmp;
                if (min < 0)
                {
                    curr = i + 1;
                    return -1;
                }
            }

        sum += tmp;
    }

    if (globsum == -1 || sum < globsum)
        globsum = sum;

    lastsum = sum;

    return min;
}

int main ()
{
    FILE *fin, *fout;

    fin = fopen ("seq.in", "rt");
    fout = fopen ("seq.out", "wt");

    fscanf (fin, "%d %d", &n, &h);

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int tmp;

        fscanf (fin, "%d", &tmp);

        nums.push_back (tmp);
    }

    while (curr + h < n)
    {
        if (nums[curr] > 1)
            curr++;
        else
        {
            int res = f (nums);

            if (n - curr - h < res)
                res = n - curr - h;

            while (res > 0)
            {
                lastsum += nums[curr] - nums[curr + h];

                if (lastsum < globsum)
                    globsum = lastsum;

                res--;
                curr++;

                if (curr + h >= n)
                    break;

                if (res < h - nums[curr + h])
                    res = h - nums[curr + h];                
            }
        }
    }

    fprintf (fout, "%d", globsum);

    return 0;
}
