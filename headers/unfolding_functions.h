#ifndef UNFOLDING_FUNCTIONS_H
#define UNFOLDING_FUNCTIONS_H

#include <iostream>
#include "/hepstore/rjones/Exercises/Unfolding_General/headers/roo_unfold.h"
#include "/hepstore/rjones/Exercises/Unfolding_General/headers/all_headers.h"
//#include "/hepstore/rjones/Exercises/Unfolding_General/src/RooUnfoldResponse.h"
//#include "/hepstore/rjones/Exercises/Unfolding_General/src/RooUnfoldBayes.h"

using namespace xsec;

// Load the list of events from the gst tree and push onto a vector of events
void LoadEventList( TTree *gst, std::vector< Event > &event_list );


#endif


