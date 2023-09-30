

//(C)2023.Author: Simon Aranda 

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <set>
#include <utility>
#include "boost/multiprecision/cpp_int.hpp"

// types
using namespace boost::multiprecision;
typedef cpp_int       SZ;
typedef cpp_rational  SQ;
using namespace std;
typedef std::pair<SQ, SQ> POINT;

// static set of points
std::set<POINT> PSET;
std::set<POINT>::iterator ite1;

// proto
SZ SZroot(const SZ p);
SZ YfromNX(const SZ n,const SZ x);

void printQPoint(const POINT P) {
const SQ x=P.first;
const SQ y= P.second;
cout<<"P("<<x<<","<<y<<") "<<endl;
}
POINT add2points(const SZ n
, const POINT P, const POINT Q) {
const SZ Cero= 0;
const POINT Inf= make_pair( Cero, Cero);
POINT S=Inf;
const SQ PX=P.first;const SQ PY=P.second;
const SQ QX=Q.first;const SQ QY=Q.second;
if(P==Q) { // P+P
  if(PY==0)return Inf;
  const SQ m= (3*PX*PX -n*n)/(2*PY);
  const SQ SX= m*m -2*PX;
  SQ SY= PY + m*(SX-PX);if(SY<0)SY= -SY;
  S= make_pair(SX,SY);
  }
  else  {   // P+Q
  const SQ tu= (PY-QY);
  const SQ td= (PX-QX);
  const SQ m = tu/td;
  const SQ m2= m*m;
  const SQ SX= ( m2 -PX-QX);
  SQ SY= PY + m*(SX-PX);if(SY<0)SY= -SY;
  S= make_pair(SX,SY);
  }
return S;
}
POINT PointBuild(const SZ xz,const SZ yz) {
const SZ One=1;
const SQ x (xz,One);
const SQ y (yz,One);
POINT P= make_pair(x, y);
return P;
}
void printPSET(void) {
for(ite1= PSET.begin();ite1 != PSET.end();++ite1) {
  const POINT P= *ite1;
  printQPoint(P);
  }
}
void PQdrop(SZ n, POINT P,POINT Q) {
POINT S= add2points(n,P,Q);
cout<<"drop ";
printQPoint(S);
PSET.erase(S);
}


// Pkg look  (cache-blk)
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
const SZ a= x+n;const SZ b= x-n;
const SZ c= a*b;
const SZ d= c*x;if(d<= 0)return Cero;
const SZ y=SZroot(d);if(y<= 0)return Cero;
return y;
}
void FindPoints(const SZ n,const SZ limit) {
const SZ Cero=0;
const SZ n2= n*n;
PSET.clear();
for(SZ x= -n;x<limit;x++) // never -n,0,+n
  {
  if(x== -n)x++;
  else if(x==  0)x=n+1;
  const SZ y= YfromNX(n,x);if(y==Cero)continue;
  //
  const POINT P= PointBuild(x,y);
  PSET.insert(P);
  printQPoint(P);
  }
}

int main(void) {
const SZ Cero=0;

// mini example n=6
SZ n = 6;
const POINT tn= PointBuild(-n,   Cero);
const POINT t0= PointBuild(Cero, Cero);
const POINT tp= PointBuild( n,   Cero);

cout<<"n= "<<n<<endl;
FindPoints( n , 9999);

cout<<"Torsion group:"<<endl;
printQPoint(tn);
printQPoint(t0);
printQPoint(tp);
//
POINT GEN1;
size_t sz= PSET.size();
cout<<"Generators: 1, Dependent: "<<(sz-1)<<endl;
// set ordered by xcoordinate.
// the infimum x is the unique generator point.

bool first=true;
for(ite1= PSET.begin();ite1 != PSET.end();++ite1) {
  POINT P= *ite1;
  if(first)cout<<"Generator: ";
  else     cout<<"Dependent: ";
  printQPoint(P);
  if(first) {
    GEN1=P;first=false;
    }
  }

cout<<"Drop linear dep."<<endl;
PQdrop(n,GEN1,tn);
PQdrop(n,GEN1,t0);
PQdrop(n,GEN1,tp);
const POINT g2=add2points(n,GEN1,GEN1);
PQdrop(n,g2,tp);

cout<<"PSET:"<<endl;
printPSET();

return 0;
}


