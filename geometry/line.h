#ifndef LINE_H_
#define LINE_H_

#include "vector.h"

namespace geometry {
  class Line : public IShape {
  private:
    int a_;
    int b_;
    int c_;
    Vector nap_;
    Point p1_;
    Point p2_;

  public:
    Line();
    Line(const Point& p1, const Point& p2);
    int& GetA();
    const int& GetA() const;
    int& GetB();
    const int& GetB() const;
    int& GetC();
    const int& GetC() const;
    Vector Nap() const;
    IShape& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    IShape* Clone() const override;
    std::string ToString() const override;
    ~Line() override;
  };
}
#endif