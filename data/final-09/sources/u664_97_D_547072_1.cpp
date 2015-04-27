#include <bitset>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef bitset<150> line;

char nch() {
  char ch;
  do {
    scanf("%c", &ch);
  } while (ch <= ' ');
  return ch;
}

void initerc(int& er, int& ec, int width, int height, vector<line>& wall, vector<line>& mask) {
    for (int r = 0; r < height; ++r) {
    for (int c = 0; c < width; ++c) {
      char ch = nch();
      if (ch == 'E') {
        er = r;
        ec = c;
      }
      if (ch == '#') {
        wall[r].set(c);
      } else {
        mask[r].set(c);
      }
    }
  }
}

int main() {
  int height, width, numQueries;
  scanf("%d", &height);
  scanf("%d", &width);
  scanf("%d", &numQueries);
  vector<line> mask(height);
  vector<line> wall(height);
  int er = -1, ec = -1;
  initerc(er, ec, width, height, wall, mask);
  vector<line> needMask(height);
  needMask[er].set(ec);
  int qId;
  for (qId = 0; qId <= numQueries; ++qId) {
    if (needMask == mask) break;
    if (qId < numQueries) {
      char ch = nch();
      switch (ch) {
        case 'L':
      for (int r = 0; r < height; ++r) {
        line tmp = mask[r];
        tmp >>= 1;
        line cross = tmp & wall[r];
        tmp ^= cross;
        cross <<= 1;
        tmp |= cross;
        mask[r] = tmp;
      }
      break;
    case 'R':
      for (int r = 0; r < height; ++r) {
        line tmp = mask[r];
        tmp <<= 1;
        line cross = tmp & wall[r];
        tmp ^= cross;
        cross >>= 1;
        tmp |= cross;
        mask[r] = tmp;
      }
      break;
    case 'U':
      for (int r = 1; r < height; ++r) {
        mask[r - 1] = mask[r];
      }
      for (int r = height - 2; r >= 0; --r) {
        line tmp = mask[r];
        line cross = tmp & wall[r];
        tmp ^= cross;
        mask[r + 1] |= cross;
        mask[r] = tmp;
      }
      break;
    case 'D':
      for (int r = height - 2; r >= 0; --r) {
        mask[r + 1] = mask[r];
      }
      for (int r = 1; r < height; ++r) {
        line tmp = mask[r];
        line cross = tmp & wall[r];
        tmp ^= cross;
        mask[r - 1] |= cross;
        mask[r] = tmp;
      }
      break;
      }
    }
  }
  if (qId > numQueries) qId = -1;
  printf("%d\n", qId);
  return 0;
}
