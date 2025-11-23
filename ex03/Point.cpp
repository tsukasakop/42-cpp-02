#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
}

Point::Point(const float x, const float y) : x(x), y(y) {
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
}

Point& Point::operator=(const Point& other) {
	// const属性のため、代入はできないが、Orthodox Canonical Formの要件を満たすため定義
	(void)other;
	return *this;
}

Point::~Point(void) {
}

Fixed Point::getX(void) const {
	return this->x;
}

Fixed Point::getY(void) const {
	return this->y;
}
