#include "Fixed.hpp"
#include <iostream>
#include <climits>

Fixed::Fixed(void) : value(0) {
}

Fixed::Fixed(const int n) {
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
	float scaledValue = f * (1 << fractionalBits);
	
	if (scaledValue > INT_MAX)
		value = INT_MAX;
	else if (scaledValue < INT_MIN)
		value = INT_MIN;
	else
		value = roundf(scaledValue);
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
	long long temp = (long long)value + (long long)other.value;
	
	if (temp > INT_MAX)
		result.setRawBits(INT_MAX);
	else if (temp < INT_MIN)
		result.setRawBits(INT_MIN);
	else
		result.setRawBits((int)temp);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	long long temp = (long long)value - (long long)other.value;
	
	if (temp > INT_MAX)
		result.setRawBits(INT_MAX);
	else if (temp < INT_MIN)
		result.setRawBits(INT_MIN);
	else
		result.setRawBits((int)temp);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long long temp = (long long)value * (long long)other.value;
	temp /= (1 << fractionalBits);
	
	if (temp > INT_MAX)
		result.setRawBits(INT_MAX);
	else if (temp < INT_MIN)
		result.setRawBits(INT_MIN);
	else
		result.setRawBits((int)temp);
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
	temp /= other.value;
	
	if (temp > INT_MAX)
		result.setRawBits(INT_MAX);
	else if (temp < INT_MIN)
		result.setRawBits(INT_MIN);
	else
		result.setRawBits((int)temp);
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
