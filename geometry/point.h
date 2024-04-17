#ifndef POINT_H
#define POINT_H

#include "vector.h"

namespace geometry {
  class Point : public IShape {
  private:
    int x_;
    int y_;
    
  public:
    Point();
    Point(const int& x, const int& y);
    explicit Point(const Vector& p);
    int& GetX();
    const int& GetX() const;
    int& GetY();
    const int& GetY() const;
    IShape& Move(const Vector& v) override;
    bool ContainsPoint(const Point& p) const override;
    bool CrossesSegment(const Segment& s) const override;
    IShape* Clone() const override;
    std::string ToString() const override;
    ~Point() override;
    friend Vector operator-(const Point& p1, const Point& p2);
    friend Point operator+(const Point& p, const Vector& v);
    friend Point& operator+=(Point& p, const Vector& v);
  };
}
#endif