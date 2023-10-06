
// (C)2023.Simon Aranda 
// bunch.cpp

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include "boost/multiprecision/cpp_int.hpp"

// types
using namespace boost::multiprecision;
typedef cpp_int       SZ;
typedef cpp_rational  SQ;
using namespace std;


SZ SZroot(const SZ p) {
const SZ Cero=0;
if(p<=0)return Cero;
SZ e=0;
const SZ r= sqrt(p,e);
if(e==0)return r;
return Cero;
}
SZ YfromNX(const SZ n,const SZ x) {
const SZ Cero=0;
SZ a= x+n;
SZ b= x-n;
SZ c= a*b;
SZ d= c*x;if(d<= 0)return Cero;
SZ y=SZroot(d);if(y<= 0)return Cero;
return y;
}

void pout(char t,SZ n,SQ x,SQ y) {
  cout<<"  "<<t<<"("<<x<<", "<<y<<")"<<endl;
  assert(y*y == (x*x*x -n*n*x) );
  }

void theBunch(const SZ n,const SZ x,const SZ y) {
SQ px,py,qx,qy;
SQ rx,ry,sx,sy;
SQ fx1,fy1,fw1;
SQ fx2,fy2,fw2;
SQ ta,tb,tc,h;
SQ fp,fq,fr,fs;

cout<<"bunch:"<<endl;
if(x<0) {
  SZ ax= -x;
  px=x;
  py=y;
  fy1= (SQ) y/(SQ)ax;
  fx1= (SQ) ax;
  fw1= (SQ) (n*n)/(SQ)ax;

// check xyw1
  // cout<<"xyw1("<<fx1<<","<<fy1<<","<<fw1<<")"<<endl;
  assert(n*n == fx1*fw1);
  assert(fx1+fy1*fy1 == fw1);

  qx= fw1;
  qy= fw1*fy1;
  pout('P',n,(SQ)x,(SQ)y);
  pout('Q',n,qx,qy);
  }

else { // x>0
  qx=x;
  qy=y;

  fy1 =(SQ)y/(SQ)x;
  fw1 =x;
  fx1 =(SQ)(n*n)/(SQ)x;

  px= fx1;
  py= px*fy1;
  pout('P',n,-px,py);  // cout P check
  pout('Q',n,(SQ)x,(SQ)y);  // cout P check
  }

  {
  h = (fx1+fw1)/fy1; //
  fy2= (2*n)/fy1;
  }
  
// check xyw1
assert(n*n == fx1*fw1);
assert(fx1+fy1*fy1 == fw1);
cout<<"xyw1 Checked"<<endl;

// P Q -> R S
  {
  rx= (fy2*(h-fy2))/2;
  ry= rx*fy2;

  sx= (fy2*(h+fy2))/2;
  sy= sx*fy2;

  fx2= rx;
  fw2= sx;
  
  // cout check r s points
  pout('R',n,-rx,ry);
  pout('S',n,sx,sy);
  }

// check xyw2
  assert(n*n == fx2*fw2);
  assert(fx2+fy2*fy2 == fw2);
  cout<<"xyw2 Checked"<<endl;
  
// h1 = h2
  assert( (fx1+fw1)/fy1 == (fx2+fw2)/fy2 );
  assert( (fx1+fw1)/fy1 == h );

// -> TR, PQRS
  {
  ta=min(fy1,fy2);
  tb=max(fy1,fy2);
  tc=h;
  // cout T check
  cout<<"TR("<<ta<<" , "<<tb<<" , "<<tc<<")"<<endl;
  assert(ta*ta+tb*tb==tc*tc);
  assert(ta*tb == 2*n);
  // pqrs
  fs= (+ta+tb+tc)/2;
  fr= (+ta+tb-tc)/2;
  fp= (+ta-tb+tc)/2;
  fq= (-ta+tb+tc)/2;
  // check pq=rs, s=p+q+r
  cout<<"form pqrs: "<<fp<<" * "<<fq<<" = "<<fr<<" * "<<fs<<endl;
  cout<<"         : "<<fp<<" + "<<fq<<" + "<<fr<<" = "<<fs<<endl;
  assert(fp*fq == fr*fs );
  assert(fp+fq+fr==fs);
  }
}


int searchPoints(const SZ n) {
const SZ rlim= 2*n*n;
int q=0;
for(SZ x= -(n-1);x< rlim;x++)
  {
  if(x==0){x= +n+1;}
  SZ y= YfromNX(n,(x));if(y==0)continue;
  cout<<"new "<<n<<": ("<<x<<","<<y<<")"<<endl;q++;
  theBunch(n,x,y);
  cout<<endl<<endl;
  }
return q;
}

int main(void) {
  
for(SZ n= 5;n<30;n++) {
  int q= searchPoints(n);
  if(q>0)cout<<endl;
  }
 
return 0;
}

