#ifndef POLYGON_H_
#define POLYGON_H_

#include "vector.h"

namespace geometry {
  class Polygon : public IShape {
  private:
    int size_;
    std::vector<Point> p_;
    std::vector<Segment> s_;
    
  public:
    Polygon();
    explicit Polygon(const std::vector<Point>& p);
    int GetSize() const;
    int GetMax() const;
    IShape& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment& s) const override;
    IShape* Clone() const override;
    std::string ToString() const override;
    ~Polygon() override;
  };
}
#endif

