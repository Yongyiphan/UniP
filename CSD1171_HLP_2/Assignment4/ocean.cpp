/*!*****************************************
 \file      ocean.cpp
 \author    Edgar Yong
 \par       DP email: y.yiphanedgar\@digipen.edu
 \par       Course: CSD 1171
 \par       Programming Assignment 4
 \date      05-02-2023
 \brief     File-header Documentation for ocean.cpp
 \brief     This file contains class with member functions to
            Create an Ocean Object and fill it with default values
            Destroy created ocean object
            Place Boat onto the ocean's grid
            Shoot onto the grid and check for damages done to boat and update fields accordingly

            GetShot = to get the stats of the boats' status
            DumpOcean print out the grid onto a text file
*/
#include "ocean.h"
#include <iostream>


namespace HLP2{
    namespace WarBoats{
        Ocean::Ocean(){}
        
        /*
        \brief      Constructor to create an ocean object and fill it with values
        \param[in]  num_boat to generate array to contain given number of boats
        \param[in]  hor_size number of columns in the grid
        \param[in]  ver_size number of rows in the grid
        */
        Ocean::Ocean(int num_boat, int hor_size, int ver_size){
            grid = new int[hor_size * ver_size];
            for(int i = 0; i < hor_size * ver_size; i++){
                grid[i] = DamageType::dtOK;
            }

            boats = new Boat[sizeof(Boat) * num_boat];
            for(int i = 0; i < num_boat; i++){
                this->boats[i] = Boat{0,0,oHORIZONTAL, Point{0,0}};
            }
            this->num_boats = num_boat;
            this->x = hor_size;
            this->y = ver_size;
            this->stats =  new ShotStats{0,0,0,0};
        }

        /*
        \brief      Destructor call for deleteing ocean object
        */
        Ocean::~Ocean(){
            //std::cout << "Delete triggered" << std::endl;
            delete[] this->boats;
            delete[] this->grid;
            delete stats;
        }

        /*
        \brief      Place a boat onto the ocean grid
        \param[in]  boat  -> const reference to the boat object
        \return     status stating whether the boat's place is allowed
        */
        BoatPlacement Ocean::PlaceBoat(const Boat&boat) const{
        
            //Edge Cases: Boat out of position:
            if (boat.position.x < 0 || boat.position.x >= x ||
                boat.position.y < 0 || boat.position.y >= y)
                return bpREJECTED;

            if(boat.ID > num_boats)
                return bpREJECTED;
            switch (boat.orientation)
            {
            case oHORIZONTAL:
                if((boat.position.x + BOAT_LENGTH )> x){
                    return bpREJECTED;
                }
                for(int i = 0; i< BOAT_LENGTH;i++){
                    if (grid[(boat.position.y * x) + boat.position.x +i] != DamageType::dtOK)
                        return bpREJECTED;
                }
                for(int i = 0;i<BOAT_LENGTH;i++){
                    //Change grid to boat id
                    grid[(boat.position.y * x) + boat.position.x +i] = boat.ID;
                }
            break;
            
            case oVERTICAL:
                if((boat.position.y + BOAT_LENGTH )> y){
                    return bpREJECTED;
                }
                for(int i =0; i<BOAT_LENGTH;i++){
                    if(grid[((boat.position.y + i) * x) + boat.position.x] != DamageType::dtOK){
                        return bpREJECTED;
                    }
                }
                for(int i = 0;i<BOAT_LENGTH;i++){
                    grid[((boat.position.y + i) * x) + boat.position.x] = boat.ID;
                }
            break;
            }

            return bpACCEPTED;
        }

        /*
        \brief      simulate shooting at the grid of boats
        \param[in]  coordinate -> reference to a point struct containing x, and y positions
        \return     a status representing is a boat is hit, sunk or the shot missed a boat
        */
        ShotResult Ocean::TakeShot(const Point&coordinate) const{
        
            if((coordinate.x < 0  || coordinate.x > x) || 
                (coordinate.y < 0  || coordinate.y > y)){
                return srILLEGAL;
            }

            //coord in 1D
            /*
            [0] [1] [2]
            [3] [4] [5] 
            [6] [7] [8]
            4 = 1 * 1 + 3  */
            int coord = coordinate.y * x + coordinate.x;
            if (coord > x * y){
                return srILLEGAL;
            }

            int V = grid[coord];
            //ok = 0
            if(V == DamageType::dtOK){ 
                stats->misses++;
                grid[coord] = DamageType::dtBLOWNUP;
                return srMISS;
            }
            //blownup = -1
            if(V == DamageType::dtBLOWNUP || (V > HIT_OFFSET )){
                stats->duplicates++;
                return srDUPLICATE;
            }

            if(V > 0 && V < HIT_OFFSET){
                stats->hits++;
                boats[V - 1].hits++;
                grid[coord] += HIT_OFFSET;
                if(boats[V - 1].hits == BOAT_LENGTH){
                    stats->sunk++;
                    return srSUNK;
                }
            }
            return srHIT;
        }
    
        /*
        \brief      Retrieve the stats of boats on the grid
        \return     a shotstat struct that contains values recorded in the ocean object
        */
        const ShotStats& Ocean::GetShotStats() const{
            return *stats;
        }
        /*
        \brief    Get ocean's grid
        \return   pointer to current grid
        */
        const int * Ocean::GetGrid() const{
            return grid;
        }
        /*
        \brief    Return current ocean object
        \return   reference to current object
        */
        const Ocean& Ocean::GetDimensions() const{
            return *this;
        }
    }
}