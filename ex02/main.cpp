#include "Fixed.hpp"
#include <iomanip>
#include <bitset>

static void showFixed(const Fixed& f) {
	const int width = 12;
	std::cout << std::setprecision(10);
	std::cout << std::setw(width) << std::left << "value" << ": " << f << std::endl;
	std::cout << std::setw(width) << std::left << "toInteger()" << ": " << f.toInt() << std::endl;
	std::cout << std::setw(width) << std::left << "getRawBits()" << ": 0b" << std::bitset<32>(f.getRawBits()) << std::endl;
}

int main(void) {
	{
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );
		
		a = Fixed( 1234.4321f );

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
		std::cout << "\n--- Arithmetic Operations ---" << std::endl;
		Fixed lhs(-12.5f), rhs(2);
		std::cout << "\nOperands:" << std::endl;
		showFixed(lhs);
		showFixed(rhs);
		std::cout << "\nResults:" << std::endl;
		showFixed(lhs + rhs);		
		showFixed(lhs - rhs);
		showFixed(lhs * rhs);
		showFixed(lhs / rhs);
	}
	{
		std::cout << "\n--- Increment/Decrement Operations ---" << std::endl;
		Fixed value(0);
		std::cout << "\npre-increment: " << value << std::endl;
		showFixed(++value);
		std::cout << "\npost-increment: " << value << std::endl;
		showFixed(value++);
		std::cout << "\npre-decrement: " << value << std::endl;
		showFixed(--value);
		std::cout << "\npost-decrement: " << value << std::endl;
		showFixed(value--);
		std::cout << "\ncurrent value: " << value << std::endl;
	}
	{
		std::cout << "\n--- Compare Operations ---" << std::endl;
		Fixed a(5), b(10);
		std::cout << std::boolalpha;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;
	}
	{
		std::cout << "\n--- Min/Max Operations ---" << std::endl;
		Fixed a(-3.14f), b(2.71f);
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "Min: " << Fixed::min(a, b) << std::endl;
		std::cout << "Max: " << Fixed::max(a, b) << std::endl;
	}
	return 0;
}
