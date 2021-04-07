#pragma once

#include "ellipse.hpp"


class CURVE_IMPORT_EXPORT CURVE_ALIGN_16 circle : public ellipse {
public:
	circle(const float& R);

	float R() const;
};