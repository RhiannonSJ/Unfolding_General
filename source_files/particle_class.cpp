/* Particle class
 *
 *  Hold the information for a single particle
 *      - PDG code
 *      - Kinetic energy
 *      - Opening angle
 *      - Smeared kinetic energy
 *      - Smeared opening angle
 *      - Is Visible?
 *      - Is Reconstructed?
 *
 * =============================================
 *
 *  Author: Rhiannon Jones
 *  Date  : July 2017
 *
 * =============================================
 */


#ifndef PARTICLE_CLASS_CPP
#define PARTICLE_CLASS_CPP

// Header file for all std::library and ROOT headers needed
#include "headers/particle_class.h"

namespace xsec{


    // Constructor
    //      
    //      PDG code
    //      Kinetic energy
    //      Opening angle
    Particle::Particle( int PDG, double T, double cos_theta ){
        
        // Define the member variables
        m_PDG       = PDG;
        m_T         = T;
        m_cos       = cos_theta;
    }

    // Getters
    //  PDG
    int Particle::GetPDG() const{
        return m_PDG;
    }
            
    //  True KE
    double Particle::GetT() const{
        return m_T;
    }

    //  True cos_theta
    double Particle::GetCos() const{
        return m_cos;
    }

    // Functions
    //  Check if the particle is reconstructed based on cuts and efficiency
    void CheckReco(){

        // Initialise random number generator
        TRandom *_rand;
        
        bool isReco;

        if( m_T < 0.05 ){
            isReco = false;
        }
    
        //CCQE efficiency as function of momentum from Fig10.b of uboone DocDB 7561
        double effmom[] = {0.79,0.95,0.975,0.98,0.98,0.99,0.99,0.995,1.0,1.0};
    
        //CCQE efficiency as function of theta from Fig10.c of uboone DocDB 7561
        double efftheta[] = {1,1,1,1,1,1,0.995,0.985,1,0.985,0.995,1,1,1,1,0.995,0.995,0.995,0.99,0.98,0.97,0.97,0.975,0.98,0.975,0.97,0.95,0.945,0.94,0.92,0.87,0.91};
    
        //Find position of muon momentum in momentum efficiency array
        int posmom = 9; 
    
        for( int i = 0; i < 10; i++ ){
    
            if( m_T < 0.1 * ( i+1 ) ) {
                posmom = i; 
                break;
            }
        }
    
        //Find position of muon angle in angle efficiency array
        int postheta = 0; 
    
        for( int j = 0; j < 32; j++ ){
    
            if( TMath::ACos(m_cos) < 0.09817 * ( j+1 ) ) {
                postheta = j; 
                break;
            }
        }
    
        //Don't have correlations between angle and momentum efficiencies, take the smallest value to be conservative
    
        double efficiency = 1; 
    
        if( effmom[ posmom ] < efftheta[ postheta ] ){
            efficiency = effmom[posmom];
        }
    
        else{
            efficiency = efftheta[postheta];
        }

        //Generate random number between 0 and 1
    
        double prob = _rand->Uniform(0,1);
    
        if( prob <= efficiency ){
            isReco = true;
        }

        else{
            isReco = false;
        }

    } // CheckReco

    // Containment
    bool isContained(){
        
        // Initialise random number generator
        TRandom *_rand;

        // Values from http://pdg.lbl.gov/2012/AtomicNuclearProperties/MUON_ELOSS_TABLES/muonloss_289.png
        double momentum[] = {0.047,0.056,0.068,0.085,0.100,0.153,0.176,0.222,0.287,0.392,0.495,0.900,1.101,1.502,2.103}; //GeV
        double range[] = {0.007,0.013,0.024,0.047,0.076,0.221,0.304,0.482,0.761,1.236,1.708,3.534,4.415,6.126,8.610}; //m
        
        // Find position of muon momentum in momentum array
        int pos = 15;
    
        for( int i = 0; i < 15; i++ ){
    
            if( m_T < momentum[i] ){
                pos = i; 
                break;
            }
        }
    
        //Use linear interpolation to calculate expected range in LAr
        double rmu = 0;
    
        if( pos == 15 ){
            rmu = 9;
        }
    
        else if( pos == 0 ){
            rmu = 0.007;
        }
    
        else{
            rmu = range[ pos-1 ] + ( m_T - momentum[ pos-1 ] ) * ( range[ pos ] - range[ pos-1 ] ) / ( momentum[ pos ] - momentum[ pos-1 ] );
        }
    
        //Generate a random position inside detector
    
        double zstart = _rand->Uniform(0,5.312);
    
        double ystart = _rand->Uniform(0,4.294);
    
        double xstart = _rand->Uniform(0,4.312);
    
        double phi = _rand->Uniform(0,6.283);
    
        double theta = TMath::ACos(cos);
    
        //Calculate end position
    
        double zend = zstart + rmu*cos;
    
        double yend = ystart + rmu*TMath::Sin(theta)*TMath::Sin(phi);
    
        double xend = xstart + rmu*TMath::Sin(theta)*TMath::Cos(phi);
    
        //If range * cos thetamu <= z position
    
        if( xend >= 0 && xend <= 4.312 && yend >= 0 && yend <= 4.294 && zend >= 0 && zend <= 5.312 ){
            return 1;
        }
        else{
            return 0;
        }

    }

    //  Smearing        
    void Smear(){}

} // namespace : xsec


#endif // PARTICLE_CLASS_H
