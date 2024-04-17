#include "rational.h"

void MakeDrob(int32_t& a, int32_t& b) {
  if (b == 0) {
    throw RationalDivisionByZero{};
  }
  int32_t k = ((a * (b > 0)) + (-a * (b < 0)));
  int32_t s = abs(b);
  a = abs(a);
  b = abs(b);
  int32_t gcd = std::__gcd(a, b);
  a = k / gcd;
  b = s / gcd;
}

Rational::Rational() : x_(0), y_(1) {
}
Rational::Rational(const int32_t& value) : x_(value), y_(1) {
}
Rational::Rational(const int32_t& ch, const int32_t& zn) : x_(ch), y_(zn) {
  MakeDrob(x_, y_);
}
int32_t Rational::GetNumerator() const {
  return x_;
}
int32_t Rational::GetDenominator() const {
  return y_;
}
void Rational::SetNumerator(int a) {
  x_ = a;
  MakeDrob(x_, y_);
}
void Rational::SetDenominator(int b) {
  y_ = b;
  MakeDrob(x_, y_);
}
Rational Rational::operator-() const {
  Rational newr = *this;
  newr.x_ = -x_;
  return newr;
}
Rational Rational::operator+() const {
  return *this;
}
Rational operator+(const Rational& a, const Rational& b) {
  return Rational(a.x_ * b.y_ + a.y_ * b.x_, a.y_ * b.y_);
}
Rational operator-(const Rational& a, const Rational& b) {
  return Rational(a.x_ * b.y_ - a.y_ * b.x_, a.y_ * b.y_);
}
Rational operator*(const Rational& a, const Rational& b) {
  return Rational(a.x_ * b.x_, a.y_ * b.y_);
}
Rational operator/(const Rational& a, const Rational& b) {
  return Rational(a.x_ * b.y_, a.y_ * b.x_);
}
Rational& operator+=(Rational& a, const Rational& b) {
  a.x_ = a.x_ * b.y_ + a.y_ * b.x_;
  a.y_ = a.y_ * b.y_;
  MakeDrob(a.x_, a.y_);
  return a;
}
Rational& operator-=(Rational& a, const Rational& b) {
  a.x_ = a.x_ * b.y_ - a.y_ * b.x_;
  a.y_ = a.y_ * b.y_;
  MakeDrob(a.x_, a.y_);
  return a;
}
Rational& operator*=(Rational& a, const Rational& b) {
  a.x_ = a.x_ * b.x_;
  a.y_ = a.y_ * b.y_;
  MakeDrob(a.x_, a.y_);
  return a;
}
Rational& operator/=(Rational& a, const Rational& b) {
  a.x_ = a.x_ * b.y_;
  a.y_ = a.y_ * b.x_;
  MakeDrob(a.x_, a.y_);
  return a;
}
Rational& Rational::operator++() {
  x_ = x_ + y_;
  return *this;
}
Rational& Rational::operator--() {
  x_ = x_ - y_;
  return *this;
}
Rational Rational::operator++(int32_t) {
  Rational temp = *this;
  *this += 1;
  return temp;
}
Rational Rational::operator--(int32_t) {
  Rational temp = *this;
  *this -= 1;
  return temp;
}
bool operator<(const Rational& a, const Rational& b) {
  int32_t temp1 = a.x_ * b.y_;
  int32_t temp2 = a.y_ * b.x_;
  return temp1 < temp2;
}
bool operator>(const Rational& a, const Rational& b) {
  int32_t temp1 = a.x_ * b.y_;
  int32_t temp2 = a.y_ * b.x_;
  return temp1 > temp2;
}
bool operator<=(const Rational& a, const Rational& b) {
  return !(a > b);
}
bool operator>=(const Rational& a, const Rational& b) {
  return !(a < b);
}
bool operator==(const Rational& a, const Rational& b) {
  int32_t temp1 = a.x_ * b.y_;
  int32_t temp2 = a.y_ * b.x_;
  return (temp1 == temp2);
}
bool operator!=(const Rational& a, const Rational& b) {
  return !(a == b);
}
std::istream& operator>>(std::istream& is, Rational& a) {
  a.x_ = 0;
  a.y_ = 0;
  while (is.peek() == ' ') {
    is.get();
  }
  char znak1 = '+';
  if ((is.peek() == '-') or (is.peek() == '+')) {
    znak1 = is.get();
  }
  while (std::isdigit(is.peek())) {
    a.x_ = a.x_ * 10 + (is.get() - 48);
  }
  if (znak1 == '-') {
    a.x_ = -a.x_;
  }
  if (is.peek() == '/') {
    is.get();
    char znak = '+';
    if ((is.peek() == '-') or (is.peek() == '+')) {
      znak = is.get();
    }
    while (std::isdigit(is.peek())) {
      a.y_ = a.y_ * 10 + (is.get() - 48);
    }
    if (znak == '-') {
      a.y_ = -a.y_;
    }
  } else {
    a.y_ = 1;
  }
  MakeDrob(a.x_, a.y_);
  return is;
}
std::ostream& operator<<(std::ostream& os, const Rational& a) {
  if (a.y_ == 1) {
    os << a.x_;
  } else {
    os << a.x_ << "/" << a.y_;
  }
  return os;
}