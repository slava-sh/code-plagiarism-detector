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
#include <cmath>

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

// returns
// -1: if a below b
//  0: if a strictly equals to b.
// +1: if a over b
//  2: if collide.
int32_t compare_two(vector<pair<int32_t, int32_t>>& a, vector<pair<int32_t, int32_t>>& b)
{
	int32_t cur_state;
	if (a[0].second == b[0].second)
		cur_state = 0;
	if (a[0].second < b[0].second)
		cur_state = -1;
	if (a[0].second > b[0].second)
		cur_state = +1;
	
	// two pointer method.
	uint32_t p_a = 1;
	uint32_t p_b = 1;
	while (p_a < a.size() and p_b < b.size()) // this two conditions will break together only
	{
		long double func_on_a;
		long double func_on_b;
		if (a[p_a].first == b[p_b].first)
		{
			func_on_a = a[p_a].second;
			func_on_b = b[p_b].second;
			
			p_a++;
			p_b++;
		}
		else if (a[p_a].first > b[p_b].first)
		{
			func_on_b = b[p_b].second;
			long double interpol_factor = 1.0L * (b[p_b].first - a[p_a - 1].first) / (a[p_a].first - a[p_a - 1].first);
			func_on_a = interpol_factor * a[p_a].second + (1 - interpol_factor) * a[p_a - 1].second;
			
			p_b++;
		}
		else if (a[p_a].first < b[p_b].first)
		{
			func_on_a = a[p_a].second;
			long double interpol_factor = 1.0L * (a[p_a].first - b[p_b - 1].first) / (b[p_b].first - b[p_b - 1].first);
			func_on_a = interpol_factor * b[p_b].second + (1 - interpol_factor) * b[p_b - 1].second;
			
			p_a++;
		}
		
		long double eps = 1e-7;
		if (std::abs(func_on_a - func_on_b) <= eps)
		{
			// equal, cur_state not changes.
		}
		else if (func_on_a < func_on_b)
		{
			if (cur_state <= 0)
				cur_state = -1;
			else
				return 2;
		}
		else
		{
			if (cur_state >= 0)
				cur_state = +1;
			else
				return 2;
		}
	}
	return cur_state;
}

pair<uint32_t, uint32_t> algo(vector<pair<uint32_t, vector<pair<int32_t, int32_t>>>>& data)
{
	// like qsort.
	if (data.size() <= 1)
		return make_pair(UINT32_MAX, UINT32_MAX);
	
	// let [0] be separator.
	vector<pair<uint32_t, vector<pair<int32_t, int32_t>>>> less;
	vector<pair<uint32_t, vector<pair<int32_t, int32_t>>>> greater;
	
	for (uint32_t i = 1; i < data.size(); i++)
	{
		int32_t r = compare_two(data[0].second, data[i].second);
		if (r == 2)
			return make_pair(data[0].first, data[i].first);
		if (r == -1)
			less.push_back(std::move(data[i]));
		if (r == +1)
			greater.push_back(std::move(data[i]));
	}
	
	data.clear();
	data.shrink_to_fit();
	
	auto res = algo(less);
	if (res.first != UINT32_MAX)
		return res;
	res = algo(greater);
	if (res.first != UINT32_MAX)
		return res;
	return make_pair(UINT32_MAX, UINT32_MAX);
}

int main()
{
	int32_t A = input<int32_t>();
	int32_t B = input<int32_t>();
	
	vector<pair<uint32_t, vector<pair<int32_t, int32_t>>>> data(input<uint32_t>());
	for (uint32_t i = 0; i < data.size(); i++)
	{
		data[i].first = i + 1;
		data[i].second.resize(input<uint32_t>() + 1);
		
		for (pair<int32_t, int32_t>& z: data[i].second)
		{
			z.first  = input<int32_t>();
			z.second = input<int32_t>();
		}
	}
	
	pair<uint32_t, uint32_t> ans = algo(data);
	if (ans.first == UINT32_MAX)
		cout << "Yes\n";
	else
		cout << "No\n" << ans.first << " " << ans.second << "\n";
	return 0;
}
