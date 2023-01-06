// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Assignment 5 Computing Pi
@date 28/09/2022
@brief Contains the implementation of 3 methods that calculate the
    approximation of Pi.

*//*______________________________________________________________________*/
// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of neccessary functions to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// @todo: Add necessary C standard library headers here ...

// @todo: Provide necessary definitions of functions
// that match corresponding declarations in q.h ...

//Trapezioid Method
/* 
    Consider a quarter circle with radius r =2
    From circle area formula area Pi * r^2. To computatinoally determine PI value is to 
    computer the quarter circle's area with radius 2 units. The trapezoid algo computers 
    the quarter circle area by dividing it into a series of rectangles. 
    These rectangles have similar width but different heights with a 
    particular rectangle's height chosen such that the circle's
    circumference passes through the midpoint of the retangle's top.
    Increasing the number of rectangles provides a closer approximation 
    of the circle's area
    and therefore a better approximation value for PI.
*/

double trapezoid_pi(int noRect){
    //assuming radius of ?
    //area of rect = w * h
    //value of w = noRect / 2 * noRect 
    //value of h = sqrt(r^2 - w^2)
    //Assuming a radius of 2.0
    //width of each rect = radius / n = 2 / n
    double PiApprox = 0.0, baseWidth = 2.0 / noRect;
    
    for(int i = 1; i <= noRect; i++){
        //no of rect - 1 half of base width;
        double width = i * baseWidth - baseWidth / 2;
        // using pythagoreas theorem, to get height
        double height = sqrt(4-width*width);
        PiApprox += height;
    }
    //total h * base width;
    PiApprox *= baseWidth;
    return PiApprox;
}

/*
    Consider a dartboard modeled as a 2 x 2 square centered at origin (0,0)
    with an inscribed circle C of radius 1
    Suppose you randomly throw a dart at dartboard S. If the dart strikes dartboard S
    at random point P. In the Monte Carlo method, the experiment will run for N trails
    In each trails, you'll randomly throw a dart and record position P and determine if P is also 
    inside C. At the end of the experimant, you'll have a count n of the number of times
    the dart is inside circle S. The ratio n/N will the provide an approximation of PI. 

    Because it is easier to generate positive random numbers, you will randomly throw a 
    dart at the upper-right quadrant of the dartboard shaded in green in the above figure to the right. 
    In this case, the probability that the random point at which the dart strikes dartboard is also in is PI/4. 
    To compute the approximate value of , you will then have to scale the result of the
    simulation by 4.

*/

double montecarlo_pi(unsigned int seed, int num_of_trails){

    double PiApprox, rand_x, rand_y, wCircle = 0;
    //wCircle = points within circle
    srand(seed);
    for(int i = 0; i < num_of_trails; i++){
        //Generate 2points from 0~1 i.e top right of circle
        rand_x =  (double) rand()/RAND_MAX * 1;
        rand_y =  (double) rand()/RAND_MAX * 1;
        //calculate distance from generated point to origin (0,0)
        // 1^2 >= (x-0)^2 + (y-0)^2;
        double dist = rand_x * rand_x + rand_y * rand_y;
        if (dist <= 1){
            wCircle += 1;
        }    
    }
    //No. point on circle / total number of points
    // == Pi / 4
    //Thefore result * 4 = Pi approx.
    PiApprox =  wCircle / num_of_trails * 4;
    return PiApprox;
}

/*
    Leibniz derived an infinite series of additions and subtraction to approximate PI.
    As the number of terms in the series increases, the approximation will be closer to
    the value of PI/4. 
*/

double leibniz_pi(int num_elements){
    //1/3 + 1/5 - 1/7 + 1/9
    //== 1/3 + 1/5 + 1/9 - 1/7
    
    double PiApprox = 4.0;    

    for(int i = 1; i<num_elements; i++){
        //mod curent iter to determine to add or subtract fraction
        int toaddorsub = i % 2;
        //evaluate fraction value
        double frac = 4.0 / (i*2 + 1);
        if(toaddorsub == 1){
            PiApprox -= frac;
        }
        else{
            PiApprox += frac;
        }
    }
    //PI = 4 - (Sum of fraction addtion/subtraction)
    return PiApprox;

}


//int main(void){
//    for (int i = 1; i< 20;i+=2){
//        printf("Iter %d: Trapezoid = %.12f | MonteCarlo = %.12f | Leibniz = %.12f\n", i, trapezoid_pi(i), montecarlo_pi(123456789U, i), leibniz_pi(i));
//    }
//    
//    printf("PI Approx: %f\n", leibniz_pi(3));    
//    return 0;
//}

