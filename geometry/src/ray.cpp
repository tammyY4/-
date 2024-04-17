#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"
#include "ray.h"
#include "segment.h"
#include "vector.cpp"
#include "point.cpp"
#include "segment.cpp"

namespace geometry {
  Ray::Ray() : p_(Point()), nap_(Vector()) {
  }

  Ray::Ray(const Point& p, const Vector& v) : p_(p), nap_(v) {
  }

  Ray::Ray(const Point& p1, const Point& p2) : p_(p1), nap_(Vector(p2, p1)) {
  }

  Point Ray::GetBegin() const{
    return p_;
  }

  Vector Ray::Nap() const{
    return nap_;
  }

  IShape& Ray::Move(const Vector& v) {
    p_ = p_ + v;
    return *this;
  }

  bool Ray::ContainsPoint(const Point& p) const {
    Point p1 = p_ + nap_;
    Point s = this->GetBegin();
    Vector v1(p1, s);
    Vector v2(p, s);
    Vector v3(p1, p);
    int k = CrossProduct(v2, v3);
    int s1 = DotProduct(v1, v2);
    return ((k == 0) and (s1 >= 0));
  }

  bool Ray::CrossesSegment(const Segment& s) const {
    bool t = false;
    Point a = p_;
    Point p1 = s.GetP1();
    Point p2 = s.GetP2();
    Vector v1(p1, a);
    int l1 = v1.Length();
    Vector v2(p2, a);
    int l2 = v2.Length();
    int k1 = CrossProduct(nap_, v1);
    int k12 = DotProduct(nap_, v1);
    int k2 = CrossProduct(nap_, v2);
    int k22 = DotProduct(nap_, v1);
    if (((k1 == 0) and (k12 >= 0)) or ((k2 == 0) and (k22 >= 0))) {
        t = true;
        return t;
    }
    Point b = a + nap_ * (l2 > l1 ? l2 : l1);
    Segment s1 = Segment(a, b);
    return s1.CrossesSegment(s);
  }

  IShape* Ray::Clone() const {
    auto p = new Ray;
    *p = *this;
    return p;
  }

  std::string Ray::ToString() const {
    std::string p = "Ray(" + p_.ToString() + ", " + nap_.ToString() + ")";
    return p;
  }

  Ray::~Ray() = default;
}