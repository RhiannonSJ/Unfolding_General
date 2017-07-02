#ifndef UNFOLDING_FUNCTIONS_H
#define UNFOLDING_FUNCTIONS_H

#include "/hepstore/rjones/Exercises/Unfolding_General/headers/roo_unfold.h"
#include "/hepstore/rjones/Exercises/Unfolding_General/headers/all_class_headers.h"
//#include "/hepstore/rjones/Exercises/Unfolding_General/src/RooUnfoldResponse.h"
//#include "/hepstore/rjones/Exercises/Unfolding_General/src/RooUnfoldBayes.h"
using namespace xsec;


typedef std::map< std::vector< int >, int > top_map; 

// Load the list of events from the gst tree and push onto a vector of events
void LoadEventList( TTree *gst, std::vector< Event > &event_list );

/*
// Get the response matrix for the chosen topology
void GetResponse( const std::vector< Event >       & event_list,
                  const Interaction                & interaction,
                  const std::vector< Interaction > & background,
                  RooUnfoldResponse                & response );
*/                             

#endif


