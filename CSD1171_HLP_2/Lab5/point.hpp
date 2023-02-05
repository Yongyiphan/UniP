// make sure to provide file-level documentation and function-level
// documentation for each function that you'll implement to avoid
// unnecessary grade deductions.

/*!*****************************************
 \file      point.hpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Lab 5
 \date      04-02-2023
 \brief     File-header Documentation for point.hpp
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
////////////////////////////////////////////////////////////////////////////////
#ifndef POINT_HPP
#define POINT_HPP
////////////////////////////////////////////////////////////////////////////////

#include <iostream> // istream, ostream

namespace hlp2 {
	
class Point {
public:
	// declare constructors (3)
    /*
    \brief      Default constructor, x and y variables are initialized to 0
    */
    Point (void);
    /*
    \brief      Constructor that takes in two points
    \param[in]  ix -> point at x axis
    \param[in]  iy -> point at y axis
    */
    Point (double ix, double iy);
    /*
    \brief      Constructor that takes in a pointer to array that constains two consecutive points
    \param[in]  p -> point at x axis
    */
    Point (double* p);

    // declare overloaded operators (8 member functions)
    /*
    \brief      Overload operator for subscript accessor
    \param[in]  i -> index to retrieve either point's x or y
    */
    double& operator[] (int i);

    /*
    \brief      Overload operator for subscript accessor
    \param[in]  i -> index to retrieve either point's x or y
    */
    const double& operator[] (int i) const;

    /*
    \brief      Overload operator for addition assignemt
    \param[in]  b -> second point to be added to current object
    */
    Point &operator+=(const Point& b);

    /*
    \brief      Overload operator for addition assignemt
    \param[in]  p -> value to be added to both variable for the current object
    */
    Point &operator+=(double p);

    /*
    \brief      Overload operator for subtraction assignemt
    \param[in]  a -> second point to be deducted from current object
    */
    Point &operator-=(const Point& a);

    /*
    \brief       Overload operator for prefix increment
    */
    Point &operator++();    //Pre

    /*
    \brief      Overload operator for postfix increment
    \param[in]  (int) dummy variable
    */
    Point operator++(int);  //Post

    /*
    \brief      Overload operator for prefix decrement 
    */
    Point &operator--();    //Pre

    /*
    \brief      Overload operator for postfix decrement 
    \param[in]  (int) dummy variable
    */
    Point operator--(int);  //Pos




	// declare overloaded operators (8 member functions)

private:
	double x; // The x-coordinate of a Point
	double y; // The y-coordinate of a Point
};
  
// declare 15 non-member, non-friend functions 
//Rotation
/*
\brief      Overload operator % for adding rotation to a point
\param[in]  a   -> Point to be rotated
\param[in]  d   -> Degrees of rotation to be applied
*/
Point operator%(const Point& a, double d);

/*
\brief      Overload operator / for calculating the distance between 2 given point
\param[in]  a   -> first point
\param[in]  b   -> second point
\return     (double)        -> the distance between the given points
*/
double operator/(const Point& a, const Point& b);

//Translation +
/*
\brief      Overload operator + for adding two points
\param[in]  a   -> first point
\param[in]  b   -> second point
\return     (Point)         -> Point with updated values
*/
Point operator+(const Point& a, const Point& b);

/*
\brief      Overload operator + for adding a value to both variable of the given point
\param[in]  a   -> Point to add value to
\param[in]  v   -> value to be added to the point
\return     (Point)         -> Point with updated values
*/
Point operator+(const Point& a, double v);

/*
\brief      Overload operator + for adding a value to both variable of the given point
\param[in]  v   -> value to be added to the point
\param[in]  a   -> Point to add value to
\return     (Point)         -> Point with updated values
*/
Point operator+(double v, const Point& a);

//Translation -
/*
\brief      Overload operator - for subtracting two points
\param[in]  a   -> first point
\param[in]  b   -> second point
\return     (Point)         -> Point with updated values
*/
Point operator-(const Point& a, const Point& b);

/*
\brief      Overload operator - for subtracting a value to both variable of the given point
\param[in]  a   -> Point to subtract value from
\param[in]  v   -> value to be subtracted from the point
\return     (Point)         -> Point with updated values
*/
Point operator-(const Point& a, double v);

/*
\brief      Overload operator - for subtracting a value to both variable of the given point
\param[in]  v   -> value to be subtracted from the point
\param[in]  a   -> Point to subtract value from
\return     (Point)         -> Point with updated values
*/
Point operator-(double v, const Point& a);
//Negation
/*
\brief      Overload operator - for negating a point's value
\param[in]  a   -> Point whose value is to be negated
\return     (Point)         -> Point with update values
*/
Point operator-(const Point& a);

//Mid Point
/*
\brief      Overload operator ^ for finding the mid-point of 2 given points
\param[in]  a   -> first point
\param[in]  b   -> second point
\return     (Point)         -> Point with updated values*/
Point operator^(const Point& a, const Point& b);

//Dot Product
/*
\brief      Overload operator * for finding the dot product of 2 given points
\param[in]  a   -> first point
\param[in]  b   -> second point*/
double operator*(const Point& a, const Point& b);

//Scale
/*
\brief      Overload operator * for scaling a point
\param[in]  a   -> Point to be scaled
\param[in]  v   -> value to scale the point with
\return     (Point) -> Point with updated value
*/
Point operator*(const Point& a, double v);

/*
\brief      Overload operator * for scaling a point
\param[in]  v   -> value to scale the point with
\param[in]  a   -> Point to be scaled
\return     (Point) -> Point with updated value
*/
Point operator*(double v, const Point& a);

//Output
/*
\brief      Overload operator << for printing out given point's value in a format
\param[in, out]  os  -> output stream
\param[in]  a   -> Point to print out
*/
std::ostream& operator<<(std::ostream& os, const Point& a);

//Input
/*
\brief      Overload operator >> for filling up a Point object with values from an input file
\param[in]  is  -> input stream
\param[in]  a   -> Point to be modified
*/
std::istream& operator>>(std::istream& is, Point& a);


} // end namespace hlp2

#endif // end POINT_HPP
////////////////////////////////////////////////////////////////////////////////
