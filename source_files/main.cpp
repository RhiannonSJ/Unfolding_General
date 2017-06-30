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
#include "headers/event_class.h"

using namespace xsec;

int main_func(){

    // Make a new particle object
    // Set the values
    int pdg1    = 13;   // Muon
    double t1   = 0.03; // GeV 
    double cos1 = 0.9;  // Very forward-going

    Particle mu1(pdg1, t1, cos1);

    int pdg2    = 211;  // Pion
    double t2   = 0.08; // GeV 
    double cos2 = 0.6;  // Very forward-going
    
    Particle mu2(pdg2, t2, cos2);

    vector< Particle > part;
    part.push_back( mu1 );

    Event ev( part ); 

    std::cout << std::endl;
    std::cout << "----- Testing event class -----" << std::endl;
    std::cout << ev << std::endl;

    ev.Add( mu2 );

    std::cout << "----- Testing event class -----" << std::endl;
    std::cout << ev << std::endl;


    return 0;

}
