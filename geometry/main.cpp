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
  Vector::Vector() : x_(0), y_(0) {
  }

  Vector::Vector(const int& x, const int& y) : x_(x), y_(y) {
  }

  Vector::Vector(const Point& p) : x_(p.GetX()), y_(p.GetY()) {
  }

  Vector::Vector(const Point& p1, const Point& p2) : x_(p1.GetX() - p2.GetX()), y_(p1.GetX() - p2.GetY()) {
  }

  int& Vector::GetX() {
    return x_;
  }
  const int& Vector::GetX() const {
    return x_;
  }
  int& Vector::GetY() {
    return y_;
  }
  const int& Vector::GetY() const {
    return y_;
  }

  int DotProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.x_ + a.y_ * b.y_;
  }
  int CrossProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.y_ - a.y_ * b.x_;
  }
  int Vector::Length() const{
    return x_ * x_ + y_ * y_;
  }

  Vector operator+(const Vector& a, const Vector& b) {
    return Vector(a.x_ + b.x_, a.y_ + b.y_);
  }
  Vector operator-(const Vector& a, const Vector& b) {
    return Vector(a.x_ - b.x_, a.y_ - b.y_);
  }
  Vector operator*(const Vector& a, const int& k) {
    return Vector(k * a.x_, k * a.y_);
  }
  Vector operator*(const int& k, const Vector& a) {
    return Vector(k * a.x_, k * a.y_);
  }
  Vector operator/(const Vector& a, const int& k) {
    return Vector(a.x_ / k, a.y_ / k);
  }
  Vector operator/(const int& k, const Vector& a) {
    return Vector(a.x_ / k, a.y_ / k);
  }
  Vector Vector::operator+() {
    return Vector(x_, y_);
  }
  Vector operator-(const Vector& a) {
    return Vector(-a.x_, -a.y_);
  }
  Vector operator+(const Vector& a) {
    return Vector(a.x_, a.y_);
  }
  Vector Vector::operator-() {
    return Vector(-x_, -y_);
  }
  Vector& operator+=(Vector& a, const Vector& b) {
    a.x_ = a.x_ + b.x_;
    a.y_ = a.y_ + b.y_;
    return a;
  }
  Vector& operator-=(Vector& a, const Vector& b) {
    a.x_ = a.x_ - b.x_;
    a.y_ = a.y_ - b.y_;
    return a;
  }
  Vector& operator*=(Vector& a, const int& k) {
    a.x_ = a.x_ * k;
    a.y_ = a.y_ * k;
    return a;
  }
  Vector& operator/=(Vector& a, const int& k) {
    a.x_ = a.x_ / k;
    a.y_ = a.y_ / k;
    return a;
  }
  bool operator==(const Vector& a, const Vector& b) {
    if ((a.x_ != b.x_) or (a.y_ != b.y_)) {
      return (false);
    }
    return (true);
  }
  bool operator!=(const Vector& a, const Vector& b) {
    return (!(a==b));
  }

  int DotProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.x_ + a.y_ * b.y_;
  }
  
  int CrossProduct(const Vector& a, const Vector& b) {
    return a.x_ * b.y_ - a.y_ * b.x_;
  }

  std::string Vector::ToString() const {
    std::string string = "Vector(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    return string;
  }

  IShape::~IShape() = default;

  //Point

  Point::Point() : x_(0), y_(0){
  }

  Point::Point(const int& x, const int& y) : x_(x), y_(y) {
  }

  Point::Point(const Vector& v) : x_(v.GetX()), y_(v.GetY()) {
  }

  int& Point::GetX() {
    return x_;
  }
  const int& Point::GetX() const {
    return x_;
  }
  int& Point::GetY() {
    return y_;
  }
  const int& Point::GetY() const {
    return y_;
  }

  IShape& Point::Move(const Vector& v) {
    x_ += v.GetX();
    y_ += v.GetY();
    return *this;
  }

  bool Point::ContainsPoint(const Point& p) const {
    return ((x_ == p.GetX()) and (y_ == p.GetY()));
  }

  bool Point::CrossesSegment(const Segment& s) const {
    return (PointBelongSegment(*this, s));
  }

  IShape* Point::Clone() const {
    auto p = new Point;
    *p = *this;
    return p;
  }

  std::string Point::ToString() const {
    std::string p = "Point(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
    return  p;
  }

  Point::~Point() = default;

  Vector operator-(const Point& p1, const Point& p2) {
    return (Vector(p2.x_ - p1.x_, p2.y_ - p1.y_));
  }
  Point operator+(const Point& p, const Vector& v) {
    return (Point(p.x_ + v.GetX(), p.y_ + v.GetY()));
  }
  Point& operator+=(Point& p, const Vector& v) {
    p.x_ = p.x_ + v.GetX();
    p.y_ = p.y_ + v.GetY();
    return p;
  }

  //Line

  Line::Line() : a_(0), b_(0), c_(0), nap_(Vector()), p1_(Point()), p2_(Point()) {
  }

  Line::Line(const Point& p1, const Point& p2) {
    a_ = p2.GetY() - p1.GetY();
    b_ = p1.GetX() - p2.GetX();
    c_ = p1.GetY() * p2.GetX() - p2.GetY() * p1.GetX();
    nap_ = Vector(-b_, a_);
    p1_ = p1;
    p2_ = p2;
  }

  int& Line::GetA() {
    return a_;
  }
  const int& Line::GetA() const {
    return a_;
  }

  int& Line::GetB() {
    return b_;
  }
  const int& Line::GetB() const {
    return b_;
  }

  int& Line::GetC() {
    return c_;
  }
  const int& Line::GetC() const {
    return c_;
  }

  Vector Line::Nap() const{
    return nap_;
  }

  IShape& Line::Move(const Vector& v) {
    p1_ = p1_ + v;
    p2_ = p2_ + v;
    Line l(p1_, p2_);
    a_ = l.GetA();
    b_ = l.GetB();
    c_ = l.GetC();
    nap_ = l.Nap();
    return *this;
  }

  bool Line::ContainsPoint(const Point& p) const {
    return (a_ * p.GetX() + b_ * p.GetY() == -c_);
  }

  bool Line::CrossesSegment(const Segment& s) const {
    return ((SidePointOfLine(s.GetP1(), *this) * SidePointOfLine(s.GetP2(), *this)) <= 0);
  }

  IShape* Line::Clone() const {
    auto p = new Line;
    *p = *this;
    return p;
  }

  std::string Line::ToString() const {
    std::string p = "Line(" + std::to_string(a_) + ", " + std::to_string(b_) + ", " + std::to_string(c_) + ")";
    return  p;
  }

  Line::~Line() = default;

  //Segment

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

  //Ray

  Ray::Ray() : p_(Point()), nap_(Vector()) {
  }

  Ray::Ray(const Point& p, const Vector& v) : p_(p), nap_(v) {
  }

  Ray::Ray(const Point& p1, const Point& p2) : p_(p1), nap_(Vector(p2, p1)) {
  }

  Point Ray::GetBegin() const{
    return p_;
  }

  Vector Ray::Nap() const{
    return nap_;
  }

  IShape& Ray::Move(const Vector& v) {
    p_ = p_ + v;
    return *this;
  }

  bool Ray::ContainsPoint(const Point& p) const {
    Point p1 = p_ + nap_;
    Point s = this->GetBegin();
    Vector v1(p1, s);
    Vector v2(p, s);
    Vector v3(p1, p);
    int k = CrossProduct(v2, v3);
    int s1 = DotProduct(v1, v2);
    return ((k == 0) and (s1 >= 0));
  }

  bool Ray::CrossesSegment(const Segment& s) const {
    bool t = false;
    Point a = p_;
    Point p1 = s.GetP1();
    Point p2 = s.GetP2();
    Vector v1(p1, a);
    int l1 = v1.Length();
    Vector v2(p2, a);
    int l2 = v2.Length();
    int k1 = CrossProduct(nap_, v1);
    int k12 = DotProduct(nap_, v1);
    int k2 = CrossProduct(nap_, v2);
    int k22 = DotProduct(nap_, v1);
    if (((k1 == 0) and (k12 >= 0)) or ((k2 == 0) and (k22 >= 0))) {
        t = true;
        return t;
    }
    Point b = a + nap_ * (l2 > l1 ? l2 : l1);
    Segment s1 = Segment(a, b);
    return s1.CrossesSegment(s);
  }

  IShape* Ray::Clone() const {
    auto p = new Ray;
    *p = *this;
    return p;
  }

  std::string Ray::ToString() const {
    std::string p = "Ray(" + p_.ToString() + ", " + nap_.ToString() + ")";
    return p;
  }

  Ray::~Ray() = default;

  //Polygon

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

  //Circle

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