/* The Main 
 *
 *  Run all functions to get the cross section distributions
 *  for various final state topologies
 *
 * =============================================
 *
 *  Author: Rhiannon Jones
 *  Date  : July 2017
 *
 * =============================================
 */

#include "headers/particle_class.h"

using namespace xsec;

int main_func(){

    // Make a new particle object
    // Set the values
    int pdg    = 13;  // Muon
    double t   = 0.03; // GeV 
    double cos = 0.9; // Very forward-going

    Particle mu(pdg, t, cos);

    std::cout << std::endl;
    std::cout << "---- Testing particle class ----" << std::endl;
    std::cout << mu << std::endl;

    return 0;

}
