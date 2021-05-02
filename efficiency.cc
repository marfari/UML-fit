#include <TH1F.h>
#include <TString.h>
#include <TFile.h>
#include <TTree.h>
#include <TEfficiency.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <TAttMarker.h>

void efficiency(int year, int q2Bin = -1){

  double q2_bins[] = {1, 2, 4.3, 6, 8.68, 10.09, 12.86, 14.18, 16};
  const int n_q2_bins = 8;

  if(q2Bin < -1 || q2Bin >= n_q2_bins){return;}
  if(year < 2016 || year > 2018){return;}


  // RECO MC
  TString input_file_mc_cuts_jpsi = Form("/eos/cms/store/user/fiorendi/p5prime/%i/skims/newphi/%iMC_JPSI.root",year,year);
  TString input_file_mc_cuts_psi = Form("/eos/cms/store/user/fiorendi/p5prime/%i/skims/newphi/%iMC_PSI.root",year,year);
  TString input_file_mc_cuts_lmnr = Form("/eos/cms/store/user/fiorendi/p5prime/%i/skims/newphi/%iMC_LMNR.root",year,year);
  TFile* f_mc_cuts_jpsi = new TFile(input_file_mc_cuts_jpsi);
  TFile* f_mc_cuts_psi = new TFile(input_file_mc_cuts_psi);
  TFile* f_mc_cuts_lmnr = new TFile(input_file_mc_cuts_lmnr);

  // GEN-LEVEL MC
  TString input_file_mc_nocuts_jpsi = Form("/eos/cms/store/user/fiorendi/p5prime/%i/skims/newphi/%iGEN_MC_JPSI.root",year,year);
  TString input_file_mc_nocuts_psi = Form("/eos/cms/store/user/fiorendi/p5prime/%i/skims/newphi/%iGEN_MC_PSI.root",year,year);
  TString input_file_mc_nocuts_lmnr = Form("/eos/cms/store/user/fiorendi/p5prime/%i/skims/newphi/%iGEN_MC_LMNR.root",year,year);
  TFile* f_mc_nocuts_jpsi = new TFile(input_file_mc_nocuts_jpsi);
  TFile* f_mc_nocuts_psi = new TFile(input_file_mc_nocuts_psi);
  TFile* f_mc_nocuts_lmnr = new TFile(input_file_mc_nocuts_lmnr);
 
  TTree* t_cuts_jpsi = (TTree*)f_mc_cuts_jpsi->Get("ntuple");
  TTree* t_cuts_psi = (TTree*)f_mc_cuts_psi->Get("ntuple");
  TTree* t_cuts_lmnr = (TTree*)f_mc_cuts_lmnr->Get("ntuple");

  TTree* t_nocuts_jpsi = (TTree*)f_mc_nocuts_jpsi->Get("ntuple");
  TTree* t_nocuts_psi = (TTree*)f_mc_nocuts_psi->Get("ntuple");
  TTree* t_nocuts_lmnr = (TTree*)f_mc_nocuts_lmnr->Get("ntuple");

  // GEN-FILTER MC (acceptance)
  TString input_file_mc_gen_jpsi = "/eos/cms/store/user/fiorendi/p5prime/2016/skims/GEN_NoFilter/newphi/GEN_BFilter_B0JpsiKstar.root";
  TString input_file_mc_gen_psi = "/eos/cms/store/user/fiorendi/p5prime/2016/skims/GEN_NoFilter/newphi/GEN_BFilter_B0PsiKstar.root";
  TString input_file_mc_gen_lmnr = "/eos/cms/store/user/fiorendi/p5prime/2016/skims/GEN_NoFilter/newphi/GEN_BFilter_B0MuMuKstar_p2.root";
  TFile* f_mc_gen_jpsi = new TFile(input_file_mc_gen_jpsi);
  TFile* f_mc_gen_psi = new TFile(input_file_mc_gen_psi);
  TFile* f_mc_gen_lmnr = new TFile(input_file_mc_gen_lmnr);

  TTree* t_gen_jpsi = (TTree*)f_mc_gen_jpsi->Get("ntuple");
  TTree* t_gen_psi = (TTree*)f_mc_gen_psi->Get("ntuple");
  TTree* t_gen_lmnr = (TTree*)f_mc_gen_lmnr->Get("ntuple");

  double mumuMass_jpsi;
  double mumuMass_psi;
  double mumuMass_lmnr;

  double gen_mumuMass_jpsi;
  double gen_mumuMass_psi;
  double gen_mumuMass_lmnr;

  double bfilter_mumuMass_jpsi;
  double bfilter_mumuMass_psi;
  double bfilter_mumuMass_lmnr;

  //variables for applying GEN-filter
  double genmupEta_jpsi;
  double genmumEta_jpsi;
  double genkstTrkpEta_jpsi;
  double genkstTrkmEta_jpsi;
  double genmupPt_jpsi;
  double genmumPt_jpsi;
  double genkstTrkpPt_jpsi;
  double genkstTrkmPt_jpsi;

  double genmupEta_psi;
  double genmumEta_psi;
  double genkstTrkpEta_psi;
  double genkstTrkmEta_psi;
  double genmupPt_psi;
  double genmumPt_psi;
  double genkstTrkpPt_psi;
  double genkstTrkmPt_psi;

  double genmupEta_lmnr;
  double genmumEta_lmnr;
  double genkstTrkpEta_lmnr;
  double genkstTrkmEta_lmnr;
  double genmupPt_lmnr;
  double genmumPt_lmnr;
  double genkstTrkpPt_lmnr;
  double genkstTrkmPt_lmnr;

  t_cuts_jpsi->SetBranchAddress("mumuMass",&mumuMass_jpsi);
  t_cuts_psi->SetBranchAddress("mumuMass",&mumuMass_psi);
  t_cuts_lmnr->SetBranchAddress("mumuMass",&mumuMass_lmnr);

  t_nocuts_jpsi->SetBranchAddress("genQ",&gen_mumuMass_jpsi);
  t_nocuts_psi->SetBranchAddress("genQ",&gen_mumuMass_psi);
  t_nocuts_lmnr->SetBranchAddress("genQ",&gen_mumuMass_lmnr);

  t_gen_jpsi->SetBranchAddress("genQ",&bfilter_mumuMass_jpsi);
  t_gen_psi->SetBranchAddress("genQ",&bfilter_mumuMass_psi);
  t_gen_lmnr->SetBranchAddress("genQ",&bfilter_mumuMass_lmnr);

  t_gen_jpsi->SetBranchAddress("genmupEta",&genmupEta_jpsi);
  t_gen_jpsi->SetBranchAddress("genmumEta",&genmumEta_jpsi);
  t_gen_jpsi->SetBranchAddress("genkstTrkpEta",&genkstTrkpEta_jpsi);
  t_gen_jpsi->SetBranchAddress("genkstTrkmEta",&genkstTrkmEta_jpsi);
  t_gen_jpsi->SetBranchAddress("genmupPt",&genmupPt_jpsi);
  t_gen_jpsi->SetBranchAddress("genmumPt",&genmumPt_jpsi);
  t_gen_jpsi->SetBranchAddress("genkstTrkpPt",&genkstTrkpPt_jpsi);
  t_gen_jpsi->SetBranchAddress("genkstTrkmPt",&genkstTrkmPt_jpsi);

  t_gen_psi->SetBranchAddress("genmupEta",&genmupEta_psi);
  t_gen_psi->SetBranchAddress("genmumEta",&genmumEta_psi);
  t_gen_psi->SetBranchAddress("genkstTrkpEta",&genkstTrkpEta_psi);
  t_gen_psi->SetBranchAddress("genkstTrkmEta",&genkstTrkmEta_psi);
  t_gen_psi->SetBranchAddress("genmupPt",&genmupPt_psi);
  t_gen_psi->SetBranchAddress("genmumPt",&genmumPt_psi);
  t_gen_psi->SetBranchAddress("genkstTrkpPt",&genkstTrkpPt_psi);
  t_gen_psi->SetBranchAddress("genkstTrkmPt",&genkstTrkmPt_psi);

  t_gen_lmnr->SetBranchAddress("genmupEta",&genmupEta_lmnr);
  t_gen_lmnr->SetBranchAddress("genmumEta",&genmumEta_lmnr);
  t_gen_lmnr->SetBranchAddress("genkstTrkpEta",&genkstTrkpEta_lmnr);
  t_gen_lmnr->SetBranchAddress("genkstTrkmEta",&genkstTrkmEta_lmnr);
  t_gen_lmnr->SetBranchAddress("genmupPt",&genmupPt_lmnr);
  t_gen_lmnr->SetBranchAddress("genmumPt",&genmumPt_lmnr);
  t_gen_lmnr->SetBranchAddress("genkstTrkpPt",&genkstTrkpPt_lmnr);
  t_gen_lmnr->SetBranchAddress("genkstTrkmPt",&genkstTrkmPt_lmnr);

  double reco_entries[] = {0., 0., 0., 0., 0., 0., 0., 0.};
  double gen_entries[] = {0., 0., 0., 0., 0., 0., 0., 0.};
  double den_entries[] = {0., 0., 0., 0., 0., 0., 0., 0.};
  double num_entries[] = {0., 0., 0., 0., 0., 0., 0., 0.};

  cout << "RECO JPSI"  << endl; 
  for(int evt = 0; evt < t_cuts_jpsi->GetEntries(); evt++){
    t_cuts_jpsi->GetEntry(evt);
     
    if( (pow(mumuMass_jpsi,2) > q2_bins[4]) && (pow(mumuMass_jpsi,2) < q2_bins[5]) ){reco_entries[4] += 1;}
  }

  cout << "RECO PSI"  << endl;
  for(int evt = 0; evt < t_cuts_psi->GetEntries(); evt++){
    t_cuts_psi->GetEntry(evt);

    if( (pow(mumuMass_psi,2) > q2_bins[6]) && (pow(mumuMass_psi,2) < q2_bins[7]) ){reco_entries[6] += 1;}
  }

  cout << "RECO LMNR"  << endl;
  for(int evt = 0; evt < t_cuts_lmnr->GetEntries(); evt++){
    t_cuts_lmnr->GetEntry(evt);

    if( (pow(mumuMass_lmnr,2) > q2_bins[0]) && (pow(mumuMass_lmnr,2) < q2_bins[1]) ){reco_entries[0] += 1;}
    else if( (pow(mumuMass_lmnr,2) > q2_bins[1]) && (pow(mumuMass_lmnr,2) < q2_bins[2]) ){reco_entries[1] += 1;}
    else if( (pow(mumuMass_lmnr,2) > q2_bins[2]) && (pow(mumuMass_lmnr,2) < q2_bins[3]) ){reco_entries[2] += 1;}
    else if( (pow(mumuMass_lmnr,2) > q2_bins[3]) && (pow(mumuMass_lmnr,2) < q2_bins[4]) ){reco_entries[3] += 1;}
    else if( (pow(mumuMass_lmnr,2) > q2_bins[5]) && (pow(mumuMass_lmnr,2) < q2_bins[6]) ){reco_entries[5] += 1;}
    else if( (pow(mumuMass_lmnr,2) > q2_bins[7]) && (pow(mumuMass_lmnr,2) < q2_bins[8]) ){reco_entries[7] += 1;}
  }

  cout << "GEN JPSI" << endl;
  for(int evt = 0; evt < t_nocuts_jpsi->GetEntries(); evt++){
      t_nocuts_jpsi->GetEntry(evt);

      if( (pow(gen_mumuMass_jpsi,2) > q2_bins[4]) && (pow(gen_mumuMass_jpsi,2) < q2_bins[5]) ){gen_entries[4] += 1;}
  }

  cout << "GEN PSI" << endl;
  for(int evt = 0; evt < t_nocuts_psi->GetEntries(); evt++){
      t_nocuts_psi->GetEntry(evt);

      if( (pow(gen_mumuMass_psi,2) > q2_bins[6]) && (pow(gen_mumuMass_psi,2) < q2_bins[7]) ){gen_entries[6] += 1;}
  }

  cout << "GEN LMNR" << endl;
  for(int evt = 0; evt < t_nocuts_lmnr->GetEntries(); evt++){
      t_nocuts_lmnr->GetEntry(evt);

    if( (pow(gen_mumuMass_lmnr,2) > q2_bins[0]) && (pow(gen_mumuMass_lmnr,2) < q2_bins[1]) ){gen_entries[0] += 1;}
    else if( (pow(gen_mumuMass_lmnr,2) > q2_bins[1]) && (pow(gen_mumuMass_lmnr,2) < q2_bins[2]) ){gen_entries[1] += 1;}
    else if( (pow(gen_mumuMass_lmnr,2) > q2_bins[2]) && (pow(gen_mumuMass_lmnr,2) < q2_bins[3]) ){gen_entries[2] += 1;}
    else if( (pow(gen_mumuMass_lmnr,2) > q2_bins[3]) && (pow(gen_mumuMass_lmnr,2) < q2_bins[4]) ){gen_entries[3] += 1;}
    else if( (pow(gen_mumuMass_lmnr,2) > q2_bins[5]) && (pow(gen_mumuMass_lmnr,2) < q2_bins[6]) ){gen_entries[5] += 1;}
    else if( (pow(gen_mumuMass_lmnr,2) > q2_bins[7]) && (pow(gen_mumuMass_lmnr,2) < q2_bins[8]) ){gen_entries[7] += 1;}
  }

  cout << "GEN B-FILTER JPSI" << endl;
  for(int evt = 0; evt < t_gen_jpsi->GetEntries(); evt++){
      t_gen_jpsi->GetEntry(evt);

      if( (pow(bfilter_mumuMass_jpsi,2) > q2_bins[4]) && (pow(bfilter_mumuMass_jpsi,2) < q2_bins[5]) ){
        den_entries[4] += 1;
        if(fabs(genmupEta_jpsi)<2.5 && fabs(genmumEta_jpsi)<2.5 &&
           fabs(genkstTrkpEta_jpsi)<2.5 && fabs(genkstTrkmEta_jpsi)<2.5 &&
           genmupPt_jpsi>2.5 && genmumPt_jpsi>2.5 &&
           genkstTrkpPt_jpsi>0.4 && genkstTrkmPt_jpsi>0.4){
             num_entries[4] += 1;
        }
      }
  }

  cout << "GEN B-FILTER PSI" << endl;
  for(int evt = 0; evt < t_gen_psi->GetEntries(); evt++){
      t_gen_psi->GetEntry(evt);

      if( (pow(bfilter_mumuMass_psi,2) > q2_bins[6]) && (pow(bfilter_mumuMass_psi,2) < q2_bins[7]) ){
        den_entries[6] += 1;
        if(fabs(genmupEta_psi)<2.5 && fabs(genmumEta_psi)<2.5 &&
           fabs(genkstTrkpEta_psi)<2.5 && fabs(genkstTrkmEta_psi)<2.5 &&
           genmupPt_psi>2.5 && genmumPt_psi>2.5 &&
           genkstTrkpPt_psi>0.4 && genkstTrkmPt_psi>0.4){
             num_entries[6] += 1;
        }
      }
  }

  cout << "GEN B-FILTER LMNR" << endl;
  for(int evt = 0; evt < t_gen_lmnr->GetEntries(); evt++){
      t_gen_lmnr->GetEntry(evt);

      if( (pow(bfilter_mumuMass_lmnr,2) > q2_bins[0]) && (pow(bfilter_mumuMass_lmnr,2) < q2_bins[1]) ){
        den_entries[0] += 1;
        if(fabs(genmupEta_lmnr)<2.5 && fabs(genmumEta_lmnr)<2.5 &&
           fabs(genkstTrkpEta_lmnr)<2.5 && fabs(genkstTrkmEta_lmnr)<2.5 &&
           genmupPt_lmnr>2.5 && genmumPt_lmnr>2.5 &&
           genkstTrkpPt_lmnr>0.4 && genkstTrkmPt_lmnr>0.4){
             num_entries[0] += 1;
        }
      }

      if( (pow(bfilter_mumuMass_lmnr,2) > q2_bins[1]) && (pow(bfilter_mumuMass_lmnr,2) < q2_bins[2]) ){
        den_entries[1] += 1;
        if(fabs(genmupEta_lmnr)<2.5 && fabs(genmumEta_lmnr)<2.5 &&
           fabs(genkstTrkpEta_lmnr)<2.5 && fabs(genkstTrkmEta_lmnr)<2.5 &&
           genmupPt_lmnr>2.5 && genmumPt_lmnr>2.5 &&
           genkstTrkpPt_lmnr>0.4 && genkstTrkmPt_lmnr>0.4){
             num_entries[1] += 1;
        }
      }

      if( (pow(bfilter_mumuMass_lmnr,2) > q2_bins[2]) && (pow(bfilter_mumuMass_lmnr,2) < q2_bins[3]) ){
        den_entries[2] += 1;
        if(fabs(genmupEta_lmnr)<2.5 && fabs(genmumEta_lmnr)<2.5 &&
           fabs(genkstTrkpEta_lmnr)<2.5 && fabs(genkstTrkmEta_lmnr)<2.5 &&
           genmupPt_lmnr>2.5 && genmumPt_lmnr>2.5 &&
           genkstTrkpPt_lmnr>0.4 && genkstTrkmPt_lmnr>0.4){
             num_entries[2] += 1;
        }
      }

      if( (pow(bfilter_mumuMass_lmnr,2) > q2_bins[3]) && (pow(bfilter_mumuMass_lmnr,2) < q2_bins[4]) ){
        den_entries[3] += 1;
        if(fabs(genmupEta_lmnr)<2.5 && fabs(genmumEta_lmnr)<2.5 &&
           fabs(genkstTrkpEta_lmnr)<2.5 && fabs(genkstTrkmEta_lmnr)<2.5 &&
           genmupPt_lmnr>2.5 && genmumPt_lmnr>2.5 &&
           genkstTrkpPt_lmnr>0.4 && genkstTrkmPt_lmnr>0.4){
             num_entries[3] += 1;
        }
      }

      if( (pow(bfilter_mumuMass_lmnr,2) > q2_bins[5]) && (pow(bfilter_mumuMass_lmnr,2) < q2_bins[6]) ){
        den_entries[5] += 1;
        if(fabs(genmupEta_lmnr)<2.5 && fabs(genmumEta_lmnr)<2.5 &&
           fabs(genkstTrkpEta_lmnr)<2.5 && fabs(genkstTrkmEta_lmnr)<2.5 &&
           genmupPt_lmnr>2.5 && genmumPt_lmnr>2.5 &&
           genkstTrkpPt_lmnr>0.4 && genkstTrkmPt_lmnr>0.4){
             num_entries[5] += 1;
        }
      }

      if( (pow(bfilter_mumuMass_lmnr,2) > q2_bins[7]) && (pow(bfilter_mumuMass_lmnr,2) < q2_bins[8]) ){
        den_entries[7] += 1;
        if(fabs(genmupEta_lmnr)<2.5 && fabs(genmumEta_lmnr)<2.5 &&
           fabs(genkstTrkpEta_lmnr)<2.5 && fabs(genkstTrkmEta_lmnr)<2.5 &&
           genmupPt_lmnr>2.5 && genmumPt_lmnr>2.5 &&
           genkstTrkpPt_lmnr>0.4 && genkstTrkmPt_lmnr>0.4){
             num_entries[7] += 1;
        }
      }

  }

  cout << '|' << setw(15) << "q2Bin" << '|' << setw(15) << "SEL NUM" << '|' << setw(15) << "SEL DEN" << '|' << setw(15) << "GEN NUM" << '|' << setw(15) << "GEN DEN" << '|' << setw(15) << "Efficiency" << '|' << setw(15) << "Acceptance" << '|' << setw(15) << "Efficiency x acceptance" << '|' << endl;

  TH1F* eff_x_acc = new TH1F("eff_x_acc","eff_x_acc",n_q2_bins,q2_bins);

  double efficiency = 0.;
  double acceptance = 0.;

  for(int i = 0; i < n_q2_bins; i++){
    efficiency = reco_entries[i]/gen_entries[i];
    acceptance = num_entries[i]/den_entries[i];
    eff_x_acc->SetBinContent(i,efficiency*acceptance);

  cout << '|' << setw(15) << q2_bins[i] << " - " << q2_bins[i+1] << '|' << setw(15) << reco_entries[i] << '|' << setw(15) << gen_entries[i] << '|' << setw(15) << num_entries[i] << '|' << setw(15) << den_entries[i] << '|' << setw(15) << efficiency << '|' << setw(15) << acceptance << '|' << setw(15) << eff_x_acc->GetBinContent(i) << '|' << endl;
  }

  TCanvas c;
  c.cd();
  gStyle->SetOptStat(0);
  eff_x_acc->SetTitle(Form("Efficiency x Acceptance - %i",year));
  eff_x_acc->GetXaxis()->SetTitle("q^2 [GeV]");
  eff_x_acc->GetYaxis()->SetTitle("#epsilon");
  eff_x_acc->SetMarkerStyle(8);
  eff_x_acc->SetMarkerColor(1);
  eff_x_acc->Draw("P");
  c.SaveAs(Form("~/public/UML-fit/Efficiency/eff_x_acc_%i.gif",year));

  TFile* f;
  f = new TFile(Form("~/public/UML-fit/Efficiency/eff_x_acc_%i.root",year),"UPDATE");
  f->cd();
  eff_x_acc->Write();
  f->Close();
}



