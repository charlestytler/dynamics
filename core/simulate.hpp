#include "models/kinematic_bicycle.hpp"

using T = double;
namespace model = models::kinematic_bicycle;

using State = model::State<T>;
using Input = model::Input<T>;
using Parameters = model::Parameters<T>;

model::State<T> simulate(const State &x, const Input &u,
                         const Parameters &params, const T t0, const T tf,
                         const T dt);
