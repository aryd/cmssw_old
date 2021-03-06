import FWCore.ParameterSet.Config as cms

process = cms.Process("TESTOUTPUTREAD")
process.load("FWCore.Framework.test.cmsExceptionsFatal_cff")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

process.analyzeOther = cms.EDAnalyzer("OtherThingAnalyzer")
process.tst = cms.Path(process.analyzeOther)

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:PoolOutputTestUnscheduled.root')
)



