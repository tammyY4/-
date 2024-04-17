#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "vector.h"

namespace geometry {
  class Circle : public IShape {
  private:
    Point p_;
    int r_;
    
  public:
    Circle();
    Circle(const Point& p, const int& r);
    IShape& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment& s) const override;
    IShape* Clone() const override;
    std::string ToString() const override;
    ~Circle() override;
  };
}
#endif

