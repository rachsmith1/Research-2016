#include <vector>
#include <math.h>
#include <TLorentzVector.h>
#include <iostream>

void invariant_mass()
{
   TFile* f = TFile::Open("signal.root");
	TTree* fChain = (TTree*)gDirectory->Get("nominal");

   Int_t triggerPass;
	fChain->SetBranchAddress("triggerPass",&triggerPass);

   std::vector<double> *jet_pt;
	fChain->SetBranchAddress("jet_pt",&jet_pt);
   std::vector<double> *jet_eta;
   fChain->SetBranchAddress("jet_eta",&jet_eta);
   std::vector<double> *jet_phi;
   fChain->SetBranchAddress("jet_phi",&jet_phi);
   std::vector<double> *jet_e;
   fChain->SetBranchAddress("jet_e",&jet_e);
   std::vector<double> *jet_mv2c20;
   fChain->SetBranchAddress("jet_mv2c20",&jet_mv2c20);

   std::vector<double> *mu_pt;
	fChain->SetBranchAddress("mu_pt",&mu_pt);
   std::vector<double> *mu_eta;
   fChain->SetBranchAddress("mu_eta",&mu_eta);
   std::vector<double> *mu_phi;
   fChain->SetBranchAddress("mu_phi",&mu_phi);
   std::vector<double> *mu_e;
   fChain->SetBranchAddress("mu_e",&mu_e);
   std::vector<double> *mu_isoGradient;
   fChain->SetBranchAddress("mu_isoGradient",&mu_isoGradient);

   Char_t HLT_mu20_iloose_L1MU15;
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15",&HLT_mu20_iloose_L1MU15);
   Char_t HLT_mu18_mu8noL1;
   fChain->SetBranchAddress("HLT_mu18_mu8noL1",&HLT_mu18_mu8noL1);
   Char_t HLT_mu18_2mu4noL1;
   fChain->SetBranchAddress("HLT_mu18_2mu4noL1",&HLT_mu18_2mu4noL1);
   Char_t HLT_mu50;
   fChain->SetBranchAddress("HLT_mu50",&HLT_mu50);
   Char_t HLT_mu60_0eta105_msonly;
   fChain->SetBranchAddress("HLT_mu60_0eta105_msonly",&HLT_mu60_0eta105_msonly);
   Char_t HLT_2mu10;
   fChain->SetBranchAddress("HLT_2mu10",&HLT_2mu10);
   Char_t HLT_mu26_imedium;
   fChain->SetBranchAddress("HLT_mu26_imedium",&HLT_mu26_imedium);
   Char_t HLT_3mu6_msonly;
   fChain->SetBranchAddress("HLT_3mu6_msonly",&HLT_3mu6_msonly);
   Char_t HLT_3mu6;
   fChain->SetBranchAddress("HLT_3mu6",&HLT_3mu6);

   std::vector<double> *mu_trigMatch_HLT_mu20_iloose_L1MU15;
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu20_iloose_L1MU15",&mu_trigMatch_HLT_mu20_iloose_L1MU15);
   std::vector<double> *mu_trigMatch_HLT_mu18_mu8noL1;
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu18_mu8noL1",&mu_trigMatch_HLT_mu18_mu8noL1);
   std::vector<double> *mu_trigMatch_HLT_mu18_2mu4noL1;
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu18_2mu4noL1",&mu_trigMatch_HLT_mu18_2mu4noL1);
   std::vector<double> *mu_trigMatch_HLT_mu50;
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu50",&mu_trigMatch_HLT_mu50);
   std::vector<double> *mu_trigMatch_HLT_mu60_0eta105_msonly;
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu60_0eta105_msonly",&mu_trigMatch_HLT_mu60_0eta105_msonly);
   std::vector<double> *mu_trigMatch_HLT_2mu10;
   fChain->SetBranchAddress("mu_trigMatch_HLT_2mu10",&mu_trigMatch_HLT_2mu10);
   std::vector<double> *mu_trigMatch_HLT_mu26_imedium;
   fChain->SetBranchAddress("mu_trigMatch_HLT_mu26_imedium",&mu_trigMatch_HLT_mu26_imedium);
   std::vector<double> *mu_trigMatch_HLT_3mu6_msonly;
   fChain->SetBranchAddress("mu_trigMatch_HLT_3mu6_msonly",&mu_trigMatch_HLT_3mu6_msonly);
   std::vector<double> *mu_trigMatch_HLT_3mu6;
   fChain->SetBranchAddress("mu_trigMatch_HLT_3mu6",&mu_trigMatch_HLT_3mu6);

   Float_t weight_mc;
	fChain->SetBranchAddress("weight_mc",&weight_mc);
   Float_t weight_pileup;
	fChain->SetBranchAddress("weight_pileup",&weight_pileup);
   Float_t weight_leptonSF;
	fChain->SetBranchAddress("weight_leptonSF",&weight_leptonSF);
   Float_t weight_bTagSF_77;
	fChain->SetBranchAddress("weight_bTagSF_77",&weight_bTagSF_77);

   TH1F *bbbb = new TH1F("bbbb","bbbb",25,0,250);
   TH1F *bbbm = new TH1F("bbbm","bbbm",25,0,250);
   TH1F *bbmm = new TH1F("bbmm","bbmm",25,0,250);
   TH1F *bmmm = new TH1F("bmmm","bmmm",25,0,250);
   TH1F *mmmm = new TH1F("mmmm","mmmm",25,0,250);

   TH1F *bbb = new TH1F("bbb","bbb",25,0,250);
   TH1F *bbm = new TH1F("bbm","bbm",25,0,250);
   TH1F *bmm = new TH1F("bmm","bmm",25,0,250);
   TH1F *mmm = new TH1F("mmm","mmm",25,0,250);

   TH1F *bb = new TH1F("bb","bb",25,0,250);
   TH1F *bm = new TH1F("bm","bm",25,0,250);
   TH1F *mm = new TH1F("mm","mm",25,0,250);  

   int no_isolated=0;
   int passed_trigger=0;
   int no_isolated_and_passed_trigger=0;

   UInt_t nentries = UInt_t(fChain->GetEntriesFast());
   for (UInt_t entryInChain=0; entryInChain<nentries; entryInChain++)
	{
		UInt_t entryInTree = fChain->GetEntry(entryInChain);
		if (entryInTree<0) break;
		fChain->GetEntry(entryInChain);

      if (entryInChain%1000==0) cout << entryInChain << endl;

      bool passTrigger = false;

      if (HLT_mu20_iloose_L1MU15==1)   passTrigger = true;
      if (HLT_mu18_mu8noL1==1)         passTrigger = true;
      if (HLT_mu18_2mu4noL1==1)        passTrigger = true;
      if (HLT_mu50==1)                 passTrigger = true;
      if (HLT_mu60_0eta105_msonly==1)  passTrigger = true;
      if (HLT_2mu10==1)                passTrigger = true;
      if (HLT_mu26_imedium==1)         passTrigger = true;
      if (HLT_3mu6_msonly==1)          passTrigger = true;
      if (HLT_3mu6==1)                 passTrigger = true;

      if (passTrigger==false) continue;

      double cross_section = 30.198; //signal
      double sum_weights =463600; //signal

      //double cross_section = 831.76; //ttbar
      //double sum_weights =500000; //ttbar

      //double cross_section = 187710.0; //qcd
      //double sum_weights =500000; //qcd

      double weight = weight_mc*weight_pileup*weight_leptonSF*weight_bTagSF_77*cross_section/sum_weights;

      vector< vector<double> > jets;
      vector<double> jet;
      vector< vector<double> > muons;
      vector<double> muon;
      jets.clear();
      muons.clear();
      
      bool isolated_muon = false;
      for (int i=0; i<mu_pt->size(); i++)
      {
         if (mu_isoGradient->at(i)==1) isolated_muon = true;
      }

      if (isolated_muon==false) no_isolated++;
      if (passTrigger==true) passed_trigger++;
      if (isolated_muon==false && passTrigger==true) no_isolated_and_passed_trigger++;

      if (isolated_muon == false) 
      {
              
         for (int m=0; m<mu_pt->size(); m++)
         {
               bool muon_in_jet=false;
         
               for (int j=0; j<jet_pt->size(); j++)
               {
                  if (jet_pt->at(j)>20000 && abs(jet_eta->at(j))<2.5 && jet_mv2c20->at(j)>-0.4434)
                  {
                     TLorentzVector m_muon;
                     TLorentzVector m_jet;
                     m_muon.SetPtEtaPhiE(mu_pt->at(m),mu_eta->at(m),mu_phi->at(m),mu_e->at(m));
                     m_jet.SetPtEtaPhiE(jet_pt->at(j),jet_eta->at(j),jet_phi->at(j),jet_e->at(j));
               
                     if (m_jet.DeltaR(m_muon)<0.4) muon_in_jet=true;
                  }
               }
         
               if (muon_in_jet==false)
               {
                  muon.clear();
                  muon.push_back(mu_pt->at(m));
                  muon.push_back(mu_eta->at(m));
                  muon.push_back(mu_phi->at(m));
                  muon.push_back(mu_e->at(m));
                  muons.push_back(muon);
               }
         }

         for (int j=0; j<jet_pt->size(); j++)
         {
            if (jet_pt->at(j)>20000 && abs(jet_eta->at(j))<2.5 && jet_mv2c20->at(j)>-0.4434)
            {
               jet.clear();
               jet.push_back(jet_pt->at(j));
               jet.push_back(jet_eta->at(j));
               jet.push_back(jet_phi->at(j));
               jet.push_back(jet_e->at(j));
               jets.push_back(jet);
            }
         }
          
      }

      int num_muons=muons.size();
      int num_jets=jets.size();
      
      TLorentzVector sum;
      TLorentzVector jetVector;
      TLorentzVector muVector;
      sum.SetPtEtaPhiE(0,0,0,0);

      if (num_muons + num_jets == 4)
      {
         for (int i=0; i<muons.size(); i++) 
         {
            muVector.SetPtEtaPhiE((muons.at(i)).at(0), (muons.at(i)).at(1), (muons.at(i)).at(2), (muons.at(i)).at(3));
            sum = sum + muVector;
         }
         for (int i=0; i<jets.size(); i++)
         {
            jetVector.SetPtEtaPhiE((jets.at(i)).at(0), (jets.at(i)).at(1), (jets.at(i)).at(2), (jets.at(i)).at(3));
            sum = sum + jetVector;
         }
         if (num_muons==0) bbbb->Fill(sum.M()/1000, weight);
         if (num_muons==1) bbbm->Fill(sum.M()/1000, weight);
         if (num_muons==2) bbmm->Fill(sum.M()/1000, weight);
         if (num_muons==3) bmmm->Fill(sum.M()/1000, weight);
         if (num_muons==4) mmmm->Fill(sum.M()/1000, weight);
      }

      if (num_muons + num_jets == 3)
      {
         for (int i=0; i<muons.size(); i++) 
         {
            muVector.SetPtEtaPhiE((muons.at(i)).at(0), (muons.at(i)).at(1), (muons.at(i)).at(2), (muons.at(i)).at(3));
            sum = sum + muVector;
         }
         for (int i=0; i<jets.size(); i++)
         {
            jetVector.SetPtEtaPhiE((jets.at(i)).at(0), (jets.at(i)).at(1), (jets.at(i)).at(2), (jets.at(i)).at(3));
            sum = sum + jetVector;
         }
         if (num_muons==0) bbb->Fill(sum.M()/1000, weight);
         if (num_muons==1) bbm->Fill(sum.M()/1000, weight);
         if (num_muons==2) bmm->Fill(sum.M()/1000, weight);
         if (num_muons==3) mmm->Fill(sum.M()/1000, weight);
      }

      if (num_muons + num_jets == 2)
      {
         for (int i=0; i<muons.size(); i++) 
         {
            muVector.SetPtEtaPhiE((muons.at(i)).at(0), (muons.at(i)).at(1), (muons.at(i)).at(2), (muons.at(i)).at(3));
            sum = sum + muVector;
         }
         for (int i=0; i<jets.size(); i++)
         {
            jetVector.SetPtEtaPhiE((jets.at(i)).at(0), (jets.at(i)).at(1), (jets.at(i)).at(2), (jets.at(i)).at(3));
            sum = sum + jetVector;
         }
         if (num_muons==0) bb->Fill(sum.M()/1000, weight);
         if (num_muons==1) bm->Fill(sum.M()/1000, weight);
         if (num_muons==2) mm->Fill(sum.M()/1000, weight);
      }
   }

   /*cout << no_isolated << endl;
   cout << passed_trigger << endl;
   cout << no_isolated_and_passed_trigger << endl;*/

   TCanvas *c1 = new TCanvas();
   bbbb->Draw();
   
   TCanvas *c2 = new TCanvas();
   bbbm->Draw();
   
   TCanvas *c3 = new TCanvas();
   bbmm->Draw();
   
   TCanvas *c4 = new TCanvas();
   bmmm->Draw();
   
   TCanvas *c5 = new TCanvas();
   mmmm->Draw();
      
   TCanvas *c6 = new TCanvas();
   bbb->Draw();
      
   TCanvas *c7 = new TCanvas();
   bbm->Draw();
  
   TCanvas *c8 = new TCanvas();
   bmm->Draw();
      
   TCanvas *c9 = new TCanvas();
   mmm->Draw();

   TCanvas *c10 = new TCanvas();
   bb->Draw();

   TCanvas *c11 = new TCanvas();
   bm->Draw();

   TCanvas *c12 = new TCanvas();
   mm->Draw();
   
   /*TFile file1("qcd_hist.root","new");
   bbbb->Write();
   bbbm->Write();
   bbmm->Write();
   bmmm->Write();
   mmmm->Write();
   bbb->Write();
   bbm->Write();
   bmm->Write();
   mmm->Write();
   bb->Write();
   bm->Write();
   mm->Write();*/

}


