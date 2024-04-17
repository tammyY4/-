#include <iostream>
#include <string>
#include <vector>
#include "vector.h"
#include "point.h"
#include "segment.h"
#include "polygon.h"
#include "vector.cpp"
#include "point.cpp"
#include "segment.cpp"

namespace geometry {
  Polygon::Polygon() : size_(0) {
  }

  Polygon::Polygon(const std::vector<Point>& p) {
    size_ = p.size();
    p_.resize(size_);
    for (int i = 0; i < size_; ++i) {
        p_[i] = p[i];
    }
    for (int i = 0; i < size_ - 1; ++i) {
        s_[i] = Segment(p_[i], p_[i + 1]);
    }
    s_[size_ - 1] = Segment(p_[size_ - 1], p_[0]);
  }

  int Polygon::GetSize() const{
    return size_;
  }

  IShape& Polygon::Move(const Vector& v) {
    for (int i = 0; i < size_; ++i) {
      p_[i] = p_[i] + v;
    }
    for (int i = 0; i < size_; ++i) {
      s_[i].Move(v);
    }
  }

  int Polygon::GetMax() const {
    int maxi = p_[0].GetX();
    for (int i = 1; i < size_; ++i) {
      maxi = (p_[i].GetX() > maxi ? p_[i].GetX() : maxi);
    }
    return maxi;
  }

  bool Polygon::ContainsPoint(const Point& p) const {
    bool t = false;
    int h = 0;
    int m = this->GetMax();
    if (p.GetX() > m) {
      return t;
    }
    Point p1(m + 1, p.GetY() + 1);
    Vector v(p1, p);
    Ray r(p, v)
    for (int i = 0; i < size_; ++i) {
      h = h + r.CrossesSegment(s_[i]);
    }
    t = ((h % 2 == 0) ? false : true);
    return t;
  }

  bool Polygon::CrossesSegment(const Segment& s) const {
    return (this->ContainsPoint(s.GetP1()) - this->ContainsPoint(s.GetP2()));
  }

  IShape* Polygon::Clone() const {
    auto p = new Polygon;
    *p = *this;
    return p;
  }

  std::string Polygon::ToString() const {
    std::string p = "Polygon(";
    for (int i = 0; i < size_ - 1; ++i) {
      p = p + p_[i].ToString() + ", ";
    }
    p = p + p_[size_ - 1].ToString() + ")";
    return p;
  }

  Polygon::~Polygon() = default;
}