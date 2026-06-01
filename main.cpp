#include <iostream>
#include <vector>

using namespace std;

void findKnightPaths(int r, int c, int movesLeft, vector<int> pathRows,
                     vector<int> pathCols, vector<vector<int>>& boardCounts,
                     vector<int>& rowMoves, vector<int>& colMoves)
{
  if (r < 0 || r >= 8 || c < 0 || c <= 8) {
    return;
  }

  pathRows.push_back(r);
  pathCols.push_back(c);
}

int main()
{
}
