#pragma once

namespace euler {

template <typename Function, typename State, typename Input, typename Params,
          typename T>
State step(const Function &f, const State &x, const Input &u, const Params &p,
           const T dt) {
  const auto xdot = f(x, u, p);

  return x + xdot * dt;
}

} // namespace euler
