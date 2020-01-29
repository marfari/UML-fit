/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "ParBound.h" 

ClassImp(ParBound) 

ParBound::ParBound(const char *name, const char *title, 
		   RooAbsReal& _P1,
		   RooAbsReal& _P2,
		   RooAbsReal& _P3,
		   RooAbsReal& _P4p,
		   RooAbsReal& _P5p,
		   RooAbsReal& _P6p,
		   RooAbsReal& _P8p) :
  RooAbsPdf(name,title), 
  P1("P1","P1",this,_P1),
  P2("P2","P2",this,_P2),
  P3("P3","P3",this,_P3),
  P4p("P4p","P4p",this,_P4p),
  P5p("P5p","P5p",this,_P5p),
  P6p("P6p","P6p",this,_P6p),
  P8p("P8p","P8p",this,_P8p)
{
}


ParBound::ParBound(const ParBound& other, const char* name) :  
  RooAbsPdf(other,name), 
  P1("P1",this,other.P1),
  P2("P2",this,other.P2),
  P3("P3",this,other.P3),
  P4p("P4p",this,other.P4p),
  P5p("P5p",this,other.P5p),
  P6p("P6p",this,other.P6p),
  P8p("P8p",this,other.P8p)
{
}



Double_t ParBound::evaluate() const 
{

  bool cond0 =false;
  bool cond1 =false;
  bool cond2 =false;
  bool cond3 =false;
  bool cond4 =false;
  double power = 6.0;
//  double power2 = 4.0;
  double ret = 1.0;
  double ret0 = 1.0;
  double ret4= 1.0;
//  double local_ret5=1.0;
//  double local_ret6=1.0;
  double shift0= 1.8;
  double shift4= 1.8;
//
  double coef0 =100;
  double coef4 =100;
//  
//   if (Q2Bin==0) coef0 =80;
//   if (Q2Bin==1) coef0 =130;
//   if (Q2Bin==2) coef0 =80;
//   if (Q2Bin==3) coef0 =70;
//   if (Q2Bin==5) coef0 =70;
//   if (Q2Bin==7) coef0 =80;
  if (Q2Bin==0) coef0 =200;
  if (Q2Bin==1) coef0 =200;
  if (Q2Bin==2) coef0 =200;
  if (Q2Bin==3) coef0 =200;
  if (Q2Bin==5) coef0 =200;
  if (Q2Bin==7) coef0 =200;
//  
  if (Q2Bin==0) coef4 =1000;
  if (Q2Bin==1) coef4 =1000;
  if (Q2Bin==2) coef4 =1000;
  if (Q2Bin==3) coef4 =1000;
  if (Q2Bin==5) coef4 =1000;
  if (Q2Bin==7) coef4 =1000;
  
//  
  double ctL4phi1 = P4p*P4p + P5p*P5p + P6p*P6p + P8p*P8p - 2 + 2*fabs( 2*P2 - P4p*P5p +P6p*P8p );
  // std::cout<<" ctL4phi1="<<ctL4phi1<<std::endl;
  
  if ( ctL4phi1>0 ) {cond0=true;}
//    cond0=true;
    // std::cout<<"ctL4phi1="<<ctL4phi1<<std::endl;
    //ret = exp(-200*pow(ctL4phi1/16.0,power2/2));
    double expo0 = coef0*(ctL4phi1)-shift0;
    ret0 = 0.5*(1-expo0/sqrt(1+expo0*expo0));
//    if(Q2Bin==7)     ret = exp(-690*pow(ctL4phi1/16.0,power2/2));
//    ret = erfc((30*ctL4phi1-1.8))/2;
//    ret = 0.5*(1-tanh(expo));
    
//    ret = 0.5*(1-(exp(expo)-exp(-expo))/(exp(expo)+exp(-expo)));
//      if (ret==0) {
//        std::cout<<Form("ERROR! Precision not sufficient for ctL4phi1=%3.20f ret=%3.20f expo=%3.20f",ctL4phi1,ret,expo)<<std::endl;
//      }    
    if (ret0==0) {
      std::cout<<"ERROR! Precision not sufficient for ctL4phi1="<<ctL4phi1
	       <<" ret= "<<ret<<std::endl;
      return 1e-300;
    }
//  }
//
if(verbose) {

  double ctK2 = P1*P1 + 4*P2*P2 + 4*P3*P3 -1;

  if ( ctK2>0 ) {
    double local_ret = exp(-690*pow(ctK2/2.0,power/2));
    if (local_ret==0) {
      std::cout<<"ERROR! Precision not sufficient for ctK2="<<ctK2
	       <<" ret=exp("<<-690*pow(ctK2/2.0,power/2)<<")"<<std::endl;
      return 1e-300;
    }
    cond1=true;
    //if ( ret > local_ret ) ret = local_ret;
    //ret=ret*local_ret;
  }

  double ctL2phi1 = P5p*P5p*(1-P1) + P6p*P6p*(1+P1) - 4*P3*P5p*P6p - 1 + P1*P1 + 4*P3*P3;
  double ctL2phi2 = P6p*P6p - 1 + P1;
  double ctL2phi3 = P5p*P5p - 1 - P1;
  // std::cout<<" ctL2phi1="<<ctL2phi1<<" ctL2phi2="<<ctL2phi2<<" ctL2phi3="<<ctL2phi3<<std::endl;

  if ( ctL2phi1>0 ) {
    // std::cout<<"ctL2phi1="<<ctL2phi1<<" ctL2phi2="<<ctL2phi2<<" ctL2phi3="<<ctL2phi3<<std::endl;
    double local_ret = exp(-690*pow(ctL2phi1/9.0,power/3));
    if (local_ret==0) {
      std::cout<<"ERROR! Precision not sufficient for ctL2phi1="<<ctL2phi1
	       <<" ret=exp("<<-690*pow(ctL2phi1/9.0,power/3)<<")"<<std::endl;
      return 1e-300;
    }
    cond2=true;
    //ret=ret*local_ret;
    //if ( ret > local_ret ) ret = local_ret;
  }
  if ( ctL2phi2>0 || ctL2phi3>0 ) {
    double local_ret = exp(-690*pow(TMath::Max(ctL2phi2,ctL2phi3)/2.0,power/2));
    if (local_ret==0) {
      std::cout<<"ERROR! Precision not sufficient for ctL2phi2="<<ctL2phi2<<" ctL2phi3="<<ctL2phi3
	       <<" ret=exp("<<-690*pow(TMath::Max(ctL2phi2,ctL2phi3)/2.0,power/2)<<")"<<std::endl;
      return 1e-300;
    }
    //if ( ret > local_ret ) ret = local_ret;
    //ret=ret*local_ret;
    cond3=true;
  }
  if ( ctL2phi1<0 && ctL2phi2*ctL2phi3<0 ) std::cout<<"ERROR! ctL2phi2 and ctL2phi3 have different sign! ctL2phi2="<<ctL2phi2<<" ctL2phi3="<<ctL2phi3<<std::endl;

}  
//if(verbose){
  // Avoid numerical computation when the boundary is already exceeded
  // except when the constraint is very weak (0.01<ret<1), and a stronger one can be obtained with the following checks
//
  //if ( ret < 0.01 ) return ret;

  double a0 = 1 - P1*P1 - P6p*P6p*(1+P1) - P8p*P8p*(1-P1) - 4*P2*P2 - 4*P2*P6p*P8p; 
  double a4 = 1 - P1*P1 - P4p*P4p*(1+P1) - P5p*P5p*(1-P1) - 4*P2*P2 + 4*P2*P4p*P5p; 

  double a1 = 4*P3*P8p*P8p - 4*P3*P6p*P6p - 8*P1*P3 + 2*P5p*P6p*(1+P1) - 2*P4p*P8p*(1-P1) - 4*P2*P4p*P6p + 4*P2*P5p*P8p;
  double a3 = 4*P3*P4p*P4p - 4*P3*P5p*P5p + 8*P1*P3 + 2*P5p*P6p*(1-P1) - 2*P4p*P8p*(1+P1) - 4*P2*P4p*P6p + 4*P2*P5p*P8p;

  double a2 = 2 + 2*P1*P1 - 8*P2*P2 - 16*P3*P3 - (P4p*P4p+P6p*P6p)*(1-P1) - (P5p*P5p+P8p*P8p)*(1+P1) + 4*P2*P4p*P5p - 4*P2*P6p*P8p + 8*P3*P4p*P8p + 8*P3*P5p*P6p;

  double b0 = P8p*P8p - 1 - P1 + 2*P2 + P6p*P8p; 
  double b2 = P4p*P4p - 1 + P1 + 2*P2 - P4p*P5p; 
  double b1 = P4p*P8p - 2*P3 + 0.5 * ( P4p*P6p - P5p*P8p );
  
  double c0 = P8p*P8p - 1 - P1 - 2*P2 - P6p*P8p; 
  double c2 = P4p*P4p - 1 + P1 - 2*P2 + P4p*P5p; 
  double c1 = P4p*P8p - 2*P3 - 0.5 * ( P4p*P6p - P5p*P8p );
  
  int nSteps = 100;
  int halfSteps = nSteps/2;
  double phi, sin2, sincos, cos2;
  double ctL1, ctL5p, ctL5m;
  double local_ret4=1;
  double min_ret4=1;
  for (int step = -1*halfSteps; step<halfSteps; ++step) {
    phi = 3.14159 * step / halfSteps;
    sin2 = sin(phi)*sin(phi);
    sincos = sin(phi)*cos(phi);
    cos2 = cos(phi)*cos(phi);

    ctL5p = b0*sin2 + b1*sincos + b2*cos2;
//    if ( ctL5p >= 0 ) continue;
    ctL5m = c0*sin2 + c1*sincos + c2*cos2;
//    if ( ctL5m >= 0 ) continue;

    ctL1 = a0*sin2*sin2 + a1*sin2*sincos + a2*sin2*cos2 + a3*sincos*cos2 + a4*cos2*cos2;
//    if ( ctL1 >= 0 ) continue;
//
//    local_ret4 = exp(690*TMath::Max(-1*pow(-1*ctL1/1.1,power/3),-1*pow(-1*TMath::Max(ctL5m,ctL5p)/3.0,power/2)));
//	double expo4 = coef4*(-1*ctL1)-shift;
//	double expo5 = coef4*(-1*ctL5m)-shift;
//	double expo6 = coef4*(-1*ctL5p)-shift;
//       double min4 = TMath::Min(ctL1,TMath::Min(ctL5m,ctL5p));
       double max4 = TMath::Max(ctL1,TMath::Max(ctL5m,ctL5p));
       double expo4 = coef4*(max4)+shift4;
//       double expo4 = coef4*(TMath::Max(-1*pow(-1*ctL1/1.1,power/3),-1*pow(-1*TMath::Max(ctL5m,ctL5p)/3.0,power/2)))-shift;
       local_ret4 = 0.5*(1+expo4/sqrt(1+expo4*expo4));
//       local_ret5 = 0.5*(1-expo5/sqrt(1+expo5*expo5));
//       local_ret6 = 0.5*(1-expo6/sqrt(1+expo6*expo6));
//       local_ret4=TMath::Min(local_ret4,TMath::Min(local_ret5,local_ret6));
    if (local_ret4==0) {
      std::cout<<"ERROR! Precision not sufficient for ctL5p="<<ctL5p<<" ctL5m="<<ctL5m<<" ctL1="<<ctL1
	       <<" ret= "<<ret<<std::endl;
      return 1e-300;
    }
//
    if(ctL5p<0&&ctL5m<0&&ctL1<0) cond4=true;
//    
    if(min_ret4> local_ret4)  min_ret4= local_ret4; 
//    if (ret4>local_ret4) ret4=ret4*local_ret4;
    
    ret4=ret4*local_ret4;
//    ret=ret*local_ret4*local_ret5*local_ret6;
    //if ( ret > local_ret4 ) ret = local_ret4;
  }
//}
  ret=ret0*ret4;
  
   if(verbose){
    std::cout<<Form("Q2Bin=%d cond 0=%d 1=%d 2=%d 3=%d 4=%d ret0=%3.10f ret4=%3.10f  retTot=%3.10f ctL4phi1=%3.10f local_ret4=%3.10f min_ret4=%3.10f",Q2Bin,cond0,cond1,cond2,cond3,cond4,
    ret0,ret4,ret,ctL4phi1,local_ret4,min_ret4)<<std::endl;
   } 
  return ret ;

}