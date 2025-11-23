#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : value(0) {
}

Fixed::Fixed(const int n) : value(n << fractionalBits) {
}

Fixed::Fixed(const float f) : value(roundf(f * (1 << fractionalBits))) {
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->value = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void) {
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

// 比較演算子
bool Fixed::operator>(const Fixed& other) const {
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->value != other.value;
}

// 算術演算子
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->value + other.value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->value - other.value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->value * other.value) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->value << fractionalBits) / other.value);
	return result;
}

// インクリメント/デクリメント演算子
Fixed& Fixed::operator++(void) {
	this->value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->value++;
	return temp;
}

Fixed& Fixed::operator--(void) {
	this->value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->value--;
	return temp;
}

// 静的メンバ関数
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
