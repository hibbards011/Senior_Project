/*********************************************************************
* Program:
*   run_sim.cpp
* Author:
*   Samuel Hibbard
* Summary:
*   This will take in the object values and run the simulation.
*********************************************************************/

#include <iostream>
#include "sim.h"
#include "uiInteract.h"
using namespace std;

// Define the window size of the opengl
float Point::xMin = -700.0;
float Point::xMax = 700.0;
float Point::yMin = -400.0;
float Point::yMax = 400.0;

/****************************************
 * callBack
 *   This will run the simulator
 ***************************************/
void callBack(const Interface *pUI, void *p)
{
    // Grab the simulator
    Simulator *sim = (Simulator *) p;

    // Now run the simulation!
    sim->runSim(pUI);
}

/****************************************
 * main
 *  Main driver of the program.
 ***************************************/
int main(int argc, char ** argv)
{
    // Start the interface
    Interface ui(argc, argv, "Gravity");

    // Grab the simulator
    Simulator sim;

    // Now do the callback function
    ui.run(callBack, &sim);

    return 0;
}