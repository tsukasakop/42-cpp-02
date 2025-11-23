#include <iostream>
#include "Point.hpp"

int main(void) {
	// 三角形の頂点を定義
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);
	
	// テストケース1: 三角形の内部の点
	Point p1(5.0f, 5.0f);
	std::cout << "Point (5, 5) is inside triangle: " 
	          << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;
	
	// テストケース2: 三角形の外部の点
	Point p2(15.0f, 5.0f);
	std::cout << "Point (15, 5) is inside triangle: " 
	          << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;
	
	// テストケース3: 頂点上の点
	Point p3(0.0f, 0.0f);
	std::cout << "Point (0, 0) [vertex] is inside triangle: " 
	          << (bsp(a, b, c, p3) ? "true" : "false") << std::endl;
	
	// テストケース4: 辺上の点
	Point p4(5.0f, 0.0f);
	std::cout << "Point (5, 0) [edge] is inside triangle: " 
	          << (bsp(a, b, c, p4) ? "true" : "false") << std::endl;
	
	// テストケース5: 別の内部点
	Point p5(7.0f, 3.0f);
	std::cout << "Point (7, 3) is inside triangle: " 
	          << (bsp(a, b, c, p5) ? "true" : "false") << std::endl;
	
	return 0;
}
