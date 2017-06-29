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
    double t   = 0.3; // GeV 
    double cos = 0.9; // Very forward-going

    Particle mu(pdg, t, cos);

    cout << " ===== Testing particle class ===== " << endl;
    cout << " ================================== " << endl;
    cout << " PDG : " << mu.GetPDG() << ", KE : " << mu.GetT() << ", cos(theta) : " << mu.GetCos() << endl;

    return 0;

}
