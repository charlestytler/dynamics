#include "core/models/kinematic_bicycle.hpp"
#include "core/simulate.hpp"
#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;
using T = double;
namespace model = models::kinematic_bicycle;
using State = model::State<T>;
using Input = model::Input<T>;
using Parameters = model::Parameters<T>;

void bind_simulate(py::module_ &m) {
  m.def("simulate", &simulate, py::arg("x"), py::arg("u"), py::arg("params"),
        py::arg("t0"), py::arg("tf"), py::arg("dt"),
        "Simulate the kinematic bicycle model using Euler integration");
}
