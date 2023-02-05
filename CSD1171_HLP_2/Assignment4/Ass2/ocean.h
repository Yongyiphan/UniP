/*!*****************************************
 \file      ocean.h
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 2
 \date      19-01-2023
 \brief     File-header Documentation for ocean.h
 \brief     This file contains function to
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
    struct Ocean; //!< Forward declaration for the Ocean 

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

      // The interface
    /*
    \brief      Create an ocean object and fill it with values
    \param[in]  num_boat to generate array to contain given number of boats
    \param[in]  hor_size number of columns in the grid
    \param[in]  ver_size number of rows in the grid
    \return     A filled ocean object
    */
    Ocean* CreateOcean(int num_boats, int x_size, int y_size);
    
    
    /*
    \brief    Destroy/free the ocean object
    \param[in] theocean pointer to the ocean object
    */
    void DestroyOcean(Ocean *theOcean);
    
    
    /*
    \brief      Place a boat onto the ocean grid
    \param[in]  ocean -> reference to the ocean object
    \param[in]  boat  -> const reference to the boat object
    \return     status stating whether the boat's place is allowed
    */
    BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat);
    
    /*
    \brief      simulate shooting at the grid of boats
    \param[in]  ocean -> reference to the ocean object
    \param[in]  coordinate -> reference to a point struct containing x, and y positions
    \return     a status representing is a boat is hit, sunk or the shot missed a boat

    */
    ShotResult TakeShot(Ocean& ocean, Point const& coordinate);
    
    /*
    \brief      Retrieve the stats of boats on the grid
    \param[in]  ocean -> reference to the ocean object 
    \return     a shotstat struct that contains values recorded in the ocean object
    */
    ShotStats GetShotStats(Ocean const& ocean);

      // Provided
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
    void DumpOcean(const Ocean &ocean, int width = 4, bool extraline = false, 
                   bool showboats = true);

  } // namespace WarBoats

} // namespace HLP2

namespace HLP2 {
  namespace WarBoats {
      //! The attributes of the ocean
    struct Ocean {
      int *grid;        //!< The 2D ocean 
      Boat *boats;      //!< The dynamic array of boats
      int num_boats;    //!< Number of boats in the ocean
      int x_size;       //!< Ocean size along x-axis
      int y_size;       //!< Ocean size along y-axis
      ShotStats stats;  //!< Status of the attack
    };

    Ocean*CreateOcean(int num_boat, int hor_size, int ver_size);
    void DestroyOcean(Ocean * theocean);
    BoatPlacement PlaceBoat(Ocean &ocean, const Boat&boat);
  } // namespace WarBoats
} // namespace HLP2

#endif // OCEAN_H
////////////////////////////////////////////////////////////////////////////////
	

   