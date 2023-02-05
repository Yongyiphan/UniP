// Since your clients will not have access to this file, your initial
// inclination will be to avoid documenting this file ...
// However, since you're a client too and will need to understand this
// file's contents at a later point in time, the documentation you provide
// now will make the process of maininting this code base easier and more
// efficient.
// Therefore, make sure to provide file-level documentation and some
// function-level documentation for each function that you'll implement to
// avoid unnecessary grade deductions.

/*!*****************************************
 \file      point.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 5
 \date      04-02-2023
 \brief     File-header Documentation for point.cpp
 \brief     Contains delcaration of class Point
            Implementation of class contains overloader for operators and constructors
            private variables of point's x, y
            3 variant of constructors
            overloader for operators:
                [] subscript accessor
                += addition and assignment
                -= subtraction and assignment
                ++ pre/post fix increment
                -- pre/post fix decrement
            Non member functions overload for
                % to calculate rotations of point at angle
                / to calculate distance between 2 given points
                +, - addition and subtraction of 
                    two points
                    a point and a double
                - negation of a point
                ^ to calculate the mid-point between 2 given points
                * to calculate the dot product of 2 given points
                * scale a point given either another point, or a scalar
                << print out point's value to an output stream
                >> retrieve and fill a point with values from an input stream

*/
#include "point.hpp"  // Point interface
#include <cmath>      // sin, cos, sqrt

///////////////////////////////////////////////////////////////////////////////
// declare private stuff here [if any] in this anonymous namespace ...
namespace {
    double const PI = {3.14159265358979323846};
    double const EPSILON = {0.00001};
}

///////////////////////////////////////////////////////////////////////////////

namespace hlp2 {
    // define 3 constructors
    /*
    \brief      Default constructor, x and y variables are initialized to 0
    */
    Point::Point():x(0), y(0){}
    /*
    \brief      Constructor that takes in two points
    \param[in]  ix -> point at x axis
    \param[in]  iy -> point at y axis
    */
    Point::Point(double ix, double iy):x(ix), y(iy){}
    /*
    \brief      Constructor that takes in a pointer to array that constains two consecutive points
    \param[in]  p -> point at x axis
    */
    Point::Point(double *p){
        this->x = *p;
        this->y = *(p+1);
    }

    /*
    \brief      Overload operator for subscript accessor
    \param[in]  i -> index to retrieve either point's x or y
    */
    double& Point::operator[](int i){
        return i && i < 2 ? this->y : this->x;
    }

    /*
    \brief      Overload operator for subscript accessor
    \param[in]  i -> index to retrieve either point's x or y
    */
    const double& Point::operator[](int i) const{
        return i && i < 2 ? this->y : this->x;
    }

    /*
    \brief      Overload operator for addition assignemt
    \param[in]  p -> second point to be added to current object
    */
    Point& Point::operator+=(const Point& p){
        this->x += p[0];
        this->y += p[1];
        return  *this;
    }

    /*
    \brief      Overload operator for addition assignemt
    \param[in]  p -> value to be added to both variable for the current object
    */
    Point& Point::operator+=(double p){
        this->x += p;
        this->y += p;
        return *this;
    }

    /*
    \brief      Overload operator for subtraction assignemt
    \param[in]  p -> second point to be deducted from current object
    */
    Point& Point::operator-=(const Point& p){
        this->x -= p[0];
        this->y -= p[1];
        return *this;
    }

    //Prefix
    /*
    \brief       Overload operator for prefix increment
    */
    Point& Point::operator++(){
        this->x++;
        this->y++;
        return *this;
    }
    //Postfix
    /*
    \brief      Overload operator for postfix increment
    \param[in]  (int) dummy variable
    */
    Point Point::operator++(int){
        Point temp = *this;
        ++*this;
        return temp;
    }

    //Prefix
    /*
    \brief      Overload operator for prefix decrement 
    */
    Point& Point::operator--(){
        this->x--;
        this->y--;
        return *this;
    }
    //Postfix
    /*
    \brief      Overload operator for postfix decrement 
    \param[in]  (int) dummy variable
    */
    Point Point::operator--(int){
        Point temp = *this;
        --*this;
        return temp;
    }

    //Rotation
    /*
    \brief      Overload operator % for adding rotation to a point
    \param[in]  a   -> Point to be rotated
    \param[in]  d   -> Degrees of rotation to be applied
    */
    Point operator%(const Point& a, double d){
        double rad = d * PI / 180;
        /* Matrix for rotation
        | x | | cos(0), -sin(0)|
        | y | | sin(0),  cos(0)|
        */
       double cosv = cos(rad), sinv = sin(rad);
       //-0.0 check
       //cosv = (cosv > -EPSILON && cosv < EPSILON) ? 0.0 : cosv;
       //sinv = (sinv > -EPSILON && sinv < EPSILON) ? 0.0 : sinv;
        return Point(a[0] * cosv - a[0] * sinv,
                     a[1] * sinv + a[1] * cosv);
    }

