

///////////////////////////////////////////////////////////
// (C) 2023, Author: Simon Aranda. 
// To compile (64bit Windows/mingw):
// g++ -Wall -march=native -Ofast -o %1.exe %1.cpp
//
// Exclusively for recreational use. 
//
// No results are guaranteed. 
// Never for research or educational use. 
// Never for industrial, medical or commercial use.
///////////////////////////////////////////////////////////

/////////////////////////////////////
// Contents of code
//
// global types and static variables
// SZ global functions
// Points global functions
// the form pqrs
// the form xyw
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
typedef std::pair<SQ, SQ> PQINT;

// static set of points
std::set<PQINT> POINTSET; // set wo repeated points.
std::set<PQINT>::iterator setiter;

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
bool isPOINTinCurve(const SZ n,const PQINT xy) 
{
SQ x= xy.first;SQ y= xy.second;
SQ b= x*x - n*n;SQ a= x*b;
SQ y2= y*y;bool isp= (y2==a);
return isp;
}

// y from C(n,x)
SZ yFROMnx(bool trz, const SZ n,const SZ x)
{
SZ x2=x*x;SZ n2=n*n;SZ d2=x2-n2;
SZ dd=x*d2;if(dd<0)return 0;
SZ y=SZrootexact(dd);if(y==0)return 0;
if(trz)cout<<"P("<<x<<","<<y<<" )"<<endl;
SQ xq=x;SQ yq=y;PQINT xy= make_pair( xq,yq);
bool pok=isPOINTinCurve(n,xy);assert(pok);return y;
}

// insert point into set
bool savePOINT(const SZ n,const PQINT xy) {
bool b= isPOINTinCurve(n,xy);assert(b);
cout<<"P("<<xy.first<<", "<<xy.second<<") "<<endl;
POINTSET.insert(xy);return true;
}

////////////////////////////////////////////////
// pqrs -> RTZ Area n.
void RTZfromPQRS(SZ p,SZ q,SZ r)
{
SZ a= p+r;SZ b= q+r;SZ c= p+q;
SZ d= (a*a + b*b);SZ e= c*c;assert(d==e);
SZ area= (a*b);assert(area%2==0);
area= area/2;SZ pq=p*q;assert(area==pq);
cout<<"RTZ ("<<a<<", "<<b<<", "<<c<<") "<<endl;
}

// pqrs -> SQZ triad integer squares
void SQZfromPQRS(SZ p,SZ q,SZ r,SZ s) {
SZ s1= q-p;SZ s2= p+q;SZ s3= r+s;
cout<<"SQZ-4N [ "<<s1<<", "<<s2;
cout<<", "<<s3<<" ]"<<endl;
bool evens= (s1%2==0) && (s2%2==0) && (s3%2==0);
if(!evens)return;
SZ h1=s1/2;SZ h2=s2/2;SZ h3=s3/2;
cout<<"SQZ-1N [ "<<h1<<", "<<h2<<", "<<h3<<" ]"<<endl;
}

// pqrs -> points
void POINTSfromPQRS(const SZ n,const SZ D,SZ p,SZ q,SZ r)
{
SZ DD= D*D;SZ DDD= D*D*D;
for(unsigned ite=0;ite<2;ite++)
  {
  SQ x,y;
  if(ite==0) {
    x= (-p*r);y= (p*r*(q+r));
    } else  {
    x= (-q*r);y= (q*r*(p+r));
    }
  x=x/DD;y=y/DDD;PQINT xy= make_pair(x,y);savePOINT(n, xy);
  }
}

// return: number of pqrs forms.
int tryPQRSform(bool trz,SZ pn, SZ pD)
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
// here is pqrs form.
    assert(p*q   == r*s);assert(p+q+r ==   s);
    //  counter
    qq++;
    if(trz) {
      cout<<qq<<"-pqrs:  n= "<<n;
      cout<<"= "<<p<<" * "<<q;
      cout<<"= "<<r<<" * "<<s<<endl;
      }
    if(trz)POINTSfromPQRS(pn,pD,p,q,r);
    if(trz)RTZfromPQRS(p,q,r);
    if(trz)SQZfromPQRS(p,q,r,s);
		}
	}
