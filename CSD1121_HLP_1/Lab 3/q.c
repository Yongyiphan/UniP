// @todo: Add a file documentation header as explained in the specs ...
// Provide file-level documentation block as described in tutorial specification
/*!
@file q.c
@author yong yip han edgar (y.yiphanedgar) 
@course RTIS CSD1121 
@section csd1121-a.sg
@tutorial Lab 3: Problem Solving, I/O, and Expressions
@date 09/16/2022
@brief Contains implementaiton for 
        tile() 
        to calculate number of tiles at a given wall length and tile width
        dispense_change()
        to calculate change at a given item's cost and money input
*//*______________________________________________________________________*/
// @todo: Add necessary C standard library headers here ...
#include <stdio.h>

// You should document [not necessary for grading but an excellent habit
// to acquire] your implementation of function tile to aid
// in debugging and maintenance not only by yourself but by others in
// your software development team ...

// Remember, the function-level documentation header in q.h is primarily
// meant for your clients. The documentation header here is primarily for
// use by you [and other on your team] solely to aid maintenance and
// debugging tasks ...


// @todo: Provide the definition of function tile that
// matches the declaration in q.h ...

//receive an input for wall length and tile's width
//to return number of tiles that can fit within the given wall length
void tile(double wallLength, double tileWidth){

    //get number of pairs of tiles (black and white) within the remaining wall length
    //assuming the first tile is black
    int NoPairs = (int) ((wallLength - tileWidth) / (2 * tileWidth));
    //get total number of tiles
    //using no of pairs found and inclusive of the first black tile. 
    int NoTiles = 1 + 2 * NoPairs;
    //gap at each end of the wall
    double GapAtEachEnd = (wallLength - NoTiles * tileWidth) /2;
    printf("Wall length: %.2f | Tile width: %.2f\n", wallLength, tileWidth);
    printf("Number of tiles: %d\n", NoTiles);
    printf("Gap at each end: %.2f\n", GapAtEachEnd);
}

// Add documentation [for yourself and not for grading] for function dispense_change ...

// @todo: Provide the definition of function dispense_change that
// matches the declaration in q.h ...

//asks for user input and returns change broken down into parts
void dispense_change(void){
    //loonies [dollar coins], 
    //half-loonies [50 cent coins], 
    //quarters [25 cent coins], 
    //dimes [10 cent coins], 
    //nickels [5 cent coins],
    //pennies [1 cent coins]

    //printf("Enter a price in dollars and cents and notes input in dollars: ");
    int dollars, cents, minput;
    scanf("%d.%d %d", &dollars, &cents, &minput);

    //Calcuation for change
    int loonies, halfLoonies, quarters, dimes, nickels, pennies;
    //Covnert dollar input into cents and 
    //getting the total change after subtracting items' purchase price
    int change = minput * 100 - (dollars * 100 + cents);
    
    //calculate no of loonies
    loonies = change / 100;
    //get the remainder change after subtracting loonies' worth
    change -= loonies * 100;
    
    //calculate no of half loonies
    halfLoonies = change / 50;
    //get the remainder change after subtracting half loonies' worth
    change -= halfLoonies * 50;

    //calculate no of quarters
    quarters = change / 25;
    //get the remainder change after subtracting quarter's worth
    change -= quarters * 25;
    //calcualte no of dimes
    dimes = change / 10;
    //get the remainder change after subtracting dimes' worth
    change -= dimes * 10;
    //calculate no of nickels
    nickels = change / 5;
    //get the remainder change after subtracting nickel's worth
    change -=  nickels * 5;
    //calcualte no of pennies
    pennies = change / 1;

    //print the make up of change 
    printf("%d loonies + %d half-loonies + %d quarters + %d dimes + %d nickels + %d pennies\n",loonies, halfLoonies, quarters, dimes, nickels, pennies  );
}