    //Distance
    /*
    \brief      Overload operator / for calculating the distance between 2 given point
    \param[in]  a   -> first point
    \param[in]  b   -> second point
    \return     (double)        -> the distance between the given points
    */
    double operator/(const Point& a, const Point&b){
        return sqrt(pow(a[0] - b[0],2) + pow(a[1] - b[1], 2));
    }

    //Translation +
    /*
    \brief      Overload operator + for adding two points
    \param[in]  a   -> first point
    \param[in]  b   -> second point
    \return     (Point)         -> Point with updated values
    */
    Point operator+(const Point&a, const Point&b){
        return Point(a[0] + b[0], a[1] + b[1]);
    }

    /*
    \brief      Overload operator + for adding a value to both variable of the given point
    \param[in]  a   -> Point to add value to
    \param[in]  v   -> value to be added to the point
    \return     (Point)         -> Point with updated values
    */
    Point operator+(const Point &a, double v){
        return Point(a[0] + v, a[1] + v);
    }

    /*
    \brief      Overload operator + for adding a value to both variable of the given point
    \param[in]  v   -> value to be added to the point
    \param[in]  a   -> Point to add value to
    \return     (Point)         -> Point with updated values
    */
    Point operator+(double v, const Point&a){
        return Point(v + a[0], v + a[1]);
    }

    //Translation -
    /*
    \brief      Overload operator - for subtracting two points
    \param[in]  a   -> first point
    \param[in]  b   -> second point
    \return     (Point)         -> Point with updated values
    */
    Point operator-(const Point&a, const Point&b){
        return Point(a[0] - b[0], a[1] - b[1]);
    }

    /*
    \brief      Overload operator - for subtracting a value to both variable of the given point
    \param[in]  a   -> Point to subtract value from
    \param[in]  v   -> value to be subtracted from the point
    \return     (Point)         -> Point with updated values
    */
    Point operator-(const Point &a, double v){
        return Point(a[0] - v, a[1] - v);
    }

    /*
    \brief      Overload operator - for subtracting a value to both variable of the given point
    \param[in]  v   -> value to be subtracted from the point
    \param[in]  a   -> Point to subtract value from
    \return     (Point)         -> Point with updated values
    */
    Point operator-(double v, const Point&a){
        return Point(v - a[0], v - a[1]);
    }

    //Negation
    /*
    \brief      Overload operator - for negating a point's value
    \param[in]  a   -> Point whose value is to be negated
    \return     (Point)         -> Point with update values
    */
    Point operator-(const Point& a){
        return Point(-a[0], -a[1]);
    }

    //Mid Point
    /*
    \brief      Overload operator ^ for finding the mid-point of 2 given points
    \param[in]  a   -> first point
    \param[in]  b   -> second point
    \return     (Point)         -> Point with updated values*/
    Point operator^(const Point &a, const Point& b){
        return Point(   (a[0] + b[0]) / 2, 
                        (a[1] + b[1]) / 2);
    }

    //Dot Product
    /*
    \brief      Overload operator * for finding the dot product of 2 given points
    \param[in]  a   -> first point
    \param[in]  b   -> second point*/
    double operator*(const Point& a, const Point& b){
        return (a[0] * b[0]) + (a[1] * b[1]);
    }

    //Scale
    /*
    \brief      Overload operator * for scaling a point
    \param[in]  a   -> Point to be scaled
    \param[in]  v   -> value to scale the point with
    \return     (Point) -> Point with updated value
    */
    Point operator*(const Point& a, double v){
        return Point(   a[0] * v,
                        a[1] * v);
    }

    /*
    \brief      Overload operator * for scaling a point
    \param[in]  v   -> value to scale the point with
    \param[in]  a   -> Point to be scaled
    \return     (Point) -> Point with updated value
    */
    Point operator*(double v, const Point& a){
        return Point(   a[0] * v,
                        a[1] * v);
    }

    //Output
    /*
    \brief      Overload operator << for printing out given point's value in a format
    \param[in, out]  os  -> output stream
    \param[in]  a   -> Point to print out
    */
    std::ostream& operator<< (std::ostream& out, const Point&p){
        out << "(" << p[0] << ", " << p[1] << ")";
        return out;

    }

    //Input
    /*
    \brief      Overload operator >> for filling up a Point object with values from an input file
    \param[in]  is  -> input stream
    \param[in]  a   -> Point to be modified
    */
    std::istream& operator>>(std::istream& in, Point& p){
        double x, y;
        in >> x >> y;
        p = Point(x, y);
        return in;
    }





} // end hlp2 namespace

///////////////////////////////////////////////////////////////////////////////
// define private stuff here [if any] in this anonymous namespace ...
namespace {
}


