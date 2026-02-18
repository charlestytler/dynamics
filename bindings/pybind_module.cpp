#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_simulate(py::module_ &m);
// void bind_integration(py::module_ &);

PYBIND11_MODULE(dynamics, m) {
  m.doc() = "Dynamics library bindings";

  bind_simulate(m);
  // bind_integration(m);
}
