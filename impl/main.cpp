#include "common_head.cpp"

int main(int argc, char const *argv[])
{
  std::srand(std::time(0));

  Problem p;
  ScheduleFunction sf;

  state_t val(SimulatedAnnealing<state_t, Node, ScheduleFunction>(p, sf));

  // std::cout << val << std::endl;
  NQueens::drawBoard(std::cout, val);

  return 0;
}
