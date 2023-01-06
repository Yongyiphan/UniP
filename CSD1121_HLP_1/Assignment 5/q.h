// @todo: Add a file-level documentation header as explained in Lab 2 specs ...
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 5 Computing Pi
@date 28/09/2022
@brief Contains the definition of 3 methods that calculate the
    approximation of Pi.

*//*______________________________________________________________________*/
// @todo: Provide function-level documentation header as explained in Assignment 2 specs ...
// It is important that you provide function-level documentation header in
// this [header] file since this file is what you would provide to your
// clients and other users to solve problems that require pi's value.
// In a commercial environment, the source file q.c containing definitions of
// functions that compute pi is your intellectual property and should therefore
// be kept private. Instead, you'll provide your clients object file q.o
// [obtained by only compiling q.c].
// Therefore, your clients will know how to use the three functions related to
// computing pi's value only by reading this function-level documentation header ...

// @todo: Now, provide the declarations or prototypes of necessary functions ...
//Trapezoid Method
//Using n no. of rect, fit it within a circle's quadrant
//Sum of rects' area will be approximation of PI's value
//Requires int number of rect, outputs double approx value of PI
double trapezoid_pi(int);
//Monte Carlo Method
//For number of iterations, 
//Plot number of points on top right quadrant of circle, 
//Evaulate points in quadrant / total points plotted to get approx value of PI
//Requires positive int seed value for rng, and number of point to generate, outputs double approx value of PI
double montecarlo_pi(unsigned int, int);
//Leibniz Method
double leibniz_pi(int);



