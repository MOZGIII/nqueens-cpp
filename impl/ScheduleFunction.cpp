#include "interfaces/IScheduleFunction.h"

class ScheduleFunction : public IScheduleFunction<double>
{
public:
  double operator()(unsigned long long t) const
  {
    return 1.0 / t;
  }

  bool zero(const double& temperature) const
  {
    return temperature < 0.001;
  }
};
