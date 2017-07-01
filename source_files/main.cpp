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

#include "/hepstore/rjones/Exercises/Unfolding_General/headers/all_headers.h"

using namespace xsec;

int main_func(){
    
    Event ev; 

    ev.Add( Particle( 2212, 0.4, 0.8 ) );
    ev.Add( Particle( 13,   0.12, 0.8 ) );

    std::cout << "----- Testing event class -----" << std::endl;
    std::cout << ev << std::endl;

    return 0;

}
