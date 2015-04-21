// This program is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License fqor more details.
//
// You should have received a copy of the GNU General Public License and
// along with this program If not, see http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <stdint.h>
#include <queue>
#include <utility>
#include <set>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;
using std::queue;
using std::set;

using std::min;
using std::max;

using std::pair;
using std::make_pair;


template <typename T>
T input()
{
	T ans;
	cin >> ans;
	return ans;
}
template <typename T>
T smart_abs(T a, T b)
{
	return a >= b ? a - b : b - a;
}

struct road_t
{
	uint32_t to;
	int32_t temp;
};

int main()
{
	uint32_t n = input<uint32_t>();
	uint32_t m = input<uint32_t>();
	uint32_t d = input<uint32_t>();
	
	
	vector<vector<road_t>> map(n);
	for (uint32_t i = 0; i < m; i++)
	{
		uint32_t from = input<uint32_t>() - 1;
		uint32_t to   = input<uint32_t>() - 1;
		int32_t  temp = input<int32_t>();
		map[from].emplace_back(road_t {to, temp});
		map[to].emplace_back(road_t {from, temp});
	}
	
	
	for (uint32_t q = input<uint32_t>(); q != 0; q--)
	{
		// bfs.
		vector<vector<bool>> visited(n);
		for (uint32_t i = 0; i < n; i++)
			visited[i] = vector<bool>(map[i].size(), false);
		queue<pair<uint32_t, int32_t>> the_queue;
		the_queue.emplace(input<uint32_t>() - 1, INT32_MAX);
		the_queue.emplace(UINT32_MAX, INT32_MAX);
		uint32_t targ = input<uint32_t>() - 1;
		uint32_t cur_dist = 0;
		
		while (!the_queue.empty())
		{
			auto cur = the_queue.front();
			the_queue.pop();
			if (cur.first == UINT32_MAX)
			{
				if (the_queue.empty())
					break;
				
				cur_dist++;
				the_queue.emplace(UINT32_MAX, INT32_MAX);
			}
			else if (cur.first == targ)
			{
				cout << cur_dist << endl;
				goto end;
			}
			else
			{
				if (cur.second == INT32_MAX) // just visit all
				{
					for (uint32_t i = 0; i < map[cur.first].size(); i++)
					{
						road_t r = map[cur.first][i];
						if (visited[cur.first][i] == false)
						{
							visited[cur.first][i] = true;
							the_queue.emplace(r.to, r.temp);
						}
					}
				}
				else
				{
					auto cmp = [](const road_t a, const road_t b){return a.temp < b.temp;};
					auto lower = std::lower_bound(map[cur.first].begin(), map[cur.first].end(), road_t {UINT32_MAX, cur.second - d}, cmp);
					auto upper = std::upper_bound(map[cur.first].begin(), map[cur.first].end(), road_t {UINT32_MAX, cur.second + d}, cmp);
					for (auto it = lower; it != upper; ++it)
					{
						road_t r = *it;
						if (visited[cur.first][it - map[cur.first].begin()] == false)
						{
							visited[cur.first][it - map[cur.first].begin()] = true;
							the_queue.emplace(r.to, r.temp);
						}
					}
				}
			}
		}
		
		cout << "-1\n";
		end:;
	}
	return 0;
}