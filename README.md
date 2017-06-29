# Unfolding_General
Writing the unfolding method with the capability of implementing the procedure for any final state topology

# The classes
## Particle
Class to hold the information on a single particle in an event
    - PDG code
    - True kinetic energy
    - True opening angle
    - Smeared kinetic energy
    - Smeared opening angle
    - Smeared visibility
    - Smeared reconstructability

## Event
Class to hold the particles in an event
    - Classify if signal
    - Classify if background
    - Classify if cut

# The function files
## Unfolding
Functions involved in the unfolding process
    - Fill the response matrix
    - Unfold the testing sample
    - Slice the 2D distribution
    - Fill a line of the signal file (pass the name as an argument)

## Cross section
Functions involved in the cross-section calculation
    - Calculate the cross-section 
    - Slice the cross-section
    - Apply errors from RooUnfold and flux
    - Separate into initial physical process break-down

## Signal comparison
Functions to compare different qualifications of a single signal definition
    - Slice different definitions of a single signal sample and slice
    - Apply errors from RooUnfold and flux 
