#include "interfaces/IProblem.h"
#include "interfaces/IScheduleFunction.h"

template <class TState, class TNode>
TState HillClimbing(const IProblem<TState> &problem)
{
  TNode * current(new TNode(problem.initialState()));

  while(true) {
    TNode * neighbor(current->next());
    if(neighbor->value() <= current->value()) {
      delete neighbor;
      auto state = current->state();
      delete current;
      return state;
    }

    delete current;
    current = neighbor;
  }
}
