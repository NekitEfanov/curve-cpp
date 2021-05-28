#pragma once

#include <array>


class curve {

public:
    virtual std::array<float, 3> cartesian_coords(float t) const = 0;
    virtual std::array<float, 3> grad(float t) const = 0;
    virtual ~curve();
};
