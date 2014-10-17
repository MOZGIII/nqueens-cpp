#include "interfaces/INode.h"

class Node : public INode<state_t>
{
  state_t _state;

public:
  Node(state_t the_state) : _state(the_state) {}
  virtual ~Node() {}

  Node * next() const
  {
    state_t new_state = _state;
    NQueens::moveRandomQueenRandomly(new_state);
    // std::cout << "Debug new state: from "  << _state  << " to " << new_state << std::endl;
    return new Node(new_state);
  }

  state_t state() const
  {
    return _state;
  }

  // Value is minimized in this task
  int value() const
  {
    const int val = NQueens::max_score - NQueens::score(_state);
    // std::cout << "Debug value: " << val  << " (" << _state << ")" << std::endl;
    return val;
  }
};