return qq;
}

//////////////////////////////////////////////////
// (n,..) -> RTQ
SZ RTQfromXYW(bool trz,SZ n,SZ pD,SZ XYWy) {
SQ cat1 (XYWy,pD);SQ cat2= 2*n/cat1;
assert((cat1*cat2)==2*n); // check area=n
SQ hip2= cat1*cat1 + cat2*cat2;
SZ hnum= numerator(hip2);SZ hden= denominator(hip2);
hnum= SZrootexact(hnum);hden= SZrootexact(hden);
assert(hnum>0);assert(hden>0); // check is RTQ
SQ hipo (hnum,hden);
SZ cd1= denominator(cat1);SZ cd2= denominator(cat2);
SZ cdp= cd1*cd2;SZ hd= denominator(hipo);assert(hd==cdp);
SZ NEWD = hd; 
if(trz) {
  cout<<"RTQ ("<<cat1<<", "<<cat2<<", "<<hipo<<")";
  cout<<" -> new D= "<<NEWD<<endl;
  }
return NEWD;
}

//////
SZpair tryXYWform(const bool trz,const SZ pn,const SZ pD) {
SZpair retval= make_pair(0,0);
const SZ ncc= (pn*pD*pD);if(ncc<1)return retval;
const SZ nn= ncc*ncc;
SZ f=0;SZ minD= -1;const SZ nnsz= nn;
for(SZ xx= 1;;xx++)
	{
	if((nnsz%xx)>0)continue;
	const SZ ww= nnsz/xx;
  const SZ ed= (ww-xx);if(ed<=0)break;
  const SZ yy= SZrootexact(ed);
	if(yy>0) 
    {
    ////SZ d= xx;SZ e= ww;SZ XYWy= yy;
    f++;
    if(trz)  {
      cout<<f<<"-xyw (x="<<xx <<", y= ";
      cout<<yy <<", w= "<<ww<<")"<<endl;
      }
    SZ CDD= RTQfromXYW(trz,pn,pD,yy);
    if(minD<0)minD= CDD;
    if(CDD< minD)minD= CDD; // the min D
    SZ xel= -xx; SZ yel= +xx*yy; // SZ nel= pn;
    PQINT xy= make_pair(xel,yel);
    savePOINT(pn, xy);
    }
  }
retval= make_pair( f,minD);return retval;
}

////////////////////////////////////////////////////
// computes range for each axis.
SZ TTrange(SZ vv,int comin) {
double a= (double)vv;a= a/(double)comin;a= std::sqrt(a);
SZ r= (SZ)a;r+=3;
return r;
}

// Thm. Tunnell criteria.
int TTtest(const bool trz,const SZ p) {
const SZ n= SZcore(p);SZ nt= n;assert(nt>0);
bool even=(nt%2 ==0);if(even)nt= nt/2;
const SZ vv= nt;
SZ limx= TTrange(vv,2);SZ limy= TTrange(vv,1);
SZ limz= TTrange(vv,8);
if(trz)cout<<"TT ("<<p<<", "<<n<<", "<<limy<<" )"<<endl;
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
int rn=0; // rk 0.
if(a==0 && b==0)rn= 1; // Odd rk
else if(q==2)rn= 2; // Even rk
if(trz) // traces
  {
  cout<<"TT ("<<a<<"/"<<b<<")-> ";
  if(rn==0) cout<<"Rank=0;  +Conj: ";
  else      cout<<"Rank>0;  +Conj: ";
  if(rn==1) {
    if(n<1254)cout<<"rank= 1."<<endl;
    else cout<<"rank Odd."<<endl;
    }
  if(rn==2) {
    if(n<29274)cout<<"rank= 2.";
    else cout<<"rank Even.";
    }
  cout<<endl;
  }
assert(rn>=0);return rn;
}

