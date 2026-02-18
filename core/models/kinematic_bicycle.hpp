#pragma once
#include <Eigen/Dense>

namespace models {
namespace kinematic_bicycle {

template <typename T> struct Parameters {
  T L; // wheelbase length
};

// x = [x  ] x-position
//     [y  ] y-position
//     [psi] yaw angle
//     [vx ] velocity
template <typename T> using State = Eigen::Matrix<T, 4, 1>;

// u = [delta] steering angle
//     [ax   ] acceleration
template <typename T> using Input = Eigen::Matrix<T, 2, 1>;

template <typename T>
State<T> dynamics(const State<T> &x, const Input<T> &u,
                  const Parameters<T> &params) {
  State<T> xdot;
  // dx = vx * cos(psi)
  // dy = vx * sin(psi)
  // dpsi= (vx / L) * tan(delta)
  // dvx = ax
  xdot[0] = u[0] * std::cos(x[2]);
  xdot[1] = u[0] * std::sin(x[2]);
  xdot[2] = (x[3] / params.L) * std::tan(u[0]);
  xdot[3] = u[1];

  return xdot;
};
} // namespace kinematic_bicycle
} // namespace models
