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

  if (movesLeft == 0) {
    for (int i = 0; i < pathRows.size(); i++) {
      cout << "(" << pathRows.at(i) << ", " << pathCols.at(i) << ")";
      if (i < pathRows.size() - 1) {
        cout << "-> ";
      }
    }
    cout << "\n";
  }
  for (int i = 0; i < 8; i++) {
    int nextRow = r + rowMoves.at(i);
    int nextCol = c + colMoves.at(i);

    findKnightPaths(nextRow, nextCol, movesLeft - 1, pathRows, pathCols,
                    boardCounts, rowMoves, colMoves);
  }
}

int main()
{
  int row, col, N;
  cout << "Enter starting row (0-7): ";
  cin >> row;
  cout << "Enter starting column (0-7): ";
  cin >> col;
  cout << "Enter number of moves: ";
  cin >> N;

  vector<int> rowMoves = {-2, -2, -1, -1, 1, 1, 2, 2};
  vector<int> colMoves = {-1, 1, -2, 2, -2, 2, -1, 1};

  vector<vector<int>> boardCounts(8, vector<int>(8, 0));
}
