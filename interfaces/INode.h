#pragma once

template<class TState, class TValue = int>
class INode
{
public:
  virtual INode<TState> * next() const = 0;
  virtual TState state() const = 0;
  virtual TValue value() const = 0;
};
