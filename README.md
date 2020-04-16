# PHYS175_HW8
Homework 8 (or Homework 1 of current segment) for CSU Atlas course, Spring 2020.

The ZprimeAnalysis .cxx and .h files are intended to be used with the ATLAS analysis package at https://gitlab.cern.ch/palacino/CsuAnalysisCode2019
Modifications have been made to the original versions to identify leading leptons and jets and create additional histograms.

PlottingMacro.cxx uses .root files created by the analysis code to make histograms and print them to the output.pdf file.

Histograms in output.pdf show the pseudorapidity, azimuthal angle, and transverse momentum of leading leptons (e and mu combined), leading electrons, leading muons, and leading jets, as well as the missing transverse energy and associated azimuthal angle, of simulated collision events in the LHC. Data comes from the ATLAS open-source data project, specifically the ZPrime750, ZPrime2500, and ttbar_lep sources. In the histograms, blue denotes ZPrime750, red denotes ZPrime2500, and gray denotes ttbar_lep (background signal).
