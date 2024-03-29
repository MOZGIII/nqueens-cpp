#include "NQueens.cpp"

int main(int argc, char const *argv[])
{
  NQueens::board_t board = 16434824; // 7 6 5 4 3 2 1 0

  std::cout << "Score: " << NQueens::score(board) << std::endl;
  NQueens::printBoard(std::cout, board);
  NQueens::drawBoard(std::cout, board);

  for (int i = 0; i < 8; ++i)
  {
    NQueens::setHeight(board, i, (i + 4) & 0xF);
  }

  std::cout << "Score: " << NQueens::score(board) << std::endl;
  NQueens::printBoard(std::cout, board);
  NQueens::drawBoard(std::cout, board);

  for (int i = 0; i < 8; ++i)
  {
    NQueens::setHeight(board, i, i);
  }

  std::cout << "Score: " << NQueens::score(board) << std::endl;
  NQueens::printBoard(std::cout, board);
  NQueens::drawBoard(std::cout, board);


  // Solved board:
  const NQueens::board_t solved_board = 6761440; // 3 1 6 2 5 7 4 0
  std::cout << "Score: " << NQueens::score(solved_board) << std::endl;
  NQueens::printBoard(std::cout, solved_board);
  NQueens::drawBoard(std::cout, solved_board);

  return 0;
}
