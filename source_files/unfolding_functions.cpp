using std::cout;
using std::endl;

#include "/hepstore/rjones/Exercises/Unfolding_General/headers/unfolding_functions.h"

// Load the list of events from the gst tree and push onto a vector of events
void LoadEventList( TTree *gst, vector< Event > &event_list ){

    // Get the branches from the tree
    //  neu
    //  cc
    //  nc
    //  nf
    //  pdgf
    //  fspl
    //  cthl
    //  cthf
    //  ef
    //  el
    //  qel
    //  mec
    //  res
    //  dis
    //  coh
    //  npip
    //  npim
    //  npi0

    TBranch *b_neu  = gst->GetBranch("neu");
    TBranch *b_cc   = gst->GetBranch("cc");
    TBranch *b_nc   = gst->GetBranch("nc");
    TBranch *b_nf   = gst->GetBranch("nf");
    TBranch *b_pdgf = gst->GetBranch("pdgf");
    TBranch *b_fspl = gst->GetBranch("fspl");
    TBranch *b_cthl = gst->GetBranch("cthl");
    TBranch *b_cthf = gst->GetBranch("cthf");
    TBranch *b_ef   = gst->GetBranch("ef");
    TBranch *b_el   = gst->GetBranch("el");
    TBranch *b_qel  = gst->GetBranch("qel");

}


