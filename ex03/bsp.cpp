#include "Point.hpp"

// 符号付き面積を計算する補助関数
static Fixed sign(Point const p1, Point const p2, Point const p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - 
	       (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// 点が三角形内部にあるかを判定する関数
// バリセントリック座標を使用した判定
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed d1, d2, d3;
	bool has_neg, has_pos;
	
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	
	// 頂点または辺上にある場合はfalseを返す
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return false;
	
	has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));
	
	// 全ての符号が同じ場合、点は三角形内部にある
	return !(has_neg && has_pos);
}
