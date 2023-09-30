

// Example of parallel use of two forms with similar requirements.
// (C)2023.Simon Aranda


#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include "boost/multiprecision/cpp_int.hpp"

using namespace boost::multiprecision;
typedef number<cpp_int_backend<128, 128, signed_magnitude, unchecked, void>> SZ; // 128b
typedef cpp_rational SQ;
using namespace std;


SZ SZroot(const SZ p) {
const SZ Cero=0;
SZ e=0;
SZ r= sqrt(p,e);if(e==0)return r;
return Cero;
}

void quartic(const SZ n) {
const SZ npn=   2*n;
const SZ n12= 1*n*n;
const SZ n42= 4*n*n;
bool filin=true;
for(SZ p=1;p< npn;p++) 
  {
  const SZ p2= p*p;
  const SZ p4= p2*p2;
  const SZ tm= n12-p4;
  const SZ tp= n42+p4;

  SZ gm=0;if(tm>1)gm= SZroot(tm);
  SZ gp= SZroot(tp);
  bool lbm= (gm>0);bool lbp= (gp>0);
  bool som= (lbm || lbp);if(!som)continue;
  if(filin){cout<<endl<<"n= "<<n<<endl;filin=false;}

  if(lbp) 
    {
    // eqn. 
    cout<<"4N2: "<<gp<<"^2 = 4*";
    cout<<n<<"^2 + "<<p<<"^4   ";
    // geometry
    SQ h  (gp , p);SQ c2 (npn, p);
    cout<<"triangle("<<p<<", "<<c2<<", "<<h<<")"<<endl;
    }
      
  if(lbm) 
    {
    // eqn. 
    cout<<"GNP: "<<gm<<"^2 = 1*";
    cout<<n<<"^2 - "<<p<<"^4   ";
    // geometry
    // gnp tr( g/p, 2np/g, (g^2 +2*p^4)/pg )
    SQ c1 (gm,p);
    SZ t01= npn*p;SQ c2 (t01, gm);
    SZ t03= (tm + 2*p4);SZ t04= p*gm;SQ h (t03, t04);
    cout<<"triangle("<<c1<<", "<<c2<<", "<<h<<")"<<endl;
    }
      
  }
}

int main(void) {

for(SZ n= 5;n< 300;n++) quartic(n);

return 0;
}


