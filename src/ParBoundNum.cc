/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 

#include "Riostream.h" 

#include "ParBoundNum.h" 

ClassImp(ParBoundNum) 

ParBoundNum::ParBoundNum(const char *name, const char *title, 
		   RooAbsReal& _Fl,
		   RooAbsReal& _P1,
		   RooAbsReal& _P2,
		   RooAbsReal& _P3,
		   RooAbsReal& _P4p,
		   RooAbsReal& _P5p,
		   RooAbsReal& _P6p,
		   RooAbsReal& _P8p) :
  RooAbsPdf(name,title), 
  Fl("Fl","Fl",this,_Fl),
  P1("P1","P1",this,_P1),
  P2("P2","P2",this,_P2),
  P3("P3","P3",this,_P3),
  P4p("P4p","P4p",this,_P4p),
  P5p("P5p","P5p",this,_P5p),
  P6p("P6p","P6p",this,_P6p),
  P8p("P8p","P8p",this,_P8p)
{
}


ParBoundNum::ParBoundNum(const ParBoundNum& other, const char* name) :  
  RooAbsPdf(other,name), 
  Fl("Fl",this,other.Fl),
  P1("P1",this,other.P1),
  P2("P2",this,other.P2),
  P3("P3",this,other.P3),
  P4p("P4p",this,other.P4p),
  P5p("P5p",this,other.P5p),
  P6p("P6p",this,other.P6p),
  P8p("P8p",this,other.P8p)
{
}



