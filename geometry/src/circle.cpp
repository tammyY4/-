#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"
#include "line.h"
#include "ray.h"
#include "segment.h"
#include "polygon.h"
#include "circle.h"

namespace geometry {
  Circle::Circle() : r_(0), p_(Point()) {
  }

  Circle::Circle(const Point& p, const int& r) : r_(r), p_(Point()) {
  }

  IShape& Circle::Move(const Vector& v) {
    p_.Move();
  }

  bool Circle::ContainsPoint(const Point& p) const {
    Vector v(p, p_);
    return (v.Length() <= r_ * r_);
  }

  bool Circle::CrossesSegment(const Segment& s) const {
    return (this->ContainsPoint(s.GetP1) - this->ContainsPoint(s.GetP2));
  }
}