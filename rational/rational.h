#ifndef RATIONAL_H_
#define RATIONAL_H_

#include <algorithm>
#include <iostream>
#include <stdexcept>

void MakeDrob(int32_t& a, int32_t& b);

class RationalDivisionByZero : public std::runtime_error {
 public:
  RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
  }
};

class Rational {
  int32_t x_;
  int32_t y_;

 public:
  Rational();
  Rational(const int32_t& value);  // NOLINT
  Rational(const int32_t& ch, const int32_t& zn);
  int32_t GetNumerator() const;
  int32_t GetDenominator() const;
  void SetNumerator(int a);
  void SetDenominator(int b);
  friend Rational operator+(const Rational& a, const Rational& b);
  friend Rational operator-(const Rational& a, const Rational& b);
  friend Rational operator*(const Rational& a, const Rational& b);
  friend Rational operator/(const Rational& a, const Rational& b);
  friend Rational& operator+=(Rational& a, const Rational& b);
  friend Rational& operator-=(Rational& a, const Rational& b);
  friend Rational& operator*=(Rational& a, const Rational& b);
  friend Rational& operator/=(Rational& a, const Rational& b);
  friend bool operator<(const Rational& a, const Rational& b);
  friend bool operator>(const Rational& a, const Rational& b);
  friend bool operator<=(const Rational& a, const Rational& b);
  friend bool operator<=(const Rational& a, const Rational& b);
  friend bool operator==(const Rational& a, const Rational& b);
  friend bool operator!=(const Rational& a, const Rational& b);
  friend std::ostream& operator<<(std::ostream& os, const Rational& a);
  friend std::istream& operator>>(std::istream& is, Rational& a);
  Rational& operator++();
  Rational& operator--();
  Rational operator++(int32_t);
  Rational operator--(int32_t);
  Rational operator-() const;
  Rational operator+() const;
};
Rational operator+(const Rational& a, const Rational& b);
Rational operator-(const Rational& a, const Rational& b);
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);
Rational& operator+=(Rational& a, const Rational& b);
Rational& operator-=(Rational& a, const Rational& b);
Rational& operator*=(Rational& a, const Rational& b);
Rational& operator/=(Rational& a, const Rational& b);
bool operator<(const Rational& a, const Rational& b);
bool operator>=(const Rational& a, const Rational& b);
bool operator>(const Rational& a, const Rational& b);
bool operator<=(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);
std::ostream& operator<<(std::ostream& os, const Rational& a);
std::istream& operator>>(std::istream& is, Rational& a);
#endif