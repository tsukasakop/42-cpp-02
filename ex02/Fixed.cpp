#include "Fixed.hpp"
#include <iostream>
#include <climits>

Fixed::Fixed(void) : value(0) {
}

Fixed::Fixed(const int n) : value(n * (1 << fractionalBits)) {
}

Fixed::Fixed(const float f) : value(roundf(f * (1 << fractionalBits))) {
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
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

bool Fixed::operator>(const Fixed& other) const {
	return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
	return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
	return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(value + other.value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(value - other.value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long long temp = (long long)value * other.value;
	result.setRawBits((int)(temp / (1 << fractionalBits)));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	if (other.value == 0) {
		std::cout << "Error: Division by zero!" << std::endl;
		result.setRawBits(0);
		return result;
	}
	long long temp = (long long)value * (1 << fractionalBits);
	result.setRawBits((int)(temp / other.value));
	return result;
}

Fixed& Fixed::operator++(void) {
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--(void) {
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
