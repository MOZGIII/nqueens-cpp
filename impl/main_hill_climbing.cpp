#include "common_head.cpp"

int main(int argc, char const *argv[])
{
  std::srand(std::time(0));

  Problem p;

  // Warning!!! This does not work since currentNode implementation
  // chooses _random_ succesor, not the _best_ one.
  state_t val(HillClimbing<state_t, Node>(p));

  std::cout << val << std::endl;
  return 0;
}
