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
   
    // Typedef for the map
    typedef std::map< std::vector< int >, int > top_map; 
    
    // CC 0pi, 1pi event
    Event ev; 

    ev.Add( Particle( 2212, 0.05, 0.8 ) );
    ev.Add( Particle( 13,   0.05, 0.8 ) );

    // Map to hold chosen signal
    top_map signal_cc_0pi;

    std::vector< int > cc_0pi_mu;
    std::vector< int > cc_0pi_p;
    std::vector< int > cc_0pi_pi;
    
    cc_0pi_mu.push_back( 13 );
    cc_0pi_p.push_back( 2212 );
    cc_0pi_pi.push_back( 211 );
    cc_0pi_pi.push_back(-211 );
    cc_0pi_pi.push_back( 111 );
    
    signal_cc_0pi.insert( std::make_pair( cc_0pi_mu, 1 ) );
    signal_cc_0pi.insert( std::make_pair( cc_0pi_p,  1 ) );
    signal_cc_0pi.insert( std::make_pair( cc_0pi_pi, 0 ) );

    std::cout << "--------------------------------" << std::endl;
    std::cout << "--------- True CC 0pi ----------" << std::endl;
    std::cout << ev << std::endl;
    std::cout << ( ev.CheckIfTrue( true, signal_cc_0pi ) ? " True signal " : " Not true signal " ) << std::endl;
    std::cout << ( ev.CheckIfReconstructed( signal_cc_0pi ) ? " Reco signal " : " Not reco signal " ) << std::endl;
    std::cout << "--------------------------------" << std::endl;

    return 0;

}
