#include <cstdlib>
#include <cmath>

#include "interfaces/IProblem.h"
#include "interfaces/IScheduleFunction.h"

template <class TState, class TNode, class TScheduleFunction>
TState SimulatedAnnealing(const IProblem<TState> &problem, const TScheduleFunction &shedule)
{
  TNode * current(new TNode(problem.initialState()));

  for(unsigned long long t = 0; ; t++) {
    double T = shedule(t);
    if(shedule.zero(T)) {
      TState state = current->state();
      delete current;
      return state;
    }

    TNode * next(current->next());
    auto current_value = current->value();
    auto next_value = next->value();
    // std::cout << "-------------" << std::endl;
    // std::cout << "Current value: " << current_value << std::endl;
    // std::cout << "Next value: " << next_value << std::endl;

    int delta_e = next_value - current_value;
    // std::cout << "Delta: " << delta_e << std::endl;
    if(delta_e > 0) {
      // std::cout << "Direct follow!" << std::endl;
      delete current;
      current = next;
    } else {
      double prob_limit = std::exp(double(delta_e) / T);
      double random_value = double(std::rand()) / RAND_MAX;
      if(random_value < prob_limit) {
        // std::cout << "Random follow: " << random_value << " < " << prob_limit << " = true" << std::endl;
        delete current;
        current = next;
      } else {
        // std::cout << "Random drop: " << random_value << " < " << prob_limit << " = false" << std::endl;
        delete next;
      }
    }
  }
}
