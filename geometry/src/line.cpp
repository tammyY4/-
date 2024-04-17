#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"
#include "line.h"
#include "segment.h"
#include "vector.cpp"
#include "point.cpp"
#include "segment.cpp"

namespace geometry {
  Line::Line() : a_(0), b_(0), c_(0), nap_(Vector()), p1_(Point()), p2_(Point()) {
  }

  Line::Line(const Point& p1, const Point& p2) {
    a_ = p2.GetY() - p1.GetY();
    b_ = p1.GetX() - p2.GetX();
    c_ = p1.GetY() * p2.GetX() - p2.GetY() * p1.GetX();
    nap_ = Vector(-b_, a_);
    p1_ = p1;
    p2_ = p2;
  }

  int& Line::GetA() {
    return a_;
  }
  const int& Line::GetA() const {
    return a_;
  }

  int& Line::GetB() {
    return b_;
  }
  const int& Line::GetB() const {
    return b_;
  }

  int& Line::GetC() {
    return c_;
  }
  const int& Line::GetC() const {
    return c_;
  }

  Vector Line::Nap() const{
    return nap_;
  }

  IShape& Line::Move(const Vector& v) {
    p1_ = p1_ + v;
    p2_ = p2_ + v;
    Line l(p1_, p2_);
    a_ = l.GetA();
    b_ = l.GetB();
    c_ = l.GetC();
    nap_ = l.Nap();
    return *this;
  }

  bool Line::ContainsPoint(const Point& p) const {
    return (a_ * p.GetX() + b_ * p.GetY() == -c_);
  }

  bool Line::CrossesSegment(const Segment& s) const {
    return ((SidePointOfLine(s.GetP1(), *this) * SidePointOfLine(s.GetP2(), *this)) <= 0);
  }

  IShape* Line::Clone() const {
    auto p = new Line;
    *p = *this;
    return p;
  }

  std::string Line::ToString() const {
    std::string p = "Line(" + std::to_string(a_) + ", " + std::to_string(b_) + ", " + std::to_string(c_) + ")";
    return  p;
  }

  Line::~Line() = default;
}