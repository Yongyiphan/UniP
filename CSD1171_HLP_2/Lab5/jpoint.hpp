////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace hlp2 {
	
	class Point {
	public:
		// declare constructors (3)
		Point (void) : x{0}, y{0} {}
		Point (double p, double q) : x{p}, y{q} {}
		Point (const double *p) : x(*p), y(*(p + 1)) {}

		// declare overloaded operators (8 member functions)
		double& operator[] (int i);
		const double& operator[] (int i) const;

		Point& operator++ ();
		Point operator++ (int);

		Point& operator-- ();
		Point operator-- (int);

		Point operator+ (const Point& p) const;
		Point operator+ (double d);

		Point operator- (const Point& p) const;
		Point operator- (double d);
		Point operator- (void);

		Point& operator+= (const Point& p);
		Point& operator+= (double d);
		Point& operator-= (const Point& p);

	private:
		double x; // The x-coordinate of a Point
		double y; // The y-coordinate of a Point
	};
		
	// declare 15 non-member, non-friend functions 
	Point operator% (const Point& p, double d);

	double operator/ (const Point& p, const Point& q);

	Point operator+ (const Point& p, double q);
	
	Point operator+ (double d, const Point& p);

	Point operator- (const Point& p, double d);

	Point operator- (double d, const Point& p);

	Point operator- (const Point& p);


	Point operator^ (const Point& p, const Point& q);

	Point operator* (const Point& p, const Point& q);

	Point operator* (const Point& p, double d);

	Point operator* (double d, const Point& p);

	std::ostream& operator<< (std::ostream& os, const Point& p);

	std::istream& operator>> (std::istream& is, Point& p);

} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
