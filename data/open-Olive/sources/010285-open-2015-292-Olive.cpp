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
	// stupid mode on.
	vector<uint32_t> data(input<uint32_t>());
	for (uint32_t& a: data)
		a = input<uint32_t>();
	
	vector<vector<uint32_t>> gr(data.size(), vector<uint32_t>(data.size() + 1, 0));
	for (uint32_t j = 0; j < data.size(); j++)
		gr[0][j] = data[0] > j;
	for (uint32_t i = 1; i < data.size(); i++)
		for (uint32_t j = 0; j <= data.size(); j++)
			gr[i][j] = gr[i - 1][j] + (data[i] > j);
	
	uint32_t best = 0;
	uint32_t best_l, best_r;
	for (uint32_t r = 1; r < data.size(); r++)
		for (uint32_t l = 0; l < r; l++)
			if (data[r] < data[l] and 1 + gr[r][data[r]] + gr[l][data[l]]  > best + gr[r][data[l]] + gr[l][data[r]])
			{
				best = 1 + gr[r][data[r]] + gr[l][data[l]] - gr[r][data[l]] - gr[l][data[r]];
				best_l = l;
				best_r = r;
			}
	if (best == 0)
		cout << "-1 -1\n";
	else
		cout << best_l + 1 << " " << best_r + 1<< endl;
	cerr << best << endl;
	return 0;
}
