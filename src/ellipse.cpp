#include "ellipse.hpp"

using namespace std;


ellipse::ellipse(const float &a, const float &b) : m_a(a), m_b(b) {
    if (m_a < 0.f)
        throw std::logic_error("invalid parametr a");
    if (m_b < 0.f)
        throw std::logic_error("invalid parametr b");
}

array<float, 3> ellipse::cartesian_coords(float t) const {
    array<float, 3> result;

    result[0] = m_a * cos(t);
    result[1] = m_b * sin(t);
    result[2] = 0.f;

    return result;
}

array<float, 3> ellipse::grad(float t) const {
    array<float, 3> result;

    result[0] = -m_a * sin(t);
    result[1] = m_b * cos(t);
    result[2] = 0.f;

    return result;
}