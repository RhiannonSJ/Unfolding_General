
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

            //  Smeared KE
            double GetTSmeared() const;

            //  Smeared cos_theta
            double GetCosSmeared() const;
            
            //  Reconstructed?
            bool GetIfReconstructed() const;
        
            friend std::ostream& operator<<( std::ostream& , const Particle& );
        
        private:

            // Member variables
            int    m_PDG;
            double m_T;
            double m_cos;
            double m_smeared_T;
            double m_smeared_cos;
            bool   m_is_reconstructed;

            // Functions
            //  Check if the particle is reconstructed based on cuts and efficiency
            bool CheckIfReconstructed();

            // Check if the particle is contained within the TPC
            bool IsContained();
            
            //  Smearing
            double RangeSmear();
            double McsSmear();
            void Smear();


    }; // class: Particle

    class Event{
    
        public: 

            // Constructor
            //      vector< Particle > 
            Event( std::vector< Particle > parts, bool is_cc );
            
            Event( bool is_cc = true );

            // Destructor
            ~Event(){}

            // Getters
            //  List of particles
            std::vector< Particle > GetListOfParticles() const;
            
            //  Length of list
            int GetLength() const;
            
            // Get Is CC
            bool GetIsCC() const;
            
            // Functions
            //  Add particle
            void Add( Particle P );

            // Checking functions
            // Does the chosen signal topology match the true
            // topology of the event
            bool CheckIfTrue( bool is_cc, std::map< std::vector< int >, int > topology );
            
            // Does the chosen signal or background topology match
            // the reconstructed topology of the event
            bool CheckIfReconstructed( std::map< std::vector< int >, int > topology );

            // Overload []
            Particle operator[]( int i ) const; 

            // Overload ostream
            friend std::ostream& operator<<( std::ostream& , const Event& );

        private:

            // Member variables
            std::vector< Particle > m_particle_vect;
            bool m_is_cc;
            
    }; // class: Event

} // namespace : xsec
