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


#ifndef PARTICLE_CLASS_H
#define PARTICLE_CLASS_H

// Header file for all std::library and ROOT headers needed
#include "headers/roo_unfold.h"

namespace xsec{

    class Particle {
    
        public: 

            // Constructor
            //      
            //      PDG code
            //      Kinetic energy
            //      Opening angle
            //      Smeared kinetic energy
            //      Smeared opening angle
            //      Is visible
            //      Is reconstructed
            //
            Particle( int PDG, double T, double cos_theta );

            // Destructor
            ~Particle(){}

            // Getters
            //  PDG
            int GetPDG() const;
            
            //  True KE
            double GetT() const;

            //  True cos_theta
            double GetCos() const;

        private:

            // Member variables
            int    m_PDG;
            double m_T;
            double m_cos;
            double m_smeared_T;
            double m_smeared_cos;
            bool   m_is_reconstructed;

            // Functions
            //  Smearing
            void Smear();

            //  Check if the particle is reconstructed based on cuts and efficiency
            void CheckReco();

            // Check if the particle is contained within the TPC
            bool isContained(){
    
    }; // class: Particle

} // namespace : xsec


#endif // PARTICLE_CLASS_H