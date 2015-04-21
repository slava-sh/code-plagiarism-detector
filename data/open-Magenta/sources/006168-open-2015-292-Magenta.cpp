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
	std::ios_base::sync_with_stdio(false);
	int32_t cur_direction = +1;
	uint32_t left = 1;
	uint32_t prev_left = 1;
	
	while (true)
	{
		if (left != 0)
		{
			if (cur_direction == +1)
				cout << "R\n";
			else
				cout << "L\n";
			left--;
		}
		else
		{
			cout << "U\n";
			prev_left = 2 * prev_left;
			left = prev_left;
			cur_direction = -cur_direction;
		}
		
		cout.flush();
		char c = input<char>();
		if (c == 'N')
			continue;
		else
			break;
	}
	
	return 0;
}
