/*!*****************************************
 \file      ocean.h
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 2
 \date      05-02-2023
 \brief     File-header Documentation for ocean.h
 \brief     This file contains class with member functions to
            Create an Ocean Object and fill it with default values
            Destroy created ocean object
            Place Boat onto the ocean's grid
            Shoot onto the grid and check for damages done to boat and update fields accordingly

            GetShot = to get the stats of the boats' status
            DumpOcean print out the grid onto a text file
*/
////////////////////////////////////////////////////////////////////////////////
#ifndef OCEAN_H
#define OCEAN_H
////////////////////////////////////////////////////////////////////////////////

namespace HLP2 {
  namespace WarBoats {
    inline int const BOAT_LENGTH {4};
    inline int const HIT_OFFSET{100};
    class Ocean; //!< Forward declaration for the Ocean 

    enum Orientation   { oHORIZONTAL, oVERTICAL };
    enum ShotResult    { srHIT, srMISS, srDUPLICATE, srSUNK, srILLEGAL };
    enum DamageType    { dtOK = 0, dtBLOWNUP = -1 };
    enum BoatPlacement { bpACCEPTED, bpREJECTED };

      //! A coordinate in the Ocean
    struct Point {
      int x; //!< x-coordinate (column)
      int y; //!< y-coordinate (row)
    };

      //! A boat in the Ocean
    struct Boat {
      int hits;                 //!< Hits taken so far
      int ID;                   //!< Unique ID 
      Orientation orientation;  //!< Horizontal/Vertical
      Point position;           //!< x-y coordinate (left-top)
    };

      //! Statistics of the "game"
    struct ShotStats {
      int hits;       //!< The number of boat hits
      int misses;     //!< The number of boat misses
      int duplicates; //!< The number of duplicate (misses/hits)
      int sunk;       //!< The number of boats sunk
    };

  } // namespace WarBoats

} // namespace HLP2

namespace HLP2 {
  namespace WarBoats {
      //! The attributes of the ocean
    /*Class implementation of Ocean struc*/
    class Ocean{
      private:
        int *grid{nullptr};   //!< The 2D ocean 
        Boat *boats{nullptr}; //!< The dynamic array of boats
        int num_boats;        //!< Number of boats in the ocean

        ShotStats *stats;     //!< Status of the attack
      public:
        int x{0}, y{0};       //!<Ocean size along x and y axis
        //Default constructor for ocean class
        Ocean();
        /*
        \brief      Constructor to create an ocean object and fill it with values
        \param[in]  num_boat to generate array to contain given number of boats
        \param[in]  hor_size number of columns in the grid
        \param[in]  ver_size number of rows in the grid
        \return     A filled ocean object
        */
        Ocean(int num_boat, int hor_size, int ver_size);
        ~Ocean();

        /*
        \brief      Place a boat onto the ocean grid
        \param[in]  ocean -> reference to the ocean object
        \param[in]  boat  -> const reference to the boat object
        \return     status stating whether the boat's place is allowed
        */
        BoatPlacement PlaceBoat(const Boat&boat) const;

        /*
        \brief      simulate shooting at the grid of boats
        \param[in]  coordinate -> reference to a point struct containing x, and y positions
        \return     a status representing is a boat is hit, sunk or the shot missed a boat
        */
        ShotResult TakeShot(const Point& coordinate) const;
        
        /*
        \brief      Retrieve the stats of boats on the grid
        \return     a shotstat struct that contains values recorded in the ocean object
        */
        const ShotStats& GetShotStats() const;

        /*
        \brief    Get ocean's grid
        \return   pointer to current grid
        */
        const int* GetGrid() const;
        
        /*
        \brief    Return current ocean object
        \return   reference to current object
        */
        const Ocean&  GetDimensions() const;
    };
  } // namespace WarBoats
} // namespace HLP2

#endif // OCEAN_H
////////////////////////////////////////////////////////////////////////////////
	

   