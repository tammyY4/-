#ifndef VECTOR_H_
#define VECTOR_H_

namespace geometry {
  class Point;
  class Segment;
  class Line;
  class Ray;
  class Polygon;
  class Circle;
  class Vector {
  protected:
    int x_;
    int y_;

  public:
    Vector();
    explicit Vector(const int& x, const int& y);
    explicit Vector(const Point& p);
    explicit Vector(const Point& p1, const Point& p2);
    int& GetX();
    const int& GetX() const;
    int& GetY();
    const int& GetY() const;

    friend int DotProduct(const Vector& a, const Vector& b);
    friend int CrossProduct(const Vector& a, const Vector& b);
    int Length() const;

    friend Vector operator+(const Vector& a, const Vector& b);
    friend Vector operator+(const Vector& a);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend Vector operator-(const Vector& a);
    friend Vector operator*(const Vector& a, const int& k);
    friend Vector operator*(const int& k, const Vector& a);
    friend Vector operator/(const int& k, const Vector& a);
    friend Vector operator/(const Vector& a, const int& k);
    Vector operator+();
    Vector operator-();
    friend Vector& operator+=(Vector& a, const Vector& b);
    friend Vector& operator-=(Vector& a, const Vector& b);
    friend Vector& operator*=(Vector& a, const int& k);
    friend Vector& operator/=(Vector& a, const int& k);
    friend bool operator==(const Vector& a, const Vector& b);
    friend bool operator!=(const Vector& a, const Vector& b);
    friend Point& operator+=(Point& p, const Vector& v);
    std::string ToString() const;
  };

  class IShape {
  public:
    virtual IShape& Move(const Vector& v) = 0;
    virtual bool ContainsPoint(const Point& p) const = 0;
    virtual bool CrossesSegment(const Segment& s) const = 0;
    virtual IShape* Clone() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~IShape() = 0;
  };

  bool PointBelongSegment(const Point& p, const Segment& s);
  bool PointBelongLine(const Point& p, const Line& l);
  bool PointBelongRay(const Point& p, const Ray& r);
  int SidePointOfLine(const Point& p, const Line& l);
  int Cross(const Line& l, const Point& p);
}

#endif
