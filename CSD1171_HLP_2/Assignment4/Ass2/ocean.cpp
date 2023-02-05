/*!*****************************************
 \file      ocean.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 2
 \date      19-01-2023
 \brief     File-header Documentation for ocean.cpp
 \brief     This file contains function to
            Create an Ocean Object and fill it with default values
            Destroy created ocean object
            Place Boat onto the ocean's grid
            Shoot onto the grid and check for damages done to boat and update fields accordingly

            GetShot = to get the stats of the boats' status
            DumpOcean print out the grid onto a text file
*/
#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
    int const BOAT_LENGTH {4};   //!< Length of a boat
    int const HIT_OFFSET  {100}; //!< Add this to the boat ID

    /*
    \brief      Create an ocean object and fill it with values
    \param[in]  num_boat to generate array to contain given number of boats
    \param[in]  hor_size number of columns in the grid
    \param[in]  ver_size number of rows in the grid
    \return     A filled ocean object
    */
    Ocean*CreateOcean(int num_boat, int hor_size, int ver_size){
     int *grid = new int[hor_size * ver_size];
     for(int i = 0; i < hor_size*ver_size; i++){
      grid[i] = DamageType::dtOK;
     }


     Boat *b = new Boat[sizeof(Boat) * num_boat];
     for(int i = 0; i < num_boat; i++){
      b[i] = {0,0,oHORIZONTAL, 0,0};
     }

     return new Ocean{grid, b, num_boat, hor_size, ver_size, {0,0,0,0}};
    }

    /*
    \brief    Destroy/free the ocean object
    \param[in] theocean pointer to the ocean object
    */
    
    void DestroyOcean(Ocean *theocean){
      delete[] theocean->boats;
      delete[] theocean->grid;
      delete theocean;
    }

    /*
    \brief      Place a boat onto the ocean grid
    \param[in]  ocean -> reference to the ocean object
    \param[in]  boat  -> const reference to the boat object
    \return     status stating whether the boat's place is allowed
    */
    BoatPlacement PlaceBoat(Ocean &ocean, const Boat&boat){
   
    //Edge Cases: Boat out of position:
    if (boat.position.x < 0 || boat.position.x >= ocean.x_size ||
        boat.position.y < 0 || boat.position.y >= ocean.y_size)
    {
      return bpREJECTED;
    }

    if(boat.ID > ocean.num_boats){
      return bpREJECTED;
    }
    switch (boat.orientation)
    {
    case oHORIZONTAL:
      if((boat.position.x + BOAT_LENGTH )> ocean.x_size){
        return bpREJECTED;
      }
      for(int i = 0; i< BOAT_LENGTH;i++){
        if (ocean.grid[(boat.position.y * ocean.x_size) + boat.position.x +i] != DamageType::dtOK)
          return bpREJECTED;
      }
      for(int i = 0;i<BOAT_LENGTH;i++){
        //Change grid to boat id
        ocean.grid[(boat.position.y * ocean.x_size) + boat.position.x +i] = boat.ID;
      }
      break;
      
    case oVERTICAL:
      if((boat.position.y + BOAT_LENGTH )> ocean.y_size){
        return bpREJECTED;
      }
      for(int i =0; i<BOAT_LENGTH;i++){
        if(ocean.grid[((boat.position.y + i) * ocean.x_size) + boat.position.x] != DamageType::dtOK){
          return bpREJECTED;
        }
      }
      for(int i = 0;i<BOAT_LENGTH;i++){
        ocean.grid[((boat.position.y + i) * ocean.x_size) + boat.position.x] = boat.ID;
      }
      break;
    }

    return bpACCEPTED;
    }


    /*
    \brief      simulate shooting at the grid of boats
    \param[in]  ocean -> reference to the ocean object
    \param[in]  coordinate -> reference to a point struct containing x, and y positions
    \return     a status representing is a boat is hit, sunk or the shot missed a boat

    */
    ShotResult TakeShot(Ocean&ocean, Point const &coordinate){
      
      if((coordinate.x < 0  || coordinate.x > ocean.x_size) || 
         (coordinate.y < 0  || coordinate.y > ocean.y_size)){
          return srILLEGAL;
      }

      //coord in 1D
      /*
      [0] [1] [2]
      [3] [4] [5] 
      [6] [7] [8]
      4 = 1 * 1 + 3  */
      int coord = coordinate.y * ocean.x_size + coordinate.x;
      if (coord > ocean.x_size * ocean.y_size){
        return srILLEGAL;
      }
      int V = ocean.grid[coord];
      //ok = 0
      if(V == DamageType::dtOK){ 
        ocean.stats.misses++;
        ocean.grid[coord] = DamageType::dtBLOWNUP;
        return srMISS;
      }
      //blownup = -1
      if(V == DamageType::dtBLOWNUP || (V > HIT_OFFSET )){
        ocean.stats.duplicates++;
        return srDUPLICATE;
      }

      if(V > 0 && V < HIT_OFFSET){
        ocean.stats.hits++;
        ocean.boats[V - 1].hits++;
        ocean.grid[coord] += HIT_OFFSET;
        if(ocean.boats[V - 1].hits == BOAT_LENGTH){
          ocean.stats.sunk++;
          return srSUNK;
        }
      }
      return srHIT;
    }

    /*
    \brief      Retrieve the stats of boats on the grid
    \param[in]  ocean -> reference to the ocean object 
    \return     a shotstat struct that contains values recorded in the ocean object
    */
    ShotStats GetShotStats(Ocean const &ocean)
    {
      ShotStats stats;
      stats.duplicates = ocean.stats.duplicates;
      stats.hits = ocean.stats.hits;
      stats.misses = ocean.stats.misses;
      stats.sunk = ocean.stats.sunk;
      return stats;
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
