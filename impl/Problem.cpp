#include "interfaces/IProblem.h"

class Problem : public IProblem<state_t>
{
public:
  state_t initialState() const
  {
    return 0;
  }
};
