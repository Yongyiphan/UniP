#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt

///////////////////////////////////////////////////////////////////////////////
// declare private stuff here [if any] in this anonymous namespace ...
namespace {
  double const PI{3.14159265358979323846};
}

///////////////////////////////////////////////////////////////////////////////

namespace hlp2 {

  // define 3 constructors


  // define 8 member functions
  double& Point::operator[] (int i) {return i ? y : x;}
  const double& Point::operator[] (int i) const {return i ? y : x;}
  Point& Point::operator++ () {++x; ++y; return *this;}
  Point Point::operator++ (int) {Point p{*this}; ++x; ++y; return p;}
  Point& Point::operator-- () {--x; --y; return *this;}
  Point Point::operator-- (int) {Point p{*this}; --x; --y; return p;}
  Point Point::operator+ (const Point& p) const {return Point{x + p[0], y + p[1]};}
  Point Point::operator+ (double d) {return Point{x + d, y + d};}
  Point Point::operator- (const Point& p) const {return Point{x - p[0], y - p[1]};}
  Point Point::operator- (double d) {return Point{x - d, y - d};}
  Point Point::operator- (void) {return Point{-x, -y};}
  Point& Point::operator+= (const Point& p) {x += p[0]; y += p[1]; return *this;}
  Point& Point::operator+= (double d) {x += d; y += d; return *this;}
  Point& Point::operator-= (const Point& p) {x -= p[0]; y -= p[1]; return *this;}

  // define 15 non-member, non-friend functions
  Point operator% (const Point& p, double d) {
    double rad = d * PI / 180;
    return Point(p[0] * cos(rad) - p[1] * sin(rad),
                 p[0] * sin(rad) + p[1] * cos(rad));
  }

  double operator/ (const Point& p, const Point& q) {
    return sqrt(pow(q[0] - p[0], 2) + pow(q[1] - p[1], 2));
  }

  Point operator+ (const Point& p, double d) {
    return Point(p[0] + d, p[1] + d);
  }

  Point operator- (const Point& p, double d) {
    return Point(p[0] - d, p[1] - d);
  }

  Point operator+ (double d, const Point& p) {
    return Point(p[0] + d, p[1] + d);
  }

  Point operator- (double d, const Point& p) {
    return Point(p[0] - d, p[1] - d);
  }

  Point operator- (const Point& p) {
    return Point(-p[0], -p[1]);
  }

  Point operator^ (const Point& p, const Point& q) {
    return Point((p[0] + q[0]) / 2, (p[1] + q[1]) / 2);
  }

  Point operator* (const Point& p, const Point& q) {
    return Point(p[0] * q[0], p[1] * q[1]);
  }

  Point operator* (const Point& p, double d) {
    return Point(p[0] * d, p[1] * d);
  }

  Point operator* (double d, const Point& p) {
    return Point(p[0] * d, p[1] * d);
  }

  std::ostream& operator<< (std::ostream& os, const Point& p) {
    os << "(" << p[0] << ", " << p[1] << ")";
    return os;
  }

  std::istream& operator>> (std::istream& is, Point& p) {
    double x, y;
    is >> x >> y;
    p = Point(x, y);
    return is;
  }



} // end hlp2 namespace

///////////////////////////////////////////////////////////////////////////////
// define private stuff here [if any] in this anonymous namespace ...
namespace {
}
