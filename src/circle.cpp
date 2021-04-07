#include "circle.hpp"

using namespace std;


circle::circle(const float& R) : ellipse(R, R) { };

float circle::R() const {
	return m_a;
}