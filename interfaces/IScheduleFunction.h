#pragma once

template<class T>
class IScheduleFunction
{
public:
  virtual T operator()(unsigned long long t) const = 0;
  virtual bool zero(const T& temperature) const = 0;
};
