
///////////////////////////////////////////////////////////
// (C) 2023, Author: Simon Aranda. 
// To compile (64bit Windows/mingw):
// g++ -Wall -march=native -Ofast -o %1.exe %1.cpp
//
// No results are guaranteed. 
///////////////////////////////////////////////////////////

/////////////////////////////////////
// Contents of code
//
// global types and static variables
// SZ global functions
// Points global functions
// the form pqrs
// the form xyw -> D
// the TT test, r(n), rank(n).
// points order
// curve rank
// main
///////////////////////////////////

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <array>
#include <set>
#include <utility>
#include "boost/multiprecision/cpp_int.hpp"
//
using namespace boost::multiprecision;
typedef cpp_int       SZ; // field Z
typedef cpp_rational  SQ; // field Q

using namespace std;
typedef std::pair<SZ, SZ> SZpair;
typedef std::pair<SQ, SQ> QPOINT;

// static set of points
std::set<QPOINT> POINTSET; // set wo repeated points.
std::set<QPOINT>::iterator setiter;
// static set of x-coord
std::set<SQ> XSET; // set wo repeated values.

// default parameters
#define PMAXHH 1000000l   // max point height
#define maxnumdvsrs 8192  // max number of divisors
static std::array<SZ,maxnumdvsrs> pleft; // pqrs
static std::array<SZ,maxnumdvsrs> prigh; 
static std::array<SZ,maxnumdvsrs> psum; 
static std::array<SZ,maxnumdvsrs> pdif; 

////////////////////////////////////////
SZ SZrootexact(const SZ p) {
SZ e=0;
SZ r= sqrt(p,e);if(e==0)return r;
return 0;
}
// n= core*(mxq^2)
SZ SZmaxsquare(const SZ n)
{
assert(n>0);
SZ e=0;SZ a= sqrt(n,e)+1;
for(SZ s= a;s>0;s--) {
	SZ ss= (s*s);if((n%ss)==0)return s;
	}
return 1;
}
// core()
SZ SZcore(const SZ n)
{
SZ m= SZmaxsquare(n);assert(n%m==0);
SZ sq= (m*m);assert(n%sq==0);
SZ f= (n/sq);
return f;
}

///////////////////////////////////////////
// Point functions
void displayP(QPOINT P) {
SQ x=P.first;SQ y= P.second;
cout<<"("<<x<<","<<y<<")  ";
}
void Pcheckin(const SZ n,const QPOINT xy) {
SQ x= xy.first;SQ y= xy.second;
SQ b= x*x - n*n;SQ a= x*b;SQ y2= y*y;
bool isp= (y2==a);assert(isp);
}
// y from (n,x)
SZ yFROMnx(const SZ n,const SZ x)
{
SZ x2=x*x;SZ n2=n*n;SZ d2=x2-n2;
SZ dd=x*d2;if(dd<0)return 0;
SZ y=SZrootexact(dd);if(y==0)return 0;
SQ xq=x;SQ yq=y;QPOINT xy= make_pair( xq,yq);
Pcheckin(n,xy);return y;
}
// try insert point into set
bool savePOINT(const SZ n,const QPOINT xy) {
Pcheckin(n,xy);
int bef= POINTSET.size();
POINTSET.insert(xy);
int aft= POINTSET.size();
bool ok= (aft>bef);if(!ok)return false;
return true;
}

