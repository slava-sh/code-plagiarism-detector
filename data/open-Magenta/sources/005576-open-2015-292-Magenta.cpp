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

#define RIGHT_1 0
#define UP      1
#define RIGHT_2 2
#define DOWN    3

int main()
{
	std::ios_base::sync_with_stdio(false);
	int32_t cur_direction = RIGHT_1;
	uint32_t left = 1;
	uint32_t prev_left = 1;
	
	char s[4] = {'R', 'U', 'R', 'D'};
	
	while (true)
	{
		if (left == 0)
		{
			prev_left++;
			left = prev_left;
			cur_direction = (cur_direction + 1) % 4;
		}
		
		cout << s[cur_direction] << endl;
		left--;
		
		cout.flush();
		char c = input<char>();
		if (c == 'N')
			continue;
		else
			break;
	}
	
	return 0;
}
