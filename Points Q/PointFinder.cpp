
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
typedef cpp_int       SZ; // field Z
typedef cpp_rational  SQ; // field Q
using namespace std;
typedef std::pair<SQ, SQ> QPOINT;

// header
SZ SZroot(const SZ p);

///////////////
bool printBIGnp(SZ n, SQ x, SQ y) {
SZ a= numerator(x);
SZ b= denominator(x);
SZ c= numerator(y);
SZ d= denominator(y);
if(b<1)return false;
if(d<1)return false;
SZ z= SZroot(b);
if(z<1)return false;
if((z*z*z) != d)return false;
SZ B= (a*a*a) - (c*c);
cout<<"        big(n,p)= "<<setw(12)<<B;
cout<<"= anz("<<a<<","<<n<<","<<z<<")";
cout<<endl;
return true;
}

bool CheckNpoint(SZ nz,QPOINT xy) {
const SZ One=1;
const SQ n (nz,One);
SQ x= xy.first;SQ y= xy.second;
SQ a= x+n;
SQ b= x-n;
SQ c= a*b;
SQ d= c*x;
SQ y2= y*y;
bool isp= (y2==d);
if(isp && true) {
  bool b= printBIGnp(nz,x,y);
  assert(b);
  }
assert(isp);
return isp;
}
void ZprintCheckNKXY(SZ n, char k,SZ x, SZ y) {
cout<<"   "<<setw(4)<<n<<setw(2)<<k;
cout<<" P("<<setw(14)<<x<<", ";
cout<<setw(14)<<y<<")"<<endl;
const SZ One=1;
SQ qx (x,One);
SQ qy (y,One);
QPOINT p= make_pair(qx,qy);
bool b= CheckNpoint(n,p);assert(b);
}
void QprintCheckNKXY(SZ n, char k,SQ x, SQ y) {
cout<<" ->"<<setw(4)<<n<<setw(2)<<k;
cout<<" P("<<setw(14)<<x<<", ";
cout<<setw(14)<<y<<")"<<endl;
QPOINT p= make_pair(x,y);
bool b= CheckNpoint(n,p);assert(b);
}
// Cn P(-a,b) -> P(n.2/a, (n.2/a)*(b/a))
void LEFTtoRIGHT(SZ n, SZ a,SZ b) {
SZ n2= n*n;
SQ x (n2, a);
SQ t (b,a);
SQ y= x*t; 
QprintCheckNKXY(n,'r',x,y);
}
// Cn P(c,d)-> P(-n.2/c, (n.2/c)*(d/c) )
void RIGHTtoLEFT(SZ n, SZ c,SZ d) {
SZ mn2= -(n*n);
SQ x   (mn2 ,c);
SQ ddc (d,c);
SQ y = x*ddc;
QprintCheckNKXY(n,'l',x,y);
}
//////////////////////////////
// Pkg look
SZ SZroot(const SZ p) {
const SZ Cero=0;
if(p<=0)return Cero;
SZ e=0;
SZ r= sqrt(p,e);
if(e==0)return r;
return Cero;
}
SZ YfromNX(const SZ n,const SZ x) {
const SZ Cero=0;
SZ a= x+n;
SZ b= x-n;
SZ c= a*b;
SZ d= c*x;
if(d<= 0)return Cero;
SZ y=SZroot(d);if(y<= 0)return Cero;
return y;
}
int SearchPoints(const SZ n) {
const SZ Cero=0;
const SZ One=1;
const SQ q0 (Cero,One);
const SZ n2= n*n;
int lpc=0;
SZ xpmax= 0;
for(SZ a= (n-1);a>0;a--)
  {
  SZ x= -a;
  SZ y= YfromNX(n,x);if(y==0)continue;
  lpc++;if(lpc==1)cout<<"Left points: "<<endl;
  SZ tt= n2*a;
  if(tt >xpmax)xpmax= tt;
  ZprintCheckNKXY(n,'L',x,y);
  LEFTtoRIGHT(n,a,y);
  cout<<endl;
  }
const SZ rlim0= xpmax;
const SZ rlim1= 9999999l;
int rpc=0;
for(SZ x= n+1;x<rlim1;x++) // never -n,0,+n
  {
  SZ y= YfromNX(n,x);
  if(lpc>0 && x>rlim0)break;
  if(y==0)continue;
  rpc++;
  if(rpc==1) {
    if(lpc==0)cout<<"No left points."<<endl;
    cout<<"Right points:"<<endl;
    }
  ZprintCheckNKXY(n,'R',x,y);
  RIGHTtoLEFT(n,x,y);
  cout<<endl;
  }
return (lpc+rpc);
}

////////

int main(void) {
  
for(SZ n=1;n< 100;n++) {
  SearchPoints(n);
  cout<<endl;
  }
 
return 0;
}


