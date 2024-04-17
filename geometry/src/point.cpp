#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"
#include "segment.h"
#include "vector.cpp"
#include "segment.cpp"

namespace geometry {
  Point::Point() : x_(0), y_(0){
  }

  Point::Point(const int& x, const int& y) : x_(x), y_(y) {
  }

  Point::Point(const Vector& v) : x_(v.GetX()), y_(v.GetY()) {
  }

  int& Point::GetX() {
    return x_;
  }
  const int& Point::GetX() const {
    return x_;
  }
  int& Point::GetY() {
    return y_;
  }
  const int& Point::GetY() const {
    return y_;
  }

  IShape& Point::Move(const Vector& v) {
    x_ += v.GetX();
    y_ += v.GetY();
    return *this;
  }

  bool Point::ContainsPoint(const Point& p) const {
    return ((x_ == p.GetX()) and (y_ == p.GetY()));
  }

  bool Point::CrossesSegment(const Segment& s) const {
    return (PointBelongSegment(*this, s));
  }

  IShape* Point::Clone() const {
    auto p = new Point;
    *p = *this;
    return p;
  }

  std::string Point::ToString() const {
    std::string p = "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    return  p;
  }

  Point::~Point() = default;

  Vector operator-(const Point& p1, const Point& p2) {
    return (Vector(p2.x_ - p1.x_, p2.y_ - p1.y_));
  }
  Point operator+(const Point& p, const Vector& v) {
    return (Point(p.x_ + v.GetX(), p.y_ + v.GetY()));
  }
  Point& operator+=(Point& p, const Vector& v) {
    p.x_ = p.x_ + v.GetX();
    p.y_ = p.y_ + v.GetY();
    return p;
  }
}