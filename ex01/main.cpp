#include "Fixed.hpp"
#include <climits>

int main(void) {
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

	std::cout << "\n--- Testing negative cases ---" << std::endl;
	Fixed negInt(-42);
	Fixed negFloat(-3.14f);
	
	std::cout << "negInt is " << negInt << std::endl;
	std::cout << "negFloat is " << negFloat << std::endl;
	std::cout << "negInt is " << negInt.toInt() << " as integer" << std::endl;
	std::cout << "negFloat is " << negFloat.toInt() << " as integer" << std::endl;
	
	std::cout << "\n--- Testing INT_MAX case ---" << std::endl;
	Fixed maxInt(INT_MAX);
	
	std::cout << "maxInt is " << maxInt << std::endl;
	std::cout << "maxInt is " << maxInt.toInt() << " as integer" << std::endl;
	
	std::cout << "\n--- Testing INT_MIN case ---" << std::endl;
	Fixed minInt(INT_MIN);
	
	std::cout << "minInt is " << minInt << std::endl;
	std::cout << "minInt is " << minInt.toInt() << " as integer" << std::endl;

	std::cout << "\n--- Testing boundary values (exact limits) ---" << std::endl;
	// 安全な最大値と最小値をテスト (INT_MAX/256, INT_MIN/256)
	int maxSafeValue = INT_MAX / 256;  // 8388607
	int minSafeValue = INT_MIN / 256;  // -8388608
	
	Fixed maxSafe(maxSafeValue);
	Fixed minSafe(minSafeValue);
	
	std::cout << "maxSafe(" << maxSafeValue << ") is " << maxSafe << std::endl;
	std::cout << "minSafe(" << minSafeValue << ") is " << minSafe << std::endl;
	std::cout << "maxSafe is " << maxSafe.toInt() << " as integer" << std::endl;
	std::cout << "minSafe is " << minSafe.toInt() << " as integer" << std::endl;

	std::cout << "\n--- Testing boundary values +1/-1 (should overflow) ---" << std::endl;
	// 境界値の1つ上と下をテスト
	Fixed maxOverflow(maxSafeValue + 1);
	Fixed minOverflow(minSafeValue - 1);
	
	std::cout << "maxOverflow(" << (maxSafeValue + 1) << ") is " << maxOverflow << std::endl;
	std::cout << "minOverflow(" << (minSafeValue - 1) << ") is " << minOverflow << std::endl;
	std::cout << "maxOverflow is " << maxOverflow.toInt() << " as integer" << std::endl;
	std::cout << "minOverflow is " << minOverflow.toInt() << " as integer" << std::endl;

	return 0;
}
