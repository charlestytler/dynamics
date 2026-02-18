#include "integration/rk4.hpp"
#include "integration/simulate.hpp"
#include "models/kinematic_bicycle.hpp"
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace model = models::kinematic_bicycle;
using T = double;

using State = model::State<T>;
using Input = model::Input<T>;
using Parameters = model::Parameters<T>;

void bind_step(py::module_ &m) {
  m.def(
      "rk4_step",
      [](const State &x, const Input &u, const Parameters &p, double dt) {
        return rk4::step(model::dynamics<T>, x, u, p, dt);
      },
      py::arg("x"), py::arg("u"), py::arg("params"), py::arg("dt"),
      "Simulate the model one integration step");
}

void bind_simulate(py::module_ &m) {
  m.def(
      "simulate",
      [](const State &x, const Input &u, const Parameters &p, double t0,
         double tf, double dt) {
        return simulate(model::dynamics<T>, x, u, p, t0, tf, dt);
      },
      py::arg("x"), py::arg("u"), py::arg("params"), py::arg("t0"),
      py::arg("tf"), py::arg("dt"), "Simulate the model using RK4 integration");
}
