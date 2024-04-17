#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "vector.h"

namespace geometry {
  class Segment : public IShape {
  private:
    Point p1_;
    Point p2_;
    Vector nap_;

  public:
    Segment();
    Segment(const Point& p1, const Point& p2);
    Point GetP1() const;
    Point GetP2() const;
    Vector Nap() const;
    IShape& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment& s) const override;
    IShape* Clone() const override;
    std::string ToString() const override;
    ~Segment() override;
  };
}
#endif