#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	
	std::cout << "\n--- Testing negative operations ---" << std::endl;
	Fixed neg1(-5.5f);
	Fixed neg2(-2.2f);
	
	std::cout << "neg1: " << neg1 << std::endl;
	std::cout << "neg2: " << neg2 << std::endl;
	std::cout << "neg1 + neg2: " << (neg1 + neg2) << std::endl;
	std::cout << "neg1 - neg2: " << (neg1 - neg2) << std::endl;
	std::cout << "neg1 * neg2: " << (neg1 * neg2) << std::endl;
	std::cout << "neg1 / neg2: " << (neg1 / neg2) << std::endl;
	
	std::cout << "\n--- Testing overflow cases ---" << std::endl;
	Fixed big1(8000000);
	Fixed big2(2);
	
	std::cout << "big1: " << big1 << std::endl;
	std::cout << "big2: " << big2 << std::endl;
	std::cout << "big1 * big2: " << (big1 * big2) << std::endl;
	
	std::cout << "\n--- Testing division by zero ---" << std::endl;
	Fixed zero(0);
	Fixed five(5);
	
	std::cout << "five: " << five << std::endl;
	std::cout << "zero: " << zero << std::endl;
	std::cout << "five / zero: " << (five / zero) << std::endl;
	
	return 0;
}
