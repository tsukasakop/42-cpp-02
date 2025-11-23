#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : value(n << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : value(roundf(f * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
