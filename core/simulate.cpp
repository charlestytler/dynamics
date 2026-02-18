#include "simulate.hpp"
#include "integration/euler.hpp"

model::State<T> simulate(const State &x, const Input &u,
                         const Parameters &params, const T t0, const T tf,
                         const T dt) {
  model::State<T> x_next;
  auto t = t0;
  while (t < tf) {
    x_next = euler::step(model::dynamics<T>, x, u, params, dt);
    t += dt;
  }
  return x_next;
}
