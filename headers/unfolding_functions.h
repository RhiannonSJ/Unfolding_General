using std::cout;
using std::endl;

#include <iostream>
#include "/hepstore/rjones/Exercises/Unfolding_General/headers/roo_unfold.h"
#include "/hepstore/rjones/Exercises/Unfolding_General/headers/all_sources.h"
#include "/hepstore/rjones/Exercises/Unfolding_General/src/RooUnfoldResponse.h"
#include "/hepstore/rjones/Exercises/Unfolding_General/src/RooUnfoldBayes.h"

// Load the list of events from the gst tree and push onto a vector of events
void LoadEventList( TTree *gst, vector< Event > &event_list );


