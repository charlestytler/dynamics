#include "core/simulate.hpp"
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_simulate(py::module_ &m) {
  m.def("simulate", &simulate, py::arg("x"), py::arg("u"), py::arg("params"),
        py::arg("t0"), py::arg("tf"), py::arg("dt"),
        "Simulate the kinematic bicycle model using Euler integration");
}
