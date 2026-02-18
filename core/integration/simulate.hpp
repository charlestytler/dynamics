#include "rk4.hpp"

template <typename Function, typename State, typename Input, typename Params,
          typename T>
State simulate(const Function &f, const State &x, const Input &u,
               const Params &params, const T t0, const T tf, const T dt) {
  State x_next;
  auto t = t0;
  while (t < tf) {
    x_next = rk4::step(f, x, u, params, dt);
    t += dt;
  }
  return x_next;
}
