#include "helix.hpp"

using namespace std;


helix::helix(const float& a, const float& b, const float& c) : ellipse(a, b), m_c(c) {
    if (m_c < 0.f)
        throw std::logic_error("invalid parametr c");
}

array<float, 3> helix::cartesian_coords(float t) const {
    array<float, 3> result = ellipse::cartesian_coords(t);

    result[2] = m_c * t;

    return result;
}

array<float, 3> helix::grad(float t) const {
    array<float, 3> result = ellipse::grad(t);

    result[2] = m_c;

    return result;
}