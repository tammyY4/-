#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"
#include "segment.h"
#include "vector.cpp"
#include "point.cpp"


namespace geometry {
  Segment::Segment() : p1_(Point()), p2_(Point()), nap_() {
  }

  Segment::Segment(const Point& p1, const Point& p2) : p1_(p1), p2_(p2), nap_(Vector(p1, p2)) {
  }

  Point Segment::GetP1() const {
    return p1_;
  }

  Point Segment::GetP2() const {
    return p2_;
  }

  Vector Segment::Nap() const {
    return nap_;
  }

  IShape& Segment::Move(const Vector& v) {
    p1_ = p1_ + v;
    p2_ = p2_ + v;
    return *this;
  }

  bool PointBelongSegment(const Point& p, const Segment& s) {
    Vector v1(s.GetP2(), s.GetP1());
    Vector v2(p, s.GetP1());
    Vector v3(s.GetP2(), p);
    int k = CrossProduct(v2, v3);
    int s1 = DotProduct(v1, v2);
    int s2 = DotProduct(v2, v3);
    return ((k == 0) and (s1 >= 0) and (s2 >= 0));
  }

  bool Segment::ContainsPoint(const Point& p) const {
    return (PointBelongSegment(p, *this));
  }

  int Cross(const Line& line, const Point& point) {
    return (line.GetA() * point.GetX() + line.GetB() * point.GetY() + line.GetC());
  }

  bool Segment::CrossesSegment(const Segment& s) const {
    bool k = false;
    Point s1 = s.GetP1();
    Point s2 = s.GetP2();
    Line line_1(s.GetP1(), s.GetP2());
    Line line_2(p1_, p2_);
    auto k1 = Cross(line_2, s1);
    auto k2 = Cross(line_2, s2);
    auto k3 = Cross(line_1, p1_);
    auto k4 = Cross(line_1, p2_);
    if (k1 * k2 <= 0 and k3 * k4 <= 0) {
      if (k1 * k2 != 0 or k3 * k4 != 0) {
        k = true;
      } else {
        Vector v1(s1, p1_);
        Vector v2(s2, p2_);
        Vector v3(p2_, s1);
        Vector v4(p2_, s2);
        Vector v5(p1_, s1);
        Vector v6(s2, p1_);
        if (k1 == 0 and k2 == 0) {
          int k1 = DotProduct(v1, v3);
          int k2 = DotProduct(v2, v4);
          int k3 = DotProduct(v5, v6);
          if (k1 >= 0 or k2 >= 0 or k3 >= 0) {
            k = true;
          }
        } else {
          k = true;
        }
      }
    }
    return k;
  }


  IShape* Segment::Clone() const {
    auto p = new Segment;
    *p = *this;
    return p;
  }

  std::string Segment::ToString() const {
    std::string p = "Segment(" + p1_.ToString() + ", " + p2_.ToString() + ")";
    return  p;
  }

  Segment::~Segment() = default;
}