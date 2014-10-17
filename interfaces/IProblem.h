#pragma once

template<class State>
class IProblem
{
public:
  virtual State initialState() const = 0;
};
