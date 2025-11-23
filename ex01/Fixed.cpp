#include "Fixed.hpp"
#include <iostream>
#include <climits>

Fixed::Fixed(void) : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	
	int maxSafeValue = INT_MAX / (1 << fractionalBits);
	int minSafeValue = INT_MIN / (1 << fractionalBits);
	
	if (n > maxSafeValue)
		value = INT_MAX;
	else if (n < minSafeValue)
		value = INT_MIN;
	else
		value = n * (1 << fractionalBits);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	
	float scaledValue = f * (1 << fractionalBits);
	
	if (scaledValue > INT_MAX)
		value = INT_MAX;
	else if (scaledValue < INT_MIN)
		value = INT_MIN;
	else
		value = roundf(scaledValue);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return value;
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float Fixed::toFloat(void) const {
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return value / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
