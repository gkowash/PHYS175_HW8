#include <EventLoop/Job.h>
#include <EventLoop/StatusCode.h>
#include <EventLoop/Worker.h>
#include <CsuAnalysisCode2019/ZprimeAnalysis.h>
#include <iostream>

// this is needed to distribute the algorithm to the workers
ClassImp(ZprimeAnalysis)



ZprimeAnalysis :: ZprimeAnalysis ()
{
  // Here you put any code for the base initialization of variables,
  // e.g. initialize all pointers to 0.  Note that you should only put
  // the most basic initialization here, since this method will be
  // called on both the submission and the worker node.  Most of your
  // initialization code will go into histInitialize() and
  // initialize().
}



EL::StatusCode ZprimeAnalysis :: setupJob (EL::Job& job)
{
  // Here you put code that sets up the job on the submission object
  // so that it is ready to work with your algorithm, e.g. you can
  // request the D3PDReader service or add output files.  Any code you
  // put here could instead also go into the submission script.  The
  // sole advantage of putting it here is that it gets automatically
  // activated/deactivated when you add/remove the algorithm from your
  // job, which may or may not be of value to you.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: histInitialize ()
{
  // Here you do everything that needs to be done at the very
  // beginning on each worker node, e.g. create histograms and output
  // trees.  This method gets called before any input files are
  // connected.

  h_event_selection = new TH1F("h_event_selection","",11, 0, 11);
  wk()->addOutput(h_event_selection);
  h_event_selection->GetXaxis()->SetBinLabel(1,"All events");
  h_event_selection->GetXaxis()->SetBinLabel(2,"Pass trigger");
  h_event_selection->GetXaxis()->SetBinLabel(3,"Good GRL");
  h_event_selection->GetXaxis()->SetBinLabel(4,"Good vertex");
  h_event_selection->GetXaxis()->SetBinLabel(5,"One good lepton");
  h_event_selection->GetXaxis()->SetBinLabel(6,">= 4 good jets");
  h_event_selection->GetXaxis()->SetBinLabel(7,">= 1 b jet");
  h_event_selection->GetXaxis()->SetBinLabel(8,"MET > 30 GeV");
  h_event_selection->GetXaxis()->SetBinLabel(9,"WmT > 30 GeV");

  h_trigger_pass = new TH1F("h_trigger_pass","",7, 0, 7);
  wk()->addOutput(h_trigger_pass);
  h_trigger_pass->GetXaxis()->SetBinLabel(1,"fail egamma");
  h_trigger_pass->GetXaxis()->SetBinLabel(2,"pass egamma");
  h_trigger_pass->GetXaxis()->SetBinLabel(3,"fail muon");
  h_trigger_pass->GetXaxis()->SetBinLabel(4,"pass muon");
  h_trigger_pass->GetXaxis()->SetBinLabel(5,"fail both");
  h_trigger_pass->GetXaxis()->SetBinLabel(6,"pass both");
  h_trigger_pass->GetXaxis()->SetBinLabel(7,"events processed");

  h_lep_n = new TH1F("h_lep_n",";N^{leptons};", 101, -0.5, 100.5);
  wk()->addOutput(h_lep_n);
  h_el_n = new TH1F("h_el_n",";N^{electrons};", 101, -0.5, 100.5);
  wk()->addOutput(h_el_n);
  h_mu_n = new TH1F("h_mu_n",";N^{muons};", 101, -0.5, 100.5);
  wk()->addOutput(h_mu_n);
  h_lep_pt = new TH1F("h_lep_pt","Leading lepton transverse momentum;p_{T}^{lepton} [GeV];", 200, 0, 2000);
  wk()->addOutput(h_lep_pt);
  h_lep_eta = new TH1F("h_lep_eta","Leading lepton pseudorapidity;#eta^{lepton};", 100, -5, 5);
  wk()->addOutput(h_lep_eta);
  h_lep_phi = new TH1F("h_lep_phi","Leading lepton azimuthal angle;#phi^{lepton};", 64, -3.2, 3.2);
  wk()->addOutput(h_lep_phi);
  h_egamma_trig_eff = new TEfficiency("h_egamma_trig_eff",";p_{T}^{electron} [GeV];Trigger Acceptance;", 200, 0, 2000);
  wk()->addOutput(h_egamma_trig_eff);
  h_muon_trig_eff = new TEfficiency("h_muon_trig_eff",";p_{T}^{muon} [GeV];Trigger Acceptance;", 200, 0, 2000);
  wk()->addOutput(h_muon_trig_eff);

  h_el_pt = new TH1F("h_el_pt","Leading electron transverse momentum;p_{T}^{electron} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_el_pt);
  h_mu_pt = new TH1F("h_mu_pt","Leading muon transverse momentum;p_{T}^{muon} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_mu_pt);
  h_el_eta = new TH1F("h_el_eta","Leading electron pseudorapidity;#eta^{electron};", 100, -5, 5);
  wk()->addOutput(h_el_eta);
  h_mu_eta = new TH1F("h_mu_eta","Leading muon pseudorapidity;#eta^{muon};", 100, -5, 5);
  wk()->addOutput(h_mu_eta);
  h_el_phi = new TH1F("h_el_phi","Leading electron azimuthal angle;#phi^{electron};", 64, -3.2, 3.2);
  wk()->addOutput(h_el_phi);
  h_mu_phi = new TH1F("h_mu_phi","Leading muon azimuthal angle;#phi^{muon};", 64, -3.2, 3.2);
  wk()->addOutput(h_mu_phi);
  h_el_isoptcone30rel = new TH1F("h_el_isoptcone30rel",";el_isoptcone30rel;", 120, 0, 1.2);
  wk()->addOutput(h_el_isoptcone30rel);
  h_el_isoetcone20rel = new TH1F("h_el_isoetcone20rel",";el_isoetcone20rel;", 120, 0, 1.2);
  wk()->addOutput(h_el_isoetcone20rel);
  h_mu_isoptcone30rel = new TH1F("h_mu_isoptcone30rel",";mu_isoptcone30rel;", 120, 0, 1.2);
  wk()->addOutput(h_mu_isoptcone30rel);
  h_mu_isoetcone20rel = new TH1F("h_mu_isoetcone20rel",";mu_iso2tcone20rel;", 120, 0, 1.2);
  wk()->addOutput(h_mu_isoetcone20rel);

  h_jet_pt = new TH1F("h_jet_pt","Leading jet transverse momentum;p_{T}^{jet};", 400, 0, 2000);
  wk()->addOutput(h_jet_pt);
  h_jet_eta = new TH1F("h_jet_eta","Leading jet pseudorapidity;#eta^{jet};", 100, -5, 5);
  wk()->addOutput(h_jet_eta);
  h_jet_phi = new TH1F("h_jet_phi","Leading jet azimuthal angle;#phi^{jet};", 64, -3.2, 3.2);
  wk()->addOutput(h_jet_phi);
  h_jet_jvf = new TH1F("h_jet_jvf",";Jet Vertex Fraction;", 200, -1, 1);
  wk()->addOutput(h_jet_jvf);
  h_jet_mv1 = new TH1F("h_jet_mv1",";MV1 response;", 100, 0, 1);
  wk()->addOutput(h_jet_mv1);
  h_bjet_pt = new TH1F("h_bjet_pt",";p_{T}^{b-jet};", 400, 0, 2000);
  wk()->addOutput(h_bjet_pt);
  h_bjet_eta = new TH1F("h_bjet_eta",";#eta^{b-jet};", 100, -5, 5);
  wk()->addOutput(h_bjet_eta);

  h_met = new TH1F("h_met","Missing transverse energy;E_{T}^{miss} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_met);
  h_el_met = new TH1F("h_el_met",";E_{T}^{miss} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_el_met);
  h_mu_met = new TH1F("h_mu_met",";E_{T}^{miss} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_mu_met);

  h_met_phi = new TH1F("h_met_phi", "Missing transverse energy, azimuthal angle;#phi^{E_{T}}", 64, -3.2, 3.2);
  wk()->addOutput(h_met_phi);

  h_wmt = new TH1F("h_wmt",";M_{T}^{W}(l, E_{T}^{miss}) [GeV];", 400, 0, 2000);
  wk()->addOutput(h_wmt);
  h_wmt_met = new TH1F("h_wmt_met",";M_{T}^{W}(l, E_{T}^{miss}) + E_{T}^{miss} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_wmt_met);
  h_el_wmt = new TH1F("h_el_wmt",";M_{T}^{W}(e, E_{T}^{miss}) [GeV];", 400, 0, 2000);
  wk()->addOutput(h_el_wmt);
  h_el_wmt_met = new TH1F("h_el_wmt_met",";M_{T}^{W}(e, E_{T}^{miss}) + E_{T}^{miss} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_el_wmt_met);
  h_mu_wmt = new TH1F("h_mu_wmt",";M_{T}^{W}(#mu, E_{T}^{miss}) [GeV];", 400, 0, 2000);
  wk()->addOutput(h_mu_wmt);
  h_mu_wmt_met = new TH1F("h_mu_wmt_met",";M_{T}^{W}(#mu, E_{T}^{miss}) + E_{T}^{miss} [GeV];", 400, 0, 2000);
  wk()->addOutput(h_mu_wmt_met);


  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: fileExecute ()
{
  // Here you do everything that needs to be done exactly once for every
  // single file, e.g. collect a list of all lumi-blocks processed
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: changeInput (bool firstFile)
{
  // Here you do everything you need to do when we change input files,
  // e.g. resetting branch addresses on trees.  If you are using
  // D3PDReader or a similar service this method is not needed.

  tree = wk()->tree();
  tree->SetBranchAddress("runNumber", &runNumber);  
  tree->SetBranchAddress("eventNumber", &eventNumber);
  tree->SetBranchAddress("channelNumber", &channelNumber);
  tree->SetBranchAddress("mcWeight", &mcWeight);  
  tree->SetBranchAddress("pvxp_n", &pvxp_n);  
  tree->SetBranchAddress("vxp_z", &vxp_z); 
  tree->SetBranchAddress("scaleFactor_PILEUP", &scaleFactor_PILEUP);
  tree->SetBranchAddress("scaleFactor_ELE", &scaleFactor_ELE);  
  tree->SetBranchAddress("scaleFactor_MUON", &scaleFactor_MUON);  
  tree->SetBranchAddress("scaleFactor_BTAG", &scaleFactor_BTAG);  
  tree->SetBranchAddress("scaleFactor_TRIGGER", &scaleFactor_TRIGGER);
  tree->SetBranchAddress("scaleFactor_JVFSF", &scaleFactor_JVFSF);  
  tree->SetBranchAddress("scaleFactor_ZVERTEX", &scaleFactor_ZVERTEX);
  tree->SetBranchAddress("trigE", &trigE);
  tree->SetBranchAddress("trigM", &trigM);
  tree->SetBranchAddress("passGRL", &passGRL);
  tree->SetBranchAddress("hasGoodVertex", &hasGoodVertex);
  tree->SetBranchAddress("lep_n", &lep_n);
  tree->SetBranchAddress("lep_truthMatched", lep_truthMatched);
  tree->SetBranchAddress("lep_trigMatched", lep_trigMatched);
  tree->SetBranchAddress("lep_pt", lep_pt);
  tree->SetBranchAddress("lep_eta", lep_eta);
  tree->SetBranchAddress("lep_phi", lep_phi);
  tree->SetBranchAddress("lep_E", lep_E);
  tree->SetBranchAddress("lep_z0", lep_z0);
  tree->SetBranchAddress("lep_charge", lep_charge);
  tree->SetBranchAddress("lep_type", lep_type);
  tree->SetBranchAddress("lep_flag", lep_flag);
  tree->SetBranchAddress("lep_ptcone30", lep_ptcone30);
  tree->SetBranchAddress("lep_etcone20", lep_etcone20);
  tree->SetBranchAddress("lep_trackd0pvunbiased", lep_trackd0pvunbiased);
  tree->SetBranchAddress("lep_tracksigd0pvunbiased", lep_tracksigd0pvunbiased);
  tree->SetBranchAddress("met_et", &met_et);
  tree->SetBranchAddress("met_phi", &met_phi);
  tree->SetBranchAddress("jet_n", &jet_n); 
  tree->SetBranchAddress("alljet_n", &alljet_n);
  tree->SetBranchAddress("jet_pt", jet_pt);
  tree->SetBranchAddress("jet_eta", jet_eta);
  tree->SetBranchAddress("jet_phi", jet_phi);
  tree->SetBranchAddress("jet_E", jet_E);
  tree->SetBranchAddress("jet_m", jet_m);
  tree->SetBranchAddress("jet_jvf", jet_jvf);
  tree->SetBranchAddress("jet_trueflav", jet_trueflav);
  tree->SetBranchAddress("jet_truthMatched", jet_truthMatched);  
  tree->SetBranchAddress("jet_SV0", jet_SV0); 
  tree->SetBranchAddress("jet_MV1", jet_MV1); 

  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: initialize ()
{
  // Here you do everything that you need to do after the first input
  // file has been connected and before the first event is processed,
  // e.g. create additional histograms based on which variables are
  // available in the input files.  You can also create all of your
  // histograms and trees in here, but be aware that this method
  // doesn't get called if no events are processed.  So any objects
  // you create here won't be available in the output if you have no
  // input events.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: execute ()
{
  // Here you do everything that needs to be done on every single
  // events, e.g. read input variables, apply cuts, and fill
  // histograms and trees.  This is where most of your actual analysis
  // code will go.

  wk()->tree()->GetEntry (wk()->treeEntry());

  getLeptons();
  getJets();
  getMET();
  getEventInfo();

  float weight = isData ? 1.0 : eventInfo.evtWeight*eventInfo.evtSF;

  // Trigger Acceptance code
  if(!eventInfo.passEgamma) h_trigger_pass->Fill(0., weight);
  else h_trigger_pass->Fill(1, weight);
  if(!eventInfo.passMuon) h_trigger_pass->Fill(2, weight);
  else h_trigger_pass->Fill(3, weight);
  if(!eventInfo.passEgamma && !eventInfo.passMuon) h_trigger_pass->Fill(4, weight);
  if(eventInfo.passEgamma && eventInfo.passMuon) h_trigger_pass->Fill(5, weight);
  h_trigger_pass->Fill(6, weight);


  h_lep_n->Fill(lep_n);

  // Kinematics of leading electron and muon
  for(unsigned int i = 0; i < lep_n; i++){
    bool foundEl = false;
    bool foundMu = false;

    if(lep_type[i]==11 && !foundEl){
      foundEl = true;
      h_el_eta->Fill(lep_eta[i]);
      h_el_phi->Fill(lep_phi[i]);
      h_el_pt ->Fill(lep_pt[i]*GeV);
    }
    else if(lep_type[i]==13 && !foundMu){
      foundMu = true;
      h_mu_eta->Fill(lep_eta[i]);
      h_mu_phi->Fill(lep_phi[i]);
      h_mu_pt ->Fill(lep_pt[i]*GeV);
    }
    if(foundEl && foundMu) break;
  }

  // Kinematics of leading lepton
  h_lep_eta->Fill(lep_eta[0]);
  h_lep_phi->Fill(lep_phi[0]);
  h_lep_pt ->Fill(lep_pt[0]*GeV);
                                                                                        
  // Kinematics of leading jet
  h_jet_eta -> Fill(jet_eta[0]);
  h_jet_phi -> Fill(jet_phi[0]);
  h_jet_pt -> Fill(jet_pt[0]*GeV);

  // Missing transverse energy
  h_met -> Fill(met_et*GeV);
  h_met_phi -> Fill(met_phi);
  


  int n_el = 0;
  int n_mu = 0;

  std::vector<lepton> goodLeptons;
  std::vector<jet> goodJets;
  std::vector<jet> bJets;

  // Good leptons
  for(unsigned int i = 0; i < leptons.size(); i++){
    lepton lep = leptons.at(i);
    if(lep.type == 11) n_el++;
    if(lep.type == 13) n_mu++;

    if(!lep.isTight) continue;
    if(lep.tlv.Pt()*GeV < 25) continue;
    if(lep.relptcone30 > 0.15) continue;
    if(lep.reletcone20 > 0.15) continue;
    goodLeptons.push_back(lep);
  }

  h_el_n->Fill(n_el, weight);
  h_mu_n->Fill(n_mu, weight);

  // Good jets
  for(unsigned int i = 0; i < jets.size(); i++){
    jet jet = jets.at(i);
    if(jet.tlv.Pt()*GeV < 25) continue;
    if(fabs(jet.tlv.Eta()) > 2.5) continue;
    if(jet.tlv.Pt()*GeV < 50 ){
      if(fabs(jet.tlv.Eta()) < 2.4 ){
        h_jet_jvf->Fill(jet.jvf, weight);
        if(jet.jvf >= 0.50) goodJets.push_back(jet);
      }
    }
    else goodJets.push_back(jet);
  }

  // B jets
  for(unsigned int i = 0; i < goodJets.size(); i++){
    jet jet = goodJets.at(i);
    h_jet_mv1->Fill(jet.mv1, weight);
    if(jet.mv1 < 0.7892) continue;
    bJets.push_back(jet);
  }

  ////--------------------------------------------------------------------------------////
  //Event Selection
  h_event_selection->Fill(allEvents, weight);
  // Trigger
  if(!(eventInfo.passEgamma || eventInfo.passMuon)) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passTrigger, weight);

  // Good Run List
  if(!eventInfo.passGRL) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passGrl, weight);

  // Has good vertex
  if(!eventInfo.hasGoodVertex) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passGoodVertex, weight);

  //Exactly one good lepton
  if(!(eventInfo.hasGoodVertex && goodLeptons.size() == 1)) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passOneGoodLepton, weight);


  /*
  //lepton kinematics for good leptons after exactly one lepton selection
  h_lep_eta->Fill(goodLeptons.at(0).tlv.Eta(), weight);
  h_lep_phi->Fill(goodLeptons.at(0).tlv.Phi(), weight);
  h_lep_pt->Fill(goodLeptons.at(0).tlv.Pt()*GeV, weight);
  //Lepton pT for electron and muon channels leptontype == 11 -> electrons, leptontype == 13 -> muon
  if(goodLeptons.at(0).type == 11 ) h_el_pt->Fill(goodLeptons.at(0).tlv.Pt()*GeV, weight);
  else if (goodLeptons.at(0).type == 13 )h_mu_pt->Fill(goodLeptons.at(0).tlv.Pt()*GeV, weight);
  */

  /*
  //At least 4 good jets
  if(!(eventInfo.hasGoodVertex && goodLeptons.size() == 1 && goodJets.size() >= 4)) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passFourGoodJets, weight);
  for(unsigned int i = 0; i < goodJets.size(); i++){
    //kinematics of good jets
    h_jet_pt->Fill(goodJets.at(i).tlv.Pt()*GeV, weight);
    h_jet_eta->Fill(goodJets.at(i).tlv.Eta(), weight);
  }
  */

  //At least one b-tagged jet
  if(!(eventInfo.hasGoodVertex && goodLeptons.size() == 1 && goodJets.size() >= 4 && bJets.size() >= 1) ) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passOneBjet, weight);
  for(unsigned int i = 0; i < bJets.size(); i++){
    //kinematics of b-jets
    h_bjet_pt->Fill(bJets.at(i).tlv.Pt()*GeV, weight);
    h_bjet_eta->Fill(bJets.at(i).tlv.Eta(), weight);
  }
  
  /*
  //Missing ET > 30 GeV
  if(!(eventInfo.hasGoodVertex && goodLeptons.size() == 1 && goodJets.size() >= 4 && bJets.size() >= 1 && MET.tlv.Et()*GeV >= 30) ) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passMet30, weight);
  h_met->Fill(MET.tlv.Et()*GeV, weight);
  */

  // Construct W boson transverse mass WmT
  double WmT = (goodLeptons.at(0).tlv + MET.tlv).Mt();
  // WmT > 30 GeV
  if(!(eventInfo.hasGoodVertex && goodLeptons.size() == 1 && goodJets.size() >= 4 && bJets.size() >= 1 && MET.tlv.Et()*GeV >= 30 && WmT*GeV >= 30) ) return EL::StatusCode::SUCCESS;
  h_event_selection->Fill(passWmt30, weight);
  
  h_wmt->Fill(WmT*GeV, weight);
  h_wmt_met->Fill(WmT*GeV + MET.tlv.Et()*GeV, weight);
  

  return EL::StatusCode::SUCCESS;
}


////--------^^^^^^^ end of the event selection ^^^^^--------////

EL::StatusCode ZprimeAnalysis :: postExecute ()
{
  // Here you do everything that needs to be done after the main event
  // processing.  This is typically very rare, particularly in user
  // code.  It is mainly used in implementing the NTupleSvc.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: finalize ()
{
  // This method is the mirror image of initialize(), meaning it gets
  // called after the last event has been processed on the worker node
  // and allows you to finish up any objects you created in
  // initialize() before they are written to disk.  This is actually
  // fairly rare, since this happens separately for each worker node.
  // Most of the time you want to do your post-processing on the
  // submission node after all your histogram outputs have been
  // merged.  This is different from histFinalize() in that it only
  // gets called on worker nodes that processed input events.
  return EL::StatusCode::SUCCESS;
}



EL::StatusCode ZprimeAnalysis :: histFinalize ()
{
  // This method is the mirror image of histInitialize(), meaning it
  // gets called after the last event has been processed on the worker
  // node and allows you to finish up any objects you created in
  // histInitialize() before they are written to disk.  This is
  // actually fairly rare, since this happens separately for each
  // worker node.  Most of the time you want to do your
  // post-processing on the submission node after all your histogram
  // outputs have been merged.  This is different from finalize() in
  // that it gets called on all worker nodes regardless of whether
  // they processed input events.
  return EL::StatusCode::SUCCESS;
}

void ZprimeAnalysis :: getLeptons()
{

  leptons.clear();
  for(unsigned int i = 0; i < lep_n; i++){
    lepton lep;
    lep.tlv.SetPtEtaPhiE( lep_pt[i], lep_eta[i], lep_phi[i], lep_E[i]);
    lep.type = lep_type[i];
    lep.isTight =  lep_flag[i] & 512 ? true : false;
    lep.relptcone30 = lep_ptcone30[i]/lep_pt[i];
    lep.reletcone20 = lep_etcone20[i]/lep_pt[i];
    leptons.push_back(lep);
  }

  return;
}

void ZprimeAnalysis :: getJets()
{

  jets.clear();
  for(unsigned int i = 0; i < alljet_n; i++){
    jet jet;
    jet.tlv.SetPtEtaPhiM( jet_pt[i], jet_eta[i], jet_phi[i], jet_m[i]);
    jet.jvf = jet_jvf[i];
    jet.flavor =  jet_trueflav[i];
    jet.mv1 = jet_MV1[i];
    jets.push_back(jet);
  }

  return;
}

void ZprimeAnalysis :: getMET()
{

  MET.tlv.SetPtEtaPhiE(met_et, 0, met_phi, met_et);

  return;
}

void ZprimeAnalysis :: getEventInfo()
{
  eventInfo.nvertices = pvxp_n;
  eventInfo.passEgamma = trigE;
  eventInfo.passMuon = trigM;
  eventInfo.passGRL = passGRL;
  eventInfo.hasGoodVertex = hasGoodVertex;
  eventInfo.evtWeight = mcWeight*scaleFactor_PILEUP*scaleFactor_ZVERTEX;
  eventInfo.evtSF = scaleFactor_ELE*scaleFactor_MUON*scaleFactor_TRIGGER;

  return;
}

void ZprimeAnalysis :: setData(bool data)
{
  isData = data;

  return;
}
