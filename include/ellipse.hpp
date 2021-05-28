#pragma once

#include "internal.hpp"
#include "curve.hpp"

#include <cmath>
#include <stdexcept>


class CURVE_IMPORT_EXPORT CURVE_ALIGN_16 ellipse : public curve {
protected:
    float m_a;
    float m_b;

public:
    ellipse(const float& a, const float& b);

    virtual std::array<float, 3> cartesian_coords(float t) const;
    virtual std::array<float, 3> grad(float t) const;
    virtual ~ellipse() overrride;
};
