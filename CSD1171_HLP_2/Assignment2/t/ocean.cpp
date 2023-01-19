#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2
{
  namespace WarBoats
  {
    int const BOAT_LENGTH{4};  //!< Length of a boat
    int const HIT_OFFSET{100}; //!< Add this to the boat ID

    Ocean *CreateOcean(int num_boats, int hor_size, int vert_size)
    {
      // dynamically allocating memory for an array of ints with hor*vert size
      // pointed to by grid
      Ocean *NewOcean = new Ocean();
      NewOcean->x_size = hor_size;
      NewOcean->y_size = vert_size;
      NewOcean->num_boats = num_boats;
      NewOcean->grid = new int[hor_size * vert_size];
      // setting each grid to constant dtOK
      for (int i = 0; i < hor_size * vert_size; i++)
      {
        NewOcean->grid[i] = DamageType::dtOK;
      }
      // setting member of stats to 0
      NewOcean->stats.duplicates = 0;
      NewOcean->stats.hits = 0;
      NewOcean->stats.misses = 0;
      NewOcean->stats.sunk = 0;
      // dynamically allocating memory for an array of Boat with size num_boats
      // setting hits and id of each boat to 0
      NewOcean->boats = new Boat[sizeof(Boat) * num_boats];
      for (int i = 0; i < num_boats; i++)
      {
        NewOcean->boats[i].hits = 0;
        NewOcean->boats[i].ID = 0;
        NewOcean->boats[i].orientation = oHORIZONTAL;
        NewOcean->boats[i].position.x = 0;
        NewOcean->boats[i].position.y = 0;
      }
      return NewOcean;
    }

    /**************************************************************************/
    /*!
      \brief
        DestroyOcean: Clean up by deallocating all previously allocated memory

      \param *theOcean
        pointer to allocated ocean
    */
    /**************************************************************************/
    void DestroyOcean(Ocean *theOcean)
    {
      delete[] theOcean->grid;
      delete[] theOcean->boats;
      delete theOcean;
    }

    /**************************************************************************/
    /*!
      \brief
        PlaceBoat: Create and record boat's placement specified by user

      \param ocean
        pointer to ocean

      \param boat
        pointer to boat array
    */
    /**************************************************************************/
    BoatPlacement PlaceBoat(Ocean &ocean, Boat const &boat)
    {
      // checks if its inside the ocean
      if (boat.position.x < 0 || boat.position.x >= ocean.x_size ||
          boat.position.y < 0 || boat.position.y >= ocean.y_size)
      {
        return bpREJECTED;
      }
      // check if boat id is more than num_boats
      if (boat.ID > ocean.num_boats)
      {
        return bpREJECTED;
      }
      // check if boat with given boat length fits in ocean and does not overlap
      if (boat.orientation == oHORIZONTAL)
      {
        if ((boat.position.x + BOAT_LENGTH) > ocean.x_size)
          return bpREJECTED;
        for (int i = 0; i < BOAT_LENGTH; i++)
        {
          if (ocean.grid[(boat.position.y * ocean.x_size) + boat.position.x + i] != DamageType::dtOK)
          {
            return bpREJECTED;
          }
        }
      }
      else
      {
        if ((boat.position.y + BOAT_LENGTH) > ocean.y_size)
          return bpREJECTED;
        for (int i = 0; i < BOAT_LENGTH; i++)
        {
          if (ocean.grid[((boat.position.y + i) * ocean.x_size) + boat.position.x] != DamageType::dtOK)
          {
            return bpREJECTED;
          }
        }
      }
      // change grid to boat id if selection is legal
      for (int i = 0; i < BOAT_LENGTH; i++)
      {
        if (boat.orientation == oHORIZONTAL)
        {
          ocean.grid[(boat.position.y * ocean.x_size) + boat.position.x + i] = boat.ID;
        }
        else
        {
          ocean.grid[((boat.position.y + i) * ocean.x_size) + boat.position.x] = boat.ID;
        }
      }
      return bpACCEPTED;
    }

    /**************************************************************************/
    /*!
      \brief
        Pick a coordinate in the ocean and returns the result of shot

      \param ocean
        Pointer to ocean

      \param coordinate
        position selected
    */
    /**************************************************************************/
    ShotResult TakeShot(Ocean &ocean, Point const &coordinate)
    {
      // check if coordinate selected is within ocean
      if (coordinate.x < 0 || coordinate.x >= ocean.x_size ||
          coordinate.y < 0 || coordinate.y >= ocean.y_size)
      {
        return srILLEGAL;
      }
      // get coord
      int cord = (coordinate.y * ocean.x_size) + coordinate.x;
      if (cord >= (ocean.x_size * ocean.y_size))
      {
        return srILLEGAL;
      }
      // check if cord selected misses a boat
      if (ocean.grid[cord] == DamageType::dtOK)
      {
        ocean.stats.misses += 1;
        ocean.grid[cord] = DamageType::dtBLOWNUP;
        return srMISS;
      }
      // check if cord selected is duplicated shot
      if (ocean.grid[cord] == DamageType::dtBLOWNUP || (ocean.grid[cord] > HIT_OFFSET))
      {
        ocean.stats.duplicates += 1;
        return srDUPLICATE;
      }
      // check if cord selected hits a boat
      if (ocean.grid[cord] != DamageType::dtOK && (ocean.grid[cord] > 0 && ocean.grid[cord] < HIT_OFFSET))
      { 
        int boat_id = 0;
        for(int i = 0; i < ocean.num_boats ; i++ ){
          if(ocean.grid[cord]== i)boat_id = i;
        }
        ocean.stats.hits += 1;
        ocean.boats[boat_id].hits += 1;
        ocean.grid[cord] += HIT_OFFSET;
        if (ocean.boats[boat_id].hits == BOAT_LENGTH)
        {
          ocean.stats.sunk += 1;
          return srSUNK;
        }
      }
      return srHIT;
    }

    /**************************************************************************/
    /*!
      \brief
        returns shot statistic values

      \param ocean
        pointer to ocean
    */
    /**************************************************************************/
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
                   bool showboats)
    {
      for (int y = 0; y < ocean.y_size; y++)
      { // For each row
        for (int x = 0; x < ocean.x_size; x++)
        { // For each column
          // Get value at x/y position
          int value = ocean.grid[y * ocean.x_size + x];
          // Is it a boat that we need to keep hidden?
          value = ((value > 0) && (value < HIT_OFFSET) && (showboats == false)) ? 0 : value;
          std::cout << std::setw(field_width) << value;
        }
        std::cout << "\n";
        if (extraline)
        {
          std::cout << "\n";
        }
      }
    }
  } // namespace WarBoats
} // namespace HLP2
