#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
    int const BOAT_LENGTH {4};   //!< Length of a boat
    int const HIT_OFFSET  {100}; //!< Add this to the boat ID

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE 
    */
    Ocean*CreateOcean(int num_boat, int hor_size, int ver_size){
      /*
      TODO:
        Dynamically allocate array of int of hor_size * ver_size elements
        3 new statements; #IMPT
      */
     int *grid = new int[hor_size * ver_size];
     for(int i = hor_size*ver_size;i--; grid[i] = DamageType::dtOK);


     Boat *b = new Boat[num_boat];
     for(int i = num_boat; i--; b[i] = {0,0});

     return new Ocean{grid, b, num_boat, hor_size, ver_size, {0,0,0,0}};
    }

    void DestroyOcean(Ocean *theocean){
      delete[] theocean->boats;
      delete[] theocean->grid;
      delete theocean;
    }

    BoatPlacement PlaceBoat(Ocean &ocean, const Boat&boat){

    /*struct Boat {
      int hits;                 //!< Hits taken so far
      int ID;                   //!< Unique ID 
      Orientation orientation;  //!< Horizontal/Vertical
      Point position;           //!< x-y coordinate (left-top)
    };

    struct Ocean {
      int *grid;        //!< The 2D ocean 
      Boat *boats;      //!< The dynamic array of boats
      int num_boats;    //!< Number of boats in the ocean
      int x_size;       //!< Ocean size along x-axis
      int y_size;       //!< Ocean size along y-axis
      ShotStats stats;  //!< Status of the attack
    };
    The client will create a boat, specify a position to locate this boat in the ocean, 
    and then call this function to record the boat's placement in the ocean. 
    Think about all the things that would make a boat be invalid for placement: 
      the boat's position may be outside the ocean; 
      even if the boat's position is inside the ocean, the boat has a finite size [with length BOAT_LENGTH which is a
      constant variable defined in ] and a portion of the boat may lie outside the ocean;
      or, the boat's position(s) might be occupied by previously placed boat(s).

      Given the ocean's dimensions, it is straightforward to determine if the boat's position is outside
      the ocean. For a boat of length BOAT_LENGTH to fit in the ocean, it must be completely inside the
      ocean and not overlap with another previously positioned boat. This can be checked using the
      boat's position and orientation. If the boat can fit in the ocean, determining whether these
      positions are already occupied by other boats is also straightforward. Straightforward because
      function CreateOcean has initialized the ocean's grid with value DamageType::dtOK .
      The return value indicates whether or not the boat could be placed in the ocean. See for
      valid values of type BoatPlacement
    */
   

    //Edge Cases: Boat out of position:
    if(boat.position.x * boat.position.y >= )



    }

    /**************************************************************************/
    /*!
      \brief
        Prints the grid (ocean) to the screen.
      
      \param ocean
        The Ocean to print
      
      \param field_width
        How much space each position takes when printed.
      
      \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.
        
      \param showboats
        If true, the boats are shown in the output. (Debugging feature)
    */
    /**************************************************************************/
    void DumpOcean(const HLP2::WarBoats::Ocean &ocean,
                                    int field_width, 
                                    bool extraline, 
                                    bool showboats) {
      for (int y = 0; y < ocean.y_size; y++) { // For each row
        for (int x = 0; x < ocean.x_size; x++) { // For each column
            // Get value at x/y position
          int value = ocean.grid[y * ocean.x_size + x];
            // Is it a boat that we need to keep hidden?
          value = ( (value > 0) && (value < HIT_OFFSET) && (showboats == false) ) ? 0 : value;
          std::cout << std::setw(field_width) << value;
        }
        std::cout << "\n";
        if (extraline) { std::cout << "\n"; }
      }
    }
  } // namespace WarBoats
} // namespace HLP2
