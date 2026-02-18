#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void bind_step(py::module_ &m);
void bind_simulate(py::module_ &m);

PYBIND11_MODULE(dynamics, m) {
  m.doc() = "Dynamics library bindings";

  bind_step(m);
  bind_simulate(m);
}
