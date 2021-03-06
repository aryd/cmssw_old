#ifndef FastSimulation_TrackingRecHitProducer_TrackingRecHitTranslator_h
#define FastSimulation_TrackingRecHitProducer_TrackingRecHitTranslator_h

//---------------------------------------------------------------------------
//! \class TrackingRecHitTranslator
//!
//! \brief EDProducer to translate RecHits ordered by SimTrackId to RecHits 
//! expected by the full pattern recognition 
//!
//---------------------------------------------------------------------------

// Framework
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Utilities/interface/InputTag.h"

// Data Formats
#include "DataFormats/TrackerRecHit2D/interface/SiTrackerGSRecHit2DCollection.h"

class TrackerGeometry;
class DetId;

namespace edm { 
  class ParameterSet;
  class Event;
  class EventSetup;
}

class TrackingRecHitTranslator : public edm::EDProducer
{
 public:
  //--- Constructor, virtual destructor (just in case)
  explicit TrackingRecHitTranslator(const edm::ParameterSet& conf);
  virtual ~TrackingRecHitTranslator();
  
  //--- The top-level event method.
  virtual void produce(edm::Event& e, const edm::EventSetup& c);
  
  // Begin Job
  virtual void beginRun(edm::Run & run, const edm::EventSetup & es);
  
 private:

  void loadRecHits(
    std::map<DetId,edm::OwnVector<SiTrackerGSRecHit2D> >& theRecHits, 
    SiTrackerFullGSRecHit2DCollection& theRecHitCollection) const;

  //
  const TrackerGeometry* geometry;
  //
  edm::InputTag hitCollectionInputTag_;
};

#endif