////////////////////////////////////////////////
// PQRS 
////////////////////////////////////////////////
// pqrs -> Curve Points.
void POINTSfromPQRS(const SZ n,const SZ D
,SZ p,SZ q,SZ r,SZ s) { 
SZ DD= D*D;SZ DDD= D*D*D;assert(D>0);
for(unsigned ite=0;ite< 4;ite++)
  {
  SQ x,y;
  if(ite==0) {
    x= (-p*r);y= (p*r*(q+r));
    } 
  if(ite==1) {
    x= (-q*r);y= (q*r*(p+r));
    }
  if(ite==2) {
    x= (q*s);y= (q*s*(q+r));
    }
  if(ite==3) {
    x= (p*s);y= (p*s*(p+r));
    }
  x=x/DD;y=y/DDD;QPOINT xy= make_pair(x,y);
  savePOINT(n, xy);
  }
}
// return: number of pqrs forms.
int tryPQRSform(SZ pn, SZ pD)
{
SZ n= pn*pD*pD;if(n%6>0)return 0;
pleft.fill(0);prigh.fill(0);psum.fill(0);pdif.fill(0);
unsigned numdiv=0;
// fill arrays
for(SZ p= 1;p<=n;p++)
	{
	if(n%p >0)continue;
	SZ q= n/p;if(q < p)break;
	assert(numdiv < pleft.size());
	pleft[numdiv]=p;prigh[numdiv]=q;
  psum[numdiv]= p+q;pdif[numdiv]= q-p;
	numdiv++;
	}
// counter
int qq= 0;
for(unsigned i= 0;i<numdiv;i++)
	{
	SZ r=pleft[i];SZ s=prigh[i];
	SZ smr=pdif[i]; // =l*r, smr= r-l.
	for(unsigned j=(i+1);j<numdiv;j++)
		{
		SZ p=pleft[j]; SZ q=prigh[j];
		SZ pmq=psum[j]; // =l*r, pmq=l+r.
    if(pmq < smr)break; // no more chances.
		if(pmq > smr)continue;
    // is pqrs form.
    assert(p*q   == r*s);assert(p+q+r ==   s);
    qq++; // cntr
    POINTSfromPQRS(pn,pD,p,q,r,s);
		}
	}
return qq;
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
// The XYW form -> D value
//////////////////////////////////////////////////
// xyw -> D
SZ DfromXYW(SZ n,SZ XYWy) {
const SZ One= 1;
SQ cat1 (XYWy,One);SQ cat2= 2*n/cat1;
assert((cat1*cat2)==2*n); // check area=n
SQ hip2= cat1*cat1 + cat2*cat2;
SZ hnum= numerator(hip2);SZ hden= denominator(hip2);
hnum= SZrootexact(hnum);hden= SZrootexact(hden);
assert(hnum>0);assert(hden>0); // check is RTQ
SQ hipo (hnum,hden);
SZ cd1= denominator(cat1);SZ cd2= denominator(cat2);
SZ cdp= cd1*cd2;SZ hd= denominator(hipo);assert(hd==cdp);
SZ NEWD = hd; 
return NEWD;
}
SZ tryXYWform(const SZ pn) {
SZ minD= -1;
const SZ nnsz= pn*pn;
for(SZ xx= 1;xx<=pn;xx++)
	{
	if((nnsz%xx)>0)continue;
	const SZ ww= nnsz/xx;
  const SZ ed= (ww-xx);if(ed<=0)break;
  const SZ yy= SZrootexact(ed);
	if(yy>0) {
    SZ CDD= DfromXYW(pn,yy);
    if(minD<0)minD= CDD;
    if(CDD< minD)minD= CDD; // the min D
    }
  }
return minD;
}


////////////////////////////////////////////////////
// The Tunnell Criteria.
////////////////////////////////////////////////////
// Record points.
//  210987654321  LENGTH
//      48272239
//    6611719866
//  797507543735
////////////////
std::array<SZ , 8> VNUM
= { 5, 34, 1254, 29274,48272239ll,6611719866ll
, 797507543735ll, 0};
std::array<int, 8> VRNK= { 1,2, 3, 4, 5, 6, 7, 99};

/////////////////////////
int maxrank(const SZ n) {
if(n<5)return 0;
assert(VNUM.size()==VRNK.size());
unsigned k=-1;
for(unsigned i=0;i< VNUM.size();i++) {
  SZ ib= VNUM[i];SZ ie= VNUM[i+1];if (ie==0)ie= n+1;
  bool inside= (ib<=n && n<ie); // [..[
  if(inside){k=i;break;}
  }
assert(k>=0 && k<=(VNUM.size()-2) );
int v= VRNK[k];return v;
}
// computes range for each axis.
SZ TTrange(SZ vv,int comin) {
double a= (double)vv;a= a/(double)comin;a= std::sqrt(a);
SZ r= (SZ)a;r+=3;
return r;
}
// Thm. Tunnell criteria and more.
// return the r() function.
int TTtest(const SZ p) {
const SZ n= SZcore(p);
SZ nt= n;assert(nt>0);
bool even=(nt%2 ==0);if(even)nt= nt/2;
const SZ vv= nt;
//
int mxrank= maxrank(p);
SZ limx= TTrange(vv,2);SZ limy= TTrange(vv,1);
SZ limz= TTrange(vv,8);
if(limy> 1000)cout<<"TT(O:"<<limy<<"^3)";
int a=0,b=0; // the counters
for(SZ x= 0;x<limx;x++)  
  {
  SZ tx= 0;if(even) tx= +4*x*x;else tx= +2*x*x;
  if(tx>vv)break;
  for(SZ y= 0;y<limy;y++)  
    {
    const SZ ty= +tx +y*y;if(ty>vv)break;
    for(SZ z= 0;z<limz;z++)  
      {
      const SZ tza = +ty + 8*z*z;
      const SZ tzb = +ty + 32*z*z;
      bool ba= (tza==vv);bool bb= (tzb==vv);
      if(ba || bb) {
        int ee=1;
        if(x!=0)ee*=2;
        if(y!=0)ee*=2;
        if(z!=0)ee*=2;
        if(ba)a+=ee;
        if(bb)b+=ee;
        }
      if(tza>vv)break;
      }
    }
  }
// decode a,b to m,q.
int q=-1,m=-1;
if(b>0) {
  m=a%b;if(m==0)q=a/b;
  }
// the function r(n)
int rn=0; // r()=0.
if(a==0 && b==0)rn= 1;
else if(q==2)rn= 2;
// cout
cout<<"TT: ("<<a<<"/"<<b<<")-> ";
if(rn==0) cout<<"Rank=0";
if(rn==1) cout<<"(0 < Rank <= ";
if(rn==2) cout<<"(0 < Rank <= ";
if(rn> 0) cout<<mxrank<<") ";
if(rn==1) cout<<" Conj: Rank Odd.";
if(rn==2) cout<<" Conj: Rank Even.";
cout<<endl;
assert(rn>=0);return rn;
}

////////////////////////////////////
// Integral points. Lattice points.
////////////////////////////////////
void naivesearch(const SZ n) {
assert(n>0);
const SZ nn= 2*n;
for(SZ x= (-n+1);x< nn;x++) // never x=+-n nor 0.
  {
  if(x==0)x=n; // skip 0 
  SZ y= yFROMnx(n,x);if(y==0)continue; // try
  SQ xq=x;SQ yq=y;QPOINT xy= make_pair(xq,yq);
  bool bsp= savePOINT(n, xy);
  if(bsp) {
    if(x<0)cout<<"*Recovered  :";
    if(x>0)cout<<"*Discovered :";
    displayP(xy);cout<<endl;
    }
  }
}
//////////////////////////////////////
////
QPOINT find2P(const SZ n, const QPOINT xy) {
SQ RX=xy.first;SQ RY=xy.second; // R= P;
//
const SZ Cero= 0;QPOINT p00= make_pair( Cero, Cero);
bool yz = (RY==0);if(yz)return p00;
// R= 2*R
SQ m= (3*RX*RX -n*n)/(2*RY);
SQ RXN= m*m -RX-RX;SQ RYN= RY+m*(RXN-RX);
RX= RXN;RY= -RYN;
QPOINT p2P= make_pair(RX, RY);
return p2P;
}

// code x not eq.
// else   {    // R= R+P  SQ m= (PY-RY)/(PX-RX);
// SQ RXN= m*m -RX-PX;SQ RYN= PY+m*(RXN-PX); ;
// RX= RXN;RY= -RYN;  }
///////////////////////////////////////////////
// get rank function
////////////////
void globalclear(void) {
POINTSET.clear();
}  
void giveuse(void) {
cout<<"Use:  xrank <n> "<<endl;
cout<<"(exclusively for recreational use)"<<endl; 
}



///////////////////////////////////////////////////////
// get rank
///////////////////////////////////////////////////////
// torsion points x:(-n,0,+n) Order=2, 2P=0. 
// T1 T2 T3, g,-g,g+Ti,-g+Ti.
///////////////////////////////////////////////////////
int tryGETrank(SZ pp) {
globalclear();  // POINTSET.clear();
assert(POINTSET.empty());
//
const SZ pqmx= SZmaxsquare(pp);
SZ pcor= pp;pcor=pcor/pqmx;pcor=pcor/pqmx;
assert( (pcor*pqmx*pqmx) == pp);
cout<<"n= "<<pp<<"= "<<pcor<<"*["<<pqmx<<"^2]  ";
//
int rn= TTtest(pp);if(rn==0)return 0;
SZ xywD= tryXYWform(pp);
cout<<"XYW->D for PQRS="<<xywD<<endl;

SZ pqrsD= xywD;if(pqrsD<1)pqrsD=1;
int qu= tryPQRSform(pp,pqrsD); // Called with D.
if(xywD>0)assert(qu>0);
cout<<"Forms PQRS: "<<qu<<endl;

naivesearch(pp);

size_t totpo= POINTSET.size();
cout<<"#Points: "<<totpo<<endl;

// Set Order(Point)
XSET.clear();
if(totpo>0) {
  for(setiter= POINTSET.begin(); setiter != POINTSET.end(); ++setiter) 
    {
    QPOINT xy= *setiter;Pcheckin(pp,xy);
    cout<<"P";displayP(xy);
    QPOINT t2P= find2P(pp,xy);
    cout<<"  2P";displayP(t2P);
    SQ ycord= t2P.second;bool yok= (ycord != 0);
    if(!yok)cout<<"TORS";
    if(yok) {
      size_t befo=XSET.size();
      XSET.insert(t2P.first);
      size_t afte=XSET.size();
      bool ok=(afte>befo);if(!ok)cout<<"DEP";
      }
    cout<<endl;
    }
  }
size_t totco= XSET.size();
SZ indep= (SZ) totco;
cout<<"Indep. P. <= "<<indep<<endl;

globalclear();
return 0;
}

/////////////////////////////////////////////
SZ getlineparam(int argc,char* argv[]) {
if(argc != 2)return 0; // 2: [0] [1].
unsigned sl= strlen(argv[1]);if(sl<1 || sl>18)return 0;
char anum[82];strcpy(anum,argv[1]);
for(unsigned i=0;i<sl;i++) {
  int v=isdigit(anum[i]);if(v==0)return 0;
  }
SZ lp= (SZ) stoll(argv[1]);if(lp<1)return 0;
return lp;
}

void seqxyw(void) 
{
for(SZ n=1;n< 501;n++) {
  tryXYWform(n);
  }
}

int main(int argc,char* argv[])
{
const SZ pp= getlineparam(argc,argv);
if(pp<1) {giveuse();return 1;}
cout<<endl<<endl<<endl;
cout<<"Elliptic Curve C[n]:[-n^2,0]."<<endl;
tryGETrank(pp);
cout<<"(conjectured result only)"<<endl<<endl; 
return 0;
}

///////////////////////////////////////////////////////////
// No results are guaranteed. 
// Exclusively for recreational use. 
// Never for research or educational use. 
// Never for industrial, medical or commercial use.
///////////////////////////////////////////////////////////
