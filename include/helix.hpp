#pragma once

#include "curve.hpp"
#include "ellipse.hpp"

#include <cmath>
#include <stdexcept>


class CURVE_IMPORT_EXPORT CURVE_ALIGN_16 helix : public ellipse {
protected:
    float m_c;

public:
    helix(const float& a, const float& b, const float& c);

    virtual std::array<float, 3> cartesian_coords(float t) const;
    virtual std::array<float, 3> grad(float t) const;
    virtual ~helix() override;
};