////////////////////////////////////
// search lattice points
int naivesearch(const SZ n) {
assert(n>0);int q=0;
const SZ xlim= 2*n;
for(SZ x= (-n+1);x< xlim;x++)
  {
  if(x==0)x=n; // jmp
  // try y rational.
  SZ y= yFROMnx(false,n,x);if(y==0)continue;
  SQ xq=x;SQ yq=y;PQINT xy= make_pair(xq,yq);
  //
  q++;if(q==1)cout<<"Naive lattice:"<<endl;
  savePOINT(n, xy);
  }
return q;
}

//////////////////////////////////////
SZ POINTminval(PQINT p) {
SQ a= p.first;SZ c= numerator(a);SZ d= denominator(a);
SQ b= p.second;SZ e= numerator(b);SZ f= denominator(b);
c=abs(c);d=abs(d);e=abs(e);f=abs(f);
SZ h= c;
if(d<h)h=d;
if(e<h)h=e;
if(f<h)h=f;
return h;
}

void POINTorder(SZ n, PQINT xy) {
const SQ PX=xy.first;const SQ PY=xy.second;
// R=P
SQ RX=PX;SQ RY=PY;unsigned np= 0;
cout<<"Order of P("<<PX<<","<<PY<<"): "<<endl;
while(true)
  {
  np++;
  PQINT xy= make_pair(RX,RY);
  SZ hh= POINTminval(xy);if(hh> PMAXHH)break;
  if(np>20)break; // limit
//
  cout<<np<<"*P= ("<<RX<<","<<RY<<" )"<<endl;
  bool b= isPOINTinCurve(n,xy);assert(b);
  bool xeq= (RX==PX);
  bool yz = (RY== 0);
  if(xeq && yz)break;
//  
  if(xeq) {
    // R= 2*R
    SQ m= (3*RX*RX -n*n)/(2*RY);
    SQ RXN= m*m -RX-RX;
    SQ RYN= RY+m*(RXN-RX);
    RX= RXN;RY= -RYN;
    }
  else {
    // R= R+P
    SQ m= (PY-RY)/(PX-RX);
    SQ RXN= m*m -RX-PX;
    SQ RYN= PY+m*(RXN-PX); ;
    RX= RXN;RY= -RYN;
    }
  }
}

///////////////////////////////////////////////
void globalclear(void) {
POINTSET.clear();
}  

void giveuse(void) {
cout<<"Use:  xrank <n> "<<endl;
cout<<"(exclusively for recreational use)"<<endl; 
}

int tryGETrank(SZ pp) {
if(pp<1) {giveuse();return 1;}

globalclear();  // POINTSET.clear();

TTtest(true,pp);cout<<endl;

int v= naivesearch(pp);if(v>0)cout<<endl;

SZpair qsd= tryXYWform(true,pp,1);
SZ qs = qsd.first;SZ minD= qsd.second;
if(qs >0)cout<<endl;

SZ DD=1;
if(minD>0) {
  DD=minD;if(DD>1)cout<<"Use new D="<<DD<<endl;
  }
int qu= tryPQRSform(true,pp,DD);if(qu>0)cout<<endl;

size_t topo= POINTSET.size(); // .empty()
// resume
cout<<"n= "<<pp<<", number of forms xyw: "<<qs<<", pqrs: "<<qu;
cout<<" points: "<<topo<<endl;

// order of all points in set
if(topo>0) {
  cout<<"Computing Points Order:"<<endl<<endl;
  for(setiter= POINTSET.begin(); setiter != POINTSET.end(); ++setiter) 
    {
    PQINT xy= *setiter;bool b= isPOINTinCurve(pp,xy);assert(b);
    POINTorder(pp,xy);cout<<endl;
    }
  }

globalclear();
cout<<"(exclusively for recreational use)"<<endl; 
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

int main(int argc,char* argv[])
{
cout<<"Curve C[n]: (y^2)= (x^3)-(n^2)*x; [-n^2,0]."<<endl;
SZ pp= getlineparam(argc,argv);

tryGETrank(pp);

return 0;
}

