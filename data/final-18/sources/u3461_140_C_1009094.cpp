#include <set>
#include <map>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <utility>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

map<int, int> order;
map<int, int> order2number;
vector<int> numbers;
vector<int> counts;
vector<vector<int> > snowmans;
int n;


bool try_ans(int cnt)
{
    // cout << "try_ans(" << cnt << ")" << endl;
    int cur_level = 0, cur_cnt = 0;
    snowmans.assign(n, vector<int>(3, -1));

    for (int i = 0; i < n; ++i)
    {
        if (counts[i] != 0)
        {
            for (int j = 0; j < counts[i]; ++j) { 
                if (cur_level == 0 || snowmans[cur_cnt][cur_level - 1] != i)
                {
                    snowmans[cur_cnt][cur_level] = i;
                    ++cur_cnt;
                } else {
                    break;
                }

                if (cur_cnt == cnt)
                {
                    ++cur_level;
                    cur_cnt = 0;

                    if (cur_level == 3) {
                        return true;
                    }
                }
            }
        } else {
            continue;
        }
    }

    return false;
}

int main(void)
{
    int num, ans = 0, latest = 1;
    int cur_ans, left, right, mid;

    cin >> n;
    counts.assign(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &num);
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    order[numbers[0]] = 0;
    order2number[0] = numbers[0];

    for (int i = 1; i < n; ++i)
    {
        if (numbers[i] != numbers[i - 1])
        {
            order[numbers[i]] = latest;
            order2number[latest] = numbers[i];
            ++latest;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        ++counts[order[numbers[i]]];
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << "counts[" << i << "] = " << counts[i] << endl;
    // }

    
    left = 0; 
    right = n;

    while (right - left > 1)
    {
        mid = left + (right - left) / 2;
        // printf("left is %d\n", left);
        // printf("right is %d\n", right);
        // printf("mid is %d\n", mid);

        if (try_ans(mid))
        {
            // printf("left = %d\n", mid);
            left = mid;
        } else {
            // printf("right = %d\n", mid - 1);
            right = mid - 1;
        }
    }

    // printf("final:\n left = %d\n right = %d \n mid = %d \n", left, right, mid);

    if (try_ans(right))
    {
        mid = right;
    }
    else
    {
        mid = left;
    }

    if (mid == 0)
    {
        cout << 0 << endl;
    } else {
        cout << mid << endl;

        try_ans(mid);

        for (int i = 0; i < mid; ++i) {
            printf("%d %d %d\n", 
                   order2number[snowmans[i][2]], 
                   order2number[snowmans[i][1]], 
                   order2number[snowmans[i][0]]);
        }
    }


    return 0;
}
