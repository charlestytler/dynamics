#pragma once

namespace rk4 {

template <typename Function, typename State, typename Input, typename Params,
          typename T>
State step(const Function &f, const State &x, const Input &u, const Params &p,
           const T dt) {
  const auto k1 = f(x, u, p);
  const auto k2 = f(x + 0.5 * dt * k1, u, p);
  const auto k3 = f(x + 0.5 * dt * k2, u, p);
  const auto k4 = f(x + dt * k3, u, p);

  return x + dt / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
}
} // namespace rk4