Double_t ParBoundNum::evaluate() const 
{

//  bool cond4 =false;
  double ret  = 1.0;
  double ret0 = 1.0;
  double ret4 = 1.0;
//  double shift4= 3;
////
//  double coef4 =10;
//  
//  
//   if (Q2Bin==0) coef4 = 40 ;
//   if (Q2Bin==1) coef4 = 40 ;
//   if (Q2Bin==2) coef4 = 40 ;
//   if (Q2Bin==3) coef4 = 40 ;
//   if (Q2Bin==5) coef4 = 40 ;
//   if (Q2Bin==7) coef4 = 2000 ;
  
  double decCC  =0;
  double decCT1 =0;
//  double decWT1 =0;
  double decCT  =1;
//  double decWT  =1;
  double decCTMin  =99999999;
//  double decWTMin  =99999999;
  double decCTMax  =-99999999;
//  double decWTMax  =-99999999;
  double phiMin=999;
  double ctKMin=999;
  double ctLMin=999;
  
  double ctL4phi1 = P4p*P4p + P5p*P5p + P6p*P6p + P8p*P8p - 2 + 2*fabs( 2*P2 - P4p*P5p +P6p*P8p );
  double expo0  =  100*(ctL4phi1)-1.8;
  
  double step = 3;
   for (double i=-step;i<=step;i++){ 
    for (double j=-step;j<=step;j++){ 
     for (double k=-step;k<=step;k++){ 
     
     
     double phi=(TMath::Pi()-1.e-5)/step*i;
     double ctK=j*(1-1.e-5)/step;
     double ctL=k*(1-1.e-5)/step;
     double unoCTK = (1-ctK)*(1+ctK);
     double unoCTL = (1-ctL)*(1+ctL);
     double sqrtCTL = sqrt(unoCTL);
     
     double ZZ = 2 * ctK * sqrt(Fl * (1-Fl) * unoCTK);
     double AA = cos(phi) * ZZ;
     double BB = sin(phi) * ZZ;
     double CC = 2 * P2 * (1-Fl) * unoCTK * ctL;
     double DD = P3 * (1-Fl) * unoCTK * unoCTL * sin(2*phi) ;
     
//  
     decCC =   0.75 * (1-Fl) * unoCTK +
     	       Fl * ctK*ctK +
     	       ( 0.25 * (1-Fl) * unoCTK - Fl * ctK*ctK ) * ( 2 * ctL*ctL -1 ) +
     	       0.5 * P1 * (1-Fl) * unoCTK * unoCTL * cos(2*phi);

     decCT1 =	 AA * ( P4p * ctL * sqrtCTL + P5p * sqrtCTL ) +
     		 BB * ( P8p * ctL * sqrtCTL - P6p * sqrtCTL ) +
     		 CC -
     		 DD;


//      decWT1 =  - AA * ( -1. * P4p * ctL * sqrtCTL + P5p * sqrtCTL ) +
//      	         BB * ( -1. * P8p * ctL * sqrtCTL - P6p * sqrtCTL ) -
//      	         CC +
//      	         DD;
//	       
     decCT = decCC+decCT1;
//     decWT = decCC+decWT1;
//     if(verbose){
//      if(decCT==0||decWT==0) std::cout<<"ctK= "<<ctK<<" ctL= "<<ctL<<" phi= "<<phi<<std::endl;
//     } 
//     if(decCT==0&&decWT==0) continue;
     if(decCT<decCTMin) {
       decCTMin=decCT;
       phiMin=phi;
       ctKMin=ctK;
       ctLMin=ctL;
     }  
//     if(decWT<decWTMin) decWTMin=decWT;
     if(decCT>decCTMax) decCTMax=decCT;
//     if(decWT>decWTMax) decWTMax=decWT;
//     double expo0C =  40*(decCT)+1;
//     double expo0W =  20*(decWT)+1;
//     if(decCT<0) ret *= 1/(1+exp(-expo0C));
//     if(decWT<0) ret *= 1/(1+exp(-expo0W));
//     ret4 *= 1/(1+exp(-expo0C));
     
//     ret4 *= 1/(1+exp(-expo0C))*1/(1+exp(-expo0W));
//
     double expo0C =  40*(decCT)+1;
//     ret4 *= .5*erfc(-expo0C);
     ret4 *= 1/(1+exp(-expo0C));
     }
    }
   }	
   
//    if	(decCTMin<0) {
//     std::cout<<"===================="<<std::endl;
//     std::cout<<" decCTMin = "<< decCTMin<<std::endl;
//     std::cout<<" phiMin   = "<< phiMin<<std::endl;
//     std::cout<<" ctKMin   = "<< ctKMin<<std::endl;
//     std::cout<<" ctLMin   = "<< ctLMin<<std::endl;
//     std::cout<<"===================="<<std::endl;
//    } 	   
//     double expo0C =  40*(decCTMin)-2;
//     ret4 = 1/(1+exp(-expo0C));
//     ret4 = .5*erfc(expo0C);

//    double expo0C =  40*(decCT)+2;
//    double expo0W =  20*(decWT)+2;
//  ret0 = 0.5*erfc(expo0);
//    decCT = 0.5*erfc(expo0C)*0.5*erfc(expo0W)*decCT;
//    decWT = 0.5*erfc(expo0C)*0.5*erfc(expo0W)*decWT;
//    decCT = 1/(1+exp(-expo0C))*1/(1+exp(-expo0W))*decCT*0.5*erfc(expo0);
//    decWT = 1/(1+exp(-expo0C))*1/(1+exp(-expo0W))*decWT*0.5*erfc(expo0);
//   ret = 1/(1+exp(-expo0C))*1/(1+exp(-expo0W))*1/(1+exp(expo0));
//  double expo0C =  (decCT)+2;
//  double expo0W =  (decWT)+2;


  ret0 =1/(1+exp(expo0));
//
  ret=ret4*ret0;
//  ret=(ret4);
//  
  
   if(verbose){
    std::cout<<Form("Q2Bin=%d decCTMin=%3.30f   decCTMax=%3.10f phiMin=%3.10f ctKMin=%3.10f  ctLMin=%3.10f ret0=%3.10f ret4=%3.10f  retTot=%3.10f ",\
    Q2Bin,decCTMin,decCTMax,phiMin,ctKMin,ctLMin,ret0,ret4,ret)<<std::endl;
   } 
  return ret ;

}
