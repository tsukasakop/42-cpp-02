#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
private:
	int value;
	static const int fractionalBits = 8;

public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
	// 比較演算子
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;
	
	// 算術演算子
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;
	
	// インクリメント/デクリメント演算子
	Fixed& operator++(void);      // 前置インクリメント
	Fixed operator++(int);         // 後置インクリメント
	Fixed& operator--(void);      // 前置デクリメント
	Fixed operator--(int);         // 後置デクリメント
	
	// 静的メンバ関数
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
