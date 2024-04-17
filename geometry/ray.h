#ifndef RAY_H_
#define RAY_H_

#include "vector.h"

namespace geometry {
  class Ray : public IShape {
  private:
    Point p_;
    Vector nap_;
    
  public:
    Ray();
    Ray(const Point& p, const Vector& v);
    Ray(const Point& p1, const Point& p2);
    Point GetBegin() const;
    Vector Nap() const;
    IShape& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment& s) const override;
    IShape* Clone() const override;
    std::string ToString() const override;
    ~Ray() override;
  };
}
#endif
