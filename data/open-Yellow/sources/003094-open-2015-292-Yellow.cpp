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
#include <map>
#include <set>
#include <stack>
#include <utility>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;
using std::map;
using std::set;
using std::stack;

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

int main()
{
	uint32_t n = input<uint32_t>();
	uint32_t log_n = 1;
	while ((1u << log_n) < n)
		log_n++;
	uint32_t e_n = 1 << log_n;
	// e_n >= 2.
	
	vector<int32_t> data(e_n, INT32_MAX);
	for (uint32_t i = 0; i < n; i++)
		data[i] = input<int32_t>();
	
	vector<uint32_t> segtree(2 * e_n - 1, 1);
	vector<pair<uint32_t, uint32_t>> indexes(2 * e_n - 1);
	for (uint32_t i = e_n - 1; i < 2 * e_n - 1; i++)
		indexes[i] = make_pair(i + 1 - e_n, i + 1 - e_n);
	for (uint32_t i = e_n - 2; true; i--)
	{
		indexes[i] = make_pair(indexes[2 * i + 1].first, indexes[2 * i + 2].second);
		segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
		
		if (data[indexes[2 * i + 1].second] == data[indexes[2 * i + 2].first])
			segtree[i]--;
		
		if (i == 0)
			break;
	}
	
	for (uint32_t Q = input<uint32_t>(); Q != 0; Q--)
	{
		uint32_t upd_coord = input<uint32_t>() - 1;
		int32_t  new_val   = input<int32_t> ();
		data[upd_coord] = new_val;
		
		uint32_t tree_coord = upd_coord + e_n - 1;
		while (true)
		{
			if (tree_coord == 0)
				break;
			tree_coord = (tree_coord - 1) / 2;
			
			segtree[tree_coord] = segtree[2 * tree_coord + 1] + segtree[2 * tree_coord + 2];
			
			if (data[indexes[2 * tree_coord + 1].second] == data[indexes[2 * tree_coord + 2].first])
				segtree[tree_coord]--;
		}
		cout << segtree[0] - (n != e_n) << endl;
	}
	
	return 0;
}
