#include <iostream>
#include <string>
#include <vector>
#include "vector.h"

namespace geometry {
  Vector::Vector() : x_(0), y_(0) {
  }

  Vector::Vector(const int& x, const int& y) : x_(x), y_(y) {
  }

  Vector::Vector(const Point& p) : x_(p.GetX()), y_(p.GetY()) {
  }

  Vector::Vector(const Point& p1, const Point& p2) : x_(p1.GetX() - p2.GetX()), y_(p1.GetX() - p2.GetY()) {
  }

  int& Vector::GetX() {
    return x_;
  }
  const int& Vector::GetX() const {
    return x_;
  }
  int& Vector::GetY() {
    return y_;
  }
  const int& Vector::GetY() const {
    return y_;
  }

  int DotProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.x_ + a.y_ * b.y_;
  }
  int CrossProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.y_ - a.y_ * b.x_;
  }
  int Vector::Length() const{
    return x_ * x_ + y_ * y_;
  }

  Vector operator+(const Vector& a, const Vector& b) {
    return Vector(a.x_ + b.x_, a.y_ + b.y_);
  }
  Vector operator-(const Vector& a, const Vector& b) {
    return Vector(a.x_ - b.x_, a.y_ - b.y_);
  }
  Vector operator*(const Vector& a, const int& k) {
    return Vector(k * a.x_, k * a.y_);
  }
  Vector operator*(const int& k, const Vector& a) {
    return Vector(k * a.x_, k * a.y_);
  }
  Vector operator/(const Vector& a, const int& k) {
    return Vector(a.x_ / k, a.y_ / k);
  }
  Vector operator/(const int& k, const Vector& a) {
    return Vector(a.x_ / k, a.y_ / k);
  }
  Vector Vector::operator+() {
    return Vector(x_, y_);
  }
  Vector operator-(const Vector& a) {
    return Vector(-a.x_, -a.y_);
  }
  Vector operator+(const Vector& a) {
    return Vector(a.x_, a.y_);
  }
  Vector Vector::operator-() {
    return Vector(-x_, -y_);
  }
  Vector& operator+=(Vector& a, const Vector& b) {
    a.x_ = a.x_ + b.x_;
    a.y_ = a.y_ + b.y_;
    return a;
  }
  Vector& operator-=(Vector& a, const Vector& b) {
    a.x_ = a.x_ - b.x_;
    a.y_ = a.y_ - b.y_;
    return a;
  }
  Vector& operator*=(Vector& a, const int& k) {
    a.x_ = a.x_ * k;
    a.y_ = a.y_ * k;
    return a;
  }
  Vector& operator/=(Vector& a, const int& k) {
    a.x_ = a.x_ / k;
    a.y_ = a.y_ / k;
    return a;
  }
  bool operator==(const Vector& a, const Vector& b) {
    if ((a.x_ != b.x_) or (a.y_ != b.y_)) {
      return (false);
    }
    return (true);
  }
  bool operator!=(const Vector& a, const Vector& b) {
    return (!(a==b));
  }

  int DotProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.x_ + a.y_ * b.y_;
  }
  
  int CrossProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.y_ - a.y_ * b.x_;
  }

  std::string Vector::ToString() const {
    std::string string = "Vector(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    return string;
  }

  IShape::~IShape() = default;
}