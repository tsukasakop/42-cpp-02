#include "Fixed.hpp"
#include <climits>
#include <iomanip>
#include <bitset>
#include <typeinfo>

template <typename T>
static void showFixed(const T& arg) {
	Fixed f(arg);
	const int width = 12;
	std::cout << std::setprecision(10);
	std::cout << std::setw(width) << std::left << "arg" << ": " << arg << " (" << typeid(arg).name() << ")" << std::endl;
	std::cout << std::setw(width) << std::left << "value" << ": " << f << std::endl;
	std::cout << std::setw(width) << std::left << "toInteger()" << ": " << f.toInt() << std::endl;
	std::cout << std::setw(width) << std::left << "getRawBits()" << ": " << std::bitset<32>(f.getRawBits()) << std::endl;
}

int main(void) {
	{
		Fixed a;
		Fixed const b(10);
		Fixed const c(42.42f);
		Fixed const d(b);
		
		a = Fixed(1234.4321f);
		
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << "\n--- Testing zero ---" << std::endl;
		showFixed(0);
		showFixed(0.0f);
	}
	{
		std::cout << "\n--- Testing negative cases ---" << std::endl;
		showFixed(-42);
		showFixed(-3.14f);
	}
	{
		std::cout << "\n--- Testing small fractional values ---" << std::endl;
		showFixed(0.00390625f);
		showFixed(-0.00390625f);
	}
	{
		std::cout << "\n--- Testing boundary values (exact limits) ---" << std::endl;
		Fixed fixedMax, fixedMin;
		fixedMax.setRawBits(0b01111111111111111111111111111111);
		fixedMin.setRawBits(0b10000000000000000000000000000000);
		showFixed(fixedMax);
		showFixed(fixedMin);
	}
	{
		std::cout << "\n--- Testing boundary values (int limits) ---" << std::endl;
		showFixed(8388607);
		showFixed(-8388608);
	}
	{
		std::cout << "\n--- Testing boundary values (float limits) ---" << std::endl;
		showFixed(8388607.5f);
		showFixed(-8388608.f);
	}
	return 0;
}
