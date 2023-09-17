

//(C)2023.Author: Simon Aranda 

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <utility>
#include "boost/multiprecision/cpp_int.hpp"

// types
using namespace boost::multiprecision;
typedef cpp_int       SZ; //  Z
typedef cpp_rational  SQ; //  Q
using namespace std;
typedef std::pair<SQ, SQ> QPOINT;


//////////////////////////////
// Pkg 
SZ SZroot(SZ p) {
const SZ Cero=0;
if(p<= Cero)return Cero;
SZ e=0;SZ r= sqrt(p,e);if(e==0)return r;
return Cero;
}
SQ SQroot(SQ q) {
const SZ Cero=0;const SZ One=1;
const SQ q0 (Cero,One);if(q<= q0)return q0;
SZ nume= SZroot( numerator(q) );
SZ deno= SZroot( denominator(q) );
if(nume==Cero)return q0;
if(deno==Cero)return q0;
SQ v (nume,deno);return v;
}
void Xcheck(SZ nz,SQ x) {
const SZ Cero=0;const SZ One=1;
const SQ q0 (Cero,One);
const SQ n (nz,One);
SQ y2= (x*x*x)-(n*n*x);assert(y2>q0);
SQ y = SQroot(y2);assert(y != q0);
}
SZ YfromNX(const SZ n,const SZ x) {
const SZ Cero=0;
SZ a= x+n;SZ b= x-n;
SZ c= a*b;SZ d= c*x;
if(d<= 0)return Cero;
SZ y=SZroot(d);if(y<= 0)return Cero;
return y;
}
void Pcheck(SZ nz,SQ x,SQ y) {
const SZ One=1;
const SQ n (nz,One);
SQ a= x+n;SQ b= x-n;
SQ c= a*b;SQ d= x*c;
SQ y2= y*y;
bool isp= (y2==d);assert(isp);
}

void ListDoubles(const SZ n) {
const SZ Cero=0;const SZ One=1;
const SZ n2= n*n;
bool first=true;
for(SZ Lx= (-n+1);Lx<0;Lx++) // never -n,0,+n
  {
  SZ aLx=  -Lx;
  SZ Ly= YfromNX(n,Lx);if(Ly==Cero)continue;
  if(first)cout<<"------------"<<endl;
  first=false;
  // point left L(Lx<0, Ly) 
  // Form XYW(fx,fy,fw)
  SQ fx (aLx, One);
  SQ fw (n2, aLx);
  // on point left, Ly is ax*fy then..
  SQ fy (Ly, aLx);
  cout<<"n= "<<setw(4)<<n<<"  XYW: ";
  cout<<fx<<"__"<<fy<<"__"<<fw;

  // point right is R(w, wy)
  SQ Rx= fw;SQ Ry= fw*fy;
  cout<<" L: "<<Lx<<","<<Ly;
  cout<<" R: "<<Rx<<","<<Ry<<endl;
  Pcheck(n, Rx,Ry);
  
  // new form from the current form
  // can iterate until infinite
    {
    SQ x= fx;SQ y= fy;

    // the new equations
    // to xnew
    SQ j= (y*y*y)/((2*x)+ (y*y));
    SQ xnew= (j*j)-(y*y);xnew= abs(xnew);
    // to wnew
    SQ k= ((2*x) - (y*y))/(2*y);
    SQ wnew= (k*k) + (2*x);
    // to ynew
    SQ y2= wnew-xnew;SQ ynew= SQroot(y2);

    // out
    cout<<"n= "<<setw(4)<<n<<"  NEW: ";
    cout<<xnew<<"_[";
    cout<<ynew<<"]_"<<wnew<<endl<<endl;
    Xcheck(n,-xnew);Xcheck(n,wnew);
    }
  }
}

int main(void) {

for(SZ n= 5;n< 66;n++) {
  ListDoubles(n);
  }

return 0;
}


